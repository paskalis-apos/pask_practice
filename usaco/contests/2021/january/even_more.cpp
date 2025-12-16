#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int odds = 0;
    int evens = 0;
    for(int i = 0;i < n ;i++) {
        int temp;
        cin >> temp;
        if (temp % 2 == 0) {
            evens++;
        }
        else {
            odds++;
        }
    }
    int answer;
    if(evens >= odds) {
        answer = odds * 2;
        if(evens > odds) {
            answer++;
        }
    }
    else {
        answer = evens * 2 + ((odds - evens) * 2) / 3;
        if((odds - evens) % 3 == 1) {
            answer--;
        }
    }

    cout << answer << endl;
}