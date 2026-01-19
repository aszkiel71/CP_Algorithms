#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define int long long

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

int help(vector<int>& a) {
  int result = 1;
  stack<int> st;
  st.push(a[0]);
  for (int i = 1; i < (int)a.size(); i++) {
    while (a[i] < st.top()) {
      assert(!st.empty());
      st.pop();
    }
    if (a[i] > st.top()) {
      assert(!st.empty());
      st.push(a[i]);
      result += 1;
    }
  }
  return result;
}

void solve() {
  int n;
  cin >> n;

  int min_idx = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < a[min_idx]) {
      min_idx = i;
    }
  }

  vector<int> l;
  for (int i = 0; i <= min_idx; i++) {
    l.push_back(a[i]);
  }
  reverse(all(l));

  vector<int> r;
  for (int i = min_idx; i < n; i++) {
    r.push_back(a[i]);
  }

  int result = help(l) + help(r) - 1;
  cout << result << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
