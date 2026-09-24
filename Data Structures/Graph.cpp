/*
 * Graph patterns for FAANG interviews
 * - Number of islands (grid DFS)
 * - Course schedule (topo / cycle detect)
 * - Dijkstra shortest path
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

void dfsIsland(std::vector<std::vector<char>>& g, int r, int c) {
    int R = g.size(), C = g[0].size();
    if (r < 0 || c < 0 || r >= R || c >= C || g[r][c] != '1') return;
    g[r][c] = '0';
    dfsIsland(g, r + 1, c);
    dfsIsland(g, r - 1, c);
    dfsIsland(g, r, c + 1);
    dfsIsland(g, r, c - 1);
}

int numIslands(std::vector<std::vector<char>> grid) {
    int count = 0;
    for (int i = 0; i < static_cast<int>(grid.size()); i++) {
        for (int j = 0; j < static_cast<int>(grid[0].size()); j++) {
            if (grid[i][j] == '1') {
                ++count;
                dfsIsland(grid, i, j);
            }
        }
    }
    return count;
}

bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> adj(numCourses);
    std::vector<int> indeg(numCourses);
    for (auto& e : prerequisites) {
        adj[e[1]].push_back(e[0]);
        indeg[e[0]]++;
    }
    std::queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indeg[i] == 0) q.push(i);
    int taken = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        taken++;
        for (int v : adj[u])
            if (--indeg[v] == 0) q.push(v);
    }
    return taken == numCourses;
}

// Dijkstra: times[i] = {u, v, w} directed edge u->v weight w. Nodes 1..n
int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for (auto& t : times) adj[t[0]].push_back({t[1], t[2]});

    std::vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    using P = std::pair<int, int>;  // dist, node
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        ans = std::max(ans, dist[i]);
    }
    return ans;
}

int main() {
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    std::cout << numIslands(grid) << "\n";  // 3

    std::cout << std::boolalpha
              << canFinish(2, {{1, 0}}) << "\n"      // true
              << canFinish(2, {{1, 0}, {0, 1}}) << "\n";  // false

    std::cout << networkDelayTime({{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2)
              << "\n";  // 2
    return 0;
}
