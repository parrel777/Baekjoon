#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int V, result=0, end_point=0;
bool visited[100002] = {false, };
vector<pair<int, int> > tree[100002];

void DFS(int p, int cost){
	if(visited[p]) return;
	visited[p] = true;
	
	if(result < cost){
		result = cost;
		end_point = p;
	}
	
	for(int i=0; i<tree[p].size(); i++){
		DFS(tree[p][i].first, cost + tree[p][i].second);
	}
	
}

int main(){
	cin >> V;
	
	for(int i=1; i<=V; i++){
		int a;
		cin >> a;
		
		while(1){
			int b, c;
			cin >> b;
			if(b == -1) break;
			cin >> c;
			tree[a].push_back({b, c});
		}
	}
	
	// start point, cost
	DFS(1, 0);
	
	result = 0;
	memset(visited, false, sizeof(visited));
	DFS(end_point, 0);
	
	cout << result;
	
	return 0;
}