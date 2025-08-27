#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fast_io                      \
  std::ios_base::sync_with_stdio(0); \
  std::cin.tie(0);                   \
  std::cout.tie(0);
#define debug(x) std::cerr << #x << " = " << x << std::endl;
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using pi = std::pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define EACH(x, a) for (auto& x : a)

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    int parzyste = 0, nieparzyste = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      // if(a[i] % 2) nieparzyste++;
      // else parzyste++;
    }
    if (n == 1) {
      if (a[0] == 1)
        cout << a[0] + k;
      else
        cout << a[0];
    } else if (k % 2) {
      for (int i = 0; i < n; i++) {
        if (a[i] % 2)
          cout << a[i] + k << " ";
        else
          cout << a[i] << " ";
      }
    } else {
      vector<int> primes = {
          2,    3,    5,    7,    11,   13,   17,   19,   23,   29,   31,
          37,   41,   43,   47,   53,   59,   61,   67,   71,   73,   79,
          83,   89,   97,   101,  103,  107,  109,  113,  127,  131,  137,
          139,  149,  151,  157,  163,  167,  173,  179,  181,  191,  193,
          197,  199,  211,  223,  227,  229,  233,  239,  241,  251,  257,
          263,  269,  271,  277,  281,  283,  293,  307,  311,  313,  317,
          331,  337,  347,  349,  353,  359,  367,  373,  379,  383,  389,
          397,  401,  409,  419,  421,  431,  433,  439,  443,  449,  457,
          461,  463,  467,  479,  487,  491,  499,  503,  509,  521,  523,
          541,  547,  557,  563,  569,  571,  577,  587,  593,  599,  601,
          607,  613,  617,  619,  631,  641,  643,  647,  653,  659,  661,
          673,  677,  683,  691,  701,  709,  719,  727,  733,  739,  743,
          751,  757,  761,  769,  773,  787,  797,  809,  811,  821,  823,
          827,  829,  839,  853,  857,  859,  863,  877,  881,  883,  887,
          907,  911,  919,  929,  937,  941,  947,  953,  967,  971,  977,
          983,  991,  997,  1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049,
          1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117,
          1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213,
          1217, 1223};

      long long p = 0;
      for (int prime : primes) {
        if (k % prime != 0) {
          p = prime;
          break;
        }
      }

      for (int i = 0; i < n; i++) {
        long long add = 0;

        while ((a[i] + add * k) % p != 0) {
          add++;
        }
        cout << a[i] + add * k << " ";
      }
    }
    cout << "\n";
  }
}

int main() {
  fast_io;
  solve();
  return 0;
}
