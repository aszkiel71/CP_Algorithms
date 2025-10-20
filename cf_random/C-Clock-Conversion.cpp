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
    int k = stoi(s.substr(0, 2));
    string tm;
    if(k < 12) tm = "AM";
    else tm = "PM";

    k = k % 12;
    if(k == 0){
        k = 12;
    }

    if(k < 10){
        cout << "0";
    }
    cout << k;

    cout << ":" << s[3] << s[4] << " " << tm;
    cout << "\n";
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
