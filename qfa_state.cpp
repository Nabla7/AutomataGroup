//
// Created on 2023/04/23.
//

#include <iostream>
#include <vector>
#include <complex>
#include <unordered_map>

class QuantumState {
public:
    QuantumState(int n) : state_vector(n) {}

    void set_amplitude(int index, const std::complex<double>& amplitude) {
        state_vector[index] = amplitude;
    }

    std::complex<double> get_amplitude(int index) const {
        return state_vector[index];
    }

    void print() const {
        for (const auto& amplitude : state_vector) {
            std::cout << amplitude << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<std::complex<double>> state_vector;
};


class QuantumTransition {
public:
    QuantumTransition(int n) : n_states(n) {}

    void set_transition_matrix(char symbol, const std::vector<std::vector<std::complex<double>>>& matrix) {
        transition_matrices[symbol] = matrix;
    }

    QuantumState apply_transition(char symbol, const QuantumState& initial_state) {
        QuantumState final_state(n_states);

        for (int i = 0; i < n_states; ++i) {
            std::complex<double> new_amplitude(0, 0);

            for (int j = 0; j < n_states; ++j) {
                new_amplitude += transition_matrices[symbol][i][j] * initial_state.get_amplitude(j);
            }

            final_state.set_amplitude(i, new_amplitude);
        }

        return final_state;
    }

private:
    int n_states;
    std::unordered_map<char, std::vector<std::vector<std::complex<double>>>> transition_matrices;
};

class QuantumSemiautomaton {
public:
    QuantumSemiautomaton(int n, const std::vector<char>& input_alphabet)
            : n_states(n), alphabet(input_alphabet), qfa_state(n), qfa_transition(n) {}

    void set_initial_amplitude(int index, const std::complex<double>& amplitude) {
        qfa_state.set_amplitude(index, amplitude);
    }

    void set_transition_matrix(char symbol, const std::vector<std::vector<std::complex<double>>>& matrix) {
        qfa_transition.set_transition_matrix(symbol, matrix);
    }

    QuantumState apply_transition(const std::string& input) {
        QuantumState current_state = qfa_state;
        for (char symbol : input) {
            current_state = qfa_transition.apply_transition(symbol, current_state);
        }
        return current_state;
    }

private:
    int n_states;
    std::vector<char> alphabet;
    QuantumState qfa_state;
    QuantumTransition qfa_transition;
};

int main() {
    int N = 3; // Number of states in the QFA
    std::vector<char> input_alphabet = {'a', 'b'};

    // Define the quantum semiautomaton
    QuantumSemiautomaton qfa(N, input_alphabet);

    // Set initial amplitudes for the quantum state
    qfa.set_initial_amplitude(0, std::complex<double>(0.5, 0.5));
    qfa.set_initial_amplitude(1, std::complex<double>(0.5, -0.5));
    qfa.set_initial_amplitude(2, std::complex<double>(0.0, 0.0));

    // Set transition matrices for each input symbol
    qfa.set_transition_matrix('a', {{{1.0, 0.0, 0.0},
                                                     {0.0, 0.5, 0.5},
                                                     {0.0, 0.5, -0.5}}});

    qfa.set_transition_matrix('b', {{{0.5, 0.5, 0.0},
                                                     {0.5, -0.5, 0.0},
                                                     {0.0, 0.0, 1.0}}});

    // Apply the transition based on an input string
    std::string input_string = "ab";
    QuantumState final_state = qfa.apply_transition(input_string);

    // Print the final quantum state after the transition
    final_state.print();

    return 0;
}






