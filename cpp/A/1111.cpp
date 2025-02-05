#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {
        cout << "NO";
        return 0;
    }

    for (size_t i = 0; i < s.length(); i++) {
        if (isVowel(s[i]) != isVowel(t[i])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
