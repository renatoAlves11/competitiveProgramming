#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

long long distancia(pair<int, int> &a, pair<int, int> &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long long estabilidade(vector<int> &triunvirato, vector<pair<int, int>> &pontos) {
    long long dists[3];
    dists[0] = distancia(pontos[triunvirato[0]], pontos[triunvirato[1]]);
    dists[1] = distancia(pontos[triunvirato[0]], pontos[triunvirato[2]]);
    dists[2] = distancia(pontos[triunvirato[1]], pontos[triunvirato[2]]);
    
    long long max_dist = *max_element(dists, dists + 3);
    long long min_dist = *min_element(dists, dists + 3);
    
    return max_dist - min_dist;
}

void encontrarTriunviratos(int n, vector<pair<int, int>> &pontos, vector<vector<int>> &triunviratos) {
    vector<int> idxs(n);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [&pontos](int a, int b) { return tie(pontos[a].first, pontos[a].second) < tie(pontos[b].first, pontos[b].second); });

    for (int i = 0; i < n; i += 3) {
        vector<int> triunvirato = {idxs[i], idxs[i + 1], idxs[i + 2]};
        triunviratos.push_back(triunvirato);
    }
}

int main() {
    int n;
    vector<pair<int, int>> pontos;
    cin >> n;
    pontos.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> pontos[i].first >> pontos[i].second;
    }
    vector<vector<int>> triunviratos;
    encontrarTriunviratos(n,pontos,triunviratos);
    
    for (auto &triunvirato : triunviratos) {
        cout << triunvirato[0] << " " << triunvirato[1] << " " << triunvirato[2] << endl;
    }

    return 0;
}
