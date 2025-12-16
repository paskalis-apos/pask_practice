#include<bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> values;
    void init(int n){
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.resize(2 * size);
    }

    void set(int i, int v, int x , int lx, int rx) {
        if(rx - lx == 1){
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i , v, 2 * x + 1, lx, m);
        }
        else {
            set(i , v, 2 * x + 2, m , rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void set(int i , int v) {
        set(i, v , 0 ,0  , size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if(rx <= r && lx >= l) {
            return values[x];
        }
        if(rx <= l || lx >= r) {
            return 0;
        }
        int m = (lx + rx) / 2;
        int sum1 = sum(l, r, 2 * x + 1, lx, m);
        int sum2 = sum(l, r , 2 * x + 2, m , rx);
        return sum1 + sum2;
    }

    int sum(int l, int r) {
        return sum(l, r, 0 , 0, size);
    }

    int find_kth(int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            return lx;
        }
        int m = (rx + lx) / 2;
        if(values[2 * x + 1] >= v) {
            return find_kth(v , 2 * x + 1, lx, m);
        }
        else {
            if(values[2 * x + 1] + values[2 * x + 2] < v){ 
                return -1;
            }
            return find_kth(v -  values[2 * x + 1],2 * x + 2 ,m, rx);
        }
    }

    int find_kth(int v) {
        return find_kth(v, 0 , 0 , size);
    }
};

int main() {
    int q;
    cin >> q;
    vector<pair<char,int>> queries(q);
    vector<int> v;
    for(auto &x : queries) {
        cin >> x.first >> x.second;
        v.push_back(x.second);
    }

    sort(v.begin(), v.end());
    map<int,int> num_to_ind;
    for(int i = 0;i < v.size();i++) {
        num_to_ind[v[i]] = i;
    }

    segtree st;
    st.init(v.size());
    for(auto &x : queries) {
        if(x.first == 'I') {
            st.set(num_to_ind[x.second], 1);
        }
        else if(x.first == 'D') {
            st.set(num_to_ind[x.second], 0);
        }
        else if(x.first == 'K') {
            if(st.find_kth(x.second) == -1) {
                cout << "invalid" << endl;
            }
            else {
                cout << v[st.find_kth(x.second)] << endl;
            }
        }
        else {
            cout << st.sum(0, num_to_ind[x.second]) << endl;
        }
    }
}