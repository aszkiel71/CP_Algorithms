#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i].first >> houses[i].second;
    }

    set<double> potential_positions; // set to storage unique positions


    // calculate pretending positions for new house
    for (int i = 0; i < n; i++) {
        int x = houses[i].first;
        int a = houses[i].second;
        potential_positions.insert(x - (a + t) / 2.0); // touching left
        potential_positions.insert(x + (a + t) / 2.0); // touching right
    }

    int valid_positions = 0;

    // check all options for position
    for (auto pos : potential_positions) {
        double new_left = pos - t / 2.0;
        double new_right = pos + t / 2.0;

        bool overlaps = false;


        // check if new house overlaps on existing one
        for (int j = 0; j < n; j++) {
            double house_left = houses[j].first - houses[j].second / 2.0;
            double house_right = houses[j].first + houses[j].second / 2.0;

            if (!(new_right <= house_left || new_left >= house_right)) {
                overlaps = true;
                break;
            }
        }

        // if not overlaping, then position is correct
        if (!overlaps) {
            valid_positions++;
        }
    }

    cout << valid_positions << endl;

    return 0;
}
