# Automaton

```
NIM       : 13515001
Nama      : Jonathan Christopher
Kelas     : K-01, TBFO IF2220
Tanggal   : 18 September 2016
Topik     : DFA
Deskripsi : Program sederhana untuk mengecek apakah suatu string diterima oleh DFA tertentu.
```

## Cara Menjalankan

1. Jalankan `make` untuk build (atau `gcc src/main.c src/dfa.c -o automaton` jika tool `make` tidak berhasil)
2. Jalankan file executable hasil keluarannya (`./automaton` atau `automaton.exe` pada Windows)
3. Masukkan nama file DFA. Contoh file DFA diberikan dalam direktori `dfa`. (untuk tugas TBFO, file DFA yang digunakan adalah `dfa/marble.dfa`)
4. Masukkan string input untuk DFA. Hasil akan ditampilkan di layar

Disediakan 2 contoh file DFA di direktori `dfa`:
- `marble.dfa`: DFA pada Exercise 2.2.1, (Hopcroft, John E.; Motwani, Rajeev; Ullman, Jeffrey D. (2013). Introduction to Automata Theory, Languages, and Computation (3rd ed.). Pearson.)
- `onoff.dfa`: DFA dari sebuah saklar yang hanya memiliki 2 state, on dan off, dengan alfabet 0 dan 1

### Format File DFA

```
<string yang masing-masing karakternya melambangkan sebuah simbol (tidak boleh mengandung whitespace dalam string dan harus unik, maksimal 255 karakter)>

<jumlah state (0 <= n <= 1023)>
<nama-nama state dipisahkan whitespace (isi nama tidak boleh mengandung whitespace dan harus unik, maksimal 1023 karakter)>

<jumlah final state (0 <= n <= jumlah state)>
<nama-nama final state dipisahkan whitespace (harus unik dan harus ada di daftar state)>

<nama state awal (hanya 1, harus ada di daftar state)>

<representasi fungsi transisi dalam bentuk tabel (baris: nama state awal, kolom: simbol, isi: nama state tujuan)>
```

