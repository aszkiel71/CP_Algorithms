#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int d, sumTime;
    cin >> d >> sumTime;

    vector<pair<int, int>> limits(d);
    vector<int> schedule(d);
    int minTotal = 0, maxTotal = 0;
    for (int i = 0; i < d; ++i) {
        cin >> limits[i].first >> limits[i].second;
        minTotal += limits[i].first;
        maxTotal += limits[i].second;
        schedule[i] = limits[i].first;
    }

    if (sumTime < minTotal || sumTime > maxTotal) {
        cout << "NO" << endl;
        return 0;
    }

    int extraHours = sumTime - minTotal;

    for (int i = 0; i < d && extraHours > 0; ++i) {
        int possibleIncrease = limits[i].second - schedule[i];
        int increment = min(possibleIncrease, extraHours);
        schedule[i] += increment;
        extraHours -= increment;
    }

    cout << "YES" << endl;
    for (int i = 0; i < d; ++i) {
        cout << schedule[i] << " ";
    }
    cout << endl;

    return 0;
}