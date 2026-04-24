#include <iostream>
#include <utility> 
#include <queue>

using namespace std;
//BFS
int board[102][102] = { 0, };
bool vis[102][102]; // 해당 칸을 방문했는지 여부를 저장
int dist[102][102]; //시작점으로 부터의 이동 거리(시작점이 1)
int row, col; // row = 행의 수, col = 열의 수
//x가 가로, y가 세로, z가 높이의 방향
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string miro; //최대 가로 100이라서
    queue<pair<int, int> > Q;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        cin >> miro;
        for (int j = 0; j < col; j++) board[i][j] = miro[j] - '0';
    }
    vis[0][0] = 1;
    Q.push({ 0, 0 });
    dist[0][0]++;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            Q.push({ nx,ny });
            dist[nx][ny] = dist[cur.first][cur.second] + 1; //기존 자리보다 한 칸 더 나아간 거리라는 표시를 숫자로 남김
        }
    }
    cout << dist[row - 1][col - 1];
}
