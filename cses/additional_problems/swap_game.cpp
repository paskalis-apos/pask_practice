#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll vector_to_num(vector<int> v) {
    ll num = 0;
    ll curmult = 1e8;
    for(int i = 0;i < 9 ;i++) {
        num += v[i] * curmult;
        curmult /= 10;
    }
    return num;
}

vector<int> num_to_vector(ll num) {
    ll curdiv = 1e8;
    vector<int> v;
    for(int i = 0;i < 9; i++) {
        v.push_back(num / curdiv);
        num %= curdiv;
        curdiv /= 10;
    }
    return v;
}

int main( ){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> nums(9);
    for(auto &x : nums) {
        cin >> x;
    }
    ll num = vector_to_num(nums);
    unordered_map<ll, int> dist;
    dist[num] = 0;
    queue<ll> q;
    q.push(num);
    while(!q.empty()) {
        ll curnum = q.front();
        q.pop();
        vector<int> cur = num_to_vector(curnum);
        for(int i = 0;i < 8; i++) {
            if(cur[i] == 0) {
                cout << "here" << endl;
            }
            vector<int> v = cur;
            swap(v[i], v[i + 1]);
            ll temp = vector_to_num(v);
            if(dist[temp] == 0 && temp != num) {
                dist[temp] = dist[curnum] + 1;
                q.push(temp);
            }   
            if(i > 5 ) {
                continue;
            }
            swap(v[i], v[i + 1]);
            swap(v[i], v[i + 3]);
            temp = vector_to_num(v);
            if(dist[temp] == 0 && temp != num) {
                dist[temp] = dist[curnum] + 1;
                q.push(temp);
            }
        }
    }
    cout << dist[123456789] << endl;
}