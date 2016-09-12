#include "dfa.h"
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255
#define FILENAME_SCAN_STR "%255s"
#define MAX_INPUT_STRING_LENGTH 1023
#define INPUT_STRING_SCAN_STR "%1023s"
#define MAX_REPEAT_LENGTH 100
#define REPEAT_SCAN_STR "%100s"

int main() {

	dfa automaton;
	int i, input_len;
	unsigned char repeat_input = 0;

	/* Cetak header */
	printf("\nDFA\n===\n\n");
	printf("NIM       : 13515001\nNama      : Jonathan Christopher\nKelas     : K-01, TBFO IF2220\nTanggal   : 12 September 2016\nTopik     : DFA\nDeskripsi : Program sederhana untuk mengecek apakah suatu string diterima oleh DFA tertentu.\n");
	printf("\n");

	/* Load file DFA */
	unsigned char load_file_ok = 0;
	do {
		char path_buf[MAX_FILENAME_LENGTH + 1];
		printf("Path ke file DFA (untuk tugas TBFO, gunakan dfa/marble.dfa): ");
		scanf(FILENAME_SCAN_STR, path_buf);
		automaton = load_dfa((char *) path_buf);
		if (automaton.start_state_index == -1) {
			printf("Gagal membaca file DFA.\n");
		} else {
			load_file_ok = 1;
		}
	} while (!load_file_ok);

	do {

		/* Baca input string */
		char input_buf[MAX_INPUT_STRING_LENGTH + 1];
		printf("\n");
		printf("Masukkan input string: ");
		scanf(INPUT_STRING_SCAN_STR, input_buf);
		input_len = strlen(input_buf);

		/* Jalankan DFA */
		int current_state_index = automaton.start_state_index;
		int next_symbol_index;
		printf("%s", automaton.states[current_state_index]);
		for (i = 0; i < input_len; i++) {
			next_symbol_index = get_symbol_index(automaton, input_buf[i]);
			/* asumsi jika terbaca sebuah simbol yang tidak dikenali, maka tidak akan berpindah state */
			if (next_symbol_index >= 0) {
				current_state_index = delta(automaton, current_state_index, next_symbol_index);
				printf(" -> %s", automaton.states[current_state_index]);
			}
		}
		printf("\n");
		printf("String diterima? %s\n", is_final_state(automaton, current_state_index) ? "Ya (berakhir di final state)" : "Tidak (tidak berakhir di final state)");

		/* Tanya apakah ingin mengulang */
		char repeat_buf[MAX_REPEAT_LENGTH + 1];
		printf("Coba lagi? (y/n): ");
		scanf(REPEAT_SCAN_STR, repeat_buf);
		repeat_input = (strlen(repeat_buf) > 0 && (repeat_buf[0] == 'y' || repeat_buf[0] == 'Y'));

	} while (repeat_input);

	unload_dfa(&automaton);
	return 0;
}