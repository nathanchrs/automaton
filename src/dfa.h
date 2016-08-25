#ifndef DFA_HEADER
#define DFA_HEADER

#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

class DFA {

	map<string, int> actions;
	map<string, int> states;
	set<string> final_states;
	vector<vector<string> > deltas;

public:
	DFA();
	void load(string filename);
	void add_state(string name);
	void add_action(string name);
	void add_final_state(string name);
	void set_delta(string action, string from_state, string to_state);
	string transition(string initial_state, vector<string> actions);
	bool is_final_state(string state);
};

#endif
