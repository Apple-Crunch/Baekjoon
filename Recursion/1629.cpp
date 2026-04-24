#include <iostream>
using namespace std;
long long func1(int a, int b, int c)
{
	if (b == 1) return a % c;
	long long val = func1(a, b / 2, c);
	//다 곱하고 나누면 숫자가 너무 큼 필요한건 C로 나눈 나머지 만큼만
	val = val * val % c;
	//b가 짝수가 아니면 한 번 더 곱해서 리턴
	if (b % 2 == 0) return val;
	return val * a % c;
}

int main()
{
	int A, B, C, ans = 0;
	cin >> A >> B >> C;
	cout << func1(A, B, C);
}
