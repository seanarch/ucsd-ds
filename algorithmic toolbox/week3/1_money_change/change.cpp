#include <iostream>
using namespace std;
 


int get_change(int n) {
  //write your code here
  int numbersOfCoin = 0; 
  while(n > 0) {
    if (n >= 10) {
      n = n - 10; 
      numbersOfCoin++;
    } else if ( n >= 5) {
      n = n - 5; 
      numbersOfCoin++; 
    } else {
      numbersOfCoin+=n;
      break;
    }
  }

  return numbersOfCoin;
  return 0;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';

  return 0;
}
