#include <iostream>

using namespace std;

int n, m;
int tree[1000001];

int getParent(int x){
	if(tree[x] == x) return x;
	return tree[x] = getParent(tree[x]);
}

void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a < b) tree[b] = a;
	else tree[a] = b;
}

void findParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a == b) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		tree[i] = i;
	}
	
	for(int i=0; i<m; i++){
		bool mode;
		int a, b;
		cin >> mode >> a >> b;
		
		if(!mode){
			unionParent(a, b);
		}
		else{
			findParent(a, b);
		}
	}
	
	return 0;
}