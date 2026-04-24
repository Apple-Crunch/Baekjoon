#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, lotto[13], num[6];
bool check[13];
//멱집합 문제
void powerset(int n, int m) // 사용여부를 결정한 수의 갯수, 사용하는 수의 갯수
{
	if (n > k)return;// 무한 루프 방지
	if (n == k && m == 6) {
		for (int i = 0; i < k; i++)
			if(check[i])cout << lotto[i] << " ";
		cout << "\n";
		return;
	}
	//이 수를 쓰는 경우
	check[n] = true;
	powerset(n + 1, m + 1);
	//이 수를 쓰지 않는 경우
	check[n] = false;
	powerset(n + 1, m);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	while (1) {
		if (k == 0)break;
		for (int i = 0; i < k; i++)cin >> lotto[i];
		powerset(0, 0);
		cout << "\n";
		cin >> k;
	}
}
