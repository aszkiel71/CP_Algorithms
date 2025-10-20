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
    int x; cin >> x;
    int a1 = 0, a2 = 0, a3 = 0, res = 0;
    while(min({a1, a2, a3}) < x){
        if(min({a1, a2, a3}) == a1){
            a1 = 2*min(a2, a3) + 1;
        }
        else if(min({a1, a2, a3}) == a2){
            a2 = 2*min(a1, a3) + 1;
        }
        else a3 = 2*min(a1, a2) + 1;
        res++;
    }
    cout << res << "\n";
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
