// 톱니바퀴
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int top[5] = { 0 }; // 각 톱니바퀴에서 12시 번호
int top_ch[5] = { 0 }; // 바뀐 12시 번호
vector<bool> visited;

// 이웃한 두 톱니바퀴가 서로 다른 극을 가리키는가
bool isDiff(vector<vector<int>>& gear, int left, int right) {
	if (gear[left][(top[left] + 2) % 8] != gear[right][(top[right] + 6) % 8]) {
		return true;
	}
	return false;
}

void solution(vector<vector<int>>& gear, int num, int dir) {
	visited[num] = true; // num번 톱니바퀴 영향 반영
	top_ch[num] = (((top_ch[num] - dir) % 8) + 8) % 8; // 시계 방향으로 회전(dir = 1), 반시계 방향으로 회전 (dir = -1)

	if (num == 1) { // 1번 톱니바퀴
		if (!visited[2] and isDiff(gear, 1, 2)) { // 2번 톱니바퀴와 다른 극이면
			solution(gear, 2, -dir); // 2번 바퀴도 움직임
		}
	}
	else if (num == 2) { // 2번 톱니바퀴
		if (!visited[1] and isDiff(gear, 1, 2)) {
			solution(gear, 1, -dir); // 1번 바퀴도 움직임
		}
		if (!visited[3] and isDiff(gear, 2, 3)) { // 3번 영향력 계산
			solution(gear, 3, -dir);
		}
 	}
	else if (num == 3) { // 3번 톱니바퀴
		if (!visited[2] and isDiff(gear, 2, 3)) {
			solution(gear, 2, -dir);
		}
		if (!visited[4] and isDiff(gear, 3, 4)) { // 4번 영향력 계산
			solution(gear, 4, -dir);
		}
	}
	else { // 4번 톱니바퀴
		if (!visited[3] and isDiff(gear, 3, 4)) { // 3번 영향력 계산
			solution(gear, 3, -dir); // 3번 바퀴도 움직임
		}
	}
}

int main() {
	int k, num, dir, sum = 0;
	char input;
	vector<vector<int>> gear(5, vector<int>(8, 0));

	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> input;
			gear[i][j] = input - '0';
		}
	}
	cin >> k;
	while (k--) {
		cin >> num >> dir;
		visited.assign(5, false);
		solution(gear, num, dir);

		for (int i = 1; i <= 4; i++) {
			top[i] = top_ch[i];
 		}
	}
	for (int i = 1; i <= 4; i++) {
		sum += gear[i][((top[i] % 8)+8)%8]*pow(2,i-1);
	}
	cout << sum;
}