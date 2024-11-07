#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> tijolos(N);
    
    for (int i = 0; i < N; i++) {
        cin >> tijolos[i];
    }

    sort(tijolos.rbegin(), tijolos.rend());

    vector<vector<int>> pilhas;

    while (!tijolos.empty()) {
        vector<int> pilha;
        pilha.push_back(tijolos[0]);
        tijolos.erase(tijolos.begin());

        for (int i = 0; i < tijolos.size();) {
            int topo = pilha.back();
            if (tijolos[i] + x <= topo) {
                pilha.push_back(tijolos[i]); 
                tijolos.erase(tijolos.begin() + i);
            } else {
                i++;
            }
        }

        pilhas.push_back(pilha);
    }

    cout << pilhas.size() << endl;

    for (auto& p : pilhas) {
        cout << p.size() << " ";
        for (int tijolo : p) {
            cout << tijolo << " ";
        }
        cout << endl;
    }

    return 0;
}