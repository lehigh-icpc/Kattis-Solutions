/*
Evan Hruskar
minorsetback
2019-03-28 23:32:20
0.12 s
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    size_t n;
    cin >> n;

    string printStyle1[] = {"A", "Bb", "B", "C", "C#", "D", "Eb", "E", "F", "F#", "G", "Ab"};
    //next one is only in F#minor case
    string printStyle2[] = {"A", "Bb", "B", "C", "C#", "D", "Eb", "E", "F", "F#", "G", "G#"};


    bool pitchSeen[12];
    bool fullType[5][12] = {{1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0},
                            {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0},
                            {0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1},
                            {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
                            {1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0}};
        
    vector<int> indexList(n);

    for(size_t i = 0; i < n; i++)
    {
        double raw;
        cin >> raw;
        raw = 12*log2(raw/440.0);
        //if (raw < 0) raw += 12; //if it's negative, just add 12.
        //now round to int
        int index = (int) round(raw) % 12; //unsafe cast?
        if (index < 0) index += 12; //idk
        // cout << "index: " << index << endl;
        pitchSeen[index] = true;
        indexList[i] = index; //for printing later.
    }

    bool keyType[5];
    int possKeys = 5;
    for(size_t i = 0; i < 5; i++)
    {
        keyType[i] = true; //assume true.
        for(size_t j = 0; j < 12; j++)
        {
            //only check 0 cases. 1 cases might just not have shown up.
            if (fullType[i][j] == 0 && pitchSeen[j] == 1) {
                keyType[i] = false;
                possKeys -= 1; //we lost a key possibility.
                break;
            }
        }
    }

    if (possKeys != 1) {
        //if it has 0 or multiple possible keys
        cout << "cannot determine key" << endl;
        return 0;
    }

    //now find the right key and print it.
    if (keyType[0]) {
        //G major
        cout << "G major" << endl;
        //print list.
        for (int index : indexList) {
            cout << printStyle1[index] << endl;
        }
    } else if (keyType[1]) {
        //G major
        cout << "C major" << endl;
        //print list.
        for (int index : indexList) {
            cout << printStyle1[index] << endl;
        }
    } else if (keyType[2]) {
        //G major
        cout << "Eb major" << endl;
        //print list.
        for (int index : indexList) {
            cout << printStyle1[index] << endl;
        }
    } else if (keyType[3]) {
        //G major
        cout << "F# minor" << endl;
        //print list.
        for (int index : indexList) {
            cout << printStyle2[index] << endl;
        }
    } else if (keyType[4]) {
        //G major
        cout << "G minor" << endl;
        //print list.
        for (int index : indexList) {
            cout << printStyle1[index] << endl;
        }
    }
    return 0;
}
