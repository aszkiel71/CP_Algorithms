#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

vector<bool> visited;
vector<int> res;
vector<vector<int>> adj;
void dfs(int u){
    visited[u] = true;
    for(auto x : adj[u]){
        if(!visited[x])
            dfs(x);
    }
    res.pb(u);
}

void solve(){
    int n; cin >> n;
    adj.clear();
    adj.resize(n+1);
    for(int i = 0; i < n - 1; i++){
        int u, v, x, y; cin >> u >> v >> x >> y;
        if(x <= y){
            adj[u].pb(v);
        }
        else{
            adj[v].pb(u);
        }
    }

    res.clear(); visited.clear();
    vector<int> p(n + 1);
    visited.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) if(!visited[i]) dfs(i);
    for(int i = n - 1, j = 0; i >= 0; i--, j++){
        p[res[i]] = j + 1;
    }
    for(int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
