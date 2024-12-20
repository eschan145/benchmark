import time
import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def compute_primes(count):
    primes = []
    number = 2
    while len(primes) < count:
        if is_prime(number):
            primes.append(number)
        number += 1
    return primes

if __name__ == "__main__":
    # Measure prime computation
    start_primes = time.perf_counter()
    primes = compute_primes(1000)
    end_primes = time.perf_counter()
    prime_duration = (end_primes - start_primes) * 1000

    # Measure insertion performance
    start_insert = time.perf_counter()
    container = []
    for i in range(10000):
        container.append(i)
    end_insert = time.perf_counter()
    insert_duration = (end_insert - start_insert) * 1000

    # Write results to Markdown
    with open("results.md", "a") as md_file:
        md_file.write("\n## Python Results\n")
        md_file.write(f"- Prime computation time: {prime_duration:.2f} ms\n")
        md_file.write(f"- Insertion time: {insert_duration:.2f} ms\n")

    # Print results to console
    print(f"Prime computation time: {prime_duration:.2f} ms")
    print(f"Insertion time: {insert_duration:.2f} ms")
