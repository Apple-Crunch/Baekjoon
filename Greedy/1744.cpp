#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> V;
bool compare(const int& a, const int& b)
{
	if (a > 0 || b > 0) return a > b;
	else if (a < 0 && b < 0) return a < b; // 같은 음수면 절댓값 순서 정렬 밑의 계산 알고리즘에서 최대 구하기 위함
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, ans = 0;
	cin >> N;
	V.resize(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	sort(V.begin(), V.end(), compare); // 내림차 순 정렬
	for (int i = 0; i < N; i++) {
		if (i + 1 < N) { // 2개 이상 살필 수 있을 때
			if (V[i] * V[i + 1] > V[i] + V[i + 1]) { // 곱했을 때 더 커질 수 있다면
				ans += V[i] * V[i + 1];
				i++;
			}
			else {
				ans += V[i];
			}
		}
		else {
			ans += V[i]; // 2개 이상 살필 수 없는 경우
		}
	}
	cout << ans;
}
