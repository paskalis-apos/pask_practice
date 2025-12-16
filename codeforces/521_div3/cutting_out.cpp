#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> elements(2 * 1e5 + 10);
vector<int> answer;
int n , k;

bool valid(int mid) {
    int length = 0;
    for(auto &x : elements) {
        length += x.first / mid;
        if(x.first / mid == 0) {
            break;
        }
        for(int i = 0 ;i < x.first / mid && answer.size() < k; i++) {
            answer.push_back(x.second);
        }
    }

    if(length >= k) {
        return true;
    }
    return false;

}

int main () {
    cin >> n >> k;

    for(int i = 0 ; i < n ;i++) {
        int temp;
        cin >> temp;
        elements[temp].first++;
        elements[temp].second = temp;
    }
    sort(elements.rbegin(), elements.rend());

    int l = 1;
    int r = 1e6;
    while(l < r) {
        answer.clear();
        int mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    answer.clear();

    valid(l);
    for(auto &x: answer) {
        cout << x <<" ";
    }
    cout << endl;

}