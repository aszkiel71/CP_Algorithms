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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  ll res = 0;
  int a_odd = 0;
  for (int i = 0; i < n; i++) {
    res += a[i] * !(a[i] % 2);
    a_odd += a[i] % 2;
  }

  if (a_odd == 0) {
    cout << 0 << "\n";
    return;
  }

  int take = (a_odd / 2) + a_odd % 2;

  for(int i = n - 1; i >= 0; i--){
    if(a[i] % 2){
        res += a[i];
        take--;
        if(!take){
            break;
        }
    }
  }

  cout << res << "\n";
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
