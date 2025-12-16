#include<bits/stdc++.h>
using namespace std;

vector<string>layout(3);
set<set<char>>winners[4];

void insert(vector<pair<int,int>> coordinates) {
    set<char>contained;
    for(auto &p : coordinates) {
        contained.insert(layout[p.first][p.second]);
    }
    winners[contained.size()].insert(contained);
}



int main() {

    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout); 

    for(int i = 0 ; i < 3 ;i++) { cin >> layout[i];}

    for(int i = 0 ;i < 3; i++){insert ( {{0 , i}, {1 , i}, {2 , i}} );}
    for(int j = 0; j < 3; j++){insert ( {{j , 0}, {j , 1}, {j ,2 }}); }
    insert({{0,0}, {1,1}, {2,2}});
    insert({{2,0}, {1,1}, {0,2}});


    cout << winners[1].size() << endl;
    cout << winners[2].size() << endl;



}