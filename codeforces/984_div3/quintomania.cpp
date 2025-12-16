#include<bits/stdc++.h>
using namespace std;

void check_melody() {
    int n;
    cin >> n;

    int interval;
    int prev;
    cin >> prev;
    bool correct = true;
    for(int i = 1; i < n ;i ++) {
        int temp;
        cin >> temp;
        interval = abs(temp - prev);
        if(interval != 5 && interval != 7) {
            correct = false;
        }
        prev = temp;
    }
    if(correct) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
int main() {
    int t;
    cin >> t;
    for(int i =0 ;i < t ;i ++) {
        check_melody();
    }

}