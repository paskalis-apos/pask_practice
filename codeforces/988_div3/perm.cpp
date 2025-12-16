#include<bits/stdc++.h>
using namespace std;

void solve_case() {
    int n;
    cin >> n;
    if(n < 5) {
        cout << -1 << endl;
        return;
    }
    vector<int> perm(n);
    int toput = n;
    if(n % 2 == 0) {
        toput--;
    }
    int counter = 0;
    while(counter <= (n - 1)/2) {
        if(toput == 5) {
            perm[counter] = 1;
        }
        else if(toput == 1) {
            perm[counter] = 5;
        }
        else {
            perm[counter] = toput;
        }
        toput -= 2;
        counter++;
    }
    toput = 2;

    while(counter < n) {
        if(toput == 2) {
            perm[counter] = 4;
        }
        else if(toput == 4) {
            perm[counter] = 2;
        }
        else {
            perm[counter] = toput;
        }
        toput+= 2;
        counter++;
    }

    for(auto &x : perm) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve_case();
    }
}