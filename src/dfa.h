#ifndef DFA_H
#define DFA_H

#define SYMBOL_COUNT_LIMIT 255
#define SYMBOL_SCAN_STR "%255s"

#define STATE_NAME_LENGTH_LIMIT 1023
#define STATE_SCAN_STR "%1023s"

typedef struct {

	/* Jumlah simbol (ukuran alfabet) dan array berisi karakter-karakter simbol */
	int n_symbols;
	char *symbols;

	/* Jumlah state dan array berisi nama-nama state */
	int n_states;
	char **states;

	/* Jumlah final state dan array berisi indeks-indeks final state */
	int n_final_states;
	int *final_state_indexes;

	/* Indeks state awal */
	int start_state_index;

	/* Array 2-dimensi berisi transition table (baris: indeks state, kolom: indeks simbol, isi: indeks state tujuan */
	int *transition_table;

} dfa;

/* Load spesifikasi DFA dari file dengan path yang diberikan.
 * Menghasilkan DFA tersebut jika berhasil, dan DFA dengan start_state -1 jika gagal.
 * Format file DFA ada di file README.md */
dfa load_dfa(const char *path);

/* Deallocate memori yang digunakan oleh DFA */
void unload_dfa(dfa *automaton);

/* Menghasilkan indeks state tujuan dari DFA jika diberikan keadaan indeks state dan indeks symbol input */
int delta(dfa automaton, int current_state_index, int symbol_index);

/* Menghasilkan nomor state dari nama state yang diberikan dan -1 jika nama state tersebut tidak ditemukan */
int get_state_index(dfa automaton, const char *state);

/* Menghasilkan nomor symbol dari karakter symbol yang diberikan dan -1 jika nama symbol tersebut tidak ditemukan */
int get_symbol_index(dfa automaton, char symbol);

/* Menghasilkan 1 jika nomor state yang diberikan adalah final state, 0 jika tidak atau state tidak ditemukan */
unsigned char is_final_state(dfa automaton, int current_state_index);

#endif
