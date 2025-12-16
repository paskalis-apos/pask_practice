#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj;
vector<int> steps;


void find_circles(int ind) {
    stack<int> s;
    vector<bool> nowvisited(n, false);
    while(!nowvisited[ind]) {
        if(steps[ind] != -1) {
            int cursteps = steps[ind] + 1;
            while(!s.empty()) {
                steps[s.top()] = cursteps;
                cursteps++;
                s.pop();
            }
            return;
        } 
        nowvisited[ind] = true;
        s.push(ind);
        ind = adj[ind];
    }

    vector<int> in_circle;
    int circlesize = 0;
    while(s.top() != ind) {
        in_circle.push_back(s.top());
        circlesize++;
        s.pop();
    }
    circlesize++;
    in_circle.push_back(ind);
    s.pop();
    for(auto &x : in_circle) {
        steps[x] = circlesize;
    }
    int curdist = circlesize + 1;
    while(!s.empty()) {
        steps[s.top()] = curdist;
        curdist++;
        s.pop();
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    steps.resize(n , -1);
    for(auto &x : adj) {
        cin >> x;
        x--;
    }
    for(int i = 0 ;i < n; i++) {
        if(steps[i] != -1) {
            continue;
        }
        find_circles(i);
    }

    for(auto &x : steps) {
        cout << x<<" ";
    }
    cout << endl;


}