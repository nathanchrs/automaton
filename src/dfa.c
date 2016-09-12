#include "dfa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Load spesifikasi DFA dari file dengan path yang diberikan, dengan asumsi format file valid.
 * Menghasilkan DFA tersebut jika berhasil, dan DFA dengan start_state -1 jika gagal.
 * Format file DFA ada di file README.md */
dfa load_dfa(const char *path) {

	dfa new_dfa;
	char symbols_buf[SYMBOL_COUNT_LIMIT + 1];
	char state_buf[STATE_NAME_LENGTH_LIMIT + 1];
	int state_len;
	int i, j;
	FILE *fin;

	/* Buka file */
	fin = fopen(path, "r");
	if (fin == NULL) {
		/* Failed to open file */
		new_dfa.start_state_index = -1;
		return new_dfa;
	}

	/* Baca simbol, asumsi simbol unik, dalam bentuk string tanpa whitespace */
	fscanf(fin, SYMBOL_SCAN_STR, symbols_buf);
	new_dfa.n_symbols = strlen(symbols_buf);
	new_dfa.symbols = malloc(sizeof(char) * new_dfa.n_symbols);
	strncpy(new_dfa.symbols, symbols_buf, new_dfa.n_symbols); /* new_dfa.symbols tidak null-terminated */

	/* Baca jumlah state dan nama-nama state */
	fscanf(fin, "%d", &new_dfa.n_states);
	new_dfa.states = malloc(sizeof(char *) * new_dfa.n_states);
	for (i = 0; i < new_dfa.n_states; i++) {
		fscanf(fin, STATE_SCAN_STR, state_buf);
		state_len = strlen(state_buf);
		new_dfa.states[i] = malloc(sizeof(char) * (state_len + 1));
		strncpy(new_dfa.states[i], state_buf, state_len + 1);
	}

	/* Baca jumlah final state dan nama-nama final state */
	fscanf(fin, "%d", &new_dfa.n_final_states);
	new_dfa.final_state_indexes = malloc(sizeof(int) * new_dfa.n_final_states);
	for (i = 0; i < new_dfa.n_final_states; i++) {
		fscanf(fin, STATE_SCAN_STR, state_buf);
		new_dfa.final_state_indexes[i] = get_state_index(new_dfa, state_buf);
	}

	/* Baca nama state awal */
	fscanf(fin, STATE_SCAN_STR, state_buf);
	new_dfa.start_state_index = get_state_index(new_dfa, state_buf);

	/* Baca transition table */
	new_dfa.transition_table = malloc(sizeof(int) * new_dfa.n_states * new_dfa.n_symbols);
	for (i = 0; i < new_dfa.n_states; i++) {
		for (j = 0; j < new_dfa.n_symbols; j++) {
			fscanf(fin, STATE_SCAN_STR, state_buf);
			new_dfa.transition_table[i*new_dfa.n_symbols + j] = get_state_index(new_dfa, state_buf);
		}
	}

	fclose(fin);
	return new_dfa;
}

/* Deallocate memori yang digunakan oleh DFA */
void unload_dfa(dfa *automaton) {
	int i;

	free((*automaton).symbols);
	(*automaton).n_symbols = 0;

	for (i = 0; i < (*automaton).n_states; i++) {
		free((*automaton).states[i]);
	}
	free((*automaton).states);
	(*automaton).n_states = 0;

	free((*automaton).final_state_indexes);
	(*automaton).n_final_states = 0;

	(*automaton).start_state_index = -1;
	
	free((*automaton).transition_table);
}

/* Menghasilkan indeks state tujuan dari DFA jika diberikan keadaan indeks state dan indeks symbol input */
int delta(dfa automaton, int current_state_index, int symbol_index) {
	return automaton.transition_table[current_state_index*automaton.n_symbols + symbol_index];
}

/* Menghasilkan nomor state dari nama state yang diberikan dan -1 jika nama state tersebut tidak ditemukan */
int get_state_index(dfa automaton, const char *state) {
	int i = 0;
	unsigned char found = 0;
	while (i < automaton.n_states && !found) {
		if (strcmp(automaton.states[i], state) == 0) {
			found = 1;
		} else {
			i++;
		}
	}
	return found ? i : -1;
}

/* Menghasilkan nomor symbol dari karakter symbol yang diberikan dan -1 jika nama symbol tersebut tidak ditemukan */
int get_symbol_index(dfa automaton, char symbol) {
	int i = 0;
	unsigned char found = 0;
	while (i < automaton.n_symbols && !found) {
		if (automaton.symbols[i] == symbol) {
			found = 1;
		} else {
			i++;
		}
	}
	return found ? i : -1;
}

/* Menghasilkan 1 jika nomor state yang diberikan adalah final state, 0 jika tidak atau state tidak ditemukan */
unsigned char is_final_state(dfa automaton, int current_state_index) {
	int i = 0;
	unsigned char found = 0;
	while (i < automaton.n_final_states && !found) {
		if (automaton.final_state_indexes[i] == current_state_index) {
			found = 1;
		} else {
			i++;
		}
	}
	return found;
}