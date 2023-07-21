#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int totalStops = 0;
    int currentRefill = 0;
    int lastRefill;

    // Add the initial position (0) and the destination as stops
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);

    int n = stops.size();

    while (currentRefill < n - 1) {
        lastRefill = currentRefill;

        // Find the farthest reachable stop from the current refill
        while (currentRefill < n - 1 && stops[currentRefill + 1] - stops[lastRefill] <= tank)
            currentRefill++;

        // If the last refill is the same as the current one, it means we cannot reach the destination
        if (currentRefill == lastRefill)
            return -1;

        // If we can reach the next refill station from the current one, increment the total stops count
        if (currentRefill < n - 1)
            totalStops++;
    }

    return totalStops;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
