/*
Evan Hruskar
lastfactorialdigit
2019-03-18 16:35:47
0.00 s
*/

#include <iostream>

using namespace std;

size_t factorial(size_t n) {
    size_t result = n;
    for(size_t i = 1; i < n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    size_t iterations;
    cin >> iterations;
    for(size_t i = 0; i < iterations; i++) {
        size_t input;
        cin >> input;
        size_t result = factorial(input);
        cout << result % 10 << endl;
    }
    return 0;
}
