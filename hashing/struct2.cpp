#include <string>
const int ST1 = 27;
const int ST2 = 31;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
const int N = 1e6 + 5;
using namespace std;

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

int main() { precomputePowers(); }
