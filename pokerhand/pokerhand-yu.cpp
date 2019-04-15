#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main() {
    string in[5];
    cin >> in[0];
    cin >> in[1];
    cin >> in[2];
    cin >> in[3];
    cin >> in[4];
    int max = 0;
    int temp = 1;
    char c;
    for(int x = 0; x < 5; x++) {
        c = in[x][0];
        for(int y = x + 1; y < 5; y++) {
            if(c == in[y][0]) {
                temp++;
            }
        }
        if(temp > max) {
            max = temp;
        }
        temp = 1;
    }
    printf("%i", max);
	return 0;
}
