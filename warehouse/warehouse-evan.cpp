/*
Evan Hruskar
warehouse
2019-03-28 21:33:55
0.01 s
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <regex>

using namespace std;

//how would I use this for greater than sort?
bool compareLess(pair<string, int> &toy1, pair<string, int> &toy2) {
    if (toy1.second == toy2.second) {
        return toy1.first.compare(toy2.first) < 0;
    }
    return toy1.second > toy2.second;
}


int main() {
    int t;
    cin >> t;
    for (int iter = 0; iter < t; ++iter) {
        int n;
        cin >> n;
        map<string, int> input;
        for (int i =  0; i < n; ++i) {
            string name;
            int amt;
            // string input;
            // getline(cin, input);
            // input.
            cin >> name >> amt;
            if (input.count(name)) {
                input[name] += amt;
            } else {
                input.insert(make_pair(name, amt));
            }
        }

        vector<pair<string, int>> toys;

        for (const auto &item : input) {
            toys.push_back(item);
        }
        
        sort(toys.begin(), toys.end(), compareLess);

        cout << toys.size() << endl;
        for (auto pair : toys) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    return 0;
}
