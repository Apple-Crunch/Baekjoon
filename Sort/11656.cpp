#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> jubmisa;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	int len = S.length();
	for (int i = 0; i < len; i++)
	{
		jubmisa.push_back(S);
		//뒤집어서 pop_back해서 S의 맨 앞을 제거하는 것을 반복
		reverse(S.begin(),S.end());
		S.pop_back();
		reverse(S.begin(), S.end());
	}
	sort(jubmisa.begin(), jubmisa.end());
	for (int i = 0; i < jubmisa.size(); i++)
	{
		cout << jubmisa[i] << "\n";
	}
}
