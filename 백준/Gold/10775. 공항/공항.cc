#include <iostream>

using namespace std;

int G, P;
int port[100001];
int ap[100001];
int ans=0;

int getParent(int a){
	if(a == port[a]) return a;
	return port[a] = getParent(port[a]);
}

void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a < b) port[b] = a;
	else port[a] = b;
}

int main(){
	cin >> G >> P;
	
	for(int i=0; i<=G; i++){
		port[i] = i;
	}
	
	for(int i=0; i<P; i++){
		cin >> ap[i];
	}
	
	for(int i=0; i<P; i++){
		int n = ap[i];
		n = getParent(n);
		
		if(n==0) break;
		
		unionParent(n, n-1);
		ans++;
	}
	
	cout << ans;
	
	return 0;
}