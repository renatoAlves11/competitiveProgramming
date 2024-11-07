#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    priority_queue<pair<int,int>> substancias;
    cin >> n;
    if(n==0){
        cout << -100 << " " << -100;
        return 0;
    }
    int geladeira1;
    int geladeira2;
    int contador = 0;
    for(int i = 0; i< n; i++){
        int t1, t2;
        cin >> t1 >> t2;
        substancias.push({t1,t2});
    }
    if(n==1){
        geladeira1 = substancias.top().first;
        geladeira2 = -100;
    }
    else{
    geladeira1 = substancias.top().first;
    substancias.pop();
    geladeira2 = substancias.top().first;
    while(!substancias.empty()){
        substancias.pop();
        if(geladeira2 > substancias.top().second){
            geladeira2 = substancias.top().first;
            if(n == 3){
                contador ++;
            }
            if(contador == 1){
                cout << -1;
                return 0;
            }
            contador++;
        }
    }
    }
    cout << geladeira2 << " " << geladeira1;
    
    return 0;
}