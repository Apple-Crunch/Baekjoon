#include <iostream>
using namespace std;
int num[8]; // 출력할 수열
int N, M;
void func(int n) // n은 현재까지 수열에 넣은 수의 갯수
{
	if (n == M) {//길이 m에 달하는 수열 완성 시
		for (int i = 0; i < n; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
    //답지에서 나온 것
	int st = 1; // 시작지점, k = 0일 때에는 st = 1
	if (n != 0) st = num[n - 1] + 1; // k != 0일 경우 st = arr[k-1]+1
	for (int i = st; i <= N; i++) {
		num[n] = i; // k번째 수를 i로 정함
		func(n + 1); // 다음 수를 정하러 한 단계 더 들어감
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0);
}
