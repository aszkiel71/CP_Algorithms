#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string res = "";
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                res += "-1";
            } else {
                if (i == n - 1) res += "2";
                else res += "3";
            }
            res += " ";
        }
        res.pop_back();
        cout << res << "\n";
    }

}
