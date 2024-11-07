#include <iostream>
#include <cmath>
using namespace std;


int main() {
    long long N;
    cin >> N;
    
    if (N == 0) {
        cout << -1;
        return 0;
    }
    
    if ( N < 0) {
        cout << -1;
        return 0;
    }


    int result = log(N)/log(3);
    float teste = pow(3, (log(N)/(float)log(3)));
    
    if ( (N - teste) == 0) {
        cout << -1;
        return 0;
    }
    
    
    cout << result+1 << endl;

    return 0;
}
