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

/*int builtin_cos_tam(int x){
    int res = 0;
    while(x){
        res += x % 2;
        x /= 2;
    }
    return res;
}*/

void solve(){
    int x, y, z; cin >> x >> y >> z;
    bool b1, b2, b3;
    b1 = (((y & z) & x) == (y & z));
    b2 = (((x&z) & y) == (x&z));
    b3 = (((x&y) & z) == (x&y));
    cout << ((b1 && b2 && b3) ? "YES\n" : "NO\n");
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
