#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void dfs(int cidade, int ultima_estrela, int msc_atual, int& msc_max, const vector<int>& estrelas, vector<bool>& visitado, const vector<list<int>>& adj) {
    // Update the maximum star count
    msc_max = max(msc_max, msc_atual);
    visitado[cidade] = true;  // Mark the current city as visited

    for (int vizinha : adj[cidade]) {
        // Check if the neighboring city hasn't been visited and satisfies the star condition
        if (!visitado[vizinha] && estrelas[vizinha - 1] > ultima_estrela) {
            dfs(vizinha, estrelas[vizinha - 1], msc_atual + 1, msc_max, estrelas, visitado, adj);
        }
    }

    visitado[cidade] = false;  // Backtrack (unvisit the current city)
}

int main() {
    int N;
    cin >> N;

    vector<int> estrelas(N);
    for (int i = 0; i < N; ++i) {
        cin >> estrelas[i];
    }

    vector<list<int>> adj(N + 1);

    // Read edges and construct the adjacency list
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_count = 0;
    vector<bool> visitado(N + 1, false);

    // Start DFS from every node
    for (int inicio = 1; inicio <= N; ++inicio) {
        dfs(inicio, estrelas[inicio - 1], 1, max_count, estrelas, visitado, adj);
    }

    cout << max_count << endl;

    return 0;
}
