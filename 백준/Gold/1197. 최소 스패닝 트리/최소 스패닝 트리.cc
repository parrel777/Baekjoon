#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int sum = 0;
vector<pair<int, pair<int, int> > > tree;
int parent[10001];

int getParent(int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

bool sameParent(int a, int b){
	a = getParent(a);
	b = getParent(b);
	
	if(a == b) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	cin >> V >> E;
	
	for(int i=0; i<E; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		tree.push_back({c, {a, b}});
		tree.push_back({c, {b, a}});
	}
	
	sort(tree.begin(), tree.end());
	
	for(int i=1; i<=V; i++){
		parent[i] = i;
	}
	
	for(int i=0; i<tree.size(); i++){
		int p = tree[i].second.first;
		int q = tree[i].second.second;
		
		if(!sameParent(p, q)){
			sum += tree[i].first;
			unionParent(p, q);
		}
	}
	
	cout << sum;
	
	return 0;
}