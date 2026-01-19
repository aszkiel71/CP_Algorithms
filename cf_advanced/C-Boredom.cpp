#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define int long long

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(1e5 + 5, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  sort(all(a));
  vector<int> dp(1e5 + 1, 0);
  dp[1] = cnt[1];

  for (int i = 2; i <= 1e5; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
  }
  cout << dp[1e5];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
