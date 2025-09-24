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



void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), s(m), t(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> s[i] >> t[i];
  }

  vector<ll> l(n, 0LL), r(n, 0LL);

  for (int i = 0; i < n - 1; i++) {
    l[i + 1] = max(0LL, a[i] - a[i + 1]);
  }
  for (int i = 1; i < n; i++) {
    r[i] = max(0LL, a[i] - a[i - 1]);
  }
  for (int i = 0; i < n - 1; i++) {
    l[i + 1] += l[i];
    r[i + 1] += r[i];
  }
  // assert(m!=0);
  for (int i = 0; i < m; i++) {
    if (s[i] < t[i]) {
      cout << l[t[i] - 1] - l[s[i] - 1] << "\n";
    } else {
      cout << r[s[i] - 1] - r[t[i] - 1] << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
