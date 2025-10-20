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
    int n, k; string s; cin >> n >> k >> s;
    vector<char> res(n, '?');
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    if(n == k){
        cout << string(n, '-') << "\n";
        return;
    }
    for(char c : s){
        cnt1 += c == '0';
        cnt2 += c == '1';
        cnt3 += c == '2';
    }
    for(int i = 0; i < cnt1; i++){
        res[i] = '-';
    }
    for(int i = 0; i < cnt2; i++){
        res[n-1-i] = '-';
    }
    int t1 = cnt1 + cnt3;
    int t2 = cnt2 + cnt3;
    for(int i = t1; i <= n - 1 - t2; i++){
        res[i] = '+';
    }
    for(char c : res) cout << c;
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
