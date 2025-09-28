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
  string s;
  cin >> s;

  ll res1 = 0;
  vector<int> pos_a;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      pos_a.push_back(i);
    }
  }

  if (pos_a.size() > 1) {
    vector<int> v1;
    for (int j = 0; j < pos_a.size(); ++j) {
      v1.push_back(pos_a[j] - j);
    }
    sort(v1.begin(), v1.end());
    ll mid = v1[v1.size() / 2];
    // debug(mid);
    // debug(v1.size());
    for (int val : v1) {
      // debug(res1);
      res1 += abs(val - mid);
    }
  }

  ll res2 = 0;
  vector<int> pos_b;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'b') {
      pos_b.push_back(i);
    }
  }

  if (pos_b.size() > 1) {
    vector<int> v2;
    for (int j = 0; j < pos_b.size(); ++j) {
      v2.push_back(pos_b[j] - j);
      // assert(0);
    }
    sort(v2.begin(), v2.end());
    ll mid = v2[v2.size() / 2];
    // debug(mid);
    // debug(v2.size());
    for (int val : v2) {
      res2 += abs(val - mid);
      // debug(res2);
    }
  }

  cout << min(res1, res2) << "\n";
}
void leminiusz_to_cheater() { solve(); }
bool leminiusz_to_oszust = true;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    leminiusz_to_oszust = !leminiusz_to_oszust;
    leminiusz_to_oszust ? leminiusz_to_cheater() : solve();
  }
}
