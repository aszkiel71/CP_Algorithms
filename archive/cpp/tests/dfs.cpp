#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, int parent, int u, int v, const vector<vector<int>>& tree) {
    if ((node == u && parent == v) || (node == v && parent == u)) {
        cout << "Istnieje krawedz " << u << " " << v << "\n";
        return;
    }


    for (auto& child : tree[node]) {
        if (child != parent) {
            dfs(child, node, u, v, tree);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> tree(8);


    tree[1].push_back(2);
    tree[1].push_back(5);
    tree[2].push_back(3);
    tree[2].push_back(4);
    tree[5].push_back(6);
    tree[6].push_back(7);

    dfs(1, -1, 2, 3, tree);

    return 0;
}
