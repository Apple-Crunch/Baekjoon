#include <iostream>
#include <algorithm>
using namespace std;
int rope[100001];
bool compare(const int& a, const int& b)
{
	return a >= b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, k;
	long long int w, max_w = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> rope[i];
	sort(rope, rope + N, compare); //크기가 큰 순으로 정렬
	w = rope[0]; // 가장 무거운 로프를 안 쓸 리 없음
	k = 1;
	max_w = w;
	//로프에 가해지는 중량 = w / k이므로 가장 가벼운 로프 * k = w
	//w값이 제일 큰 거 찾기
	for (int i = 1; i < N; i++) {
		w = rope[i] * (k + 1);
		if (max_w < w) max_w = w;
		k++;
	}
	cout << max_w;
}
