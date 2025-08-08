#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int ST1 = 27;
const int ST2 = 31;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
const int N = 1e6 + 5;

int hash1[N], pot1[N];
int hash2[N], pot2[N];

pair<int, int> getHash(int a, int b) {
  int res1 =
      (hash1[a] - (((long long)hash1[b + 1] * pot1[b - a]) % M1) + M1) % M1;
  int res2 =
      (hash2[a] - (((long long)hash2[b + 1] * pot2[b - a]) % M2) + M2) % M2;
  return {res1, res2};
}

bool cmp(pair<int, int> h1, pair<int, int> h2) {
  return h1 == h2;
}

void buildHash(const string& s) {
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    hash1[i] = (((long long)hash1[i + 1] * ST1) + (s[i] - 'a' + 1)) % M1;
    hash2[i] = (((long long)hash2[i + 1] * ST2) + (s[i] - 'a' + 1)) % M2;
  }
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
  precomputePowers();


}
