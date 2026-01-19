#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#define int long long

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

int abs(int a, int b) {
    return a > b ? a - b : b - a;
}
void solve(){
    int n; cin >> n; vector<int> a(n);
    int sum = 0;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        sum += abs(a[i] - a[i+1]);
    }
    // debug(sum);
    int res = sum;
    res = min(res, sum - abs(a[0] - a[1]));
    res = min(res, sum - abs(a[n-1] - a[n-2]));

    for (int i = 1; i < n - 1; i++) {
        int tmp = sum;
        tmp -= abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]);
        tmp += abs(a[i-1] - a[i+1]);
        res = min(res, tmp);
    }
    cout << res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
