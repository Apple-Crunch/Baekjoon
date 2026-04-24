#include <iostream>
#include <algorithm>
using namespace std;
long long int card[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	long long int x, y, sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> card[i];
	for (int i = 0; i < m; i++) {
		sort(card, card + n);
		x = card[0] + card[1]; y = card[0] + card[1];
		card[0] = x; card[1] = y;
	}
	for (int i = 0; i < n; i++) sum += card[i];
	cout << sum;
}
