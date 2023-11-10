#include <iostream>
#include <algorithm>

using namespace std;

int N, a, b;
int total = 0;
int pos[51];
int neg[51];
bool zero = false;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	a = b = 0;
	
	for(int i=0; i<N; i++){
		int num;
		cin >> num;
		if(num < 0){
			neg[a] = num;
			a++;
		}
		if(num > 0){
			pos[b] = num;
			b++;
		}
		if(num == 0)
			zero = true;
	}
	
	sort(neg, neg+a);
	sort(pos, pos+b, greater<int>());
	
	// neg calculate
	if(a > 1){
		if(a % 2 == 0){
			for(int i=0; i<a; i+=2){
				total += neg[i] * neg[i+1];
			}
		}
		else{
			for(int i=0; i<a-1; i+=2){
				total += neg[i] * neg[i+1];
			}
			if(!zero) total += neg[a-1];
		}
	}
	else if(a == 1){
		if(!zero) total += neg[a-1];
	}
	
	// pos calculate
	if(b > 0){
		if(b % 2 == 0){
	 		for(int i=0; i<b; i+=2){
	 			if(pos[i] != 1 && pos[i+1] != 1)
	 				total += pos[i] * pos[i+1];
	 			else
	 				total += pos[i] + pos[i+1];
			}
		}
		else{
			for(int i=0; i<b-1; i+=2){
				if(pos[i] != 1 && pos[i+1] != 1)
	 				total += pos[i] * pos[i+1];
	 			else
	 				total += pos[i] + pos[i+1];
			}
			total += pos[b-1];
		}
	}
	
	cout << total;
	
	return 0;
}