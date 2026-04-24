#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long int> V;
//정렬로 풀기
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, cnt = 1, cnt_max = 1; // cnt는 현재 카운트 cnt_max는 최고 카운트
	long long int num;  // 가장 작은 수를 보내야하니까 min, 비교용 pivot 사용
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		V.push_back(num);
	}
	sort(V.begin(), V.end());
	long long int pivot = V[0], min = V[0];
	for (int i = 1; i < N; i++) {
		if (pivot == V[i]) { // 많이 보유하면 cnt가 늘고 cnt_max인게 가장 많이 가진 정수
			cnt++;
			if (cnt > cnt_max) {
				cnt_max = cnt;
				min = V[i];
			}
		}
		else {
			cnt = 1; // 다른 정수를 포함해야 하니까 1로 초기화
			pivot = V[i];
		}
	}
	cout << min;
}
