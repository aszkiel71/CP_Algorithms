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
#include <set>
vector<bool> dp(N+1, 0);
set<string> numbers;

void move(string s = "1"){
    int n = s.size();
    if(n == 6) return;
    numbers.insert(s);
    move(s + "1");
    move(s + "0");
}

void load(){
    move();
    dp[1] = true;
    vector<int> liczby;
    for(string xxx : numbers){
        ll num = stoll(xxx);
        if(num > N) continue;
        liczby.pb((int)num);
    }

    sort(all(liczby));
    for(int i = 1; i <= N; i++){
        if(!dp[i]) continue;
        for(int d : liczby){
            ll product = (ll)i*d;
            if(product > N) break;
            dp[product] = true;
        }
    }
}

void solve(){
    int n; cin >> n;
    cout << (dp[n] ? "YES\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    load();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
