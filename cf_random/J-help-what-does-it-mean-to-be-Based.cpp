#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve() {
    int x;
    cin >> x;
    if (x == 1) {
        cout << "yoink a\n";
        cout << "yoink b\n";
        cout << "*slaps a on top of b*\n";
        cout << "yeet b\n";
        cout << "go touch some grass\n";
    } else if (x == 2) {
        cout << "yoink a\n";
        cout << "bruh b is lowkey just 0\n";
        cout << "rip this b fell off by a\n";
        cout << "vibe check a ratios b\n";
        cout << "simp for 7\n";
        cout << "bruh a is lowkey just b\n";
        cout << "yeet a\n";
        cout << "go touch some grass\n";
    } else if (x == 3) {
        cout << "yoink n\n";
        cout << "yoink a\n";
        cout << "bruh m is lowkey just a[0]\n";
        cout << "bruh i is lowkey just 1\n";
        cout << "vibe check n ratios i\n";
        cout << "simp for 9\n";
        cout << "yeet m\n";
        cout << "go touch some grass\n";
        cout << "vibe check a[i] ratios m\n";
        cout << "bruh m is lowkey just a[i]\n";
        cout << "*slaps 1 on top of i*\n";
        cout << "simp for 5\n";
    } else if (x == 4) {
        cout << "yoink n\n";
        cout << "yoink a\n";
        cout << "yoink k\n";
        cout << "rip this k fell off by 1\n";
        cout << "bruh i is lowkey just 0\n";
        cout << "vibe check n ratios i\n";
        cout << "simp for 9\n";
        cout << "go touch some grass\n";
        cout << "bruh count is lowkey just 0\n";
        cout << "bruh j is lowkey just 0\n";
        cout << "vibe check n ratios j\n";
        cout << "simp for 14\n";
        cout << "simp for 18\n";
        cout << "vibe check a[j] ratios a[i]\n";
        cout << "*slaps 1 on top of count*\n";
        cout << "*slaps 1 on top of j*\n";
        cout << "simp for 11\n";
        cout << "vibe check count ratios k\n";
        cout << "simp for 24\n";
        cout << "vibe check k ratios count\n";
        cout << "simp for 24\n";
        cout << "yeet a[i]\n";
        cout << "go touch some grass\n";
        cout << "*slaps 1 on top of i*\n";
        cout << "simp for 6\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
