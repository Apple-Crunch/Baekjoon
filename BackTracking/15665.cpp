#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, num[8];
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
		// 정렬이 되어있으니 V[i]와 V[i-1]만 비교해도 대부분의 중복 해결
		if (i > 0 && V[i] == V[i - 1]) continue;
		num[k] = V[i]; // k번째 칸에 넣기
		func(k + 1);
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
