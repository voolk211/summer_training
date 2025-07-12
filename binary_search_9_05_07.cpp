#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

bool check(const vector<int>& arr, int X, int Y) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int E = arr[i];
        int low = E - Y;
        int high = E + Y;

        auto left = lower_bound(arr.begin(), arr.end(), low);
        auto right = upper_bound(arr.begin(), arr.end(), high);

        int count = right - left;
        if (count >= X) return true;
    }
    return false;
}

int main() {
    int N, X, Y;
    int min_val = 0, max_val = 100; 
    cout << "Enter N (size), X and Y:\n ";
    cin >> N >> X >> Y;

    cout << "Enter the range of number[min max]:\n";
    cin >> min_val >> max_val;

    mt19937 rng(static_cast<unsigned int>(time(nullptr))); 
    uniform_int_distribution<int> dist(min_val, max_val);
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = dist(rng);
    }

    cout << "generated list:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    sort(arr.begin(), arr.end());

    if (check(arr, X, Y)) {
        cout << "bad generator\n"; 
    }
    else {
        cout << "good generator\n";
    }

    return 0;
}
