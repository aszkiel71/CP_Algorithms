#include <algorithm>
#include <iostream>
#include <map>
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
  map<int, int> mapka;
  vector<int> nxt;
  for (int i = 0; i < n; i++) {
    int x1, x2;
    cin >> x1 >> x2;
    mapka[x1] = x2;
    nxt.pb(x1);
  }
  int res = 0;
  for (int i = 0, time = 0, pos = 0; i < n; i++) {
    int nxt_time = nxt[i];
    int nxt_pos = mapka[nxt_time];
    int delta = nxt_time - time;
    if (delta % 2 == 0) {
      res += delta - 1;
      if (nxt_pos == pos) res++;
    } else {
      res += delta - 1;
      if (nxt_pos != pos) res++;
    }
    time = nxt_time;
    pos = nxt_pos;
  }
  int lst = nxt.back();
  res += (m - lst);

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
