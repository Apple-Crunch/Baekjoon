#include <iostream>
#include <utility> 
#include <queue>

using namespace std;
//BFS
int board[1002][1002];
int dist[1002][1002]; //시작점으로 부터의 이동 거리(시작점이 1)
int row, col; // row = 행의 수, col = 열의 수
//x가 가로, y가 세로, z가 높이의 방향
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tomato, day = 1; //1일차부터 시작
    bool is_able = true;
    queue<pair<int, int> > Q;
    cin >> row >> col;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> tomato;
            board[i][j] = tomato;
            dist[i][j] = tomato;
            if (board[i][j] == 1) { //BFS를 하는 시작점이 여러 개인 경우
                Q.push({ i, j });
            }
        }
    }
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= col || ny < 0 || ny >= row) continue; // 범위 밖일 경우 넘어감
            if (dist[nx][ny] != 0) continue; // 
            Q.push({ nx,ny });
            dist[nx][ny] = dist[cur.first][cur.second] + 1; //기존 자리보다 한 칸 더 나아간 거리라는 표시를 숫자로 남김
            board[nx][ny] = 1;
            if (dist[nx][ny] > day) day = dist[nx][ny];
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (dist[i][j] == 0) {
                is_able = false;
                break;
            }
        }
    }
    if (is_able)cout << day - 1; //x일차에 끝날 때 x-1일 소요가 되었을 것
    else cout << -1;
}
