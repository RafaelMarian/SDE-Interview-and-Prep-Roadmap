/*
 * Union-Find (DSU) for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <utility>

struct DSU {
    std::vector<int> parent, rankv;
    int components;

    explicit DSU(int n) : parent(n), rankv(n, 0), components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) std::swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        components--;
        return true;
    }

    bool connected(int a, int b) { return find(a) == find(b); }
};

int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
    int n = static_cast<int>(isConnected.size());
    DSU dsu(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isConnected[i][j]) dsu.unite(i, j);
    return dsu.components;
}

std::vector<int> findRedundantConnection(
    const std::vector<std::vector<int>>& edges) {
    int n = static_cast<int>(edges.size());
    DSU dsu(n + 1);
    for (auto& e : edges) {
        if (!dsu.unite(e[0], e[1])) return e;
    }
    return {};
}

int main() {
    std::vector<std::vector<int>> g = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    std::cout << findCircleNum(g) << "\n";  // 2

    auto red = findRedundantConnection({{1, 2}, {1, 3}, {2, 3}});
    std::cout << red[0] << " " << red[1] << "\n";  // 2 3
    return 0;
}
