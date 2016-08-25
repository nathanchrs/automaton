#include "dfa.h"
#include <string>
#include <iostream>
using namespace std;


DFA::DFA() {};

void DFA::add_state(string name) {
	if (states.count(name) == 0) {
		int sz = states.size();
		states[name] = sz;
		vector <string> new_delta_state;
		for (int i = 0; i < actions.size(); i++) new_delta_state.push_back("");
		deltas.push_back(new_delta_state);
	} else {
		throw "State '" + name + "'' already present";
	}
}

void DFA::add_action(string name) {
	if (actions.count(name) == 0) {
		int az = actions.size();
		actions[name] = az;
		for (int i = 0; i < states.size(); i++) deltas[i].push_back("");
	} else {
		throw "Action '" + name + "'' already present";
	}
}

void DFA::add_final_state(string name) {
	if (states.count(name) > 0) {
		if (final_states.count(name) == 0) {
			final_states.insert(name);
		} else {
			throw "Final state '" + name + "'' already present";
		}
	} else {
		throw "State '" + name + "' not defined yet";
	}
}

void DFA::set_delta(string action, string from_state, string to_state) {
	if (actions.count(action) == 0) throw "Action '" + action + "' not defined yet";
	if (states.count(from_state) == 0) throw "State '" + from_state + "' not defined yet";
	if (states.count(to_state) == 0) throw "State '" + to_state + "' not defined yet";	

	deltas[states[from_state]][actions[action]] = to_state;
}

string DFA::transition(string initial_state, vector<string> sequence) {
	string current_state = initial_state;
	for (int i = 0; i < sequence.size(); i++) {
		if (actions.count(sequence[i]) == 0) throw "Action '" + sequence[i] + "' not defined yet";
		current_state = deltas[states[current_state]][actions[sequence[i]]];
		if (states.count(current_state) == 0) throw "State '" + current_state + "' not defined yet";
	}
	return current_state;
}

bool DFA::is_final_state(string state) {
	return states.count(state) > 0;
}
