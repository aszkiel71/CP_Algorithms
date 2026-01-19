#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
  vector<string> g;
    int n;
    int m;
    bool goodtho(int x, int y) {
        if (0 > x) return false;
        if (0 > y) return false;
        if (x >= m) return false;
        if (y >= n) return false;
        if (g[x][y] == '#') return false;
        return true;
    }
    int backtrack(int x, int y, int d, int lvl = 0){
        int res = 0;
        if (lvl == n-1) {
            return 1;
        }
        for (int dx = 0; dx * dx <= d; dx++) {
            for (int dy = 0; dy * dy <= d; dy++) {
                if ((dx * dx + dy * dy) <= d) {
                    if (goodtho(dx, dy)){
                        res += backtrack(dx, dy, d, lvl + dy - y);
                    }
                }
            }
        }
        return res;
    }

    int numberOfRoutes(vector<string>& grid, int d) {
        const int M = 1e9 + 7;
        n = (int)grid.size() - 1; m = (int) grid[0].size();
        g = grid;
        int ress = 0;
        for (int x = 0 ; x < m; x++) {
            ress += backtrack(x, 0, d);
        }
        return ress;
    }
};

template <typename T>
void printVec(const vector<T>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << (i == v.size() - 1 ? "" : ", ");
  cout << "]\n";
}

int main() {
  Solution sol;


  cout << "Wynik 1: " << sol.numberOfRoutes({"..", "#."}, 2) << endl;     // 4
  cout << "Wynik 2: " << sol.numberOfRoutes({"#"}, 750) << endl;  // 0
  cout << "Wynik 3: " << sol.numberOfRoutes({".."}, 1) << endl;  // 4
  return 0;
}
