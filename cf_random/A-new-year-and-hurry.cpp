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

int suma(int x) {
  ll sum = 5 * x * (x + 1) / 2;
  return sum;
}

void solve() {
  int n, k;
  cin >> n >> k;
  int l = 0, r = n;
  int time = 240 - k;
  int res = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (suma(mid) <= time) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << min(res, n) << "\n";
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
