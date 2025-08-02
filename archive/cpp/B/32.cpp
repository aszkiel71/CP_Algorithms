#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string result = "";
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            result += '0';
        } else if (s[i] == '-' && i + 1 < s.length()) {
            if (s[i + 1] == '.') {
                result += '1';
            } else if (s[i + 1] == '-') {
                result += '2';
            }
            i++;
        }
    }
    cout << result << endl;
    return 0;
}
