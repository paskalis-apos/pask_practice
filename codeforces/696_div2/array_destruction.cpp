#include<bits/stdc++.h>
using namespace std;

void solve_case() {
    int arrsize;
    cin >> arrsize;
    arrsize *= 2;

    multiset<int> numbers;
    for(int i = 0;i < arrsize; i++) {
        int temp;
        cin >> temp;
        numbers.insert(temp);
    } 

    for(multiset<int>::iterator it = numbers.begin();it != prev(numbers.end()); it++) {
        multiset<int> tempnumbers = numbers;
        tempnumbers.erase(tempnumbers.find(*it));
        tempnumbers.erase(prev(tempnumbers.end()));

        vector<pair<int,int>> moves(arrsize / 2);
        bool valid = true;
        moves[0].first = *it;
        moves[0].second = *prev(numbers.end());
        int movescounter = 1;

        int sum = *it + *prev(numbers.end());
        int tempsum = *prev(numbers.end());

        while(! tempnumbers.empty()) {
            int v = tempsum - *prev(tempnumbers.end());
            if(tempnumbers.find(v) == tempnumbers.end() || tempnumbers.find(v) == prev(tempnumbers.end())) {
                valid = false;
                break;
            }
            else {
                tempsum = *prev(tempnumbers.end());
                moves[movescounter].first = *prev(tempnumbers.end());
                moves[movescounter].second = v;
                tempnumbers.erase(tempnumbers.find(moves[movescounter].first));
                tempnumbers.erase(tempnumbers.find(moves[movescounter].second));
                movescounter++;
            }
        }

        if(valid) {
            cout << "YES" <<endl;
            cout << sum << endl;
            for(auto &x : moves) {
                cout << x.first << " " << x.second << endl;
            }
            return;
        }
        

    }

    cout << "NO" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve_case();
    }
}