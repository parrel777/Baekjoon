#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
vector<pair<int, int> > tree[1001];
bool visited[1001] = {0,};
int result = 0;

void DFS(int p, int q, int cost){
	if(p == q){
		result = cost;
		return;
	}
	
	for(int i=0; i<tree[p].size(); i++){
		int next_node = tree[p][i].first;
		int next_len = tree[p][i].second;
		
		if(!visited[next_node]){
			visited[next_node] = true;
			DFS(next_node, q, cost+next_len);
			visited[next_node] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	
	for(int i=0; i<N-1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}
	
	for(int i=0; i<M; i++){
		int p, q;
		cin >> p >> q;
		visited[p] = true;
		// start, end, cost
		DFS(p, q, 0);
		cout << result << '\n';
		memset(visited, 0, sizeof(visited));
		result = 0;
	}
	
	return 0;
}
