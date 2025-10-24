#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define debug(x) cout << #x << " = " << (x) << "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
const int N = 2e5 + 12;
const ll inf = 1e18 + 7;

void solve(){
    int n; cin >> n; vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));

    if (n == 0) {
        cout << "TAK\n";
        return;
    }

    vector<int> major_indices;
    vector<bool> is_major_flag(n, false);
    int max_z = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i].second > max_z){
            major_indices.push_back(i);
            is_major_flag[i] = true;
            max_z = a[i].second;
        }
    }

    if (major_indices.size() % 2 == 0) {
        cout << "TAK\n";
        return;
    }

    vector<int> non_major_indices;
    for(int i = 0; i < n; i++){
        if(!is_major_flag[i]) non_major_indices.push_back(i);
    }

    if (non_major_indices.empty()) {
        cout << "NIE\n";
        return;
    }

    int nm_max_s_idx = non_major_indices.back();

    int nm_max_z_idx = -1;
    int max_agility_val = -1;
    for (int idx : non_major_indices) {
        if (a[idx].second > max_agility_val) {
            max_agility_val = a[idx].second;
            nm_max_z_idx = idx;
        }
    }

    vector<int> champions;
    champions.push_back(nm_max_s_idx);
    if (nm_max_s_idx != nm_max_z_idx) {
        champions.push_back(nm_max_z_idx);
    }

    bool can_eliminate = false;
    for (int champ_idx : champions) {
        for (int m_idx : major_indices) {
            if (a[champ_idx].first > a[m_idx].first || a[champ_idx].second > a[m_idx].second) {
                can_eliminate = true;
                break;
            }
        }
        if (can_eliminate) {
            break;
        }
    }

    if (can_eliminate) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
