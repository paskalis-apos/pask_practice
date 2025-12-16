#include<bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    map<int,vector<int>> num_to_ind; 
    vector<int> v(n);
    for(int i = 0;i < n; i++) {
        int num;
        cin >> num;
        v[i] = num;
        num_to_ind[num].push_back(i);
    }
    for(auto &x : num_to_ind) {
        x.second.push_back(n);
    }
    vector<int> sofaki(n + 1);
    vector<int> sofaki2(n);
    sofaki[n] = 0;

    for(int i = n -1;i >=0 ;i--) {
        if(num_to_ind[v[i] + 1].empty()) {
            sofaki[i] = 1;
            sofaki2[i] = n;
            continue;
        }
        int ind = *upper_bound(num_to_ind[v[i] + 1].begin(), num_to_ind[v[i] + 1].end() , i);
        sofaki[i] = sofaki[ind] + 1;
        sofaki2[i] = ind;
    }

    int maxind = 0;
    int maxlength = 0;
    for(int i = 0;i < n;i++) {
        if(sofaki[i] > maxlength) {
            maxlength = sofaki[i];
            maxind = i;
        }
    }

    cout << maxlength << endl;
    int ind = maxind;
    while(ind < n){
        cout << ind + 1<< " ";
        ind = sofaki2[ind];
    }

    

}