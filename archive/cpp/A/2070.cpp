#include <iostream>
#define ll long long
using namespace std;

using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll A = (n >= 2) ? (n - 2) / 15 : -1;
        ll B = (n >= 1) ? (n - 1) / 15 : -1;
        ll C = n / 15;
        ll result = 3 * (A + 1) + 2 * (B - A) + (C - B);
        cout << result << '\n';
    }
    return 0;
}