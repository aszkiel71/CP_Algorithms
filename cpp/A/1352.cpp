#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;
        int place_value = 1;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                arr.push_back(digit * place_value);
            }
            n /= 10;
            place_value *= 10;
        }

        cout << arr.size() << "\n";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
