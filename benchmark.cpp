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
