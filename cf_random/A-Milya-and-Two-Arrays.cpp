#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    int n; cin >> n; vector<int> a(n), b(n);
    set<int> aa;
    set<int> bb;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        aa.insert(x);
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        bb.insert(x);
    }
    cout << (aa.size() + bb.size() >= 4 ? "YES\n" : "NO\n");
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
