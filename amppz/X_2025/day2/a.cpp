#include <algorithm>
#include <cassert>
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
#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int result = 0;
  vector<int> dp(n + 1, 0);
  vector<int> dp_prev(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[j] = dp_prev[j - 1] + (a[i - 1] != b[j - 1]);
      result = max(result, dp[j]);
    }
    swap(dp, dp_prev);
  }
  cout << result << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
