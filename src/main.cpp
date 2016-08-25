#include <iostream>
#include "dfa.h"
using namespace std;

int main() {

	DFA machine;

	machine.add_action("0");
	machine.add_action("1");

	machine.add_state("q0");
	machine.add_state("q1");
	machine.add_final_state("q1");

	machine.set_delta("0", "q0", "q0");
	machine.set_delta("1", "q0", "q1");
	machine.set_delta("0", "q1", "q0");
	machine.set_delta("1", "q1", "q1");

	vector<string> actions;
	actions.push_back("1");
	actions.push_back("1");
	actions.push_back("0");
	actions.push_back("1");
	actions.push_back("2");

	string result_state = machine.transition("q0", actions);

	cout << result_state << endl;
	cout << machine.is_final_state(result_state) << endl;

	return 0;
}