#include <iostream>
#include <algorithm>
using namespace std;
int A[51], B[51];
bool compare(const int&a, const int&b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	//B의 가장 큰 수에 A의 가장 작은 수 곱하기를 반복하면?
	sort(B, B + N); // B를 정렬시킴
	sort(A, A + N, compare); // A는 B와 반대로 정렬
	for (int i = 0; i < N; i++) ans += A[i] * B[i];
	cout << ans;
}
