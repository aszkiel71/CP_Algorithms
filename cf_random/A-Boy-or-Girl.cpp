#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>
#define int long long

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
    set<char> cnt;
    for(char c : s){
        cnt.insert(c);
    }
    int sz = (int)cnt.size();
    if(sz%2){
        cout << "IGNORE HIM!";
    }
    else{
        cout << "CHAT WITH HER!";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
