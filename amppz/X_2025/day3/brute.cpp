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

int cnt_1(int a) {
  int res = 0;
  while (a) {
    res += a % 2;
    a >>= 1;
  }
  return res;
}

int pot2(int a) {
  int k = 1;
  while (k <= a) {
    k *= 2;
  }
  return k;
}

int spot2(int a) {
  int k = 1;
  while (k * 2 < a) {
    k *= 2;
  }
  return k;
}

bool goodtho(int a, int b, int cand) {
  if (cand >= a && cand <= b) {
    return true;
  }
  return false;
}

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 1) {
    cout << 1 << "\n";
    return;
  }
  int pot = pot2(a);
  if (a == b) {
    cout << a << "\n";
    return;
  }
  if (goodtho(a, b, pot)) {
    cout << pot << "\n";
    return;
  }
  int candidate = spot2(a);
  if (goodtho(a, b, candidate)) {
    cout << candidate << "\n";
    return;
  }
  int tmp = candidate;
  int pos = candidate / 2;
  /*while(1){
      if(goodtho(a, b, tmp)){
          cout << tmp << "\n";
          return;
      }
  }*/

  int l = spot2(a);
  int r = 2 * l + 1;
  int kk = l;
  int plc;
  int last_l;
  while (l <= r) {
    last_l = l;
    int mid = (l + r) / 2;
    if (goodtho(a, b, mid)) {
      plc = mid;
      break;
      // cout << mid << "\n";
      // return;
    }
    if (a < mid) {
      r = mid;
    } else {
      l = mid;
    }
  }
  // debug(plc);
  // debug(cnt_1(plc));
  // debug(cnt_1(1025));
  int x = plc;
  while (goodtho(a, b, plc)) {
    plc = (plc + last_l) / 2;
    // debug(plc);
    if (goodtho(a, b, plc)) {
      x = plc;
    }
  }
  /*int bits = cnt_1(x);
  int point = spot2(a);
  int idx = 1;
  int lst;
  while(point < a){
    lst = point;
    point ^= (point / (1 << idx));
    idx++;
  }
  int miss = bits - cnt_1(point);
  int res;
  debug(miss);*/
  // debug(plc);
  // debug(cnt_1(plc));
  // debug(cnt_1(x));

  int res_1 = cnt_1(x);

  //debug(res_1);

  for (int cc = a; cc < b; cc++) {
    if (cnt_1(cc) == res_1) {
      cout << cc;
      return;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
