#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int bfs(int n, vector<vector<bool>> connection){
    vector<bool> visited(n+1, false);
    queue<int> q;
    
    visited[1] = true;
    q.push(1);
    int cnt = 1;
    
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (int i = 1; i<=n; i++){
            if (!visited[i] and connection[node][i]){
                cnt++;
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<bool>> connection(n+1, vector<bool>(n+1, false));
    int answer = 100;
    for (int i = 0; i < wires.size(); i++){
        connection[wires[i][0]][wires[i][1]] = true;
        connection[wires[i][1]][wires[i][0]] = true;
    }
    // i번째 연결을 끊으면
    for (int i = 0; i < wires.size(); i++){
        connection[wires[i][0]][wires[i][1]] = false;
        connection[wires[i][1]][wires[i][0]] = false;
        int cnt = bfs(n, connection);
        connection[wires[i][0]][wires[i][1]] = true;
        connection[wires[i][1]][wires[i][0]] = true;
        answer = min(answer, abs(n-2*cnt));
    }
    return answer;
}