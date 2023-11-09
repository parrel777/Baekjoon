#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool arr[101][101];
bool visit[101][101];
int N, M;
int T=0, L=0; //Time, Last Left

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

bool bfs(){
	queue<pair<int, int> > q;
	visit[0][0] = true;
	int ch = 0;
	q.push({0, 0});
	T++;
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny>=0 && nx>=0 && ny<N && nx<M && !visit[ny][nx]){
				if(!arr[ny][nx])
					q.push({ny, nx});
				else{
					arr[ny][nx] = 0;
					ch++;
				}
				visit[ny][nx] = true;
			}
		}
	}
	
	if(ch == 0){
		cout << --T << '\n' << L;
		return true;
	}
	else{
		L = ch;
		return false;
	}
	
}

int main(){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
		}
	}
	
	while(true){
		if(bfs()) break;
		memset(visit, false, sizeof(visit));
	}
	
	return 0;
}