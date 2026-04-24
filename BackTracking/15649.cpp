#include <iostream>
using namespace std;
int num[8]; // 실제 수열
bool check[8]; // 사용한 숫자인지 체크
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
		if (!check[i-1]) {
			check[i - 1] = true;
			num[n] = i;
			func(n + 1);
			check[i - 1] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0);
}
