#include <iostream>
#include <string>
using namespace std;
string S;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt_0 = 0, cnt_1 = 0; //연속되는 0의 묶음 개수, 연속되는 1의 묶음 개수
	bool no_flip = true;
	cin >> S;
	char C = S[0];
	//기본 카운트 1 증가
	if (C == '1') cnt_1++;
	else cnt_0++;
	for (int i = 1; i < S.length(); i++) {
		if (S[i] != C) {
			//다른 숫자로 바뀌면서 그 전 숫자의 묶음 카운트 증가
			if (C == '0') {
				cnt_1++;
				no_flip = false;
			}
			else {
				cnt_0++;
				no_flip = false;
			}
			C = S[i];
		}
	}
	if (no_flip) cout << 0; //모두 같은 숫자면
	else {
		if (cnt_0 && cnt_1) cout << min(cnt_0, cnt_1);
		else if (cnt_0 && !cnt_1) cout << cnt_0; // 1이 없으면
		else if (!cnt_0 && cnt_1) cout << cnt_1; // 0이 없으면
	}
}
