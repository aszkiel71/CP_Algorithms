#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// misinterpreted :c
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void yes(){
    cout << "YES\n";
}

void no(){
    cout << "NO\n";
}

/*vector<int> leaders;
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
}*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    /*leaders.clear();
    sz.clear();
    leaders.resize(n);
    sz.assign(n, 0);
    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    for(int i = 0; i < n; i++){
        char c1 = s[i];
        char c2 = s[(i+1)%n];
        if(c1 == c2){
            union_set(i, (i+1)%n);
        }
    }

    vector<int> la, lb;
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c == 'b'){
            lb.pb(find_set(i));
        }
        else{
            la.pb(find_set(i));
        }
    }*/

    int first_b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'b'){
            first_b = i;
            break;
        }
    }
    int last_b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'b'){
            last_b = i;
        }
    }
    int first_a, last_a;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            first_a = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            last_a = i;
        }
    }

    ll tmp1 = 0, tmp2 = 0;
    // FIXING B
    // <- LEWO

    ll res1 = inf;
    for(int i = 0; i < first_b; i++){
        tmp1 += s[i] == 'a';
    }
    for(int i = last_b; i < n; i++){
        tmp1 += s[i] == 'a';
    }

    // FIXING B
    // -> PRAWO
    for(int i = first_b; i < last_b; i++){
        tmp2 += s[i] == 'a';
    }

    res1 = min(tmp1, tmp2);

    // FIXING A
    // <- LEWO
    ll res2 = inf;
    tmp1 = 0; tmp2 = 0;
    for(int i = 0; i < first_a; i++){
        tmp1 += s[i] == 'b';
    }
    for(int i = last_a; i < n; i++){
        tmp1 += s[i] == 'b';
    }

    // FIXING A
    // -> PRAWO

    for(int i = first_a; i < last_a; i++){
        tmp2 += s[i] == 'b';
    }
    res2 = min(tmp1, tmp2);

    if(last_a == first_a){
        res2 = inf;
    }
    if(last_b == first_b){
        res1 = inf;
    }
    if(res1 == res2 && res1 == inf){
        cout << 0 << "\n";
        return;
    }

    cout << min(res1, res2) << "\n";

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
