#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve() {
    string s;
    cin >> s;

    ll suma = 0;
    int count2 = 0;
    int count3 = 0;

    for (char c : s) {
        int x = c - '0';
        suma += x;
        if (x == 2) {
            count2++;
        } else if (x == 3) {
            count3++;
        }
    }

    if (suma % 9 == 0) {
        cout << "YES\n";
        return;
    }

    int x = (9 - (suma % 9)) % 9;
    int mn[9] = {0, 5, 1, 6, 2, 7, 3, 8, 4};

    for (int i = 0; i <= min(count3, 2); ++i) {
        int z = i * 6;
        int y = (x - (z % 9) + 9) % 9;

        if (count2 >= mn[y]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

}
