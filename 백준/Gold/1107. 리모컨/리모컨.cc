#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool ch[1000002] = {0,};

int Min(int a, int b){
	return a > b ? b : a;
}

int main(){
	int N, M;
	int t1=9999999, t2=9999999, t3;
	string num;
	char bt[11];
	
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		cin >> bt[i];
	}
	
	if(N != 100){
		for(int i=0; i<=1000000; i++){
			ch[i] = true;
			num = to_string(i);
			for(int j=0; j<M; j++){
				if(num.find(bt[j]) != std::string::npos){
					ch[i] = false;
					break;
				}
			}
		}
		ch[100] = true;
		
		for(int i=N; i>=0; i--){
			if(ch[i]){
				t1 = i;
				break;
			}
		}
		
		for(int i=N; i<=1000000; i++){
			if(ch[i]){
				t2 = i;
				break;
			}
		}
		
		int a = abs(t1 - N) + (to_string(t1).length());
		int b = abs(t2 - N) + (to_string(t2).length());
		int c = abs(100 - N);
		
		cout << Min(Min(a, b), c);
	}
	else{
		cout << 0;
	}
	return 0;
}