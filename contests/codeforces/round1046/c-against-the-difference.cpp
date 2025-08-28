#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define pb push_back

void solve() {
  int t;
  cin >> t;
  while (t--) {
    // map<int, vector<int>> mapka;
    int n;
    cin >> n;
    vector<vector<int>> mapka(n + 1);
    vector<int> dp(n, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
      int x = a[i];
      dp[i] = dp[max(i - 1, 0)];
      mapka[x].pb(i);
      int k = mapka[x].size();
      if (k >= x) {
        int start = mapka[x][k - x];
        int prev = 0;
        if (start > 0) prev = dp[start - 1];
        dp[i] = max(dp[i], prev + x);
      }
    }
    cout << dp[n - 1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
