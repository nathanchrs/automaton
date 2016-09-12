all:
	gcc src/main.c src/dfa.c -o automaton

clean:
	rm automaton
