#include <iostream>
#include <vector>

using std::vector;

// double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
//   double value = 0.0;      
   
//   // write your code here
   
//   if(capacity == 0 || weights.size() == 0) {
//     return 0;
//   } else {
//     int maxindex; 
//     for(int i = 0; i <= weights.size(); i++) {
//       double maxvalue = 0;
//       if ( (double)values[i] / weights[i] > maxvalue) {
//         int maxindex = i;  
//       }
//     }
//     int amount = std::min(weights[maxindex], capacity); 
    
//     value += values[maxindex] * (amount / weights[maxindex]);
//     weights.erase(weights.begin() + maxindex - 1);

//   }

//   return value;
//   return 0;
// }

double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values) {
    double total_value = 0.0;

    // Check if the capacity is zero or there are no items to pick
    if (capacity == 0 || weights.empty() || values.empty()) {
        return 0.0;
    }

    int n = weights.size();
    std::vector<double> value_per_unit_weight(n);

    for (int i = 0; i < n; i++) {
        value_per_unit_weight[i] = static_cast<double>(values[i]) / weights[i];
    }

    while (capacity > 0) {
        int max_index = -1;
        double max_value_per_unit_weight = 0.0;

        // Find the item with the maximum value per unit weight ratio
        for (int i = 0; i < n; i++) {
            if (weights[i] > 0 && value_per_unit_weight[i] > max_value_per_unit_weight) {
                max_index = i;
                max_value_per_unit_weight = value_per_unit_weight[i];
            }
        }

        if (max_index == -1) {
            // No more items that can be added to the knapsack
            break;
        }

        int weight_to_take = std::min(weights[max_index], capacity);
        total_value += (static_cast<double>(weight_to_take) / weights[max_index]) * values[max_index];
        capacity -= weight_to_take;
        weights[max_index] -= weight_to_take;
    }

    return total_value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
