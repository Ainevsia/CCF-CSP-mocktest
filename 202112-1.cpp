#include <iostream>

using namespace std;

int main(){
    int n, N;
    cin >> n >> N;
    int * A = new int [1+n+1];
    int * f = new int [Na];
    int idx = 0;

    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i+1];
    }

    A[0] = 0;
    A[n+1] = N;

    for (size_t cprize = 0; cprize < N; cprize++)
    {
        while (A[idx+1]<=cprize) idx ++;
        f[cprize] = idx;
    }

    // for (size_t i = 0; i < N; i++)
    // {
    //     cout << f[i] << ' ';
    // }

    int sum = 0;
    
    for (size_t i = 0; i < N; i++)
    {
        sum += f[i];
    }
    
    cout << sum;

    return 0;
}
