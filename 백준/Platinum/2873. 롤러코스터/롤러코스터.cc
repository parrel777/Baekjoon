#include <iostream>

using namespace std;

int R, C;
int a, b; // min y, x
int m = 1001;
int arr[1001][1001];

void rodd(){
	for(int i=0; i<R; i++){
		for(int j=0; j<C-1; j++){
			if(i%2==0) cout << 'R';
			else cout << 'L';
		}
		if(i == R - 1) break;
		cout << 'D';
	}
}

void codd(){
	for(int i=0; i<C; i++){
		for(int j=0; j<R-1; j++){
			if(i%2==0) cout << 'D';
			else cout << 'U';
		}
		if(i == C - 1) break;
		cout << 'R';
	}
}

void even(){
	int r, c;
	
	if(a % 2 == 1) 
		r = a-1;
	else 
		r = a;
		
	c = b;
	
	// before blank line (pair)
	for(int i=0; i<r; i++){
		for(int j=0; j<C-1; j++){
			if(i%2==0)cout << 'R';
			else cout << 'L';
		}
		cout << 'D';
	}
	
	// blank line, before blank
	for(int i=0; i<c; i++){
		if(i%2 == 0) cout << "DR";
		else cout << "UR";
	}
	
	// blank line, after blank
	for(int i=c; i<C-1; i++){
		if(i%2 == 0) cout << "RD";
		else cout << "RU";
	}
	
	// after blank line (pair)
	for(int i=r+2; i<R; i++){
		cout << 'D';
		for(int j=0; j<C-1; j++){
			if(i%2==0) cout << 'L';
			else cout << 'R';
		}
	}
}

int main(){
	cin >> R >> C;
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> arr[i][j];
			if((i+j)%2 == 1 && arr[i][j] < m){
				m = arr[i][j];
				a = i;
				b = j;
			}
		}
	}
	
	if(R%2 != 0) rodd();
	else if(C%2 != 0) codd();
	else even();
	
	return 0;
}