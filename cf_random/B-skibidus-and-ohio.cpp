#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    string s; cin >> s; int n = s.size();
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i+1]){
            cout << 1 << "\n";
            return;
        }
    }
    cout << n << "\n";
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
