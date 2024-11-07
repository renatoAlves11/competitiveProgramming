#include <iostream>
#include <unordered_map>
#include <vector>

void dfs(int no, std::vector<int> &valor,
         std::unordered_map<int, std::vector<int>> &lista_adj,
         std::vector<int> &resposta, std::vector<bool> &visitado,
         std::vector<int> &msc // MAIOR SUBSEQUENCIA CRESCENTE!
) {
  visitado[no] = true;
  // aqui eu processo td haver c o no!

  if (valor[no] > msc.back()) {    // ultimo elemento = maior elemento!
    msc.push_back(valor[no]);      // baguncando tudo
    resposta[no - 1] = msc.size(); // nao preciso da resposta do primeiro

    for (int filho : lista_adj[no]) {
      if (!visitado[filho]) {
        dfs(filho, valor, lista_adj, resposta, visitado, msc);
      }
    }
    msc.pop_back(); // desfaço o ultimo passo. limpei a bagunca
  } else {
    int idx = std::lower_bound(msc.begin(), msc.end(), valor[no]) - msc.begin();
    // BUSCA BINARIA (vetor ja ta ordenado)
    // retorna a posicao onde todos os elementos sao menores ou iguais que o
    // VALOR! subtraindo msc.begin() pra tirar o iterador -> indice!
    int aux = msc[idx]; // salvando o elemento, vai q da zebra

    resposta[no - 1] = msc.size();
    msc[idx] = valor[no];

    for (int filho : lista_adj[no]) {
      if (!visitado[no]) {
        dfs(filho, valor, lista_adj, resposta, visitado, msc);
      }
    }
    msc[idx] = aux;
  }
}

void solution(std::vector<int> &valor,
              std::unordered_map<int, std::vector<int>> &lista_adj,
              std::vector<int> &resposta) {
  std::vector<bool> visitado(valor.size(), false);
  std::vector<int> msc; // ou LIS -> longest increasing subsequence.

  visitado[0] = true;
  msc.push_back(valor[0]);
  for (auto &filho : lista_adj[0])
    dfs(filho, valor, lista_adj, resposta, visitado, msc);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> valor(n);
  std::vector<int> resposta(n - 1);
  std::unordered_map<int, std::vector<int>> lista_adj;

  lista_adj.reserve(n);

  for (int i = 1; i < n; i++) {
    int j;
    std::cin >> j;
    j--; // one based
    lista_adj[i].push_back(j);
    lista_adj[j].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    std::cin >> valor[i];
  }

  solution(valor, lista_adj, resposta);

  std::cout << resposta[0];
  for (int i = 1; i < n - 1; i++) {
    std::cout << " " << resposta[i];
  }
  std::cout << std::endl;

  return 0;
}