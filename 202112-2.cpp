// http://118.190.20.162/home.html
#include <bits/stdc++.h>
#define u64 uint64_t
using namespace std;

u64 n, N, r, err;

int h(int i) {
    if (i < 0) return 0;
    return r * ((i+1)/r-1) * ((i+1)/r) / 2 + (i+1)%r*(i/r);
}

int cal(int fi, int li, int ri) {
    int sum2 = (ri - li + 1) * fi;
    int sum1 = h(ri) - h(li-1);
    return abs(sum1 - sum2);
}

int main() {
    cin >> n >> N;
    r = N / (n + 1);

    vector <u64> A = {0};
    for (int i = 0; i < n; i++) {
        u64 t;
        cin >> t;
        A.push_back(t);
    }

    A.push_back(N);

    for (int fi = 0; fi <= n; fi ++ ) {
        int li = A[fi], ri = A[fi+1]-1;
        // cout << li << ' ' << ri << endl;
        if (li/r>=fi || ri/r <= fi) {
            err += cal(fi,li,ri);
            // cout << "here1" << err << endl;
        }
        else {
            err += cal(fi,li,r*fi) + cal(fi,r*fi+1,ri);
            // cout << "here2" << err << endl;
        }
    }
    
    cout << err << endl;


    // for (size_t i = 0; i < 9; i++)
    // {
    //     cout << h(i) << " ";
    // }
    
    return 0;
}