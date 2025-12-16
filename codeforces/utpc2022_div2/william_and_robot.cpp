#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int arrsize;
    cin >> arrsize;

    vector<int> numbers(arrsize);
    multiset<int>sortnums;
    for(auto &x : numbers) {
        cin >> x;
        sortnums.insert(x);
    }

    multiset<int>want_to_take;
    multiset<int>want_robot_to_take;
    multiset<int> have_taken;

    for(multiset<int>::iterator it = prev(sortnums.end());; it--) {
        if(want_to_take.size()  < arrsize / 2) {
            want_to_take.insert(*it);
        }
        else{
            want_robot_to_take.insert(*it);
        }
        if(it == sortnums.begin()) {
            break;
        }
    }

    int myindex = 0;
    int robotindex = 0;

    while(want_to_take.size() > 0) {
        while(want_to_take.find(numbers[myindex]) == want_to_take.end()) {
            myindex++;
            continue;
        }
        have_taken.insert(numbers[myindex]);
        want_to_take.erase(want_to_take.find(numbers[myindex]));
        numbers[myindex] = -1;
        myindex++;

        while(numbers[robotindex] == -1) {
            robotindex++;
            continue;
        }
        if(want_to_take.find(numbers[robotindex]) == want_to_take.end()) {
            want_robot_to_take.erase(want_robot_to_take.find(numbers[robotindex]));
            numbers[robotindex] = -1;
        }
        else {
            if(numbers[robotindex] > *have_taken.begin()) {
                have_taken.erase(have_taken.begin());
                have_taken.insert(numbers[robotindex]);
            }
            want_to_take.erase(want_to_take.find(numbers[robotindex]));
            want_to_take.insert(*prev(want_robot_to_take.end()));
            want_robot_to_take.erase(prev(want_robot_to_take.end()));
            numbers[robotindex] = -1;
        }
        robotindex++;
    }

    ll sum = 0;
    for(auto &x : have_taken) {
        sum += x;
    }

    cout << sum << endl;

    
}