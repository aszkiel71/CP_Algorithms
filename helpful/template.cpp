#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    // adjust your input data
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    // example of use debug:
    for(int x : a){
        debug(x);
    }

    // if you want to check what is causing the error, you can use:
    assert(0);
    // and move it up/down until the message ‘assertion failed’ appears.
    // then you know which line is causing the error

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t; // comment this line if the problem has just one test case
    while(t--){
        solve();
    }
}
