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

void yes() { cout << "YES\n"; }

void no() { cout << "NO\n"; }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  int cnt_of_2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt_of_2 += a[i] == 2;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int res = 1e6;
  if (cnt_of_2 == 1) {
    res = 1;  // wystarczy zmienic ktorakolwiek na parzysta
    for (int i = 0; i < n; i++) {
      if (a[i] == 2) {
        continue;
      } else {
        if (a[i] % 2 == 0) {
          cout << 0 << "\n";
          return;
        } else {
          cout << 1 << "\n";
          return;
        }
      }
    }
  } else if (cnt_of_2 > 1) {
    cout << 0 << "\n";
    return;
  }

  sort(all(a));  // since b[i] = 1 for all i

  // worst case scenario:
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 1 && a[i + 1] == 1) {
      res = min(res, 2);
      continue;
    }
    res = min(max(a[i + 1] - a[i], 0), res);
  }
  if (res == 0) {
    cout << 0 << "\n";
    return;
  }
  if (res == 1) {
    cout << 1 << "\n";
    return;
  } else
    cout << 2 << "\n";
  // output zawsze bedize od 0-2
}
#include <set>
void solve(bool b) {
  set<int> setka;
  if (!b) return;
  int n;
  cin >> n;
  int x;
  vector<int> a(n);
  int cnt = 0;  // parzyste
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt += (1 - (a[i] % 2));
    setka.insert(a[i]);
  }
  for (int i = 0; i < n; i++) cin >> x;
  sort(all(a));
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != 1 && a[i] == a[i + 1]) {
      cout << 0 << "\n";
      return;
    }
  }
  x = 42;
  int res = 2;
  if (cnt > 1) {
    cout << 0 << "\n";
    return;
  }
  if (cnt == 1) {
    res = 1;  // cout << 1 << "\n";
              // mozemy wziac inne liczbe i zrobic z niej parzysta
              // musimy sprawdzic jedynie, czy nie istnieja juz liczby z gcd > 0
  }
  // sort(all(a));
  // mozemy dla liczb pierwszych od 3 do 1e5 (jest ich okolo 20 tysiecy)
  // przeiterowac po tablicy. da to okolo 1e7 operacji. moze wywalic TLE
  // ewentualnie: wziac pierwsza liczbe, np. 3 i skakac po jej potegach i
  // sprawdzic czy nie istnieje liczba +/- 1 w a while(i*i < n) -> O(log(n)) n
  // liczb - O(n) sprawdzenie w secie: O(log(n)) razem: O(n*2log(n)) = O(nlogn)
  // -> powinno przejsc (hope so)
  for (int i = 0; i < n; i++) {
    int tmp = a[i];
    if (tmp == 1) continue;
    while (tmp < 2e5 + 5) {
      if (setka.count(tmp - 1) > 0) {
        res = 1;
      }
      if (setka.count(tmp + 1) > 0) {
        res = 1;
      }
      if (setka.count(tmp) > 0) {
        cout << 0 << "\n";
        return;
      }
      tmp*=tmp;
    }
  }
  cout << res << "\n";
}

vector<int> primes(N); // przechowujemy najmniejsza liczbe pierwsza dla kazdej liczby

#include <cassert>
void load(bool g){
    assert(g);
    for(int i = 0; i < N; i++){
        primes[i] = i;
    }
    //vector<bool> notPrime(N, false);
    //notPrime[0] = 1; notPrime[1] = 1;
    for(int i = 2; i*i < N; i++){
        //if(notPrime[i] == false){
        if(primes[i] == i){
            for(int j = i*i; j < N; j += i){
             //notPrime[j] = true;
             if(primes[j] == j){
                primes[j] = i;
             }
            }
        }
    }
}




void solve(bool k1, bool k2){
    if (!(k1 ^ k2)) return;
    set<int> setka;
    int n, cnt = 0, res = 2; cin >> n;
    int XXXXX; vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt += (1 - (a[i] % 2));
        setka.insert(a[i]);
    }
    for(int i = 0; i < n; i++) cin >> XXXXX;
    XXXXX = 42;
    sort(all(a));

    if(cnt > 1){
        cout << 0 << "\n";
        return;
    }

    for(int i = 0; i < n-1; i++){
        if(a[i] != 1 && a[i] == a[i+1]){
            cout << 0 << "\n";
            return;
        }
    }

    vector<bool> visited (N, false);

    for(int x : a){
        vector<int> factors;
        int dummy = x;
        while(dummy > 1){
            int fct = primes[dummy];
            factors.pb(fct);
            while(dummy % fct == 0){
                dummy /= fct;
            }
        }
        for(int p : factors){
            if(visited[p]){
                cout << 0 << "\n";
                return;
            }
        }
        for(int p : factors){
            visited[p] = true;
        }
    }
    if(cnt == 1){
        res = 1;
    }
    // +/- case
    for(int x : a){
        vector<int> factors;
        int dummy = 1 + x;
        while(dummy > 1){
            int fct = primes[dummy];
            factors.pb(fct);
            while(dummy % fct == 0){
                dummy /= fct;
            }
        }
        for(int p : factors){
            if(visited[p]){
                cout << 1 << "\n";
                return;
            }
        }
    }
    cout << 2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  load(true);
  int t = 1;
  cin >> t;
  while (t--) {
    solve(true, false);
  }
}
