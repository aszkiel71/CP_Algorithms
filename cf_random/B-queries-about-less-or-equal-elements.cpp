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

int skibidi_fun_sigma(int x, vector<int>& xoxo) {
  int l = 0;
  int r = xoxo.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (xoxo[mid] > x) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    cout << skibidi_fun_sigma(x, a) << " ";
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
