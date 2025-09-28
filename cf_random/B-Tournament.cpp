#include <algorithm>
#include <iostream>
#include <queue>
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
  int n, j, k;
  cin >> n >> j >> k; j--;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  if(a[j] == mx || k > 1){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }



  /*j--;
  int x = a[j];
  sort(all(a));
  reverse(all(a));
  for (int i = 0; i < n - 1 && k > 0; i++) {
    if (a[i] == x) {
      cout << "YES\n";
      return;
    }
    k--;
    i += (a[i] == a[i + 1]);
  }
  cout << "NO\n";
  priority_queue<int> pq;
  for (int i = 0; i < n; i++){
      cin >> a[i];
  }
  for(int i = 0; i < n; i++){
      if(pq.size() < k){
          pq.push(a[i]);
      }
      else{
          int x = pq.top(); pq.pop();
          int y = a[i];
          pq.push(max(x, y));
      }
  }
  bool flague = 0;
  while(!pq.empty() && !flague){
      int tmp = pq.top(); pq.pop();
      if(tmp == a[j]){
          flague = true;
      }
  }
  cout << (flague ? "YES\n" : "NO\n");*/
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
