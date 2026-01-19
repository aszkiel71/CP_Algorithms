#include <algorithm>
#include <cassert>
#include <iostream>
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
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> P(n+1);
  l--;
  r--;

  for (int i = 0; i <= n; i++) P[i] = i;
  P[r+1] = P[l];

  for (int i = 0; i < n; i++) {
    cout << (P[i+1] ^ P[i]) << " ";
  }
  cout << "\n";
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
