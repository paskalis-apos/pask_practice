#include<bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(size * 2, 0);
    }
    void add(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){ 
            add(i , v , 2 * x + 1, lx ,m);
        }
        else {
            add(i , v , 2 * x + 2, m , rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void add(int i, int v) {
        add(i , v , 0 , 0 , size);
    }

    int sum(int l , int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        int s1 = sum(l , r , 2 * x + 1, lx , m);
        int s2 = sum(l , r , 2 * x + 2, m , rx);
        return s1 + s2;
    }
    int sum(int l, int r) {
        return sum(l ,r , 0 , 0, size);
    }
};

vector<int> total;
int find(int v) {
    return lower_bound(total.begin(), total.end(), v) - total.begin();
}

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> sals(n);
    vector<pair<pair<char,int>, int>> queries(q);
    for(auto &x : sals) {
        cin >> x;
        total.push_back(x);
    }
    for(auto &x : queries) {
        cin >> x.first.first >> x.first.second >> x.second;
        if(x.first.first == '!') {
            total.push_back(x.second);
        }
    }
    sort(total.begin(), total.end());
    int newsize = unique(total.begin(), total.end()) - total.begin();
    total.resize(newsize);
    segtree st;
    st.init(total.size());
    for(auto &x : sals) {
        st.add(find(x), 1);
    }

    for(auto &x : queries) {
        if(x.first.first == '!') {
            int k , v;
            k = x.first.second;
            v = x.second;
            k--;
            st.add(find(v), 1);
            st.add(find(sals[k]), -1);
            sals[k] = v;
        }
        else {
            int a, b;
            a = x.first.second;
            b = x.second;
            auto ita = lower_bound(total.begin(), total.end(), a);
            auto itb = upper_bound(total.begin(), total.end(), b);
            if(ita == total.end() || itb == total.begin()) {
                cout << 0 << endl;
                continue;
            }
            itb--;
            a = find(*ita);
            b = find(*itb) + 1;
            cout << st.sum(a , b) << endl;

        }
    }


}