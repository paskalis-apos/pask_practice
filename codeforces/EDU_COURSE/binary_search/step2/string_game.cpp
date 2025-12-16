#include<bits/stdc++.h>
using namespace std;
string t , p;
vector<int> order;

bool works(int num) {
    string temp = t;
    for(int i =0  ;i < num ;i++) {
        temp[order[i] ] = '0';
    }
    int counter = 0;
    int i = 0;
    while(counter < p.size()) {
        if(temp[i] == p[counter]) {
            counter++;
        }
        if(i == t.size()) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    cin >> t >> p;
    
    order.resize(t.size()) ;
    for(int i = 0 ;i < order.size() ;i++) {
        cin >> order[i];
        order[i]--;
    }

    int r = t.size() ;
    int l = 0;

    while (r - l > 1) {
        int mid = (r + l) / 2;
        if(works(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << l;

}