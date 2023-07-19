#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1) {
        return n;
    }

    long long previous = 0;
    long long current = 1;

    for (long long i = 2; i <= n; i++) {
        long long temp = previous;
        previous = current;
        current = (temp + current) % m;

        // Check for the Pisano period
        if (previous == 0 && current == 1) {
            long long pisano_period = i - 1;
            long long remainder = n % pisano_period;
            return get_fibonacci_huge_fast(remainder, m);
        }
    }

    return current;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
