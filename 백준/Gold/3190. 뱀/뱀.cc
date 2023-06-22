#include <bits/stdc++.h>

using namespace std;
void init(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int board[101][101];
int n, k, dir = 0, times = 0; //처음 방향은 무조건 동쪽을 향함
int x = 1, y = 1;

queue<pair<int, char>> commands;
queue<pair<int, int>> tails;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0}; 

int cmdTime;
char cmdDir;

bool OOB(int nx, int ny){
  return nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == 1;
}

int main()
{
  init();
  cin >> n >> k;
  board[x][y] = 1; //가장 북쪽의 가장 서쪽은 무조건 뱀이 있음
  tails.push({x, y});

  while(k--){
    int x, y;
    cin >> x >> y;
    board[x][y] = 2;
  }

  cin >> k;
  while(k--){
    int times;
    char dirs;
    cin >> times >> dirs;
    commands.push({times, dirs});
  }
  
  bool isCompleted = true;
  while(1){
    if(!commands.empty() && isCompleted){ //커맨드가 남아 있다면 계속 집어 넣는다. 이러면 커맨드가 완성 되지 않았는데도 계속 다른걸 넣어서 오류가 남
      auto cur = commands.front();commands.pop();
      cmdTime = cur.first;
      cmdDir = cur.second;
      isCompleted =false;
    }
    if(cmdTime == times){
      dir = (cmdDir == 'D') ? (dir+1)%4 : (dir+3)%4;
      isCompleted = true;
    }
    ++times;

    x += dx[dir];
    y += dy[dir];

    if(OOB(x, y)){//게임끝인지 확인
      cout << times<<'\n';
      break;
      return 0;
    }

    if(board[x][y] == 0){//그저 빈칸이라면 꼬리 자르고 앞에 머리 추가
      pair<int, int> t = tails.front(); tails.pop();
      board[t.first][t.second] = 0;
    }
    board[x][y] = 1;
    tails.push({x, y});
  }
  return 0;
}