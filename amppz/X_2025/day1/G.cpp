#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include <cstdint>

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;
#include <cmath>

int logg(long long x) { return 64 - __builtin_clzl(x) - 1; }

/*int loog(float x) {
  ll res = 0;
  if (x == 1) return 0;
  ll dd = 1;
  while (dd < x) {
    dd *= 2;
    res++;
  }
  return res;
}*/

uint32_t log3(float *x) {
  uint32_t bity = (*((uint32_t *)x) & 0x7f000000) >> 22;
  return bity;
}


#include <cassert>



void solve() {
  float H1, H2, B;
  cin >> H1 >> H2 >> B;
  float factor = (B - 1) / B;
  // debug(factor);
  // double n = log(H2)/log(H1*factor);
  // ll l = 0, r = inf;
  // float l1 = (log(H2 / H1)), l2 = ((log((B - 1) / B)));
  float licznik = (float)logl(H2/H1);
  float mianownik = (float)logl((B-1)/B);
  //assert(mianownik != 0);
  float n = ceil(licznik / mianownik);
  ll res = ((ll)n);
  cout << res << "\n";

  // debug(l1); debug(l2);
  /*while(H1 > H2){
      res++;
      H1*=factor;
  }*/
  /*ll res;
  while(l <= r){
       ll mid = (l + r)/2;
       if(mid >= target){
           res = mid;
           r = mid - 1;
       }
       else{
           l = mid + 1;
       }
  }*/

  // cout << res << "\n";
}

void solve2(){
    ll H1, H2, B; cin >> H1 >> H2 >> B;
    double LH1 = (double)H1, LH2 = (double)H2;
    double factor = double(B-1) / double(B);
    double licznik = logl(LH2/LH1);
    double mianownik = logl(factor);
    ll res = (ll)(ceil(licznik/mianownik));
    cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve2();
  }
}
