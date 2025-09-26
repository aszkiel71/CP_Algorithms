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

vector<int> leaders;
vector<int> sz;

void make_set(int x) {
  leaders[x] = x;
  sz[x] = 1;
}

int find_set(int u) {
  if (u == leaders[u]) {
    return u;
  }
  return leaders[u] = find_set(leaders[u]);
}

void union_set(int u, int v) {
  u = find_set(u);
  v = find_set(v);
  if (u == v) return;
  if (sz[v] > sz[u]) {
    swap(u, v);
  }
  sz[u] += sz[v];
  leaders[v] = leaders[u];
}

void solve() {
  int q; cin >> q;

  map<string, string> nxt;
  map<string, string> mapka;

  for (int i = 0; i < q; ++i) {
    string old_h, new_h;
    cin >> old_h >> new_h;

    if (mapka.find(old_h) == mapka.end()) {
      nxt[old_h] = new_h;
      mapka[new_h] = old_h;
    } else {
      string original_user = mapka[old_h];
      nxt[original_user] = new_h;
      mapka[new_h] = original_user;
      mapka.erase(old_h);
    }
  }

  cout << nxt.size() << "\n";
  for (auto x : nxt) {
    cout << x.first << " " << x.second << "\n";
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
