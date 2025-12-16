#include<bits/stdc++.h>
using namespace std;

vector<int> p(1e6 + 5);
vector<int> maxel(1e6 + 5);
vector<int> cr(1e6 + 5);

int get(int a){
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}

void unite(int a , int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return;
    }
    if(cr[a] < cr[b]) {
        swap(a , b);
    }
    if(cr[a] == cr[b]) {
        cr[a]++;
    }
    maxel[a] = max(maxel[a], maxel[b]);
    p[b] = a;
}

int find_max(int a) {
    a = get(a);
    return maxel[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 0;i < 1e6 + 5; i++) {
        p[i] = i;
        maxel[i] = i;
    }
    for(int i = 0 ;i < m;i++) {
        char c;
        cin >> c;
        if(c == '-') {
            int x;
            cin >> x;
            x--;
            unite(x, x + 1);
        }
        else {
            int x;
            cin >> x;
            x--;
            int cur = find_max(x);
            cur++;
            if(cur > n) {
                cout << -1 << endl;
            }
            else {
                cout << cur << endl;
            }
        }
    }
}