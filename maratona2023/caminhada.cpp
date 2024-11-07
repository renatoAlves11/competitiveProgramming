#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

void calcule(vector<int> &photos, vector<pair<int, int>> adjs, vector<int> like,
             int nodes) {
  for (int i = 1; i < nodes + 1; i++) {
    photos[i] = 0;
  }
  photos[1] = 1;
  for (int i = 1; i < nodes+1; i++) {
    for (pair<int, int> j : adjs) {
      int a, b;
      a = j.first;
      b = j.second;
      if (like[b] > like[a]) {
        photos[b] = max(photos[b], photos[a] + 1);
      } else
        photos[b] = max(photos[b], photos[a]);
    }
  }
}

int main() {
  int nodes, aux;
  cin >> nodes;
  vector<int> photos, like;
  vector<pair<int, int>> adjs;
  photos.push_back(0);
  like.push_back(0);
  for (int i = 2; i < nodes + 1; i++) {
    cin >> aux;
    if(aux > i){
      adjs.push_back({i, aux});
    }
    else adjs.push_back({aux,i});
  }
  for (int i = 1; i < nodes + 1; i++) {
    cin >> aux;
    like.push_back(aux);
  }
  calcule(photos, adjs, like, nodes);
  for (int i = 2; i < nodes + 1; i++) {
    cout << photos[i] << " ";
  }
}