#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  for (int i = 0; i < N; i++) cin >> w[i] >> v[i];
  vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= W; j++) {
      dp[i][j] = dp[i - 1][j];
      if (w[i - 1] <= j) {
        long long tmp = dp[i - 1][j - w[i - 1]] + v[i - 1];
        dp[i][j] = max(dp[i][j], tmp);
      }
    }
  }
  cout << dp[N][W];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
