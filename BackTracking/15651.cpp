#include <iostream>
using namespace std;
int num[8]; // 실제 수열
int N, M;
void func(int n) // n은 현재까지 수열에 넣은 수의 갯수
{
	if (n == M) {//길이 m에 달하는 수열 완성 시
		for (int i = 0; i < n; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		num[n] = i;
		func(n + 1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0);
}
