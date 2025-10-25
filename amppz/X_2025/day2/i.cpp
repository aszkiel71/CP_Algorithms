#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back
#include <cassert>
typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;
const ll MOD = 1e9 + 7;

#define int long long

vector<int> factorial(N+1);

void load(){
    factorial[0] = 1;
    for (int i = 1; i <= N; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
}

ll inverse(int n, int k = MOD-2){
    if(k == 0) return 1;
    if(k % 2 == 0){
        int pow = inverse(n, k/2) % MOD;
        return pow*pow % MOD;
    }
    else{
        return inverse(n, k-1)*n % MOD;
    }
}

ll binomial_coefficient(int n, int k) {
    if(n < k || k < 0) return 0LL;
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % MOD) % MOD;
}

void solve() {
  int K, S, T;
  cin >> K >> S >> T;


  int r = K % T;

  int odp = 0;
  int S_wolne = S - K;
  if(S == K && S == T){
    cout << 1 << "\n";
    return;
  }

  if (r == 0) {
    int kula = (K / T);
    int kubelki = T;
    //debug(kubelki); debug(kula);
    //debug(S); debug(K); debug(S_wolne);
    int res = binomial_coefficient(S_wolne / kula + kubelki - 1, kubelki - 1);
    //debug(res);
    cout << res << "\n";
    return;
  }

  int mala = K / T, duza = (mala + 1) % MOD;
  int kubelki_reszta = ((((K / T) + 1) * T) - K + MOD) % MOD;  // mala
  int kubelki_cykl = (T - kubelki_reszta + MOD) % MOD;         // duza
  // cout << kubelki_cykl << kubelki_reszta << "\n";

  for (int ile_malych = 0; S_wolne - mala * ile_malych >= 0; ile_malych++) {
    const int wolne_kulki = (S_wolne - (ile_malych * mala) + MOD) % MOD;
    if (wolne_kulki % duza != 0) continue;
    int ile_duzych = (wolne_kulki * inverse(duza)) % MOD ;
    // cout << "a=" << ile_malych << " "
    //<< "b=" << ile_duzych << "\n";

    int res_cykl = binomial_coefficient(ile_duzych + kubelki_cykl - 1, kubelki_cykl - 1) % MOD;
    // cout << "w cyklu: " << res_cykl << "\n";
    int res_reszta =
        binomial_coefficient(ile_malych + kubelki_reszta - 1, kubelki_reszta - 1) % MOD;
    // cout << "poza cyklem: " << res_reszta << "\n";
    odp += (res_cykl * (res_reszta % MOD)) % MOD;
  }

  cout << odp % MOD << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
    load();
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
