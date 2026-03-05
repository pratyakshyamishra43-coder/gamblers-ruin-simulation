# Gambler's Ruin Simulation 🎲

A C++ simulation of the classical **Gambler's Ruin probability problem**.  
The program runs thousands of simulations to analyze the probability of ruin and the duration of games.

---

##  Problem

In the Gambler's Ruin problem:

- A gambler starts with an initial amount of money.
- Each round:
  - They win $1 with probability **p**
  - They lose $1 with probability **1 - p**
- The game ends when:
  - The gambler reaches **0 (ruin)**  
  - Or reaches the **target fortune**

This project simulates the experiment multiple times to observe statistical outcomes.

---

##  Implementation

The simulation is implemented in **C++**.

Steps:

1. Run thousands of simulated games.
2. Track:
   - Number of games ending in ruin
   - Number reaching the target
   - Game duration
3. Store results in a **CSV file**.
4. Use **Python / Google Colab** to generate graphs.

---

##  Results

The simulation produces the following graphs:

### Ruin vs Success

Shows how often the gambler loses everything vs reaches the target.

![Ruin Comparison](ruin_comparison.png)

### Game Duration Distribution

Shows how long games tend to last.

![Game Duration](ruin_duration.png)

---

gamblers-ruin
│
├── ruin.cpp
├── ruin_results.csv
├── README.md
│
├── graphs
│   ├── ruin_probability.png
│   ├── game_duration.png
│
└── screenshots
    ├── simulation_output.png

##  How to Run

Compile the program:

```
g++ ruin.cpp -o ruin
```

Run the simulation:

```
./ruin
```

This will generate the output CSV file.

---
## Results

### Ruin Probability vs Win Probability

![Ruin Probability](graphs/ruin_probability.png)

### Game Duration vs Probability

![Game Duration](graphs/game_duration.png)

### Simulation Output

![Terminal Output](screenshots/simulation_output.png)

##  Concepts Demonstrated

- Monte Carlo Simulation
- Probability Theory
- Gambler's Ruin Problem
- Data Visualization
- C++ File Handling

---

##  Future Improvements

- Interactive parameter input
- Larger-scale simulations
- Web visualization dashboard

---

## Author

Pratyakshya Mishra