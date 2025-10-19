#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

bool is_palindrom(vector<int>& x) {
  int n = x.size();
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (x[i] != x[j]) return false;
  }
  return true;
}
#include <set>
void solve(){
    int n, k; cin >> n >> k; vector<int> a(n), unused, res;
    vector<bool> used(n+1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        used[a[i]] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!(used[i])) unused.pb(i);
    }
    int kk = unused.size();

    if(kk >= k){
        for(int i = 0; i < k; i++)
            cout << unused[i] << " ";
        cout << "\n";
        return;
    }
    /*if(kk >= 2){
        if(k == 1){
            cout << unused[0] << "\n";
            return;
        }
        if(k == 2){
            cout << unused[0] << " " << unused[1] << "\n";
            return;
        }
        if(k > 2){
            cout << unused[0] << " " << unused[1] << " ";
            for(int i = 0; i < k - 2; i++){
                cout << a[i] << " ";
            }
        }
        cout << "\n";
        return;
    }
    if(kk == 1){
        res.pb(unused[0]);
    }
    int idx = 0;
    int m = res.size();
    while(m < k){
        res.pb(a[idx%n]);
        idx++;
        m++;
    }
    for(int x : res){
        cout << x << " ";
    }*/
   // wypiszmy kk liczb. zostanie nam k - kk do wypisania
    /*if(kk < k){
        for(int i = 0; i < kk; i++){
            cout << unused[i] << " ";
        }
    }
    for(int i = 0; i < k - kk; i++){
        cout << a[i] << " ";
    }*/
   if(kk >= 3){
        for(int i = 0; i < k; i++){
            cout << unused[i%3] << " ";
        }
        cout << "\n";
        return;
   }
   if(kk == 2){
        /*int shit_we_dont_want = a.back();
        int idx = n - 1;
        while(idx >= 0 && shit_we_dont_want == a[idx]){
            idx--;
        }
        shit_we_dont_want = a[max(0,idx)];*/
        vector<int> cycle = {unused[0], unused[1], a[0]};
        for(int i = 0; i < k; i++){
            cout << cycle[i%3] << " ";
        }
        cout << "\n";
        return;
   }
   if(kk == 1){
    // powtarza sie tylko jeden element
        /*int lst = a[n-2];
        if(lst == a[n-1]) lst = a[0];
        vector<int> cycle = {unused[0], lst};
        for(int i = 0; i < k; i++){
            cout << cycle[i%2] << " ";
        }*/
        vector<int> tmp;
        tmp.pb(unused[0]);
        set<int> unq;
        unq.insert(unused[0]);
        for(int x : a){
            if(tmp.size() == 3) break;
            if(unq.find(x) == unq.end()){
                tmp.pb(x);
                unq.insert(x);
            }
        }

        int c1 = -1, c2 = -1, c3 = -1;
        for (int x : tmp) {
            if (x != a[n-1] && x != a[n-2]) {
                c1 = x;
                break;
            }
        }

        vector<int> rest;
        for (int x : tmp) if (x != c1) rest.pb(x);

        if (rest[0] != a[n-1]) {
            c2 = rest[0];
            c3 = rest[1];
        } else {
            c2 = rest[1];
            c3 = rest[0];
        }

        vector<int> cycle = {c1, c2, c3};

        for (int i = 0; i < k; i++) {
            cout << cycle[i % 3] << " ";
        }
        cout << "\n";
        return;
   }

   // kk == 0
   /*vector<int> cycle;
   vector<int> tmp = {a[0], a[1], a[2]};
   int xxx;
   for(int cand : tmp){
        if(cand != a[n-1] && cand != a[n-2]){
            xxx = cand;
            break;
        }
   }
   cycle.push_back(xxx);
   for(int cand : tmp){
        if(cand != xxx)
            cycle.pb(cand);
   }

   for(int i = 0; i < k; i++){
    cout << cycle[i%3] << " ";
   }*/
    vector<int> tmp = {a[0], a[1], a[2]};
    int c1 = -1, c2 = -1, c3 = -1;

    for (int x : tmp) {
        if (x != a[n-1] && x != a[n-2]) {
            c1 = x;
            break;
        }
    }

    vector<int> rest;
    for (int x : tmp) {
        if (x != c1) {
            rest.pb(x);
        }
    }

    if (rest[0] != a[n-1]) {
        c2 = rest[0];
        c3 = rest[1];
    } else {
        c2 = rest[1];
        c3 = rest[0];
    }

    vector<int> cycle = {c1, c2, c3};

    for (int i = 0; i < k; ++i) {
        cout << cycle[i % 3] << " ";
    }
    cout << "\n";
}

/*

*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
