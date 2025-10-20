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
    int n, f = -1, l = -1, res = 0, sum = 0; cin >> n; vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i]; sum += a[i];
        if(a[i] > 0){
            l = i;
            if(f == -1) f = i;
        }
    }
    if(sum > 0){
        res = 1;
        for(int i = f+1; i < l; i++){
            if(a[i] == 0){
                res = 2;
                break;
            }
        }
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
