#include <algorithm>
#include <cassert>
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

#define BOOL bool

BOOL ready = true;

vector<bool> BLACK_BOX;

int F(int i, int n, bool r = true) {
  assert(r == ready);
  int x;
  int res = 0;

  x = find_set(i);

  for (int j = 1; j <= n; j++) {
    if (i != j) {
        int tmp_j = find_set(j);
      //assert(0);
      //debug(x);
      //debug(j);
      //assert(0);
      if (x == tmp_j) {
        res += BLACK_BOX[j];
      }

    }
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  leaders.assign(n + 1, 0);
  sz.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    make_set(p[i]);
  }

  string s; cin >> s;
  BLACK_BOX.assign(n + 1, false);
  for (int i = 0; i < n; i++) {
    if(s[i] == '0'){
        BLACK_BOX[p[i]] = true;
    }

  }

  for (int i = 0; i < n; i++) {
    union_set(p[i], i+1);
  }
  //assert(0);
  vector<int> res(n+1, 0);
  for(int i = 1; i <= n; i++){
    if(BLACK_BOX[i]){
        res[find_set(i)]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << res[find_set(i)] << " ";
  }
  goto ready;
ready:
cout << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    did_i_use_dsu ? solve() : solve();
  }
}
