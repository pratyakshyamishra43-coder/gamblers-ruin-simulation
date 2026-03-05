#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

// Closed-form probability of ruin
double theoretical_ruin(int initial, int target, double p) {
    if (std::abs(p - 0.5) < 1e-12) {
        return 1.0 - static_cast<double>(initial) / target;
    }

    double q = 1.0 - p;
    double ratio = q / p;

    return (std::pow(ratio, initial) - std::pow(ratio, target)) /
           (1.0 - std::pow(ratio, target));
}

int main() {

    const int simulations = 50000;
    const int target_capital = 1000; 

    std::vector<int> capitals = {10, 50, 100, 500};
    std::vector<double> p_values = {0.49, 0.50, 0.51};

    std::mt19937 rng(42);
    std::uniform_real_distribution<> U(0.0, 1.0);

    std::cout << std::fixed << std::setprecision(4);

    // =========================
    // OPEN CSV FILE
    // =========================
    std::ofstream file("ruin_results.csv");
    file << std::fixed << std::setprecision(6);
    file << "capital,p,mc_ruin,theory,error,avg_steps\n";

    std::cout << "=================================================\n";
    std::cout << "        Gambler's Ruin : Capital Sensitivity\n";
    std::cout << "=================================================\n";

    std::cout << "Simulations : " << simulations << "\n";
    std::cout << "Target      : " << target_capital << "\n";

    for (int initial_capital : capitals) {

        std::cout << "\n-------------------------------------------------\n";
        std::cout << "Initial Capital : " << initial_capital << "\n";
        std::cout << "p\tMC_Ruin\t\tTheory\t\tError\t\tAvgSteps\n";
        std::cout << "-------------------------------------------------\n";

        for (double p : p_values) {

            int ruin_count = 0;
            long long total_steps = 0;

            for (int s = 0; s < simulations; ++s) {

                int capital = initial_capital;
                int steps = 0;

                while (capital > 0 && capital < target_capital) {
                    capital += (U(rng) < p) ? 1 : -1;
                    steps++;
                }

                if (capital == 0)
                    ruin_count++;

                total_steps += steps;
            }

            double mc_ruin = static_cast<double>(ruin_count) / simulations;
            double theory = theoretical_ruin(initial_capital, target_capital, p);
            double error = std::abs(mc_ruin - theory);
            double avg_steps = static_cast<double>(total_steps) / simulations;

            // Terminal output
            std::cout << p << "\t"
                      << mc_ruin << "\t\t"
                      << theory << "\t\t"
                      << error << "\t\t"
                      << avg_steps << "\n";

            // CSV output
            file << initial_capital << ","
                 << p << ","
                 << mc_ruin << ","
                 << theory << ","
                 << error << ","
                 << avg_steps << "\n";
        }
    }

    file.close();   // close CSV file

    std::cout << "\nCSV file 'ruin_results.csv' created successfully.\n";
    std::cout << "Done.\n";
}