#include<bits/stdc++.h>
using namespace std;

int main() {
    int n1 , n2 , n3 , n4;
    cin >> n1;
    vector<vector<int>> v(5);
    v[1].resize(n1);
    for(auto &x : v[1]) {
        cin >> x;
    }
    cin >> n2;
    v[2].resize(n2);
    for(auto &x : v[2]) {
        cin >> x;
    }
    cin >> n3;
    v[3].resize(n3);
    for(auto &x : v[3]) {
        cin >> x;
    }
    cin >> n4;
    v[4].resize(n4);
    for(auto &x : v[4]) {
        cin >> x;
    }

    for(auto &x : v) {
        sort(x.begin(), x.end());
    }
    int final1, final2, final3, final4;



    int ind1 = 0;
    int ind2 = 0;
    int ind3 = 0;
    int ind4 = 0;
    int mindiff = INT_MAX;
    while(ind1 < n1 && ind2 < n2 && ind3 < n3 && ind4 < n4) {
        int num1 = v[1][ind1];
        int num2 = v[2][ind2];
        int num3 = v[3][ind3];
        int num4 = v[4][ind4];

        vector<pair<int,int>> temp;
        temp.push_back({-1 , -1});
        temp.push_back({num1 , 1});
        temp.push_back({num2, 2});
        temp.push_back({num3, 3});
        temp.push_back({num4, 4});
        sort(temp.begin(), temp.end());
        if(temp[4].first - temp[1].first < mindiff) {
            final1 = num1;
            final2 = num2;
            final3 = num3;
            final4 = num4;
            mindiff = temp[4].first - temp[1].first;
        }
        int ind ;
        if(temp[1].second == 1) {
            ind1++;
        }
        else if(temp[1].second == 2){
            ind2++;
        }
        else if(temp[1].second == 3) {
            ind3++;
        }
        else {
            ind4++;
        }
    }

    cout << final1 << " " << final2 << " " << final3 << " " << final4 << endl;

}