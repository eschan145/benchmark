#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <fstream>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void compute_primes(std::vector<int>& primes, int count) {
    int number = 2;
    while (primes.size() < count) {
        if (is_prime(number)) primes.push_back(number);
        number++;
    }
}

int main() {
    // Measure prime computation
    auto start_primes = std::chrono::high_resolution_clock::now();
    std::vector<int> primes;
    compute_primes(primes, 1000);
    auto end_primes = std::chrono::high_resolution_clock::now();
    auto prime_duration = std::chrono::duration<double, std::milli>(end_primes - start_primes).count();

    // Measure insertion performance
    auto start_insert = std::chrono::high_resolution_clock::now();
    std::vector<int> container;
    for (int i = 0; i < 10000; ++i) {
        container.push_back(i);
    }
    auto end_insert = std::chrono::high_resolution_clock::now();
    auto insert_duration = std::chrono::duration<double, std::milli>(end_insert - start_insert).count();

    // Append results to Markdown (without escaping markdown)
    std::ofstream md_file("results.md", std::ios_base::app);
    md_file << "| " << std::getenv("OPT_LEVEL") << " | "
            << prime_duration << " | "
            << insert_duration << " |\n";
    md_file.close();

    // Print results to console
    std::cout << "Optimization Level: " << std::getenv("OPT_LEVEL") << "\n";
    std::cout << "Prime computation time: " << prime_duration << " ms\n";
    std::cout << "Insertion time: " << insert_duration << " ms\n";

    return 0;
}
