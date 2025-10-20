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
    int n; string s; cin >> n >> s;
    int cnt = 0;
    bool sorted = true;
    for(int i = 0; i < n - 1; i++){
        if(s[i] > s[i+1]){
            sorted = false;
            break;
        }
    }
    if(sorted){
        cout << 0 << "\n";
        return;
    }
    string p = s;
    sort(all(p));
    for(int i = 0; i < n; i++){
        cnt += s[i] != p[i];
    }
    cout << cnt / 2 << "\n";
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
