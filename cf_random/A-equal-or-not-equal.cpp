#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

vector<int> leaders;
vector<int> sz;

bool did_i_use_dsu = true;

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
  leaders.clear();
  sz.clear();
  string s;
  cin >> s;
  int n = s.size();
  leaders.resize(n);
  sz.assign(n, 0);
  for (int i = 0; i < n; i++) {
    make_set(i);
  }
  int it = 0;
  for (char c : s) {
    if (c == 'E') {
      union_set(it, (it + 1) % n);
    }
    it++;
  }
  it = 0;
  for (char c : s) {
    /*debug(c);
    debug(it);
    debug(find_set(it));
    debug(find_set(it+1));*/
    if (c == 'N') {
      if (find_set(it) == find_set((it + 1) % n)) {
        NO;
        return;
      }
    }
    it++;
  }
  YES;
}
void nothing(){

}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    did_i_use_dsu ? solve() : nothing();
  }
}
