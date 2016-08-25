# Automaton

Simple deterministic finite automaton runner class for trying out whether a given sequence of actions is valid for that DFA.

## Usage

Run `make` to build.

Set up your DFA by creating a file with the format:

```
<number of actions>
<action names separated by whitespace>

<number of states>
<state names separated by whitespace>

<number of final/accepting states>
<final state names separated by whitespace>

<transition table (rows: from_state, columns: action, cell content: to_state)>
```

A sample DFA file (`dfa/sample.dfa`) is provided.

By nathanchrs