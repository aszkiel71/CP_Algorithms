#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

// robimy dwa grafy
// bedziemy je laczyc ze soba, ale przjescie z drugiej warstwy (grafu) do pierwszego
// będzie kosztować 2w

// incorrect btw ale trudno

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(2 * n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];


            graph[u].push_back({v, w});
            graph[u].push_back({v + n, w});
            graph[v + n].push_back({u, 2*w});
            graph[v].push_back({u + n, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(2 * n, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& [v, weight] : graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Minimum z
        // - dotarcia bez odwrócenia (warstwa 0)
        // - dotarcia z odwróceniem (warstwa 1)
        int result = min(dist[n-1], dist[2*n-1]);
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> nums1 = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
    cout << "res : " << sol.minCost(4, nums1) << endl;
    cout << "---" << endl;

    vector<vector<int>> nums2 = {{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}};
    cout << "res: " << sol.minCost(4, nums2) << endl;
    cout << "---" << endl;


    return 0;
}
