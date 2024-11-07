#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int buscaBinariaInsercao(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    int size, lazerA, lazerB, areaTotal = 1;
    vector<int> valuesAU, valuesAR, valuesBU, valuesBL;
    cin >> size >> lazerA >> lazerB;
    for (int i = 0; i < lazerA; i++){
        char aux1;
        int aux2;
        cin >> aux1;
        cin >> aux2;
        if(aux1 == 'U'){
            valuesAU.push_back(aux2);
        }
        else{
            valuesAR.push_back(aux2);
        }
        areaTotal++;
    }
    int areaAux = areaTotal;
    sort(valuesAU.begin(), valuesAU.end());
    if(valuesAU.size() + valuesAR.size() == 0){
        for(int i = 0; i < lazerB; i++){
            areaTotal++;
        }
    }
    else{
    for (int i = 0; i < lazerB; i++){
        char aux1;
        int aux2;
        cin >> aux1;
        cin >> aux2;
        if(aux1 == 'L'){
            areaTotal += areaAux;
        }
        else{
            int qt = valuesAR.size();
            int n = buscaBinariaInsercao(valuesAU, aux2);
            int total = valuesAU.size() - n;
            
            qt = qt + total + 1;
            areaTotal += qt;
        }
    }
    }
    cout << areaTotal;
}