#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX = 101;

int M, N, H, day=0;
int arr[MAX][MAX][MAX];
int stack[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
queue<tuple<int, int, int> > q;
int dy[] = {0,0,0,0,1,-1};
int dx[] = {0,0,1,-1,0,0};
int dh[] = {1,-1,0,0,0,0};

void BFS(){
	while(!q.empty()){
		int h = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();
		
		for(int i=0; i<6; i++){//0(1,0), 1(-1,0), 2(0,1), 3(0,-1)
			int nh = h + dh[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(nh < 0 || ny < 0 || nx < 0 || nh >= H || ny >= N || nx >= M)
				continue;
			if(arr[nh][ny][nx]==0 && visit[nh][ny][nx]==false){
				visit[nh][ny][nx] = true;
				q.push(make_tuple(nh,ny,nx));
				stack[nh][ny][nx] = stack[h][y][x] + 1;
			}
		}
		
	}
}

int main(){
	cin >> M >> N >> H;
	
	for(int k=0; k<H; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cin >> arr[k][i][j];
			}
		}
	}
	
	for(int k=0; k<H; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(arr[k][i][j]==1)
					q.push(make_tuple(k, i, j));
			}
		}
	}
	BFS();
	
	for(int k=0; k<H; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(arr[k][i][j]==0 && stack[k][i][j]==0){
					cout << -1;
					return 0;
				}
				if(stack[k][i][j] > day)
					day = stack[k][i][j];
			}
		}
	}
	
	cout << day;
	
	return 0;
}