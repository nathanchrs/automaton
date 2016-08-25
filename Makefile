all:
	g++ src/dfa.cpp src/main.cpp -o bin/automaton -g

clean:
	rm bin/automaton
