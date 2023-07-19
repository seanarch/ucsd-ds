#include <iostream>
using namespace std;
 

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
   int remainder = 0; 
   int tempA = a; 
   int tempB = b;

   while(tempA != 0 && tempB != 0) {
    if(tempA>tempB) {
      remainder = tempA % tempB;
      tempA = remainder; 
    } else {
      remainder = tempB % tempA; 
      tempB = remainder; 
    }
   }
   
   int gcd = (tempA == 0 ? tempB : tempA);

   return static_cast<long long>(a) * b / gcd;
 
}

int main() {
  int a, b;
  cin >> a >> b;
  // cout << lcm_naive(a, b) << endl;
  cout << lcm_fast(a, b) << endl;
  return 0;
}
