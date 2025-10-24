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
    int n,m,l,r; cin >> n >> m >> l >> r;
    int l0, r0;
    if(m <= r){
        r0 = m;
        l0 = 0;
    }
    else{
        r0 = r;
        m -= r;
        l0 = 0 - m;
    }
    cout << l0 << " " << r0 << "\n";
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
