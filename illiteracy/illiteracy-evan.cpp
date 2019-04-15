/*
Evan Hruskar
illiteracy
2019-03-17 21:48:14
2.98 s
*/

#include <iostream>
#include <string>
#include <queue> //necessary?
#include <unordered_map>
#include <string>

using namespace std;

// A, B, C, D, E, F
void rotate(string &data, size_t index) {
    char &letter = data[index];
    if (letter >= 'F') {
        letter = 'A';
    } else {
        letter++;
    }
}

int main() {
    string original;
    string target;
    getline(cin, original); //default delim is newline
    getline(cin, target);

    unordered_map<string, int> explored;
    queue<string> frontier;

    //initiialize map and queue
    explored.insert(make_pair(original, 0));
    frontier.push(original);

    while (!frontier.empty()) {
        string exploreParent = frontier.front();
        frontier.pop();
        if (exploreParent == target) {
            cout << explored[exploreParent] << endl;
            return 0;
        }
        

        //explore this item
        for (int i = 0; i < exploreParent.size(); i++) {
            string candidate = exploreParent;
            char character = candidate[i];
            //Check every possible char:
            if (character == 'A') {
                if (i == 0) {
                    rotate(candidate, 1);
                }
                else if (i == 7) {
                    rotate(candidate, 6);
                }
                else {
                    rotate(candidate, i - 1);
                    rotate(candidate, i + 1);
                }
            }
            else if (character == 'B') {
                if (i != 0 && i != 7) {
                    candidate[i + 1] = candidate[i - 1];
                }
            }
            else if (character == 'C') {
                rotate(candidate, 7 - i);
            }
            else if (character == 'D') {
                if (i <= 3) {
                    //rotate everything to left
                    for (int j = 0; j < i; j++) {
                        rotate(candidate, j);
                    }
                }
                else if (i >= 4) {
                    //rotate everything on right
                    for (int j = i + 1; j < 8; j++) {
                        rotate(candidate, j);
                    }
                }
            }
            else if (character == 'E') {
                if (i != 0 && i != 7) {
                    int dist = 0;
                    if (i <= 3) {
                        dist = i;
                    }
                    else if (i >= 4) {
                        dist = 7 - i;
                    }
                    rotate(candidate, i - dist);
                    rotate(candidate, i + dist);
                }
            }
            else if (character == 'F') {
                //just for this problem :(
                int index = i + 1;
                if (index % 2 == 0) {
                    rotate(candidate, (index / 2) - 1);
                }
                else {
                    rotate(candidate, ((index + 9) / 2) - 1);
                }
            }

            //check uniqueness (want directed acyclic graph)
            //cout << candidate << endl;

            auto findIter = explored.find(candidate);
            if (findIter == explored.end()) {
                int lastCost = explored.at(exploreParent);
                explored.insert(make_pair(candidate, lastCost + 1));
                frontier.push(candidate);
            }
        }
    }
}
