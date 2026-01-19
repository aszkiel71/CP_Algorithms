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


    int solve(vector<int>& nums) {

        return 0;
    }
};

template<typename T>
void printVec(const vector<T>& v) {
    cout << "[";
    for(int i=0; i<v.size(); ++i) cout << v[i] << (i==v.size()-1 ? "" : ", ");
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<int> t1 = {1, 2, 3, 4};
    cout << "Wynik 1: " << sol.solve(t1) << endl;

    return 0;
}
