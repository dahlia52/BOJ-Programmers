// 감시
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
int n, m, min_cnt = 64;
vector<pi> cctv;

int dr[4] = { 0, -1, 0, 1 }; // 좌, 상, 우, 하
int dc[4] = { -1, 0, 1, 0 };

int check(vector<vector<int>> &room, int r, int c, int dir, int cnt) {
	dir %= 4;
	while (1) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		r = nr; c = nc; // 다음 탐색 위치
		if (nr < 0 or nc < 0 or nr >= n or nc >= m or room[nr][nc] == 6) { // 인덱스 범위 초과하거나 벽이면 종료
			return cnt;
		}
		if (room[nr][nc] != 0) { // CCTV가 있으면 통과
			continue;
		}
		if (room[nr][nc] != -1){
			room[nr][nc] = -1; // CCTV 감시 구역
			cnt--;
		}
	}
	return cnt;
}

void dfs(vector<vector<int>> &room, int v, int cnt) {
	if (v == cctv.size()) {
		min_cnt = min(min_cnt, cnt);
		return;
	}
	int r = cctv[v].first;
	int c = cctv[v].second;

	// 초기값 저장
	vector<vector<int>> temp(n, vector<int>(m, 0)); 
	copy(room.begin(), room.end(), temp.begin()); // 배열 복사
	int temp_cnt = cnt; // cnt(남은 감시구역) 복사

	for (int dir = 0; dir < 4; dir++) {
		if (room[r][c] == 1) { // 단방향 check
			cnt = check(room, r, c, dir, cnt);
		}
		else if (room[r][c] == 2) { // 양방향 check
			if (dir == 2 or dir == 3) { // 이미 탐색 완료
				return;
			}
			cnt = check(room, r, c, dir, cnt);
			cnt = check(room, r, c, dir + 2, cnt);
		}
		else if (room[r][c] == 3) {
			cnt = check(room, r, c, dir, cnt);
			cnt = check(room, r, c, dir + 1, cnt);
		}
		else if (room[r][c] == 4) {
			cnt = check(room, r, c, dir, cnt);
			cnt = check(room, r, c, dir + 1, cnt);
			cnt = check(room, r, c, dir + 2, cnt);
		}
		else if (room[r][c] == 5) {
			if (dir == 0) {
				cnt = check(room, r, c, dir, cnt);
				cnt = check(room, r, c, dir + 1, cnt);
				cnt = check(room, r, c, dir + 2, cnt);
				cnt = check(room, r, c, dir + 3, cnt);
			}
		}
		dfs(room, v + 1, cnt);

		// 초기화
		copy(temp.begin(), temp.end(), room.begin());
		cnt = temp_cnt;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> room(n, vector<int>(m, 0));
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] != 0 and room[i][j] != 6) {
				cctv.push_back({ i, j });
			}
			if (room[i][j] == 0) {
				cnt++;
			}
		}
	}

	dfs(room, 0, cnt);
	cout << min_cnt;
}