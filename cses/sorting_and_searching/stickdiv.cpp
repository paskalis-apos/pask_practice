#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int length , num;
    cin >> length >> num;
    multiset<int> sticks;
    for(int i = 0; i < num ;i++) {
        int temp;
        cin >>temp;
        sticks.insert(temp);
    }
    ll answer = 0;
    while(sticks.size() > 1) {
        int newpair = *sticks.begin() + *next(sticks.begin());
        sticks.erase(sticks.begin());
        sticks.erase(sticks.begin());
        sticks.insert(newpair);
        answer += newpair;
    }

    cout << answer;
}