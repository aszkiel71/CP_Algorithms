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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), sorted_a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sorted_a[i] = a[i];
  }

  // dodaj do stosu wszystkie <= a[0]
  sort(all(sorted_a));
  stack<int> st;
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (sorted_a[i] <= a[0] && (st.empty() || st.top() < sorted_a[i])) {
      st.push(sorted_a[i]);
        debug(st.top());
      result += 1;
    }
  }

  // dodaj 1 jak idzie w gore
  // zdejmij ze stosu jak idzie w dol
  for (int i = 1; i < n; i++) {
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
  cout << result << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
