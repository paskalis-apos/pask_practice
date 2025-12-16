#include<bits/stdc++.h>
using namespace std;

struct rect {
    int lx , ly , rx , ry;
};

int main() {
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    rect first , second;
    cin >> first.lx >> first.ly >> first.rx >> first.ry;
    cin >> second.lx >> second.ly >> second.rx >> second.ry;
    int start_rect = (first.rx - first.lx) * (first.ry - first.ly); 

    int takes_row = 0;
    int takes_column = 0;

    takes_row = min(second.rx, first.rx) - max(first.lx , second.lx);
    takes_column =  min(second.ry, first.ry) - max(first.ly , second.ly) ;
    takes_row = max(0 ,takes_row);
    takes_column = max(0 , takes_column);
    int answer = start_rect;
    if((takes_column == first.ry - first.ly && (second.lx <= first.lx || second.rx >= first.rx))|| (takes_row == first.rx - first.lx  && (second.ly <= first.ly || second.ry >= first.ry))) {
        answer -= takes_column * takes_row;
    }

    cout << answer << endl;

    
}