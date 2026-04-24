#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, num[7];
vector<int>V;
void func(int k)
{
	if (k == M) {
		for (int i = 0; i < M; i++) 
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		num[k] = V[i]; // k번째 칸에 넣기
		func(k + 1);
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
		V.push_back(n);
	}
	sort(V.begin(), V.end());
	func(0);
}
