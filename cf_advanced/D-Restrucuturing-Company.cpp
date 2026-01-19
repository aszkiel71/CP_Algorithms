#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>
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
//vector<int> nxt;
vector<int> sz;

bool did_i_use_dsu = true;

/*int find_nxt(int u) {
  if (u == nxt[u]) {
    return u;
  }
  return nxt[u] = find_nxt(nxt[u]);
}*/

void make_set(int x) {
  leaders[x] = x;
  sz[x] = 1;
  //nxt[x] = x;
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
  //nxt[u] = max(nxt[u], nxt[v]);

}

/*void union_nxt(int u, int v){
    u = find_nxt(u);
    v = find_nxt(v);
    if(u != v){
        nxt[u] = nxt[v];
    }
}*/

void solve(){
    int n, Q; cin >> n >> Q;
    set<int> stk;
    leaders.clear();
    sz.clear();
    //nxt.clear();
    leaders.resize(1+n);
    sz.assign(1+n, 0);
    //nxt.assign(2+n, 0);
    for (int i = 1; i <= n; i++) {
        make_set(i);
        stk.insert(i);
    }
    //nxt[n+1] = n+1;

    while(Q--){
        int q, x, y; cin >> q >> x >> y;
        if(q == 1){
            union_set(x, y);
        }
        else if(q == 2){
            /*// hardest part
            //x = find_nxt(x);
            for (int i = find_nxt(x); i <= y; i = find_nxt(i+1)){
                union_set(x, i);
                //int xd = find_nxt(i+1);
                //nxt[i] = xd;
                //i = xd;
                //union_nxt(i, i+1);
            }*/
            auto it = stk.upper_bound(x);
            while(it != stk.end() && *it <= y){
                union_set(x, *it);
                it = stk.erase(it);
            }
        }
        else{
            x = find_set(x);
            y = find_set(y);
            if(x == y){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
