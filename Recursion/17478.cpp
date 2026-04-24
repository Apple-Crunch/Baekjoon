#include <iostream>
using namespace std;
int N; // 초기의 카운트 기억 위해 전역변수 선언
void recur(int n)
{
    if (n < 0) return;
    for (int i = 0; i < (N - n); i++) cout << "____"; // 초기의 카운트와 차이 만큼
    cout << "\"재귀함수가 뭔가요?\"\n";
    if (n) { //n이 0이상이면 아직 더 재귀함수 가동해야 함
        for (int i = 0; i < (N - n); i++) cout << "____";
        cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        for (int i = 0; i < (N - n); i++) cout << "____";
        cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        for (int i = 0; i < (N - n); i++) cout << "____";
        cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    }
    else {
        for (int i = 0; i < (N - n); i++) cout << "____";
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    }
    recur(n - 1); // n이 감소하면서 재귀
    for (int i = 0; i < (N - n); i++) cout << "____";
    cout << "라고 답변하였지.\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    recur(N);
}
