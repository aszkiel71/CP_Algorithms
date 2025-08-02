#include <iostream>
#include <vector>
#include <set>
using namespace std;



int main() {
    int t; // liczba test case'ow
    cin >> t;

    while (t--) {
        int n, m, q; // n - liczba kart, m - pozycja jokera, q - liczba operacji
        cin >> n >> m >> q;

        vector<int> operations(q);
        for (int i = 0; i < q; i++) {
            cin >> operations[i];
        }

        set<int> seen_positions; // unique joker's positions
        seen_positions.insert(m);

        // *** nwm co dalej
        // zostawie na kiedys

    return 0;
}
