#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>>V;
bool compare(pair<int, int> a, pair<int, int>b) {
	if(a.second != b.second) return a.second < b.second; // 끝나는 시간이 이른 순서
	return a.first < b.first; // 끝나는 시간이 같으면 시작 시간이 빠른 순서
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, cnt = 0;
	pair<int, int> cur;
	cin >> N;
	V.resize(N);
	for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
	sort(V.begin(), V.end(), compare);
	cur = V[0];
	cnt++;
	for (int i = 1; i < N; i++) {
		if (V[i].first >= cur.second) { // 다음 회의와 현재 회의 시간이 엇갈리지 않을 때
			cur = V[i];
			cnt++;
		}
	}
	cout << cnt;
}
