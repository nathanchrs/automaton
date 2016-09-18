# Tugas I IF2220 Teori Bahasa Formal dan Automata

```
NIM       : 13515001
Nama      : Jonathan Christopher
Kelas     : K-01, TBFO IF2220
Tanggal   : 18 September 2016
Topik     : DFA
Deskripsi : Program sederhana untuk mengecek apakah suatu string diterima oleh DFA tertentu, serta contoh DFA berdasarkan Exercise 2.2.1 dari buku Introduction to Automata Theory, Languages, and Computation (3rd ed.)
```

## Cara menjalankan program

1. Pindah ke direktori utama program
2. Pindah ke direktori `bin`
3. Jalankan `./automaton` (`automaton` atau `automaton.exe` pada Windows)
4. Program akan berjalan. Masukkan nama file DFA yang ingin dijalankan (untuk tugas TBFO, file DFA yang digunakan adalah `../src/marble.dfa`). Jika nama file salah, maka akan diminta mengulangi input nama file
5. Masukkan string input untuk DFA
6. Hasil state-state yang dilalui serta apakah string input diterima akan ditampilkan di layar
7. Untuk keluar, jawab `n' ketika program bertanya apakah ingin mengulang

## Struktur direktori

* `bin` berisi file-file binary program
* `src` berisi source code program (*.c dan *.h) serta file DFA (*.dfa)
* `doc` berisi laporan (`report.pdf`)

## Cara build

Catatan: untuk pengumpulan tugas TBFO, file binary program untuk Windows 64-bit dan Linux 64-bit serta file PDF laporan sudah disertakan sehingga tidak usah dikompilasi ulang
Program yang dibutuhkan:
* GNU GCC untuk kompilasi program
* PDFLatex untuk pemrosesan laporan

### Build menggunakan GNU Make

1. Pindah ke direktori utama program
2. Jalankan `make` untuk build keseluruhan komponen program (gunakan perintah `make bin` untuk build binary saja, `make doc` untuk build report saja, atau `make clean` untuk membersihkan file-file hasil build)

### Build tanpa menggunakan GNU Make

1. Pindah ke direktori utama program
2. Jalankan `gcc src/main.c src/dfa.c -o bin/automaton` untuk kompilasi program
3. Jalankan `pdflatex doc/report.tex -output-directory doc` untuk pemrosesan file laporan

## Format File DFA

```
<string yang masing-masing karakternya melambangkan sebuah simbol (tidak boleh mengandung whitespace dalam string dan harus unik, maksimal 255 karakter)>

<jumlah state (0 <= n <= 1023)>
<nama-nama state dipisahkan whitespace (isi nama tidak boleh mengandung whitespace dan harus unik, maksimal 1023 karakter)>

<jumlah final state (0 <= n <= jumlah state)>
<nama-nama final state dipisahkan whitespace (harus unik dan harus ada di daftar state)>

<nama state awal (hanya 1, harus ada di daftar state)>

<representasi fungsi transisi dalam bentuk tabel (baris: nama state awal, kolom: simbol, isi: nama state tujuan)>
```

## Referensi
(Hopcroft, John E.; Motwani, Rajeev; Ullman, Jeffrey D. (2013). Introduction to Automata Theory, Languages, and Computation (3rd ed.). Pearson.)