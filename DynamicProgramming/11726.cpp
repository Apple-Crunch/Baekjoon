#include <iostream>
using namespace std;
long long int S[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	S[0] = 1; // n = 1 2x1도형 1개
	S[1] = 2; // n = 2 2x1 도형 2개 or 1x2도형 2개
	S[2] = 3; // n = 3 1x2 1개 2x1 2개 2종류 1x2 3개
	//S[3] = 5 S[n-1]은 S[n-2]에 1x2칸을 더 넣거나 S[n-3]에 2x1칸들을 넣는 경우의 수의 합
	for (int i = 3; i <= n; i++) 
		S[i] = (S[i - 1] + S[i - 2]) % 10007;// 숫자가 너무 커져서
	cout << S[n-1];
}
