#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> V;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, ans = 0;
	cin >> N;
	V.resize(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	sort(V.begin(), V.end());
	for (int i = 0; i < N; i++) ans += V[i] * (N - i); // i번 째 사람들의 시간이 N-i번 만큼 반복되니까 그만큼 곱해서 계산
	cout << ans;
}
