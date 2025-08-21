#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    vector<string> liczby(19, "");
    for (int i = 0; i < 19; i++) {
        string tmp = "1";
        string chvj(i, '0');
        tmp += chvj;
        tmp += "1";
        liczby[i] = tmp;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;

        vector<unsigned long long> ans;
        int am_of_ans = 0;
        for (int i = 0; i < 19; i++) {
            unsigned long long tmpuoll = stoull(liczby[i]);

            if (n % tmpuoll == 0) {
                ans.push_back(n / tmpuoll);
                am_of_ans++;
            }
        }

        sort(ans.begin(), ans.end());
        cout << am_of_ans << "\n";
        for (int xdd = 0; xdd < am_of_ans; xdd++) {
            cout << ans[xdd] << " ";
        }
        if(am_of_ans > 0) cout << "\n";
    }
}
