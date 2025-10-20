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
    int n; cin >> n;
    vector<int> a(n);

    int min_pos = -1, max_pos = -1;
    int mn = n + 1, mx = 0;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < mn){
            mn = a[i];
            min_pos = i;
        }
        if(a[i] > mx){
            mx = a[i];
            max_pos = i;
        }
    }

    if (min_pos > max_pos) {
        swap(min_pos, max_pos);
    }

    int res1 = max_pos + 1;
    int res2 = n - min_pos;
    int res3 = (min_pos + 1) + (n - max_pos);
    res1 = min(res1, res2);
    res1 = min(res1, res3);
    cout << res1 << "\n";
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
