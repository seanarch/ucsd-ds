#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    }

    int array[n]; 
    array[0] = 1; 
    array[1] = 1;

    for(int i = 2; i <= n; i ++) {
        array[i] = (array[i - 1] % 10 + array[i - 2] % 10) % 10; 
    }

    return array[n-1];
}

int main() {
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    // std::cout << c << '\n';
    int d = get_fibonacci_last_digit_fast(n);
    std::cout << d << '\n';
    }
