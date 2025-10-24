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
    ll a, b; cin >> a >> b;
    ll res = 0;
    bool t1 = a % 2;
    bool t2 = b % 2;
    if(!t1 && !t2){
        ll tmp1 = (b - a) / 2; tmp1++;
        res += tmp1 - tmp1 % 2;
        ll tmp2 = (b - a) / 2;
        res += tmp2 - tmp2 % 2;
    }
    else if(t1 ^ t2){
        ll tmp1 = (b - a + 1) / 2;
        res += tmp1 - tmp1 % 2;
        ll tmp2 = (b - a + 1) / 2;
        res += tmp2 - (tmp2%2);
    }
    else if(t1 && t2){
        ll tmp1 = (b - a) / 2;
        res += tmp1 - tmp1 % 2;
        ll tmp2 = ((b - a) / 2) + 1;
        res += tmp2 - tmp2 % 2;
    }
    cout << res << "\n";
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
