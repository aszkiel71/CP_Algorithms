#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countFactorsOf2(int x) {
    int count = 0;
    while (x % 2 == 0) {
        x /= 2;
        count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), [](int x, int y) {
            return countFactorsOf2(x) > countFactorsOf2(y);
        });

        int s = 0, counter = 0;

        for (int x : a) {
            s += x;
            if (s % 2 == 0) {
                counter++;
                s /= 2;
                while (s % 2 == 0) {
                    s /= 2;
                }
            }
        }

        cout << counter << endl;
    }

    return 0;
}
