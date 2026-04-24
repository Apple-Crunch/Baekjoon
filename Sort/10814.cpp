#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<pair<int, string>>people;
bool compare(const pair<int, string>&a, const pair<int, string>& b) // 나이만 정렬
{
	return a.first < b.first;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, age;
	string name;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		people.push_back({ age,name });
	}
	stable_sort(people.begin(),people.end(), compare); //순서를 살리기 위해 stable_sort사용
	for (int i = 0; i < N; i++) 
		cout << people[i].first << " " << people[i].second << "\n";
}
