#include<bits/stdc++.h>
using namespace std;

int garlength;
string startcolours;


int best_for_plan() {
    int repaint;
    char favcolour;
    cin >> repaint >> favcolour;

    int goodcolourblocks = 0;
    if(favcolour == startcolours[0]) {
        goodcolourblocks = 1;
    }
    int answer = 0;
    int l = 0;
    int r = 0;
    while(r < garlength) {
        if(repaint < r - l + 1 - goodcolourblocks) {
            if(startcolours[l] == favcolour) {
                goodcolourblocks--;
            }
            l++;
        }
        else {
            answer = max(answer , r - l + 1);
            r++;
            if(r < garlength && startcolours[r] == favcolour) {
                goodcolourblocks++;
            }
        }
    }

    return answer;
}

int main() {
    cin >> garlength;
    cin >> startcolours;
    int q;
    cin >> q;
    for(int i =0 ;i <q ;i++) {
        cout << best_for_plan() << endl;
    }
}