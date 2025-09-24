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
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if(a.back() != b.back()){
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    bool c1, c2 = 0, c3 = 0;
    c1 = (a[i] == b[i]);
    if (i < n - 1) {
      c2 = (a[i] ^ a[i + 1]) == b[i];
      c3 = (a[i] ^ b[i + 1]) == b[i];
    }
    int x = c1 + c2 + c3;
   //debug(x);
    if (x == 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
