#include <iostream>
#include <vector>
using namespace std;
pair<int, int>P[100000], tmp[100000];
//머지 소트인데 pair를 사용한
void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int l = st, r = mid;
	for (int i = st; i < en; i++) {
		if (r == en) {
			tmp[i].first = P[l].first;
			tmp[i].second = P[l].second;
			l++;
		}
		else if (l == mid) {
			tmp[i].first = P[r].first;
			tmp[i].second = P[r].second;
			r++;
		}
		else if (P[l].second < P[r].second) {
			tmp[i].first = P[l].first;
			tmp[i].second = P[l].second;
			l++;

		}
		else if (P[l].second > P[r].second) {
			tmp[i].first = P[r].first;
			tmp[i].second = P[r].second;
			r++;
		}
		else {
			if (P[l].first <= P[r].first) {
				tmp[i].first = P[l].first;
				tmp[i].second = P[l].second;
				l++;
			}
			else {
				tmp[i].first = P[r].first;
				tmp[i].second = P[r].second;
				r++;
			}
		}
	}
	for (int i = st; i < en; i++) {
		P[i].first = tmp[i].first;
		P[i].second = tmp[i].second;
	}
}
void merge_sort(int st, int en)
{
	if (en - st <= 1) return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		P[i].first = x; P[i].second = y;
	}
	merge_sort(0, N);
	for (int i = 0; i < N; i++) 
		cout << P[i].first << " " << P[i].second << "\n";
}
