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
    int a, b, c; cin >> a >> b >> c;
    if ((a + b + c) % 3 != 0){
        cout << "NO\n";
        return;
    }
    int tmp = ((a + b + c) / 3);
    cout << ((b <= tmp) ? "YES\n" : "NO\n");
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
