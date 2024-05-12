#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, ans=0;

int arr[501][501];
vector<pair<int, int> > v;
bool visit[501][501] = {0,};

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int cnt, int total){
	if(cnt == 4) {
		ans = max(ans, total);
		return;
	}
	
	for(int j=0; j<v.size(); j++) {
		int y = v[j].first;
		int x = v[j].second;
		
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(nx<0 || nx>=M || ny<0 || ny>=N || visit[ny][nx]) continue;
			
			visit[ny][nx] = 1;
			v.push_back({ny, nx});
			dfs(cnt+1, total + arr[ny][nx]);
			v.pop_back();
			visit[ny][nx] = 0;
		}
	}
	
}

int main(){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
		}
	}
	
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			v.push_back({i, j});
			visit[i][j] = 1;
			dfs(1, arr[i][j]);
			visit[i][j] = 0;
			v.pop_back();
		}
	}
	
	cout << ans;
	
	return 0;
}