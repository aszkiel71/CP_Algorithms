#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    int n, m; cin >> n >> m;
    int imax = -1, imin = 1000, jmax = -1, jmin = 1000;
    vector<vector<char>> adj(n, vector<char>(m));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin >> adj[i][j];
            if(adj[i][j] == '*'){
                imin = min(imin, i);
                imax = max(imax, i);
                jmin = min(jmin, j);
                jmax = max(jmax, j);
            }
        }
    }
    for(int i = imin; i <= imax; i++){
        for(int j = jmin; j <= jmax; j++){
            cout << adj[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
