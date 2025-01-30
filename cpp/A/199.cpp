#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "0 0 0";
        return 0;
    }
    if (n == 1) {
        cout << "1 0 0";
        return 0;
    }

    vector<int> fibb;
    fibb.push_back(0);
    fibb.push_back(1);
    int nextFib = 1;

    while (nextFib <= n) {
        nextFib = fibb[fibb.size() - 1] + fibb[fibb.size() - 2];
        fibb.push_back(nextFib);
    }


    unordered_set<int> fibSet(fibb.begin(), fibb.end());


    for (int i = 0; i < fibb.size(); i++) {
        for (int j = i; j < fibb.size(); j++) {
            int needed = n - fibb[i] - fibb[j];
            if (fibSet.find(needed) != fibSet.end()) {
                cout << fibb[i] << " " << fibb[j] << " " << needed;
                return 0;
            }
        }
    }

    cout << "I'm too stupid to solve this problem";
    return 0;
}
