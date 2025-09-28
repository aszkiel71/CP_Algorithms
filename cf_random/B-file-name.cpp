#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> streaks;
  int l = 0;
  while (l < n) {
    while (s[l] != 'x') {
      l++;
      if (l == n) {
        break;
      }
    }
    int streak = 0;
    while (s[l] == 'x') {
      l++;
      streak++;
      if (l == n) {
        break;
      }
    }
    if (streak > 2) {
      streaks.pb(streak);
    }
  }
  int res = 0;
  for (int x : streaks) {
    if (x <= 3) {
      res += 1;
    } else {
      res += x - 2;
    }
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
