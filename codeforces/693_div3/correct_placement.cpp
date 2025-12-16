#include<bits/stdc++.h>
using namespace std;

struct person {
    int first , second , num;
};

bool comp(person a , person b) {
    return a.first < b.first;
}

void make_pref(vector<pair<int,int>> &pref, vector<person> &friends, int n) {
    pref[0].first = INT_MAX;
    person temp;
    temp.first = -1;
    temp.second = INT_MAX;
    for(int i = 1; i <= n; i++) {
        if(friends[i].first > temp.first) {
            pref[i].first = temp.second;
            pref[i].second = temp.num;
        }
        else { 
            pref[i] = pref[i - 1];
        }

        if(friends[i].second < temp.second) {
            temp = friends[i];
        }
    }
}

void solve_case() {
    int n;
    cin >> n;
    vector<person> friends(n + 1);
    for(int i =1 ; i <= n; i++) {
        int a ,b;
        cin >> a >> b;
        friends[i].num = i;
        friends[i].first = min(a, b);
        friends[i].second = max(a, b);
    }
    sort(friends.begin(), friends.end(), comp);
    vector<pair<int,int>> pref(n + 1);
    make_pref(pref, friends, n);

    vector<int> ans(n + 1);

    for(int i = 1; i <= n; i++) {
        if(pref[i].first < friends[i].second) {
            ans[friends[i].num] = pref[i].second;
            continue;
        }
        else {
            ans[friends[i].num] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0;i < t; i++){
        solve_case();
    }
}