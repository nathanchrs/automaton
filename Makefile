.PHONY: all clean report

all:
	gcc src/main.c src/dfa.c -o automaton

report:
	pdflatex report/report.tex -output-directory report

clean:
	-rm automaton
	-rm automaton.exe
	-rm report/report.aux
	-rm report/report.log
	-rm report/report.pdf
