/*
Evan Hruskar
pokerhand
2019-02-11 16:34:15
0.00 s
*/

#include<iostream>
#include<string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    int max = 0;
    int newMax = 0;
    for (int i = 0; i < input.size(); i+=3) {
        char candidate = input.at(i);
    //cout << candidate << endl;
        newMax = 0;
        for (int j = 0; j < input.size(); j+=3) {
            if (input.at(i) == input.at(j)) {
                newMax++;
        //cout << "newmax " << newMax << endl;
            }
        }
        //cout << newMax;
    //cout << "newMax " << newMax << " Max " << max << endl;
    if (newMax > max) {
        //cout << candidate << endl;
            max = newMax;
        }
    }
    cout << max;
    return 0;
}
