/*
Evan Hruskar
heirsdilemma
2019-02-17 20:24:47
0.02 s
*/

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void printVector(vector<int> vec) {
    for(size_t i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << ", ";
    }
    cout << endl;
    
}

int main() {
    int low, high;
    cin >> low >> high;
    vector<int> lowvec;
    
    //six, non-zero decimal digits
    //all unique
    //the number is divisible by each of its digits.

    //1, 2, 3, 4, 5, 6, 7, 8, 9
    //5 odd, 4 even (6 digit num must be even)

    //first, switch to an even number if odd.
    if (low % 2 != 0) {
        low++;
    }

    int count = 0;
    
    while (low <= high) {
        bool zero = false;
        bool unique = true;
        bool divisible = true;
        int jump = 2; //no odd numbers allowed
        int zeroJump = 1;

        lowvec.clear();
        for(size_t i = 1; i <= 100000; i*=10) {
            int digit = (low / i) % 10;
            if (digit == 0) {
                zero = true;
                if (i == 1) {
                    //special case for ones place.
                    zeroJump = 2;
                } else {
                    zeroJump *= i;
                }
                break;
            }
            lowvec.push_back(digit);
        }

        //printVector(lowvec);

        //if we have a zero, skip ahead the apporopriate amount.
        if (zero) {
            low += zeroJump;
            continue;
        }

        //check uniqueness
        for(size_t i = 0; i < lowvec.size() && unique; i++) {
            for(size_t j = i + 1; j < lowvec.size() && unique; j++) {
                if (lowvec.at(i) == lowvec.at(j)) {
                    unique = false;
                }
            }
        }
        
        //check divisibility
        for(size_t i = 0; i < lowvec.size() && divisible; i++)
        {
            if (low % lowvec.at(i) != 0) {
                divisible = false;
            }
        }

        if (divisible && unique) {
            count++;
        }
        //cout << "div: " << divisible << " uniq: " << unique << endl;
        low += jump;
    }
    cout << count;
}
