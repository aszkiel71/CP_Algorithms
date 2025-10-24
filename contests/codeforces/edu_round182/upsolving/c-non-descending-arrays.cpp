#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int M = 998244353;
vector<int> a, b;

void wczytaj1(int n) {
  a.clear();
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
void wczytaj2(int n) {
  b.clear();
  b.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
}


void solve(int n) {
  wczytaj1(n);
  wczytaj2(n);
  long long res = 0;
  vector<int> c(n), d(n);
  for (int i = 0; i < n; i++) {
    c[i] = min(a[i], b[i]);
    d[i] = max(a[i], b[i]);
  }
  vector<vector<long long>> dp(n, vector<long long>(2, 0));
  dp[0][0] = 1;
  dp[0][1] = c[0] < d[0];

  for (int i = 1; i < n; i++) {
    dp[i][0] = (dp[i][0] + dp[i - 1][0]) % M;
    if (c[i] >= d[i - 1] && d[i] >= c[i - 1]) {
      dp[i][0] = (dp[i][0] + dp[i - 1][1]) % M;
    }

    if (c[i] < d[i]) {
      if (d[i] >= c[i - 1] && c[i] >= d[i - 1]) {
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % M;
      }
      dp[i][1] = (dp[i][1] + dp[i - 1][1]) % M;
    }

  }
  res = (dp[n - 1][0] + dp[n - 1][1]) % M;
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
}
