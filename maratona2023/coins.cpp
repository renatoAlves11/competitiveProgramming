#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int qtdMoedas(vector<int> moedas, int troco){
    int best = 1000;
    if(troco < 0){
        return best;
    }
    if(troco == 0){
        return 0;
    }
    for(int i : moedas){
    best = min(best, qtdMoedas(moedas, troco-(moedas[i])) + 1);    
    }
    return best;
}

int main(){
    int n, troco;
    cin >> troco;
    cin >> n;
    vector<int> moedas;
    for (int i = 0; i < n; i++){
        int m; 
        cin >> m;
        moedas.push_back(m);
    }
    int resposta = qtdMoedas(moedas, troco);
    cout << resposta;
    return 0;
}