#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define int long long

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

void solve() {
  leaders.clear();
  sz.clear();
  int n; cin >> n;
  string s; cin >> s;
  leaders.resize(2*n);
  sz.assign(2*n, 0);
  for (int i = 0; i < 2*n; i++) {
    make_set(i);
  }

  int open = 0, closed = 0;
  stack<int> stk;

  for (int i = 0; i < 2*n; i++){
    if(s[i] == '('){
        stk.push(i);
    }
    else{
        int u = stk.top(); stk.pop();
        union_set(u, i);
        if(!u) continue;
        if(s[u-1] == ')'){
            union_set(u, u-1);
        }
    }
  }
  int cnt = 0;
  for(int i = 0; i < 2*n; i++){
    cnt += (leaders[i] == i);
  }
  cout << cnt << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
