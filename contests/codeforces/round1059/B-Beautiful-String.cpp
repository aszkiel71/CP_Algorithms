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

bool is_palindrom(string k){
    int n = k.size();
    for(int i = 0, j = n - 1; i < j; i++, j--){
        if(k[i] != k[j]) return false;
    }
    return true;
}

bool non_decr(string k){
    int n = k.size();
    for(int i = 0; i < n - 1; i++){
        if(k[i] > k[i+1]) return false;
    }
    return true;
}

void solve(){
    int n; string s; cin >> n >> s;
    vector<int> res;
    long long comb = 1LL << n;
    for(ll i = 0; i < comb; i++){
        string tmp1 = "", tmp2 = "";
        vector<int> res;
        ll tmp_i = i;
        for(int j = 0; j < n; j++){
            if(tmp_i % 2){
                tmp1 += s[j];
                res.pb(j+1);
            }
            else{
                tmp2 += s[j];
            }
            tmp_i /= 2;
        }
        if(non_decr(tmp1) && is_palindrom(tmp2)){
            cout << res.size() << "\n";
            for(int x : res) cout << x << " ";
            cout << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
