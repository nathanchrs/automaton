CC=gcc
LATEX=pdflatex

.PHONY: all clean report

all: automaton report	

automaton:
	$(CC) src/main.c src/dfa.c -o automaton

report:
	-$(LATEX) report/report.tex -output-directory report

clean:
	-rm automaton
	-rm automaton.exe
	-rm report/report.aux
	-rm report/report.log
	-rm report/report.pdf
