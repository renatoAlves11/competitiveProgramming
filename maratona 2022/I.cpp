#include <iostream>
using namespace std;

int main() {
  int num[8];
  string resposta;
  for (int i = 0; i < 8; i++) {
    cin >> num[i];
  }
  for (int i = 0; i < 8; i++) {
    if (num[i] == 9) {
      cout << "F";
      return 0;
    }
  }
  cout << "S";
  return 0;
}