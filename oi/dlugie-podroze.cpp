#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

#define pb push_back
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> distances;
int n;
void bfs(int node) {
  distances[node].assign(n + 1, -1337);
  deque<int> q;
  distances[node][node] = 0;
  q.push_back(node);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    for (int v : adj[u]) {
      if (distances[node][v] == -1337) {
        distances[node][v] = distances[node][u] + 1;
        q.push_back(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, p;
  cin >> n >> m >> p;

  adj.resize(n + 1);
  distances.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  srand(time(0));
  int ran = 213;
  vector<int> r;
  vector<bool> arr(n + 1, 0);

  for (int i = 0; i < ran; i++) {
    int rn = (rand() % n) + 1;
    arr[rn] = true;
    r.push_back(rn);
  }

  for (int nd : r) bfs(nd);

  while (p--) {
    int k1, k2;
    cin >> k1 >> k2;
    int exmp = r[0];
    int res = distances[exmp][k1] + distances[exmp][k2];
    for (int nds : r) {
      res = min(res, distances[nds][k1] + distances[nds][k2]);
    }
    cout << res << "\n";
  }
}
