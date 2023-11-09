#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int dp[501][501] = {0,};
bool visit[501][501] = {0,};
int M, N;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int DFS(int y, int x){
	if(y==M-1 && x==N-1)
		return 1; // end point
	if(visit[y][x])
		return dp[y][x]; // return dp point
	
	visit[y][x] = true;
	
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
			
		if(ny<0 || nx<0 || ny>=M || nx>=N) continue;
		if(arr[y][x] > arr[ny][nx]){
			dp[y][x] += DFS(ny, nx);
		}
	}
	
	return dp[y][x];
}

int main(){
	cin >> M >> N;
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}
	
	cout << DFS(0, 0);
	
	return 0;
}