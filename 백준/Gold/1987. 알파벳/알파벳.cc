#include <iostream>
#include <string>

using namespace std;

int R, C;
int start, ans=0, cnt=0;
char arr[21][21];
bool list[26] = {0,};

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void find(int y, int x){
	cnt++;
	if(ans < cnt) ans = cnt;
	
	for(int i=0; i<4; i++){
		int yy = y + dy[i];
		int xx = x + dx[i];
		int next = arr[yy][xx] -'A';
		
		if(yy < 0 || yy >= R || xx < 0 || xx >= C) continue;
		if(list[next]) continue;
		
		list[next] = true;
		find(yy, xx);
		list[next] = false;
		cnt--;
	}
}

int main(){
	cin >> R >> C;
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> arr[i][j];
		}
	}
	
	start = arr[0][0] - 'A';
	list[start] = true;
	find(0, 0);
	
	cout << ans;
	
	return 0;
}