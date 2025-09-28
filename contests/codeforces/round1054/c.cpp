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

void yes(){
    cout << "YES\n";
}

void no(){
    cout << "NO\n";
}


void solve(){
    int n, k; cin >> n >> k; vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a));
    ll less = 0;
    ll same = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < k) less++;
        same += (a[i] == k);
        if (a[i] > k){break;}
    }
    vector<int> sat(k + 1, 0);
    for(int i = 0; i < n; i++){
        if(a[i] >= k) break;
        sat[a[i]]++;
    }
    ll res = 0;
    for(int i = 0; i < k; i++){
        if(sat[i] == 0){
            res++;
        }
    }

    cout << max(res, same) << "\n";
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
