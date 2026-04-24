#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string word[20001];
bool compare(const string &a, const string &b)
{
	if (a.size() != b.size()) return a.size() < b.size(); //먼저 크기 순서 확인
	return a < b; // 같은 크기면 사전 순 정렬 string은 비교 연산자만으로도 가능
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	sort(word, word + N, compare);
	for (int i = 0; i < N; i++) {
		if (i>0 &&word[i] == word[i-1]) continue;
		cout << word[i] << "\n";
	}
}
