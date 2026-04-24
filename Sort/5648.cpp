#include <iostream>
#include <algorithm>
using namespace std;
long arr1[1000001], arr2[1000001]; // arr1에 숫자 받아서 arr2에 뒤집은거 저장
void reverse(int idx)
{
	while (1)
	{
		if (arr1[idx] == 0) return;
		arr2[idx] *= 10;
		arr2[idx] += arr1[idx] % 10;
		arr1[idx] /= 10;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr1[i];
		reverse(i);
	}
	sort(arr2, arr2 + N);
	for (int i = 0; i < N; i++) cout << arr2[i] << "\n";
}
