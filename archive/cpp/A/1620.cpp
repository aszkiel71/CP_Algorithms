#include <iostream>
#include <string>

using namespace std;

bool goodtho(int &s, const string &t) {
    for (int i = 0; i < s - 1; i++) {
        if (t[i] != t[i + 1])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        bool flague = true;
        int s;
        string str;
        cin >> str;
        s = str.length();

        int countN = 0;
        for (char c : str) countN += (c == 'N');

        if (countN == 1) {
            cout << "NO\n";
            continue;
        }

        if (goodtho(s, str)) {
            cout << "YES\n";
            continue;
        }

        if (s == 1) {
            cout << "YES\n";
            continue;
        }

        if (s == 2) {
            if (str[0] == str[1])
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }

        if (str.back() == 'E') {
            for (int i = 1; i < s - 1; i++) {
                if (str[i] == 'N') {
                    cout << "YES\n";
                    flague = false;
                    break;
                }
            }
        } else {
            for (int i = 1; i < s - 1; i++) {
                if (str[i] == 'E') {
                    cout << "YES\n";
                    flague = false;
                    break;
                }
            }
        }

        if (flague) {
            if (countN >= 2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}