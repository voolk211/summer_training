#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& a) {
        int i = 0, n = a.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> full;
        set<int> dry;
        for (i = 0; i < n; i++) {
            if (a[i] == 0) {
                dry.insert(i);
                continue;
            }
            if (full.find(a[i]) != full.end()) {
                auto it = dry.lower_bound(full[a[i]]); 
               
                if (it == dry.end()) 
                    return {};
                ans[*it] = a[i];
                dry.erase(it);
            }
            full[a[i]] = i;
        }

        for (auto e : dry) {
            ans[e] = 1; 
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<int> test1 = { 1, 2, 3, 4 };
    vector<int> result1 = sol.avoidFlood(test1);
    cout << "Test 1 result: ";
    for (int num : result1) cout << num << " ";
    cout << endl;
    cout << "Expected result: -1 -1 -1 -1\n\n";

    // Test 2
    vector<int> test2 = { 1, 2, 0, 0, 2, 1 };
    vector<int> result2 = sol.avoidFlood(test2);
    cout << "Test 2 result: ";
    for (int num : result2) cout << num << " ";
    cout << endl;
    cout << "Expected result: -1 -1 2 1 -1 -1\n\n";

    // Test 3
    vector<int> test3 = { 1, 2, 0, 1, 2 };
    vector<int> result3 = sol.avoidFlood(test3);
    cout << "Test 3 result: ";
    if (result3.empty()) {
        cout << "[]";
    }
    else {
        for (int num : result3) cout << num << " ";
    }
    cout << endl;
    cout << "Expected result: []\n\n";

    return 0;
}
