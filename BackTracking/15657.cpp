#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[8]; // 출력할 수열
vector<int> number; // 수를 입력받을 수열
int N, M;
void func(int n) // n은 현재까지 수열에 넣은 수의 갯수
{
	if (n >= 2) { 
		if (num[n - 2] > num[n - 1]) return; // 수열 내 수 중복 허용이니 >
	}
	if (n == M) {//길이 m에 달하는 수열 완성 시
		for (int i = 0; i < n; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {// 수열 내 수 중복 허용이니 >
		num[n] = number[i];
		func(n + 1);
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
		number.push_back(n);
	}
	sort(number.begin(), number.end());
	func(0);
}
