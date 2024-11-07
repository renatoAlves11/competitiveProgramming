#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> ids_grupos(N + 1);
    vector<vector<int>> adj(N + 1);
    vector<int> grau_entrada(N + 1, 0); // QUANTAS ARESTAS TEM ESSE NO COMO DESTINO

    for (int i = 1; i <= N; ++i) {
        cin >> ids_grupos[i];
    }

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        grau_entrada[B]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prioridade;

    for (int projeto = 1; projeto <= N; ++projeto) {
        if (grau_entrada[projeto] == 0) {
            prioridade.push({ids_grupos[projeto], projeto});
        }
    }

    vector<int> resultado;

    while (!prioridade.empty()) {
        
        auto [id_grupo, projeto] = prioridade.top();
        prioridade.pop();
        resultado.push_back(projeto);

        
        for (int filho : adj[projeto]) {
            grau_entrada[filho]--;
            if (grau_entrada[filho] == 0) {
                prioridade.push({ids_grupos[filho], filho});
            }
        }
    }

    if (resultado.size() == N) {
        for (int projeto : resultado) {
            cout << projeto << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}