#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<int>> dp;
  dp.clear();
  dp.assign(n, {0, 0, 0});
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
  for (int i = 1; i < n; i++) {
    dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = c[i] + max(dp[i - 1][1], dp[i - 1][0]);
  }
  cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
