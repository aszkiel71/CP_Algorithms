#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define fast_io std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

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

void solve() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n); long long res = 0;
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        // wystarczy zrobic by dla kazdej pary bylo to spelnione. w tresci jest 1-based wiec trzeba byc uwaznym
        for(int i = 0; i < n - 1 ; i++){
            // gdy parzysta (1-based)
            if (i % 2 == 0){
                if(p[i+1] >= p[i]) continue;
                int delta = p[i] - p[i+1];
                res += delta;
                p[i] = p[i+1];
            }
             else{
                if(p[i] >= p[i+1]) continue;
                int delta = p[i+1] - p[i];
                res += delta;
                p[i+1] = p[i];
            }
        }
        cout << res << "\n";
    }
}

int main() {
    fast_io;
    solve();
    return 0;
}
