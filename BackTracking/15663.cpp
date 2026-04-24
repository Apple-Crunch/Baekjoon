#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, num[8];
bool isused[8]; // 완전 같은 숫자 중복 방지
vector<int>V;
void func(int k)
{
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!isused[i]) {
			// 정렬이 되어있으니 V[i]와 V[i-1]만 비교해도 대부분의 중복 해결
			//isused[i-1]을 점검하면 예제2처럼 9가 두개인 상황에서는 나중에오는 9에서 수열을 만드는 것을 전부 거를 수 있음
			if (i > 0 && V[i] == V[i - 1] && isused[i-1] == false) continue;
			num[k] = V[i]; // k번째 칸에 넣기
			isused[i] = true;
			func(k + 1);
			isused[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		V.push_back(n);
	}
	sort(V.begin(), V.end());
	func(0);
}
