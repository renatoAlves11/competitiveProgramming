#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    vector<long long> lazy; // Array para armazenar atualizações pendentes
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0; // Inicializa com 0
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Soma dos filhos
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) { // Verifica se há atualizações pendentes
            tree[node] += lazy[node] * (end - start + 1); // Aplica a atualização

            if (start != end) { // Não é uma folha
                lazy[2 * node + 1] += lazy[node]; // Propaga para o filho esquerdo
                lazy[2 * node + 2] += lazy[node]; // Propaga para o filho direito
            }

            lazy[node] = 0; // Limpa a atualização pendente
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        propagate(node, start, end); // Propaga atualizações pendentes

        if (start > end || start > r || end < l) return; // Fora do intervalo

        if (start >= l && end <= r) { // Totalmente dentro do intervalo
            tree[node] += val * (end - start + 1); // Aplica a atualização
            if (start != end) { // Não é uma folha
                lazy[2 * node + 1] += val; // Propaga a atualização para os filhos
                lazy[2 * node + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Atualiza a soma
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end); // Propaga atualizações pendentes

        if (start > end || start > r || end < l) return 0; // Fora do intervalo
        if (start >= l && end <= r) return tree[node]; // Totalmente dentro do intervalo

        int mid = (start + end) / 2;
        long long sumLeft = queryRange(2 * node + 1, start, mid, l, r);
        long long sumRight = queryRange(2 * node + 2, mid + 1, end, l, r);
        return sumLeft + sumRight; // Soma os resultados das subárvores
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n, 0); // Inicializa o lazy com 0
        build(0, 0, n - 1);
    }

    void update(int l, int r, long long val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    long long query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};

int main() {
    int n, eventos, a, b, c;
    cin >> n >> eventos;
    vector<int> permutations(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> permutations[i];
    }

    SegmentTree segTree(n + 1); // Árvore de segmentos para A[1] a A[n]

    for(int i = 0; i < eventos; i++) {
        int option;
        cin >> option;

        switch(option) {
            case 0: // Tipo 0: Atualização direta
                cin >> a >> b >> c;
                segTree.update(a, b, c);
                break;
                
            case 1: // Tipo 1: Atualização por permutação
                cin >> a >> b >> c;
                for(int j = a; j <= b; j++) {
                    segTree.update(permutations[j], permutations[j], c);
                }
                break;

            case 2: // Tipo 2: Soma direta
                cin >> a >> b;
                cout << segTree.query(a, b) << endl;
                break;

            case 3: // Tipo 3: Soma por permutação
                cin >> a >> b;
                long long total = 0;
                for(int j = a; j <= b; j++) {
                    total += segTree.query(permutations[j], permutations[j]);
                }
                cout << total << endl;
                break;
        }
    }
    return 0;
}