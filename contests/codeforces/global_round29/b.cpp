#include <algorithm>
#include <iostream>
#include <queue>
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
  vector<int> res(2 * n + 42, 0);
  for (int i = n, j = 1; i >= 1; j++, i--) {
    res[j] = i;
  }
  res[n + 1] = n;
  for (int i = n - 1, j = 2; i >= 1; j++, i--) {
    res[2 * i + j] = i;
  }

  for (int i = 1; i <= 2 * n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
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
