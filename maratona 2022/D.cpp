#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n, xfinal, yfinal;
  cin >> n >> xfinal >> yfinal;
  int x0 = pow(2, n - 1);
  int y0 = pow(2, n - 1);
  pair<int, int> atratores[4] = {
      {0, 0}, {0, pow(2, n)}, {pow(2, n), 0}, {pow(2, n), pow(2, n)}};

  int resposta = 0;

  while (x0 != xfinal && y0 != yfinal) {
    resposta++;
    int tempx = xfinal - x0;
    int tempy = yfinal - y0;

    if (x0 == xfinal && y0 == yfinal) {
      break;
    }

    if (tempx <= 0 && tempy <= 0) {
      x0 = (x0 + atratores[0].first) / 2;
      y0 = (y0 + atratores[0].second) / 2;
      continue;
    }
    if (tempx >= 0 && tempy <= 0) {
      x0 = (x0 + atratores[1].first) / 2;
      y0 = (y0 + atratores[1].first) / 2;
      continue;
    }
    if (tempx <= 0 && tempy >= 0) {
      x0 = (x0 + atratores[2].first) / 2;
      y0 = (y0 + atratores[2].first) / 2;
      continue;
    }
    if (tempx >= 0 && tempy >= 0) {
      x0 = (x0 + atratores[3].first) / 2;
      y0 = (y0 + atratores[3].first) / 2;
      continue;
    }
  }
  cout << resposta;

  return 0;
}