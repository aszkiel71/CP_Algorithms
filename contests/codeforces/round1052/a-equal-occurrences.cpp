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
  vector<int> mapka(101, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mapka[x]++;
  }

  int res = 0;
  for (int i = 1; i <= 100; i++) {
    int tmp = 0;
    for (int j = 1; j <= 100; j++) {
      if (mapka[j] >= i) {
        tmp += i;
      }
    }
    res = max(res, tmp);
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
