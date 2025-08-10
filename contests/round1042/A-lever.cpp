#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;
int main() {
  int t;
  cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int cnt = 0; bool flague = 1;
    while (flague){
        cnt++;
    for(int i = 0; i < n; i++){

        if (a[i] > b[i]){
            a[i]--;
            i = n + 42;
        }
        if (i == n - 1) flague = 0;
        }
    for (int i = 0; i < n && flague; i++){
        if(a[i] < b[i]){
            b[i]--;
            i = n + 42;
        }
    }
    }
    cout << cnt << "\n";
  }
}
