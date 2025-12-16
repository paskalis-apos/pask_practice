#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(size * 2, 0);
    }

    void add(int i ,int v , int x , int lx , int rx)  {
        if(rx - lx == 1) {
            values[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            add(i , v , 2 * x + 1 , lx , m);
        }
        else{
            add(i , v, 2 * x + 2, m , rx);
        }
        values[x] = max(values[2 * x + 1] , values[2 * x + 2]);
    }
    void add(int i, int v) {
        add(i , v , 0 , 0, size);
    }

    int find_max(int l , int r, int x , int lx , int rx) {
        if(l >= rx || r <= lx) {
            return 0;
        }
        if(l <= lx && r >= rx) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        int s1 = find_max(l , r, 2 * x + 1, lx , m);
        int s2 = find_max(l , r ,2 * x + 2, m , rx);
        return max(s1 , s2);
    }   
    int find_max(int l , int r) {
        return find_max(l , r , 0 , 0, size);
    }
    int first_bigger(int v,int x, int lx, int rx) {
        if(rx - lx == 1 ) {
            if(values[x] < v) {
                return -1;
            }
            return lx;
        }
        int m = (lx + rx) / 2;
        if(find_max(lx, m) >= v) {
            return first_bigger(v, 2 * x + 1, lx, m);
        }
        else if(find_max(m, rx) >= v){
            return first_bigger(v, 2 * x + 2, m , rx);
        }
        else {
            return -1;
        }
    }   

    int first_bigger(int v) {
        return first_bigger(v,0, 0, size);
    }
};

int main() {
    int n , m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    for(int i = 0;i< n;i++) {
        int num;
        cin >> num;
        st.add(i, num);
    }
    for(int i = 0;i < m;i++) {
        int num;
        cin >> num;
        int hotel = st.first_bigger(num);
        cout << hotel + 1 << " ";
        if(hotel != -1) {
            st.add(hotel, -num);
        }
    }

    cout << endl;

}   