#include <iostream>

using namespace std;

bool canjump(const string& s, int k) {
    int counter = 0;
    for (char c : s) {
        if (c == '#') {
            counter++;
            if (counter >= k) return false;
        } else {
            counter = 0;
        }
    }
    return true;
}


int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (canjump(s, k))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
