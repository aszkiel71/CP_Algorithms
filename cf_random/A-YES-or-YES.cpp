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
    string s; cin >> s;
    bool ok = 1;
    vector<char> chr1 = {'y', 'e', 's'};
    vector<char> chr2 = {'Y', 'E', 'S'};
    int i = 0;
    for(char c : s){
        ok = (c == chr1[i] || c == chr2[i]);
        if(!ok){
            break;
        }
        i++;
    }
    cout << (ok ? "YES\n" : "NO\n");
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
