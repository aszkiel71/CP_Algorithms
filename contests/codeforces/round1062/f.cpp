#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#define int long long

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

vector<int> sz;

int dfs(int v, int p, vector<vector<int>>& adj, int n, int k){
    int res = 1;
    sz[v] = 1;
    for(int u : adj[v]){
        if(u == p) continue;
        res += dfs(u, v, adj, n, k);
        sz[v] += sz[u];
        if(n - sz[u] >= k){
            res += sz[u];
        }
    }
    if (sz[v] >= k) res += n - sz[v];
    return res;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n+1);
    sz.assign(n+1, 0);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int res = dfs(1, -1, adj, n, k);


    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
