#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back
#include <deque>
typedef long long ll;
#define int long long
int res;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  deque<int> dq;
  dq.push_front(0);
  res = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if(dq.front() <= dq.back()){
        res += dq.front();
        dq.push_front(x);
    }
    else{
        res += dq.back();
        dq.push_back(x);
    }
  }
  cout << res << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
