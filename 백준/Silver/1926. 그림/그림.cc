#include <iostream>

using namespace std;

int n, m;
int s=0, ans=0, num=0;
bool arr[501][501];
bool visit[501][501];

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void DPS(int y, int x){
	visit[y][x] = true;
	s += 1;
	
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
		
		if(arr[ny][nx] && !visit[ny][nx]){
			DPS(ny, nx);
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] && !visit[i][j]){
				DPS(i, j);
				num += 1;
				if(s > ans) ans = s;
				s = 0;
			}
		}
	}
	
	cout << num << '\n' << ans;	
	
	return 0;
}