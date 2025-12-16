#include<bits/stdc++.h>
using namespace std;
set<int> m;
vector<int> LDS;
vector<int> ans;
bool stop;
int n;
int qnum;

void ask() {
    cout << "? " << m.size() << " ";
    for(auto &x : m) {
        cout << x << " ";
    } 
    cout << endl;
    cout.flush();
}

void print_ans() {
    cout << "! " ;
    for(auto &x : ans){ 
        cout << x << " ";
    }
    cout << endl;
    cout.flush();
}

void check_ans() {
    int c;
    cin >> c;
    if(c > n){ 
        for(int i = 0;i < c ;i++) {
            int num;
            cin >> num;
            if(i <= n){ 
                ans.push_back(num);
            }
        }
        print_ans();
        stop = true;
        return;
    }
    for(int i = 0;i < c ;i++) {
        int num;
        cin >> num;
        LDS[num] = qnum;
        m.erase(num);
    }
}

void solve() {
    ans.clear();
    cin >> n;
    stop = false;
    m.clear();
    for(int i =1 ;i <= n * n + 1; i++) {
        m.insert(i);
    }

    LDS.assign(n * n + 2, 0);
    for(qnum = 1;qnum <= n && !stop; qnum++){ 
        ask();
        check_ans();
    }
    if(stop) {
        return;
    }

    for(auto &x : LDS){ 
        if(x == 0) {
            x = n + 1;
        }
    }

    int ind = n * n + 1;
    for(int i = n + 1; i > 0; i--) {
        while(LDS[ind] != i) {
            ind--;
        }
        ans.push_back(ind);
    }

    reverse(ans.begin(), ans.end());
    print_ans();
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}