#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long k, ans=1;
vector<int> v;

bool visit[21] = {0,};
long long fac[21];

void mode1(){
	cin >> k;
	
	for(int i=0; i<N; i++){
		for(int j=1; j<=N; j++){
			if(visit[j]) continue;
			
			if(k > fac[N - 1 - i]){
				k -= fac[N - 1 - i];
			}
			else{
				v.push_back(j);
				visit[j] = 1;
				break;
			}
			
		}
	}
	
	for(int i=0; i<N; i++) cout << v[i] << ' ';
}

void mode2(){
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	for(int i=0; i<N; i++){
		for(int j=1; j<v[i]; j++){
			if(!visit[j]){
				ans += fac[N - 1 - i];
			}
		}
		visit[v[i]] = 1;
	}
	
	cout << ans;
}


int main(){
	cin >> N >> M;
	
	fac[0] = fac[1] = 1;
	
	for(int i=2; i<N; i++){
		fac[i] = fac[i-1] * i;
	}
	
	if(M==1) mode1();
	else mode2();
	
	
	return 0;
}