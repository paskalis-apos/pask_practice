#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    int rects, topaint;
    cin >> rects >> topaint;

    vector<vector<int>> barn(1002, vector<int>(1002));

    for(int i = 0 ;i < rects; i++) {
        int x1 , y1 ,x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++;
        y1++;

        barn[y1][x1]++;
        barn[y1][x2+1]--;
        barn[y2+1][x1]--;
        barn[y2+1][x2+1]++;
    }
    int answer = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1 ;j <= 1000; j++) {
            barn[i][j] += barn[i-1][j] + barn[i][j-1] - barn[i-1][j-1];
                if(barn[i][j] == topaint) {
                    answer++;
                }
            
        }
    }
    cout << answer <<endl;
}