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

void yes(){
    cout << "YES\n";
}

void no(){
    cout << "NO\n";
}


void solve(){
    int n; cin >> n; vector<int> a(n);
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > 0) pos++;
        else if(a[i] == 0) zero++;
        else if(a[i] < 0) neg++;
    }
    int res = zero;
    res += 2*(neg % 2);
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
