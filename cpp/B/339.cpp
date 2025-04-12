#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    ll total_time = 0;
    int pos = 1;

    for (int hs : a) {
        if (hs >= pos) {
            total_time += (hs - pos);
        } else {
            total_time += (n - pos) + hs;
        }
        pos = hs;
    }

    cout << total_time << '\n';

    return 0;
}