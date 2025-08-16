#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define INLINE __attribute__((always_inline))inline

using namespace std;

#pragma GCC optimize("Ofast")

const int ST1 = 27;
const int ST2 = 31;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
const int N = 1e6 + 5;

int pot1[N];


int mapka[1337];
string pociagi[1337];
int res[1337];


void precomputePowers() {
  pot1[0] = 1;
  for (int i = 1; i < N; i++) {
    pot1[i] = ((long long)pot1[i - 1] * ST1) % M1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  precomputePowers();

  int n, l, m;
  cin >> n >> l >> m;

  unordered_map<int, unordered_set<int>> pociagi_hashy; // key: hash, val: pociagi z tym hashem


  for (int i = 0; i < n; i++) {
    string s = "";
    char tmp;
    for (int j = 0; j < l; j++) {
      cin >> tmp;
      s += tmp;
    }
    pociagi[i] = s;

    long long h1 = 0;
    for (int j = 0; j < l; j++) {
      h1 = (h1 + (long long)(s[j] - 'a' + 1) * pot1[j]) % M1;
    }

    mapka[i] = (int)h1;
    pociagi_hashy[mapka[i]].insert(i);
  }

  for (int i = 0; i < n; i++)
    res[i] = pociagi_hashy[mapka[i]].size();



  for (int iter = 0; iter < m; iter++) {
    int p1, w1, p2, w2;
    cin >> p1 >> w1 >> p2 >> w2;
    p1--;
    w1--;
    p2--;
    w2--;


    // ten sam pociag
    if (p1 == p2) {
      int old_hash = mapka[p1];
      string& s = pociagi[p1];


      int new_hash = old_hash;


      new_hash = (new_hash -
                        ((long long)(s[w1] - 'a' + 1) * pot1[w1]) % M1 + M1) %
                       M1;

      new_hash = (new_hash -
                        ((long long)(s[w2] - 'a' + 1) * pot1[w2]) % M1 + M1) %
                       M1;


      new_hash =
          (new_hash + ((long long)(s[w2] - 'a' + 1) * pot1[w1]) % M1) %
          M1;
      new_hash =
          (new_hash + ((long long)(s[w1] - 'a' + 1) * pot1[w2]) % M1) %
          M1;


      swap(s[w1], s[w2]);


      pociagi_hashy[old_hash].erase(p1);


      mapka[p1] = new_hash;
      pociagi_hashy[new_hash].insert(p1);

      for (int nr : pociagi_hashy[new_hash]) {
        res[nr] = max(res[nr], (int)pociagi_hashy[new_hash].size());
      }
    } else {
      int old_hash1 = mapka[p1];
      int old_hash2 = mapka[p2];


      int new_hash1 = old_hash1;
      int new_hash2 = old_hash2;

      string& s1 = pociagi[p1];
      string& s2 = pociagi[p2];


      new_hash1 = (new_hash1 -
                         ((long long)(s1[w1] - 'a' + 1) * pot1[w1]) % M1 + M1) %
                        M1;

      new_hash1 =
          (new_hash1 + ((long long)(s2[w2] - 'a' + 1) * pot1[w1]) % M1) %
          M1;


      new_hash2 = (new_hash2 -
                         ((long long)(s2[w2] - 'a' + 1) * pot1[w2]) % M1 + M1) %
                        M1;

      new_hash2 =
          (new_hash2 + ((long long)(s1[w1] - 'a' + 1) * pot1[w2]) % M1) %
          M1;


      swap(s1[w1], s2[w2]);

      pociagi_hashy[old_hash1].erase(p1);
      pociagi_hashy[old_hash2].erase(p2);

      // dodanie pociagow do nowych koszykow (pociagi ktore maja dany hash)
      mapka[p1] = new_hash1;
      mapka[p2] = new_hash2;
      pociagi_hashy[new_hash1].insert(p1);
      pociagi_hashy[new_hash2].insert(p2);

      // aktualizacja res dla nowych grup
      for (int nr : pociagi_hashy[new_hash1])
        res[nr] = max(res[nr], (int)pociagi_hashy[new_hash1].size());


      // jesli rozne koszyki i nie zaktualizowalismy w petli wyzej
      if (new_hash1 != new_hash2) {
        for (int nr : pociagi_hashy[new_hash2]) {
          res[nr] = max(res[nr], (int)pociagi_hashy[new_hash2].size());
        }
      }
    }
  }


  for (int i = 0; i < n; i++)
    cout << res[i] << "\n";


  return 0;
}
