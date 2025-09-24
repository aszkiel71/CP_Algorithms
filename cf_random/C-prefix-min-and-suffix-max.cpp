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
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    string res;
    vector<int> pref(n), suff(n);
    pref[0] = a[0];
    suff[n - 1] = a[n - 1];
    for(int i1 = 1; i1 < n; i1++){
        pref[i1] = min(pref[i1-1], a[i1]);
    }
    for(int i2 = n - 2; i2 >= 0; i2--){
        suff[i2] = max(suff[i2+1], a[i2]);
    }
    int pre_min_left = a[0];
    int pre_max_right = suff[1];
    if(min(pre_min_left, pre_max_right) == a[0] || max(pre_min_left, pre_max_right) == a[0]){
        res += '1';
    }
    else if(suff[0] == a[0] || pref[n-1] == a[0]){
        res += '1';
    }
    else{
        res += '0';
    }

    for(int i = 1; i < n - 1; i++){
        int min_left = pref[i];
        int max_right = suff[i+1];
        int min_left2 = pref[i-1];
        int max_right2 = suff[i];
        if(max(min_left, max_right) == a[i] || min(min_left, max_right) == a[i]){
            res += '1';
        }
        else if(max(min_left2, max_right2) == a[i] || min(min_left2, max_right2) == a[i]){
            res += '1';
        }
        else{
            res += '0';
        }
    }

    int post_min_left = pref[n - 2];
    int post_max_right = a[n-1];
    if(min(post_min_left, post_max_right) == a[n-1] || max(post_max_right, post_min_left) == a[n-1]){
        res += '1';
    }
    else if(pref[n-1] == a[n-1] || suff[0] == a[n-1]){
        res += '1';
    }
    else{
        res += '0';
    }

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
