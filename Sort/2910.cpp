#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int message[1001];
vector<pair<int,int>> cnt; //sort사용을 위해 vector를 사용
void check(int idx)
{
	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i].first == message[idx]) {
			cnt[i].second++;
			return;
		}
	}
	cnt.push_back({ message[idx],1 });
}
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> message[i];
		check(i);
	}
	// compare를 안만들면 first까지 정렬해서 순서 안맞음, sort를 쓰면 같은 빈도 수일 때 반드시 순서를 보장하지 않고 순서를 바꿀 수도 있음
	stable_sort(cnt.begin(), cnt.end(), compare); 
	for (int i = 0; i < cnt.size(); i++) 
		for (int j = 0; j < cnt[i].second; j++) cout << cnt[i].first << " ";
}
