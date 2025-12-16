#include<bits/stdc++.h>
using namespace std;

int main() {
    int strsize;
    cin >> strsize;
    
    string str;
    cin >> str;

    int max_score = 0;
    int min_score = 0;

    char prev = str[0];
    bool onedif = false;

    for(int i = 1 ;i < strsize; i++) {
        int counter = 0;
        while(str[i] == 'F' && i < strsize) {
            counter++;
            i++;
        }
        if(counter != 0) {
            if(i == strsize) {
                i--;
                max_score += counter;
                min_score += 0;
                onedif = true;
                continue;
            }
            if(prev == 'F' ) {
                onedif = true;
                max_score += i + 1;
                min_score += 0;
            }
            else if(prev == str[i]) {
                max_score += counter + 1;
                min_score += 1 - counter % 2;
            }
            else {
                max_score += counter;
                min_score += counter % 2;
            }
        }
        else {
            if(prev == 'F') {
                onedif = true;
                max_score++;
            }
            else if(prev == str[i]) {
                max_score++;
                min_score++;
            }
            
        }
        prev = str[i];
    }
    int possib;
    possib = max_score - min_score;
    if(!onedif) {
        possib /= 2;
    }
    possib++;
    cout << possib << endl;

    if(onedif) {
        while(min_score <= max_score) {
            cout << min_score << endl;
            min_score++;
        }
    }
    else {
        while(min_score <= max_score) {
            cout << min_score << endl;
            min_score += 2;
        }
    }
}