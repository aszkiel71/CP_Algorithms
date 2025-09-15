#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> p;

void wczytaj(int n){
    p.clear(); p.resize(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
}

void solve(int n){
    wczytaj(n);
    vector<bool> mapka(n + 1, false);
    for(int i = 0; i < n; ++i) {
        if (p[i] != 0) {
            mapka[p[i]] = true;
        }
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; ++i) {
        if (!mapka[i]) {
            pq.push(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (p[i] == 0) {
            p[i] = pq.top();
            pq.pop();
        }
    }


    int l = 0;
    while(l < n && p[l] == l + 1)
        l++;

    if (l == n) {
        cout << "0\n";
        return;
    }

    int r = n - 1;
    while(r >= 0 && p[r] == r + 1)
        r--;


    cout << r - l + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        solve(n);
    }
}
