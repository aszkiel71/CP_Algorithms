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
  ll n, c;
  cin >> n >> c;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  reverse(all(a));
  int res = 0;
  long long pow = 0;
  for (int i = 0; i < n; i++, pow *= 2) {
    if (a[i] * (1 << res) <= c) {
      res++;
    }
  }
  cout << n - res << "\n";
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
