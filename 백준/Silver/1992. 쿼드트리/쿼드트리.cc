#include <iostream>
#include <string>

using namespace std;

int N;
char arr[65][65];

void quad(int a, int b, int size){
	bool clear = true;
	int check = arr[a][b] -'0';
	
	for(int i=a; i<a+size; i++){
		for(int j=b; j<b+size; j++){
			if(arr[i][j] - '0' != check){
				clear = false;
			}
		}
	}
	
	if(clear){
		cout << check;
	}
	else{
		cout << "(";
		quad(a, b, size/2);
		quad(a, b+size/2, size/2);
		quad(a+size/2, b, size/2);
		quad(a+size/2, b+size/2, size/2);
		cout << ")";
	}
}

int main(){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	// Y, X, size
	quad(0, 0, N);
	
	return 0;
}