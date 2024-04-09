#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
typedef pair<int, int> pi;

int parent[MAX] = { -1 };
int visited[MAX] = { false };

void bfs(int k, int v) {
	queue<pi> q; // 현재 위치, 움직인 횟수 저장
	q.push({ v, 0 }); // 첫번째 원소 push

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == k) {
			cout << cnt << '\n';
			return;
		}

		if (cur * 2 < MAX) {
			if (!visited[cur * 2]) {
				visited[cur * 2] = true;
				q.push({ cur * 2, cnt + 1 });
				parent[cur * 2] = cur;
			}
		}
		if (cur + 1 < MAX) {
			if (!visited[cur + 1]) {
				visited[cur + 1] = true;
				q.push({ cur + 1, cnt + 1 });
				parent[cur + 1] = cur;
			}
		}
		if (cur - 1 >= 0) {
			if (!visited[cur - 1]) {
				visited[cur - 1] = true;
				q.push({ cur - 1, cnt + 1 });
				parent[cur - 1] = cur;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	bfs(k, n);
	vector<int> result;

	while (1) {
		result.push_back(k);
		if (k == n) {
			break;
		}
		k = parent[k]; // 거슬러 올라가기
	}
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << ' ';
	}
}