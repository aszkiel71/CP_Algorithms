#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <climits>

using namespace std;

// -----------------------

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) ((int)(x).size())
#define fi first
#define se second

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool goodtho(int idx, int n){
        if (idx < 0) return false;
        if (idx >= n) return false;
        return true;
    }
    // lets go test it local

    int solve(vector<int>& nums, int k) {

       int n = (int) nums.size();

        /*for (int i = 1; i < n; i++){
            ps[i] = (long long) ps[i-1] + (long long) nums[i];
        }*/

        int cnt = 1e6;

        long long sum = 0;
        for (int x : nums) {
            sum += (long long)x;
        }
        if (sum < k && (sum > 0)) {
            return -1;
        }

        int r = 0, l = 0;
        long long curr = 0;
        map<int, int> mp; mp.clear();

        while (r < n){
            if (mp[nums[r]] == 0) { // havent seen
                curr += (long long) nums[r];
            }
            mp[nums[r]]++;
            while (curr >= k) {
                cnt = min (cnt, r - l + 1);
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    curr -= nums[l];
                }
                l++;
            }
            r++;
        }

        return cnt;
    }
};


int main() {
    Solution sol;

    vector<int> t1 = {13,13,20,27,7,28,3}; int k1 = 44;     // 2
    vector<int> t2 = {13,13,20,27,7,28,3}; int k2 = 121111; // -1
    vector<int> t3 = {63,47,9,23,47,29,47,23,36,47,9}; int k3 = 121; // 4
    vector<int> t4 = {6, 6, 11}; int k4 = 12; // 2
    cout << "Wynik 1: " << sol.solve(t1, k1) << endl;
    cout << "Wynik 2: " << sol.solve(t2, k2) << endl;
    cout << "Wynik 3: " << sol.solve(t3, k3) << endl;
    cout << "Wynik 4: " << sol.solve(t4, k4) << endl;

    return 0;
}
