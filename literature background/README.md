# Quantum Finite Automata (QFA) Features

Here are the 8 features derived from the Measure-once Quantum Finite Automata (MO-QFA) description, each focusing on a specific aspect of the automaton:

## 1. QFA State Representation
Allow users to represent QFA states using N-state qubits, utilizing complex projective space and inner product to define the state space. This feature will enable users to define and manipulate quantum states in the automaton.

$$
|\psi\rangle \in \mathbb{C}P^N
$$

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
