#include <iostream>
using namespace std;
int paper[2200][2200];
int N, cnt_0 = 0, cnt_1 = 0, cnt_m1 = 0;
bool check(int start_x, int start_y, int n) // 시작의 x와 y, , 변의 길이
{
    for (int i = start_x; i < start_x + n; i++)
        for (int j = start_y; j < start_y + n; j++)
            if (paper[start_x][start_y] != paper[i][j]) return false;
    return true;
}
void paper_cut(int n, int x, int y) // n = 한 변의 길이 x,y는 시작
{
    if (check(x, y, n)) {
        if (paper[x][y] == 1) cnt_1++;
        else if (paper[x][y] == 0) cnt_0++;
        else cnt_m1++;
        return;
    }
    //종이를 9등분을 하는 중
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) paper_cut(n / 3, x + i * n / 3, y + j * n / 3);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
    paper_cut(N, 0, 0);
    cout << cnt_m1 << "\n" << cnt_0 << "\n" << cnt_1;
}
