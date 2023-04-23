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

In the context of the code example provided earlier, the `QuantumState` class represents a quantum state with N-state qubits (generalization of a qubit), and each entry in the `std::vector` of complex numbers corresponds to the amplitude of a basis state in the quantum system.
    #include <iostream>
    #include <vector>
    #include <complex>

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

## 2. QFA Transitions
Implement state transitions using N×N unitary matrices for each input symbol. This feature allows users to specify quantum state transitions corresponding to each input symbol.

$$
|\psi'\rangle = U_\alpha |\psi\rangle
$$

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

## 7. Right-action Alternative
Offer an alternative definition for QFAs using right-action on Hermitian transpose states to preserve the order of input symbols in the string.

## 8. Regular Language Acceptance
Implement a method to determine if a regular language is accepted with probability $p$ by a QFA, given that for all sentences $\sigma$ in the language and a fixed initial state $|\psi\rangle$, $p < \operatorname{Pr}(\sigma)$.

These 8 features break down the measure-once quantum finite automata into smaller, more manageable components, allowing users to explore and understand the intricacies of QFAs in a clear and concise manner.
