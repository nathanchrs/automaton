CC=gcc
LATEX=pdflatex

.PHONY: all clean bin doc

all: bin doc

bin:
	$(CC) src/main.c src/dfa.c -o bin/automaton

doc:
	-$(LATEX) doc/report.tex -output-directory doc

clean:
	-rm bin/automaton
	-rm bin/automaton.exe
	-rm doc/report.aux
	-rm doc/report.log
	-rm doc/report.pdf
