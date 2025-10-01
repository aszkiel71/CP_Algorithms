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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s(m, 'B');

  for (int i = 0; i < n; i++) {
    int l1 = a[i] - 1;
    int l2 = m - l1 - 1;

    if (s[l1] == 'A') {
      s[l2] = 'A';
    } else if (s[l2] == 'A') {
      s[l1] = 'A';
    } else {
      s[min(l1, l2)] = 'A';
    }
  }
  cout << s << "\n";
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
