#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#define int long long

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a % b);
}
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n ; i++) {
    cin >> a[i];
  }

  // sort(all(a));
  for(int p : primes){
    for(int x : a){
        if(x % p != 0){
            cout << p << "\n";
            return;
        }
    }
  }
  cout << -1 << "\n";

}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
