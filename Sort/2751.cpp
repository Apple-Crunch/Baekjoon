#include <iostream>
using namespace std;
int N;
int arr[1000000];
int tmp_arr[1000000];
void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int lidx = st; //arr[st:mid]
	int ridx = mid; //arr[mid:en]
	for (int i = st; i < en; i++) {
		if (ridx == en)tmp_arr[i] = arr[lidx++];
		else if (lidx == mid) tmp_arr[i] = arr[ridx++];
		else if (arr[lidx] <= arr[ridx])tmp_arr[i] = arr[lidx++];
		else tmp_arr[i] = arr[ridx++];
	}
	for (int i = st; i < en; i++)arr[i] = tmp_arr[i];
}
void merge_sort(int st, int en)
{
	if (en - st == 1)return; // 길이 1인 경우
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]을 정렬한다.
	merge_sort(mid, en); // arr[mid:en]을 정렬한다.
	merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	merge_sort(0,N);
	for (int i = 0; i < N; i++)cout << arr[i] << "\n";
}
