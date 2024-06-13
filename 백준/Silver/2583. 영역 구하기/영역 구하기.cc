#include <iostream>
#include <queue>

using namespace std;

int M, N, K;
bool arr[101][101] = {0,};
priority_queue<int, vector<int>, greater<int> > v;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int total = 0;

void DFS(int a, int b){
	arr[a][b] = 1;
	total++;
	
	for(int i=0; i<4; i++){
		int nx = b + dx[i];
		int ny = a + dy[i];
		
		if(nx<0 || ny<0 || nx>=N || ny>=M || arr[ny][nx] == 1)
			continue;
			
		DFS(ny, nx);
	}
}

int main(){
	cin >> M >> N >> K;
	
	for(int i=0; i<K; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int i=x1; i<x2; i++){
			for(int j=y1; j<y2; j++){
				arr[j][i] = 1;
			}
		}
	}
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] == 0){
				DFS(i, j);
				v.push(total);
				total = 0;
			}
		}
	}
	
	int s = v.size();
	cout << s << '\n';
	
	for(int i=0; i<s; i++){
		cout << v.top() << ' ';
		v.pop();
	}
	
	return 0;
}