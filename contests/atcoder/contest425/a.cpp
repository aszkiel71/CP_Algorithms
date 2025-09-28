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

ll suma(int N) {
  ll res = 0;
  int sgn = -1;
  for (int i = 1; i <= N; i++) {
    res += (sgn)*i * i * i;
    sgn *= -1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  cout << suma(n) << "\n";
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
