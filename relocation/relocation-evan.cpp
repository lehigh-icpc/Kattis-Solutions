/*
Evan Hruskar
relocation
2019-03-18 17:22:37
0.10 s
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t n, q;
    cin >> n >> q;

    vector<int> points(n); //index is id - 1
    for(size_t i = 0; i < n; i++)
    {
        cin >> points[i];
    }

    //now do operations
    for(size_t i = 0; i < q; i++)
    {
        int type, op1, op2;
        cin >> type >> op1 >> op2;
        
        if (type == 1) {
            points[op1 - 1] = op2;
        }
        else {
            cout << abs(points[op1 - 1] - points[op2 - 1]) << endl;
        }
    }
    return 0;
}
