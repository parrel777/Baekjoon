#include <iostream>
#include <cmath>
using namespace std;

int N;
int cnt = 0;
int cb[16];

void queen(int x){
	if(x==N)
		cnt++;
	else{
		for(int i=0; i<N; i++){
			cb[x] = i;
			bool check = true;
			for(int j=0; j<x; j++){
				if(cb[x] == cb[j] || abs(cb[x] - cb[j]) == x-j){
					check = false;
				}
			}
			
			if(check) 
				queen(x+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	queen(0);
	cout << cnt;
	return 0;
}