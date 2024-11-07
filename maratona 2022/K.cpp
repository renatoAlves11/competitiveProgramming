#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<pair<int, int>> pulos;
int k;

int solve(int x, int e, vector<vector<int>> &values,
          vector<vector<bool>> &ready) {
  if (e > k) {
    return 0;
  }
  if (x == 1) {
    return 1;
  }
  if (x < 1) {
    return 0;
  }
  if (ready[x][e]) {
    return values[x][e];
  }
  int sum = 0;
  for (pair<int, int> i : pulos) {
    sum += solve(x - i.first, e + i.second, values, ready)%1000000000;
  }
  ready[x][e] = true;
  values[x][e] = sum;
  return sum;
}

int main() {
  int n, m;
  cin >> n >> m >> k;
  // vector<bool> ready(n + 1, false);
  // unordered_map<pair<int, int>, int> values(n + 1, 0);
  vector<vector<bool>> ready(n+1, vector<bool>(k, false));
  vector<vector<int>> values(n+1, vector<int>(k, 0));

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    pulos.push_back({a, b});
  }
  int sum = solve(n, 0, values, ready);
  cout << sum;
  return 0;
}