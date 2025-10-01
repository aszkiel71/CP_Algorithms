#include <algorithm>
#include <cmath>
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

bool validator(ll n, ll s, ll x) {
  return ((ll)(x * ((n/2) + 1 )) <= (ll)s);
}

void solve() {
  ll n, s;
  cin >> n >> s;
  ll l = 0, r = s;
  ll res = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (validator(n, s, mid)) {
      l = mid + 1;
      res = max(res, mid);
    } else {
      r = mid - 1;
    }
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
