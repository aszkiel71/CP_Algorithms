#include <iostream>

using namespace std;

int main() {
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    int total = 0;
    int l, r;
    int tmp_afk_time = 0;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> l >> r;

        total += (r - l) * p1;
        arr[i] = r;

        if (i > 0) {
            tmp_afk_time = l - arr[i - 1];

            if (tmp_afk_time > 0) {
                if (tmp_afk_time <= t1) {

                    total += tmp_afk_time * p1;
                } else if (tmp_afk_time <= t1 + t2) {

                    total += t1 * p1;
                    total += (tmp_afk_time - t1) * p2;
                } else {
                    total += t1 * p1;
                    total += t2 * p2;
                    total += (tmp_afk_time - t1 - t2) * p3;
                }
            }
        }

    }

    cout << total;
    return 0;
}
