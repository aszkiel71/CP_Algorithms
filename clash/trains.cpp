#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

const int ST1 = 27;
const int ST2 = 31;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
const int N = 1e6 + 5;

int pot1[N];
int pot2[N];

struct Hash {
  int h1, h2;
  bool operator<(const Hash& other) const {
    if (h1 != other.h1) return h1 < other.h1;
    return h2 < other.h2;
  }
};

void precomputePowers() {
  pot1[0] = 1;
  pot2[0] = 1;
  for (int i = 1; i < N; i++) {
    pot1[i] = ((long long)pot1[i - 1] * ST1) % M1;
    pot2[i] = ((long long)pot2[i - 1] * ST2) % M2;
  }
}

Hash computeHash(const string& s) {
  long long h1 = 0, h2 = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    h1 = (h1 + (long long)(s[i] - 'a' + 1) * pot1[i]) % M1;
    h2 = (h2 + (long long)(s[i] - 'a' + 1) * pot2[i]) % M2;
  }
  return {(int)h1, (int)h2};
}

Hash updateHashWithChar(const Hash& currentHash, int pos, char old_char,
                        char new_char) {
  int val_old = old_char - 'a' + 1;
  int val_new = new_char - 'a' + 1;

  long long new_h1 = currentHash.h1;
  new_h1 = (new_h1 - (long long)val_old * pot1[pos] % M1 + M1) % M1;
  new_h1 = (new_h1 + (long long)val_new * pot1[pos]) % M1;

  long long new_h2 = currentHash.h2;
  new_h2 = (new_h2 - (long long)val_old * pot2[pos] % M2 + M2) % M2;
  new_h2 = (new_h2 + (long long)val_new * pot2[pos]) % M2;

  return {(int)new_h1, (int)new_h2};
}

int res[1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  precomputePowers();
  int n, l, m;
  cin >> n >> l >> m;
  vector<string> pociagi_slownie(n);
  vector<Hash> pociagi_hash(n);

  map<Hash, int> mapka;

  for (int i = 0; i < n; i++) {
    string tmp_train = "";
    for (int j = 0; j < l; j++) {
      char inpt;
      cin >> inpt;
      tmp_train += inpt;
    }
    pociagi_slownie[i] = tmp_train;
    Hash tmp_hash = computeHash(tmp_train);
    pociagi_hash[i] = tmp_hash;
    mapka[tmp_hash]++;
  }

  for (int i = 0; i < n; i++) res[i] = mapka[pociagi_hash[i]];

  for (int i = 0; i < m; i++) {
    int w1, p1, w2, p2;
    cin >> p1 >> w1 >> p2 >> w2;
    p1--;
    w1--;
    p2--;
    w2--;

    if (p1 == p2) {
      mapka[pociagi_hash[p1]]--;

      char c1 = pociagi_slownie[p1][w1];
      char c2 = pociagi_slownie[p1][w2];

      Hash new_hash = updateHashWithChar(pociagi_hash[p1], w1, c1, c2);
      new_hash = updateHashWithChar(new_hash, w2, c2, c1);

      swap(pociagi_slownie[p1][w1], pociagi_slownie[p1][w2]);
      pociagi_hash[p1] = new_hash;
      mapka[new_hash]++;
    } else {
      mapka[pociagi_hash[p1]]--;
      mapka[pociagi_hash[p2]]--;

      char c1 = pociagi_slownie[p1][w1];
      char c2 = pociagi_slownie[p2][w2];

      Hash new_hash1 = updateHashWithChar(pociagi_hash[p1], w1, c1, c2);
      Hash new_hash2 = updateHashWithChar(pociagi_hash[p2], w2, c2, c1);

      swap(pociagi_slownie[p1][w1], pociagi_slownie[p2][w2]);
      pociagi_hash[p1] = new_hash1;
      pociagi_hash[p2] = new_hash2;
      mapka[new_hash1]++;
      mapka[new_hash2]++;
    }

    for (int j = 0; j < n; j++) res[j] = max(res[j], mapka[pociagi_hash[j]]);
  }

  for (int i = 0; i < n; i++) cout << res[i] << "\n";
  return 0;
}
