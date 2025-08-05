#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("Ofast")
using namespace std;

const int ST1 = 27;
const int ST2 = 31;
const int M1 = 1000000007;
const int M2 = 1000000009;
const int N = 1000000 + 5;

int hash1[N], pot1[N];
int hash2[N], pot2[N];

int h1[1000005];
int h2[1000005];

pair<int, int> getHash(int a, int b) {
  int res1 =
      (hash1[a] - (((long long)hash1[b + 1] * pot1[b - a]) % M1) + M1) % M1;
  int res2 =
      (hash2[a] - (((long long)hash2[b + 1] * pot2[b - a]) % M2) + M2) % M2;
  return {res1, res2};
}

bool cmp(pair<int, int> h1, pair<int, int> h2) { return h1 == h2; }

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
  srand(time(nullptr));
  std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  int Nk, Q;
  cin >> Nk >> Q;

  for (int val = 0; val <= 1000000; val++) {
    h1[val] = rand() % M1;
    h2[val] = rand() % M2;
  }

  vector<int> arr1(Nk);
  vector<int> arr2(Nk);

  for (int i = 0; i < Nk; ++i) cin >> arr1[i];
  for (int i = 0; i < Nk; ++i) cin >> arr2[i];

  vector<pair<int, int>> p_hash1(Nk + 1);
  p_hash1[0] = {0, 0};
  vector<pair<int, int>> p_hash2(Nk + 1);
  p_hash2[0] = {0, 0};
  int iter = 1;
  for (int k : arr1) {
    int fstt = (p_hash1[iter - 1].first + h1[k]) % M1;
    int sndd = (p_hash1[iter - 1].second + h2[k]) % M2;
    p_hash1[iter] = {fstt, sndd};
    iter++;
  }

  iter = 1;
  for (int k : arr2) {
    int fstt = (p_hash2[iter - 1].first + h1[k]) % M1;
    int sndd = (p_hash2[iter - 1].second + h2[k]) % M2;
    p_hash2[iter] = {fstt, sndd};
    iter++;
  }

  while (Q--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    pair<int, int> s1 = {
        (p_hash1[r1].first - p_hash1[l1 - 1].first + M1) % M1,
        (p_hash1[r1].second - p_hash1[l1 - 1].second + M2) % M2};

    pair<int, int> s2 = {
        (p_hash2[r2].first - p_hash2[l2 - 1].first + M1) % M1,
        (p_hash2[r2].second - p_hash2[l2 - 1].second + M2) % M2};

    if (cmp(s1, s2))
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}
