#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C, cnt = 0;
char ans[16];
vector<char> word;
bool check[16];
void func(int n)
{
	if (n >= 2) { //사전순 정렬이 되고 있는지 확인
		if (ans[n - 2] > ans[n - 1]) {
			return;
		}
	}
	if (n == L) {
		if (cnt < 1) return; // 모음이 1개도 없으면
		if (n - cnt < 2) return; // 자음이 2개 미만이면
		for (int i = 0; i < L; i++)
			cout << ans[i];
		cout << "\n";
		return;
	}
	for (int i = n; i < C; i++) {
		if (!check[i]) {
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') //모음이 들어가면 카운트
				cnt++;
			ans[n] = word[i];
			check[i] = true;
			func(n + 1);
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') //다시 빠지면 카운트 감소
				cnt--;
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> C;
	char c;
	for (int i = 0; i < C; i++) {
		cin >> c;
		word.push_back(c);
	}
	sort(word.begin(), word.end());
	func(0);
}
