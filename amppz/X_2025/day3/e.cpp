#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define int long long

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

// void extend(vector<int>& vector1, vector<int>& vector2) {
//   vector1.insert(vector1.end(), vector2.begin(), vector2.end());
// }

// void merge(int id1, int id2, vector<vector<int>>& adj, map<int, int>& mapka)
// {
//   const int type_id2 = mapka[id2];
//   if (type_id2 == -6) {
//     extend(adj[id1], adj[id2]);
//   } else if (type_id2 < 0) {
//     adj[id1].push_back(id2);
//   }
// }
map<int, int> mapka;
vector<bool> visited(N, 0);
int dfs(int v, int parent, vector<vector<int>>& g, vector<vector<int>>& adj) {
  vector<int> val;
  val.clear();
  visited[v] = true;
  for (auto k : adj[v]) {
    if (v == parent) continue;
    if (!visited[k]) val.pb(dfs(k, v, g, adj));
  }
  if (mapka[v] == -3) {
    int res = 0;
    for (int x : val) res += x;
    return res;
  } else if (mapka[v] == -1) {
    int res = 1;
    for (int x : val) res *= x;
    return res;
  } else if (mapka[v] == -2) {
    int mx = -1000, mn = N;  // N ?
    for (int x : val) mx = max(x, mx);
    for (int x : val) mn = min(x, mn);
    return mx / mn;
  } else if (mapka[v] == -4) {
    int mx = -1000, mn = N;  // N ?
    for (int x : val) mx = max(x, mx);
    for (int x : val) mn = min(x, mn);
    return mx - mn;
  } else if (mapka[v] == -6) {
    return val[0];
  } else if (mapka[v] == -5) {
    return val[0];
  } else {
    return mapka[v];
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int cnt = 0;
  vector<vector<int>> grid_ids(n, vector<int>(m, -42));
  int xxx;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char curr = grid[i][j];
      if (curr != '.') {
        if (curr == '*') {
          mapka[cnt] = -1;
          grid_ids[i][j] = cnt;
          cnt++;
        } else if (curr == '/') {
          mapka[cnt] = -2;
          grid_ids[i][j] = cnt;
          cnt++;
        } else if (curr == '+') {
          mapka[cnt] = -3;
          grid_ids[i][j] = cnt;
          cnt++;
        } else if (curr == '-') {
          mapka[cnt] = -4;
          grid_ids[i][j] = cnt;
          cnt++;
        } else if (curr == 'P') {
          mapka[cnt] = -5;
          grid_ids[i][j] = cnt;
          xxx = cnt;
          cnt++;
        } else if (curr == '#') {
          mapka[cnt] = -6;
          grid_ids[i][j] = cnt;
          cnt++;
        } else {
          mapka[cnt] = (int)curr - 48;
          grid_ids[i][j] = cnt;
          cnt++;
        }
      } else {
        mapka[-69] = -69;
        grid_ids[i][j] = -69;
      }
    }
  }

  vector<vector<int>> adj(n * m + 5);
  const vector<pii> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      const int id = grid_ids[i][j];
      if (id == -69) continue;

      for (auto& [di, dj] : directions) {
        const int i2 = i + di, j2 = j + dj;
        if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= m) continue;
        const int id2 = grid_ids[i2][j2];
        if (id2 == -69) continue;
        adj[id].push_back(id2);
        // adj[id2].push_back(id);
        // merge(id, id2, adj, mapka);
      }
    }
  }

  // debug printy
  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j];
    }
    cout << "\n";
  }
  cout << "\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid_ids[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << mapka[grid_ids[i][j]] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  for (int i = 0; i < adj.size(); i++) {
    if (!adj[i].empty()) {
      cout << i << ": ";
      for (auto x : adj[i]) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
  */
  visited[xxx] = true;
  cout << dfs(xxx, -1337, grid_ids, adj) << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
