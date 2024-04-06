// 퇴사 - DFS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pi;

int max_cost = 0;

void dfs(int n, int v, int cost, vector<pi> &meeting){
    if (v-1 > n){
        return;
    }
    max_cost = max(max_cost, cost);
    
    for (int i=v; i<=n; i++){
        dfs(n, i+meeting[i].first, cost+meeting[i].second, meeting);
    }
}

int main(){
    int n, t, p;
    
    cin >> n;
    vector<pi> meeting(n+1, {0,0});
    
    for (int i = 1; i<=n; i++){
        cin >> t >> p;
        meeting[i] = {t,p};
    }
    dfs(n, 1, 0, meeting);
    cout << max_cost;
}