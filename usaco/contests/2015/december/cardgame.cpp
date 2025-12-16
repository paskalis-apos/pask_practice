#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w", stdout);
    int totalcards;
    cin >> totalcards;

    vector<int>elsie_first_half(totalcards / 2);
    vector<int>elsie_second_half(totalcards / 2);
    set<int>bessie_first_half;
    set<int>bessie_second_half;
    set<int> bessiecards;
    for(int i = 1 ;i <= 2 * totalcards; i++) {
        bessiecards.insert(i);
    }

    for(auto &x: elsie_first_half) {
        cin >> x;
        bessiecards.erase(x);
    }
    for(auto &x : elsie_second_half) {
        cin >> x;
        bessiecards.erase(x);
    }
    multiset<int>::iterator it = bessiecards.begin();
    while(int(bessie_second_half.size()) < totalcards / 2) {
        bessie_second_half.insert(*it);
        it++;
    }
    while(int(bessie_first_half.size()) < totalcards / 2) {
        bessie_first_half.insert(*it);
        it++;
    }
    
    sort(elsie_first_half.begin(), elsie_first_half.end());
    sort(elsie_second_half.begin(), elsie_second_half.end());

    int answer = 0;
    for(int i = 0 ;i < int(elsie_first_half.size()); i++) {
        if(bessie_first_half.upper_bound(elsie_first_half[i]) != bessie_first_half.end()) {
            answer++;
            bessie_first_half.erase(bessie_first_half.upper_bound(elsie_first_half[i]));
        }
        else {
            bessie_first_half.erase(bessie_first_half.begin());
        }
    }
    for(int i = 0 ;i < int(elsie_second_half.size()); i++) {
        if(bessie_second_half.upper_bound(elsie_second_half[i]) != bessie_second_half.begin()) {
            answer++;
            bessie_second_half.erase(prev(bessie_second_half.upper_bound(elsie_second_half[i])));
        }
        else {
            bessie_second_half.erase(prev(bessie_second_half.end()));
        }
    }

    cout << answer;
}