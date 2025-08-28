#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int streak = 0;
  bool possible = true;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      streak++;
    else
      streak = 0;
    if (streak == k) {
      possible = false;
      break;
    }
  }
  if (!possible) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int up = 0;
  for (char c : s) up += (c == '1');
  up++;
  int dwn = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      cout << dwn++ << " ";
    else
      cout << up++ << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
