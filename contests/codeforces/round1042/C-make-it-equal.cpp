#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> S(n), T(n);

        for (int i = 0; i < n; i++) {
            cin >> S[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> T[i];
        }

        unordered_map<int, int> mapkaS;
        unordered_map<int, int> mapkaT;

        for (int i = 0; i < n; i++) {
            int r = S[i] % k;
            mapkaS[min(r, (k - r) % k)]++;
        }

        for (int i = 0; i < n; i++) {
            int r = T[i] % k;
            mapkaT[min(r, (k - r) % k)]++;
        }

        bool possible = (mapkaS == mapkaT);

        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }
}
