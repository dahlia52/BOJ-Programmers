// 아기 상어
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
int n;

// 이동 방향
int dr[4] = {-1, 1, 0, 0};  // 좌, 우, 상, 하
int dc[4] = { 0, 0, -1, 1 };

// 최적의 물고기 한 마리를 찾아 먹고 시간 계산
pair<int, pi> eatFish(vector<vector<int>> &room, pi &pos, int shark_size){
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq; // min heap (최적의 경로를 찾도록 정렬)
    
    vector<vector<int>> dist(n,vector<int>(n,0)); // 이동한 거리를 0으로 초기화
    queue<pi> q; // 위치 (r,c)
    
    dist[pos.first][pos.second] = 1; // 살아남은 시간
    q.push(pos); 
    
    while (!q.empty()){
        pi curr = q.front(); // 현재 위치
        q.pop();
        
        for (int dir = 0; dir < 4; dir++){ // BFS
            pi next = {curr.first+dr[dir], curr.second+dc[dir]}; // 다음 위치
            if (next.first >= 0 and next.first < n and next.second >= 0 and next.second < n){
                // 이미 지나간 길이면 -> 지나갈 수 없음
                if (dist[next.first][next.second]){
                    continue;
                }
                // 자신보다 큰 물고기가 있다면 -> 지나갈 수 없음
                if (room[next.first][next.second] > shark_size){
                    continue;
                }
                // 먹이 후보 물고기를 우선순위 큐에 push
                if (room[next.first][next.second] and room[next.first][next.second] < shark_size){
                    pq.push({dist[curr.first][curr.second], next});
                    continue;
                }
                dist[next.first][next.second] = dist[curr.first][curr.second] + 1; // 현재 이동 거리 + 1
                q.push(next);
            }
        }
    }
    if (pq.empty()){
        return {-1, {-1, -1}};
    }
    room[pq.top().second.first][pq.top().second.second] = 0; // 조건에 맞는 물고기 먹기
    return pq.top(); // 살아남은 시간, 상어의 좌표를 리턴
}

void survive(vector<vector<int>> &room, pi pos){
    int shark_size = 2, cnt = 0, ans = 0;
    room[pos.first][pos.second] = 0;
    
    while (1){
        pair<int, pi> target_fish = eatFish(room, pos, shark_size);
        
        if (target_fish.first == -1){ // 엄마 상어에게 도움 요청
            break; 
        }
        cnt++; // 물고기 먹기
        ans += target_fish.first; // 시간 증가
        
        if (cnt == shark_size){ // 상어의 크기와 같은 수의 물고기를 먹음
            cnt = 0;
            shark_size++; // 상어 크기 키우기
        }
        pos = target_fish.second; // 상어 위치 이동
    }
    cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vector<vector<int>> room(n, vector<int>(n, 0));
	pi pos; // 아기상어 위치

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> room[i][j];
			if (room[i][j] == 9) {
				pos = { i,j }; // 아기상어 위치
			}
		}
	}
	survive(room, pos);
}