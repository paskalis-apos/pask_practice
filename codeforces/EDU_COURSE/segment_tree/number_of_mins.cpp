#include<bits/stdc++.h>
using namespace std;

struct segtree {
    vector<pair<int,int>> mins;
    int size;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        mins.assign(2 * size, {1e9 + 1, 0});
    }

    void set(int i , int v , int x , int lx , int rx) {
        if(rx - lx == 1) {
            mins[x].first = v;
            mins[x].second = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i , v , 2 * x + 1, lx , m);
        }
        else {
            set(i , v , 2 * x + 2, m , rx);
        }
        if(mins[2 * x + 1].first == mins[2 * x + 2].first) {
            mins[x].first = mins[2 * x + 1].first;
            mins[x].second = mins[2 * x + 1].second + mins[2 * x + 2].second;
        }
        else {
            mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
        }
    }
    void set(int i, int v) {
        set(i , v , 0 , 0 , size);
    }
    pair<int,int> find_min(int l , int r , int x , int lx, int rx) {
        if(lx >= r || rx <= l) {
            return {1e9 + 1, 0};
        }
        else if (lx >= l && rx <= r) {
            return mins[x];
        }
        int m = (lx + rx) / 2;
        pair<int,int> s1 = find_min(l , r , 2 * x + 1, lx , m);
        pair<int,int> s2 = find_min(l , r , 2 * x + 2, m , rx);
        pair<int,int> send;
        send = min(s1 , s2);
        if(s1.first == s2.first) {
            send.second = s1.second + s2.second;
        }
        return send;
    }
    pair<int,int> find_min(int l , int r) {
        return find_min(l , r , 0 , 0, size);
    }
};

int main() {
    int n ,  m;
    segtree st;
    cin >> n >> m;
    st.init(n);

    for(int i = 0; i < n ;i++) {
        int val;
        cin >> val;
        st.set(i , val);
    }
    for(int i = 0 ;i < m ;i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int i , v;
            cin >> i >> v;
            st.set(i , v);
        }
        else {
            int l , r;
            cin >> l >> r;
            pair<int,int> answer = st.find_min(l , r);
            cout << answer.first << " " << answer.second << endl;
        }
    }
}