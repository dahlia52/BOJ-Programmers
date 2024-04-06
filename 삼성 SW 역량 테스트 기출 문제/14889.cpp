// 스타트와 링크
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n,start, link, min_cost = 100000000;

void backtrack(int person, int cnt, vector<vector<int>> &s, vector<int> &team){
    if (cnt == n/2){
        start = 0, link = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (team[i] == 0 and team[j] == 0)
                    start += s[i][j];
                else if (team[i] == 1 and team[j] == 1)
                    link += s[i][j];
            }
        }
        min_cost = min(min_cost, abs(link-start));
        return;
    }
    for (int i=person; i<n; i++){
        team[i] = 1; // link team 배정
        backtrack(i+1, cnt+1, s, team);
        team[i] = 0;
    }
}

int main(){
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n,0));
    vector<int> team(n,0);
    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> s[i][j];

    backtrack(0, 0, s, team);
    cout << min_cost;
}