#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
bool arr[101][101];
bool visit[101][101];
int air[101][101];

int T=0;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

bool bfs(){
	queue<pair<int, int> > q;
	q.push({0, 0});
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		if(visit[y][x]) continue;
		visit[y][x] = true;
		
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny>=0 && ny<N && nx>=0 && nx<M){
				if(!arr[ny][nx]) q.push({ny, nx});
				else air[ny][nx]++;
			}
		}
	}
	
	bool melt = false;
	
	for(int i=1; i<N-1; i++){
		for(int j=1; j<M-1; j++){
			if(air[i][j] >= 2){
				arr[i][j] = 0;
				melt = true;
			}
		}
	}
	
	if(melt){
		T++;
		return false;
	}
	else{
		cout << T;
		return true;
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
		memset(visit, false, sizeof(visit));
		memset(air, 0, sizeof(air));
		if(bfs()) break;
	}
	
	return 0;
}