#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> b(n);
    map<int, int> occ;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        occ[b[i]]++;
    }
    bool possible = true;
    for(auto k : occ){
        if(k.second % k.first != 0) possible = false;
        if(!possible) break;
    }
    if(!possible){
        cout << -1 << "\n";
        return;
    }

    map<int, vector<int>> groups;
    for(int i = 0; i < n; i++){
        groups[b[i]].push_back(i);
    }

    vector<int> a(n);
    int elem_to_put = 1;

    for(auto k : groups){
        int tmp = k.first;
        int tmp_size = k.second.size();
        for(int i = 0; i < tmp_size; i++){
            if(i > 0 && i % tmp == 0)
                elem_to_put++;
            a[k.second[i]] = elem_to_put;
        }
        elem_to_put++;
    }

    for(int x : a){
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}