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

string convert(ll n){
    if(n == 0) return "0";
    string res = "";
    while(n > 0){
        res += '0' + (n%2);
        n >>= 1;
    }
    reverse(all(res));
    return res;
}

bool palindrome(string s){
    int n = s.size();
    for(int i = 0, j = n - 1; i < j; i++, j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

void solve(){
    ll n; cin >> n;
    string k = convert(n);

    for(int i = (int)k.length(); i < 64; i++){
        string tmp = string(i - k.length(), '0') + k;
        bool c1 = palindrome(tmp), c2 = true;
        if(i % 2){
            c2 = (tmp[i/2] == '0');
        }
        if(c1 && c2){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
