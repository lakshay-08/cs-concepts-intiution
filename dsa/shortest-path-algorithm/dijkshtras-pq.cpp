#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, int start, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Ignore outdated entry
        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // print shortest distances
    for(int i = 0; i < n; i++)
        cout << "Distance to " << i << " = " << dist[i] << "\n";
}

int main() {
    int n = 5; // number of nodes
    vector<vector<pair<int,int>>> adj(n);

    // edges {to, weight}
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    dijkstra(n, 0, adj); // start from node 0
}