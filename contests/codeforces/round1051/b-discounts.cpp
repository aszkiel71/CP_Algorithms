#include <algorithm>
#include <cassert>
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(k);
  priority_queue<int> pq1, pq2;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pq1.push(a[i]);
  }
  for (int i = 0; i < k; i++) {
    cin >> b[i];
    pq2.push(-b[i]);
  }

  ll res = 0;

  while (!pq1.empty()) {
    ll sum = 0;
    ll mn = inf;
    if (!pq2.empty()) {
      int tmp_c = -pq2.top();

      if (pq1.size() < tmp_c) {
        while (!pq2.empty()) {
          pq2.pop();
        }
        continue;
      }

      pq2.pop();

      if (tmp_c == 1) {
        if (!pq1.empty()) {
          pq1.pop();
        }
        continue;
      }

      while (tmp_c--) {
        if (!pq1.empty()) {
          int tmp_a = pq1.top();
          pq1.pop();
          sum += tmp_a;
          mn = min(mn, (ll)tmp_a);
        } else {
          break;
        }
      }
      if (sum > 0) res += sum - mn;
    } else {
      while (!pq1.empty()) {
        res += pq1.top();
        pq1.pop();
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
