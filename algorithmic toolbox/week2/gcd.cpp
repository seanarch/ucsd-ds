#include <iostream>
using namespace std; 

int main(){
    int a,b;
    cin >> a >> b; 
    int d = 0; 

    if(a>b) {
        for(int i=0; i<a; i++) {
            if(a % i == 0 && b % i == 0) d = i; 
        } 
    } else {
        for(int i=0; i<b; i++) {
            if(a % i == 0 && b % i == 0) d = i; 
        } 
    }
    
    cout << d << endl;

    return 0;
}  


// euclidiean algorithm 

//   gcd(3918847, 1653264)
// = gcd(1653264, 612320)
// = gcd(612320, 428624)
// = gcd(428624, 183696)
// = gcd(183696, 61232)
// = gcd(61232, 0)