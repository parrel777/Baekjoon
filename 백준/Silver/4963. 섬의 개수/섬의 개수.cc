#include <iostream>
using namespace std;

int arr[51][51];
bool visit[51][51];
int w, h;
int island = 0;

void DFS(int a, int b){
	visit[a][b] = true;
	
	int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	
	for(int i=0; i<8; i++){
		int nx = b + x[i];
		int ny = a + y[i];
		
		if((nx>=0 && nx<w) && (ny>=0 && ny<h) && !visit[ny][nx] && arr[ny][nx]==1){
			DFS(ny, nx);
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while(1){
		cin >> w >> h;
		if(w==0 && h==0)
			break;
		
		island = 0;
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin >> arr[i][j];
			}
		}
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(arr[i][j] == 1 && !visit[i][j]){
					island++;
					DFS(i, j);
				}
			}
		}
		
		cout << island << '\n';
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				arr[i][j] = 0;
				visit[i][j] = false;
			}
		}
	}
	
	return 0;
}