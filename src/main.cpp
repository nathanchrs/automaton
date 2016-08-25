#include <iostream>
#include "dfa.h"
using namespace std;

int main() {

	string filename, inp, start_state;
	int n_actions;
	vector<string> actions;
	DFA machine;

	cout << "Input .dfa filename: ";
	cin >> filename;
	machine.load(filename);

	cout << "Input number of actions: ";
	cin >> n_actions;
	for (int i = 0; i < n_actions; i++) {
		cin >> inp;
		actions.push_back(inp);
	}

	cout << "Input start state: ";
	cin >> start_state;

	string result_state = machine.transition(start_state, actions);

	cout << "The result state: " << result_state << endl;
	cout << "Is final state? " << (machine.is_final_state(result_state) ? "Yes" : "No") << endl;

	return 0;
}