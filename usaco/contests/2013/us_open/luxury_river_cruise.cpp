#include<bits/stdc++.h>
using namespace std;

int portsnum , dirnum, repetitions;
vector<pair<int,int>> rivers;
vector<int> adj;
vector<char> directions;
vector<bool> visited;
vector<int> ordered_circle;
vector<int> ordered_line;
int steps_before_circle = 0;
int circlelength = 0;



int ending_point(int ind) {
    for(auto &x : directions) {
        if(x == 'L'){
            ind = rivers[ind].first;
        }
        else {
            ind = rivers[ind].second;
        }
    }
    return ind;
}

void check_adj() {
    int ind = 0;
    stack<int> s;
    while(!visited[ind]) {
        visited[ind] = true;
        s.push(ind);
        ind = adj[ind];
    }
    while(s.top()!= ind) {
        ordered_circle.push_back(s.top());
        s.pop();
        circlelength++;
    }
    ordered_circle.push_back(s.top());
    s.pop();
    circlelength++;
    reverse(ordered_circle.begin(), ordered_circle.end());
    while(!s.empty()) {
        ordered_line.push_back(s.top());
        s.pop();
        steps_before_circle++;
    }
    reverse(ordered_line.begin(), ordered_line.end());
}

int main() {
    freopen("cruise.in","r",stdin);
    freopen("cruise.out", "w", stdout);
    cin >> portsnum >> dirnum >> repetitions;
    visited.resize(portsnum);
    adj.resize(portsnum);
    rivers.resize(portsnum);
    directions.resize(dirnum);
    for(auto &x : rivers) {
        cin >> x.first >> x.second;
        x.first--;
        x.second--;
    }

    for(auto &x : directions) {
        cin >> x;
    }


    for(int i = 0 ;i < portsnum ;i++) {
        adj[i] = ending_point(i);
    }
    
    check_adj();
    int answer;
    if(repetitions < steps_before_circle) {
        answer = ordered_line[repetitions];
    }
    else {
        int circleplace = (repetitions - steps_before_circle) % circlelength;
        answer = ordered_circle[circleplace];
    }
    answer++;

    cout << answer << endl;
    
}