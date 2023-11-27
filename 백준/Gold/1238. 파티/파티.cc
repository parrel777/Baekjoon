#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M, X;
int ans[2][1001]; //min way
vector<pair<int, int> > d[2][100001]; // all way
int longest = 0;

void dijkstra(int k){
	ans[k][X] = 0;
	
	// pq <cost, end>
	priority_queue<pair<int, int> > pq; // min cost array 
	pq.push({0, X});
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int end = pq.top().second;
		pq.pop();
		
		// if now way is more cost, pass it
		if(ans[k][end] < cost) continue;
			
		int s = d[k][end].size();
		
		for(int i=0; i<s; i++){
			int next = d[k][end][i].first;
			int ncost = d[k][end][i].second;
			
			if(ans[k][next] > cost + ncost){
				ans[k][next] = cost + ncost;
				pq.push({-ans[k][next], next});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M >> X;
	
	for(int i=0; i<M; i++){
		int s, e, c; // start, end, cost
		cin >> s >> e >> c;
		
		// d[0] = X to home (origin way)
		d[0][s].push_back({e, c});
		
		// d[1] = home to X 
		// (reverse way BUT it actually work like X to home)
		d[1][e].push_back({s, c});
	}
	
	for(int j=1; j<=N; j++) ans[0][j] = INF;
	for(int j=1; j<=N; j++) ans[1][j] = INF;
	
	
	dijkstra(1); // go to X (reverse)
	dijkstra(0); // back to home (origin)
	
	
	for(int i=1; i<=N; i++){
		int temp = (ans[0][i] + ans[1][i]);
		if(temp > longest) longest = temp;
	}
	
	cout << longest;
	
	return 0;
}