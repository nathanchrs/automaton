all:
	gcc src/main.c src/dfa.c -o automaton -Wall -O2 -g

clean:
	rm automaton