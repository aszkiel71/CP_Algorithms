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

bool goodtho(int x) {
  bool b1, b2, b3, b4;
  b1 = (x % 2 > 0);
  b2 = (x % 3 > 0);
  b3 = (x % 5 > 0);
  b4 = (x % 7 > 0);
  return b1 && b2 && b3 && b4;
}

#define u64 unsigned long long int

u64 res(int x) {
  u64 rs = 0;
  for (int i = 0; i <= x; i++) {
    rs += goodtho(i);
  }
  return rs;
}

u64 get_res(u64 x) {
  u64 k = res(210);
  u64 rs = x / 210;
  rs *= k;
  rs += res(x % 210);
  return rs;
}

void solve() {
  u64 l, r;
  cin >> l >> r;
  u64 r1 = get_res(r);
  u64 r2 = get_res(l-1);
  cout << r1 - r2 << "\n";
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
