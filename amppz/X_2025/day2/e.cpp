#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define int long long
typedef long long ll;

int ebs(int n, int k, int MOD) {
  if (k == 0) return 1LL;
  if (k % 2 == 0) {
    int tmp = ebs(n, k / 2, MOD) % MOD;
    return tmp * tmp;
  } else {
    return (n % MOD) * ebs(n, k - 1, MOD) % MOD;
  }
}

int get_ps(int x, int mod) {
  int tmp = ebs(2, x / 2, mod);
  if (x % 2) {
    int res = 3 * tmp - 2;
    return res % mod;
  }
  return (2 * tmp - 2) % mod;
}

void solve() {
  int l, r, M;
  cin >> l >> r >> M;
  cout << (get_ps(r, M) - get_ps(l-1, M) + M) % M  << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) solve();
}
