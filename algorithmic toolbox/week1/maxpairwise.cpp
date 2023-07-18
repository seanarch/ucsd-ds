#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


// long long MaxPairwiseProductFast(const vector<int>& numbers) {
//     long long max_product = 0;
//     int n = numbers.size();
//     int largest = 0; 
//     int secondlargest = 0; 
//     int largestindex, secondindex; 

//     for (int i = 0; i < n; i++) {
//         if ((numbers[i]) > largest ) largest = numbers[i]; largestindex = i;  
//     }

//     for (int i = 0; i < n; i++) { 
//         if (secondindex == largestindex) continue; 
//         if ((numbers[i]) > secondlargest && (numbers[i]) <= largest) secondlargest = numbers[i]; 
//     }

//     max_product = (long long)largest * secondlargest;
 
//     return max_product;
// }

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int largest = numbers[0];
    int secondlargest = numbers[1];
    int largestindex = 0;
    int secondindex = 1;

    for (int i = 1; i < n; i++) {
        if (numbers[i] > largest) {
            secondlargest = largest;
            secondindex = largestindex;
            largest = numbers[i];
            largestindex = i;
        } else if (numbers[i] > secondlargest) {
            secondlargest = numbers[i];
            secondindex = i;
        }
    }

    max_product = (long long)largest * secondlargest;

    return max_product;
}


// long long MaxPairwiseProduct(const vector<int>& numbers) {
//     long long max_product = 0;
//     int n = numbers.size();

//     for (int first = 0; first < n; ++first) {
//         for (int second = first + 1; second < n; ++second) {
//             max_product = max(max_product,
//                 (long long)(numbers[first]) * numbers[second]);
//         }
//     }

//     return max_product;
// }



int main() {
    // stress test
    // while(true) {
    //     int n = rand() % 10 + 2; 
    //     cout << n << "\n";
    //     vector<int> a; 

    //     for(int i = 0; i < n; i++) {
    //         a.push_back(rand() % 10);
    //     }

    //     for(int i = 0; i < n; i++) {
    //         cout << a[i] << ' ';
    //     }

    //     cout << "\n"; 

    //     long long res1 = MaxPairwiseProduct(a); 
    //     long long res2 = MaxPairwiseProductFast(a); 

    //     if(res1 !=res2) {
    //         cout << "Wrong answer: " << res1 << ' ' << res2 << "\n"; 
    //         break;
    //     } else {
    //         cout << "OK\n";
    //     }
    // }
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    cout << MaxPairwiseProductFast(numbers) << endl;
    return 0;
}
