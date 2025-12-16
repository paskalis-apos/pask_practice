#include<bits/stdc++.h>
using namespace std;

int n , k;
multiset<int>lowvals;
multiset<int>highvals;

void ins(int value) {
    if (lowvals.size() <= highvals.size()) {
        if(highvals.empty() || value > *highvals.begin()) {
            highvals.insert(value);
            value = *highvals.begin();
            highvals.erase(highvals.begin());
        }
        lowvals.insert(value);
    }
    else {
        if(value < *prev(lowvals.end())) {
            lowvals.insert(value);
            value = *prev(lowvals.end());
            lowvals.erase(prev(lowvals.end()));
        }
        highvals.insert(value);
    }
}

void ers(int value) {
    if(lowvals.find(value) != lowvals.end()) {
        lowvals.erase(lowvals.find(value));
    }
    else {
        highvals.erase(highvals.find(value));
    }
}

int median() {
    return *prev(lowvals.end());
}

int main() {
    cin >> n >> k;
    vector<int>v(n);
    for(auto &x : v) {
        cin >> x;
    }

    for(int i = 0 ;i< n ;i++) {
        if(i < k) {
            ins(v[i]);
            if(i == k - 1) {
                cout << median() << " ";
            }
            continue;  
        }   
        ers(v[i - k]);
        ins(v[i]);
        cout << median() << " ";
    }
}