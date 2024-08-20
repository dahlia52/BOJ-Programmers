#include<vector>
#include <queue>
#define MAX 10000
using namespace std;
typedef pair<int, int> pi;
int dr[4] = {0,0,-1,1}; // 행
int dc[4] = {1,-1,0,0}; // 열

int solution(vector<vector<int> > maps){
    int n = maps.size();
    int m = maps[0].size();
    int answer = MAX;
    vector<vector<int>> visited(n, vector<int>(m, MAX));
    queue<pi> q; // x, y
    q.push({0,0});
    visited[0][0] = 1;
    while (!q.empty()){
        pi node = q.front();
        q.pop();
        int nr = node.first;
        int nc = node.second;
        if (nr == n-1 and nc == m-1){
            answer = visited[n-1][m-1];
            break;
        }
        for (int i = 0; i < 4; i++){
            if (nr+dr[i]>=0 and nr+dr[i] < n and nc+dc[i]>=0 and nc+dc[i]<m and maps[nr+dr[i]][nc+dc[i]] == 1 and visited[nr+dr[i]][nc+dc[i]] > visited[nr][nc] + 1){
                q.push({nr+dr[i], nc+dc[i]});
                visited[nr+dr[i]][nc+dc[i]] = visited[nr][nc] + 1;
            }
        }
    }
    if (answer == MAX){
        answer = -1;
    }
    return answer;
}