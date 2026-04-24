#include <iostream>
using namespace std;
int num[8]; // 출력할 수열
int N, M;
void func(int n) // n은 현재까지 수열에 넣은 수의 갯수
{
	if (n >= 2) { // 여기서 앞의 자리 수보다 작은 수를 넣은 경우를 걸러냄
		if (num[n - 2] >= num[n - 1]) return;
	}
	if (n == M) {//길이 m에 달하는 수열 완성 시
		for (int i = 0; i < n; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = n; i < N; i++) { // {1,2}가 있는데 {2,1}은 불가 넣은 갯수를 가리키는 n부터 넣어보면 {2,1}같은 거 넣을 일 없음
		num[n] = i + 1;
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
