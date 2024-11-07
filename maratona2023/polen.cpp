#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int somadigitos(int polem){
    string pol = to_string(polem);
    int soma = 0;
    cout << "aqui";
    for(char i : pol){
        soma += (i - '0');
    }
    if((polem-soma) <= 0){
        return polem;
    }
    return soma;
}

int main(){
    vector<int> flores;
    int flo, qtdFlores = 0, gertrudeVez = 0, resultado;
    cin >> qtdFlores >> gertrudeVez;
    for(int i = 0; i < qtdFlores; i++){
        cin >> flo;
        flores.push_back(flo);
        cout << "aqui1" << endl;
    }
    for(int i = 0; i < gertrudeVez; i++){
        sort(flores.begin(), flores.end());
        resultado = somadigitos(flores[i]);
        flores[0] -= resultado;
        if(i == gertrudeVez-1){
            cout << resultado;
        }
    }
    return 0;
}