# Quantum Finite Automata (QFA) Features Disambiguation

This is the same as the explanation on the main page but we're trying to delve a little deeper into the specific terminology to give a clearer overview.

## 1. QFA State Representation
Allow users to represent QFA states using N-state qubits, utilizing complex projective space and inner product to define the state space. This feature will enable users to define and manipulate quantum states in the automaton.

$$
|\psi\rangle \in \mathbb{C}P^N
$$

In a quantum system, a quantum state is a linear combination of basis states, and each basis state is associated with a complex number called the amplitude. These amplitudes contain information about the probability of the quantum system being in that particular basis state when measured. The square of the absolute value of the amplitude of a basis state represents the probability of finding the quantum system in that specific state when a measurement is performed.

For example, consider a qubit (2-state system) in the following state:

$$
|\psi\rangle = \alpha|0\rangle + \beta|1\rangle
$$

Here, $|0\rangle$ and $|1\rangle$ are the basis states, and $\alpha$ and $\beta$ are complex numbers representing the amplitudes associated with these basis states. The probabilities of measuring the qubit in states $|0\rangle$ and $|1\rangle$ are given by $|\alpha|^2$ and $|\beta|^2$, respectively. The sum of these probabilities is always equal to 1, as required by the normalization condition in quantum mechanics:

$$
|\alpha|^2 + |\beta|^2 = 1
$$

In the context of the code example provided, the `QuantumState` class represents a quantum state with N-state qubits (generalization of a qubit), and each entry in the `std::vector` of complex numbers corresponds to the amplitude of a basis state in the quantum system.

```cpp
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

int main() {
    int N = 3; // Number of states in the QFA
    QuantumState qfa_state(N);

    // Set amplitudes for the quantum state
    qfa_state.set_amplitude(0, std::complex<double>(0.5, 0.5));
    qfa_state.set_amplitude(1, std::complex<double>(0.5, -0.5));
    qfa_state.set_amplitude(2, std::complex<double>(0.0, 0.0));

    // Print the quantum state
    qfa_state.print();

    return 0;
}
```

## 2. QFA Transitions
Implement state transitions using N×N unitary matrices for each input symbol. This feature allows users to specify quantum state transitions corresponding to each input symbol.

$$
|\psi'\rangle = U_\alpha |\psi\rangle
$$
    
```cpp
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

int main() {
    int N = 3; // Number of states in the QFA

    // Define the quantum state
    QuantumState qfa_state(N);

    // Set amplitudes for the quantum state
    qfa_state.set_amplitude(0, std::complex<double>(0.5, 0.5));
    qfa_state.set_amplitude(1, std::complex<double>(0.5, -0.5));
    qfa_state.set_amplitude(2, std::complex<double>(0.0, 0.0));

    // Print the quantum state
    qfa_state.print();

    // Define the QuantumTransition with the number of states
    QuantumTransition qfa_transition(N);

    // Set transition matrices for each input symbol
    qfa_transition.set_transition_matrix('a', {{{1.0, 0.0, 0.0},
                                                {0.0, 0.5, 0.5},
                                                {0.0, 0.5, -0.5}}});

    qfa_transition.set_transition_matrix('b', {{{0.5, 0.5, 0.0},
                                                {0.5, -0.5, 0.0},
                                                {0.0, 0.0, 1.0}}});

    // Apply the transition based on an input symbol
    QuantumState final_state = qfa_transition.apply_transition('a', qfa_state);

    // Print the final quantum state after the transition
    final_state.print();

    return 0;
}
```

## 3. Quantum Semiautomaton
Provide the functionality to create a quantum semiautomaton with the triple $(\mathbb{C}P^N, \Sigma, \{U_\alpha\;|\;\alpha\in\Sigma\})$, enabling users to define a quantum automaton with state space, input alphabet, and transition matrices.

## 4. Acceptance Probability Calculation
Implement a method to calculate the acceptance probability of a QFA for a given input string using the projection matrix $P$ and the state vector $|\psi\rangle$:

$$
\operatorname{Pr}(\sigma) = \Vert P U_{\sigma_k} \cdots U_{\sigma_1} U_{\sigma_0}|\psi\rangle\Vert^2
$$

## 5. Probability Threshold for Acceptance
Define a probability threshold $p$ for acceptance, such that if $\operatorname{Pr}(\sigma) > p$, the input string is accepted by the QFA.

## 6. Initial State Probability
Allow users to calculate the probability of the initial state being an accepted state with:

$$
\operatorname{Pr}(\varnothing)= \Vert P |\psi\rangle\Vert^2
$$

### == Examples ==
    

#### This is an excerpt from https://en.wikipedia.org/wiki/Probability_amplitude , it nicely explains the meaning of probability amplitudes using the polarization of light as a real life example.

    
Take the simplest meaningful example of the discrete case: a quantum system that can be in [two possible states](https://en.wikipedia.org/wiki/Two-state_quantum_system): for example, the [light polarization](https://en.wikipedia.org/wiki/Light_polarization) of a [photon](https://en.wikipedia.org/wiki/Photon). When the polarization is measured, it could be the horizontal state $|H\rangle$ or the vertical state $|V\rangle$. Until its polarization is measured the photon can be in a [Quantum superposition](https://en.wikipedia.org/wiki/Quantum_superposition) of both these states, so its state $|\psi\rangle$ could be written as:

$$|\psi\rangle = \alpha |H\rangle + \beta|V\rangle$$

The probability amplitudes of $|\psi\rangle$ for the states $|H\rangle$ and $|V\rangle$ are $\alpha$ and $\beta$ respectively. When the photon's polarization is measured, the resulting state is either horizontal or vertical. But in a random experiment, the probability of being horizontally polarized is $|\alpha|^2$, and the probability of being vertically polarized is $|\beta|^2$.

Therefore, for example, a photon in a state $|\psi\rangle = \sqrt{\frac{1}{3}} |H\rangle - i \sqrt{\frac{2}{3}}|V\rangle$ would have a probability of $\frac{1}{3}$ to come out horizontally polarized, and a probability of $\frac{2}{3}$ to come out vertically polarized when an [statistical ensemble (mathematical physics)](https://en.wikipedia.org/wiki/Statistical_ensemble_(mathematical_physics)) of measurements are made. The order of such results, is, however, completely random.
