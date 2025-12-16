#include<bits/stdc++.h>
using namespace std;

struct dur {
    int l ,r;

    bool operator<(const dur &a) {
        return r < a.r;
    }
};

int main() {
    int movnum , cmembs;
    cin >>movnum >> cmembs;

    vector<dur> movies(movnum);
    for(auto &x : movies) {
        cin >> x.l >> x.r;
    }

    sort(movies.begin(), movies.end());
    multiset<int> finish;
    int non_active = cmembs;
    int answer = 0;
    for(auto &x: movies) {
        if(!finish.empty() && *finish.begin() <= x.l) {
            finish.erase(prev(finish.upper_bound(x.l)));
            finish.insert(x.r);
            answer++;
        }
        else if(non_active > 0) {
            finish.insert(x.r);
            non_active--;
            answer++;
        }
    }

    cout << answer << endl;
}