#include <iostream>
#include <string>
using namespace std;
int paper[64][64];
int N;
bool check(int start_x, int start_y, int n) // 시작의 x와 y, , 변의 길이
{
    for (int i = start_x; i < start_x + n; i++)
        for (int j = start_y; j < start_y + n; j++)
            if (paper[start_x][start_y] != paper[i][j]) return false;
    return true;
}

void Quad_Tree(int n, int x, int y) // n = 한 변의 길이 x,y는 시작
{
    if (check(x, y, n)) {
        if (paper[x][y] == 0) cout << 0;
        else cout << 1;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!check(x + i * n / 2, y + j * n / 2, n / 2))cout << "("; // 그 다음에 나눌 필요가 있으면
            Quad_Tree(n / 2, x + i * n / 2, y + j * n / 2);     
        }
    }
    cout << ")"; // 나누었던 사분면을 다 체크하면 괄호 닫기
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            paper[i][j] = s[j] -'0';
        }  
    }
    if (!check(0, 0, N))cout << "("; //초기에 괄호 한 번
    Quad_Tree(N, 0, 0);
}
