#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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
  set<int> setka;
  bool zero = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!zero) {
      zero = a[i] == 0;
    }
    if (a[i] != -1) setka.insert(a[i]);
  }
  if (setka.size() <= 1 && !zero) {
    cout << "YES\n";
  } else
    cout << "NO\n";
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
