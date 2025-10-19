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
  int a, b;
  cin >> a >> b;

  if (a == b) {
    cout << 0 << "\n";
    return;
  }
  ll S = 1;
  while(S <= a) S*=2;
  if (b >= S) {
    cout << -1 << "\n";
    return;
  }
  cout << 2 << "\n";
  int x, y;
  x = a ^ (a | b);
  y = (a | b) ^ b;
  cout << x << " " << y << "\n";
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
