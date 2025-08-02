#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> intersection(pair<int, int> p1, pair<int, int> p2) {
    int left = max(p1.first, p2.first);
    int right = min(p1.second, p2.second);

    if (left > right) {
        return {-1, -1};
    }

    return {left, right};
}

int main() {
    int n, x;
    cin >> n >> x;

    pair<int, int> result;
    int a, b;
    cin >> a >> b;
    result = {min(a, b), max(a, b)};

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        pair<int, int> p = {min(a, b), max(a, b)};
        result = intersection(result, p);

        if (result.first == -1) {
            cout << "-1";
            return 0;
        }
    }

    if (x >= result.first && x <= result.second) {
        cout << "0";
    } else {
        cout << min(abs(x - result.first), abs(x - result.second));
    }

    return 0;
}
