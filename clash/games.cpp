#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int ST1 = 27;
const int ST2 = 31;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
const int N = 1e6 + 5;

set<pair<int, int>> sett;
int hash1[N], pot1[N];
int hash2[N], pot2[N];

/*

void buildHash(const string& s) {

  int n = s.size();

  for (int i = n - 1; i >= 0; i--) {

    hash1[i] = (((long long)hash1[i + 1] * ST1) + (s[i] - 'a' + 1)) % M1;

    hash2[i] = (((long long)hash2[i + 1] * ST2) + (s[i] - 'a' + 1)) % M2;

  }

}*/

pair<int, int> getHash(int a, int b) {
  int res1 =
      (hash1[a] - (((long long)hash1[b + 1] * pot1[b - a + 1]) % M1) + M1) % M1;
  int res2 =
      (hash2[a] - (((long long)hash2[b + 1] * pot2[b - a + 1]) % M2) + M2) % M2;
  return {res1, res2};
}

void precomputePowers() {
  pot1[0] = 1;
  pot2[0] = 1;
  for (int i = 1; i < N; i++) {
    pot1[i] = ((long long)pot1[i - 1] * ST1) % M1;
    pot2[i] = ((long long)pot2[i - 1] * ST2) % M2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  precomputePowers();

  int Ni, Mi;
  cin >> Ni >> Mi;

  vector<string> teams(Ni, "");

  while (Mi--) {
    int mov = 0;
    for (int i = 0; i < Ni; i++) {
      if (i == Ni / 2) {
        mov = 1;
      }
      int player;
      cin >> player;
      teams[player - 1] += ('A' + mov);
    }
  }

  vector<pair<int, int>> hashes(Ni);

  for (int i = 0; i < Ni; i++) {
    string s = teams[i];
    int n = s.size();

    hash1[n] = 0;
    hash2[n] = 0;

    for (int j = n - 1; j >= 0; j--) {
      hash1[j] = (((long long)hash1[j + 1] * ST1) + (s[j] - 'A' + 1)) % M1;
      hash2[j] = (((long long)hash2[j + 1] * ST2) + (s[j] - 'A' + 1)) % M2;
    }

    pair<int, int> fullHash = getHash(0, n - 1);
    hashes[i] = fullHash;
  }

  for (auto h : hashes) {
    if (sett.count(h)) {
      cout << "NIE\n";
      return 0;
    }
    sett.insert(h);
  }

  cout << "TAK\n";
  return 0;
}
