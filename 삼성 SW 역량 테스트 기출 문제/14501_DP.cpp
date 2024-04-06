// 퇴사 - Dynamic Programming
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pi;

//i일까지 받은 금액 저장
int solution(int n, vector<pi> &meeting){
    int max_cost = 0;
    vector<int> dp(n+1,0);
    for (int i = 1; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i]);
        if ((i+meeting[i].first-1) > n)
            continue;
        dp[i+meeting[i].first-1] = max(dp[i+meeting[i].first-1], dp[i-1]+meeting[i].second);
    }
    for (int i=1;i<=n; i++){
        max_cost = max(max_cost, dp[i]);
    }
    return max_cost;
}

int main(){
    int n, t, p;
    
    cin >> n;
    vector<pi> meeting(n+1, {0,0});
    
    for (int i = 1; i<=n; i++){
        cin >> t >> p;
        meeting[i] = {t,p};
    }
    cout << solution(n, meeting);
}