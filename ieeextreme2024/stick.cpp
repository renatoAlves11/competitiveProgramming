#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

long long area(int N, int K, int L) {
    vector<pair<long long,long long>> supEsquerdo(N+1);
    vector<pair<long long,long long>> supDireito(N+1);
    vector<long long> areas(N+1, 0);
    areas.push_back(0);
    for(int i = 1; i < N+1; i ++){
        supEsquerdo[i].first = (i * K - L);
        supEsquerdo[i].second = (i * K - L);
        supDireito[i].first = (i * K + L);
        supDireito[i].second = (i * K + L);
        //pair<long long,long long> aux = {supDireito[i].first - supEsquerdo[i].first, supDireito[i].second - supEsquerdo[i].second};
        long long lado = supDireito[i].first - supEsquerdo[i].first;
        long long area = lado * lado;
        if(i == 1){
            areas[i] = area;
        }
        else if((supDireito[i-1].first - supEsquerdo[i].first) > 0){
            long long a = supDireito[i-1].first - supEsquerdo[i].first;
            long long b = supEsquerdo[i].second - supEsquerdo[i-1].second;
            b = lado - b;
            long long areaAux = a*b;
            if(areaAux < 0){
                areaAux = -areaAux;
            }
            areas[i] = area - areaAux;
        }
        else{
            areas[i] = area;
        }
    }
    long long total = 0;
    for(int i = 1; i <= N+1; i++){
        total += areas[i];
    }
    return total;
}

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    cout << area(N, K, L) << endl;
    return 0;
}
