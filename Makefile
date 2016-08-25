all:
	g++ src/dfa.cpp src/main.cpp -o automaton -g

clean:
	rm automaton
