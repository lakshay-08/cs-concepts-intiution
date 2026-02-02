#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, int start, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    set<pair<int, int>> s; // {distance, node}
    s.insert({0, start});

    while (!s.empty()) {
        auto [d, u] = *s.begin(); // node with smallest distance
        s.erase(s.begin());

        for(auto [v, w] : adj[u]) { // relax neighbors
            if(dist[u] + w < dist[v]) {
                // remove old distance if it exists
                s.erase({dist[v], v});
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }

    // print shortest distances
    for(int i = 0; i < n; i++)
        cout << "Distance to " << i << " = " << dist[i] << "\n";
}

int main(){
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);

    adj[0].push_back({1, 10});
    adj[0].push_back({2, 3});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 2});
    adj[2].push_back({1, 4});
    adj[2].push_back({3, 8});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 7});
    adj[4].push_back({3, 9});
    
    dijkstra(n, 0, adj);
    return 0;
}