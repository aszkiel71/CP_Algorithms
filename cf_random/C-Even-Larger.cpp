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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) a.pb(0);
  vector<int> b(n + 1, 0);
  for (int i = 1; i < n; i += 2) {
    b[i] = a[i];
  }
  ll res = 0;
  for (int i = 0; i < n; i += 2) {
    int tmp_min = a[i];
    if (i >= 2) {
      tmp_min = min(tmp_min, a[i - 1] - b[i - 2]);
    }
    if (i + 1 < n) {
      tmp_min = min(tmp_min, a[i + 1]);
    }
    b[i] = tmp_min;
    res += (a[i] - b[i]);
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
