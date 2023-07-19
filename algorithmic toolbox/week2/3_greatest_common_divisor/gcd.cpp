#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  int remainder = 0; 
  while(a != 0 && b != 0) {

    if( a > b) {
      remainder = a % b; 
      a = remainder;  
    } else {
      remainder = b % a;
      b = remainder; 
    }
  }

  return a == 0 ? b : a; 
  return 0;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << "naive" << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
