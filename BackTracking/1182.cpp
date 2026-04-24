#include <iostream>
using namespace std;
int N, S, num[20], cnt = 0;
bool check[20];
//멱집합 문제
void powerset(int k) // k번째 원소를 결정
{
	if (k == N) { //N개의 원소를 결정 완료했을 때
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (check[i]) sum += num[i]; // 내가 쓰기로 한 원소일 경우에만 계산
		}
		if (sum != S) return; // 합이 안맞으면 리턴
		cnt++;
		return;
	}
	check[k] = false; // 이 원소를 안 씀
	powerset(k + 1);
	check[k] = true; // 이 원소를 씀
	powerset(k + 1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++)cin >> num[i];
	powerset(0);
	if (S == 0) cnt--; // S가 하필 0인 경우, sum = 0으로 두고 체크하니 필요함
	cout << cnt;
}
