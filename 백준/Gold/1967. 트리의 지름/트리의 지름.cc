#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, result=0, end_point=0;
bool visited[10002] = {false, };
vector<pair<int, int> > tree[10002];

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
	cin >> N;
	
	for(int i=0; i<N-1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}
	
	// start point, cost
	DFS(1, 0);
	
	result = 0;
	memset(visited, false, sizeof(visited));
	DFS(end_point, 0);
	
	cout << result;
	
	return 0;
}