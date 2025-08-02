#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string n1, m1;
    cin >> n1 >> m1;


    if (n1.length() != m1.length())
    {
        cout << "WRONG_ANSWER";
        return 0;
    }
    int n = stoi(n1);
    int m = stoi(m1);
    if (n == 0 and m != 0)
    {
        cout << "WRONG_ANSWER";
        return 0;
    }
    if (n == 0 and m == 0)
    {
        cout << "OK";
        return 0;
    }




    vector<int> digits;
    int tmp_n = n;

    while (tmp_n > 0) {
        digits.push_back(tmp_n % 10);
        tmp_n /= 10;
    }

    sort(digits.begin(), digits.end());


    if (digits[0] == 0) {
        for (int i = 1; i < digits.size(); i++) {
            if (digits[i] != 0) {
                swap(digits[0], digits[i]);
                break;
            }
        }
    }


    int new_number = 0;
    for (int d : digits) {
        new_number = new_number * 10 + d;
    }


    if (new_number == m) {
        cout << "OK";
    } else {
        cout << "WRONG_ANSWER";
    }

    return 0;
}
