#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void yes() { cout << "YES\n"; }
void nah() { cout << "NO\n"; }



void solve(){
    int n; cin >> n;
    vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
    int mn = a[0];
    for(int x : a){
        if(x >= 2*mn){
            nah();
            return;
        }
        mn = min(mn, x);
    }
    yes();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
