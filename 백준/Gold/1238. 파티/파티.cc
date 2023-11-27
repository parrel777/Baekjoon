#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M, X;
int ans[1001]; //min way
int time[1001]; //result
vector<pair<int, int> > d[100001]; // all way
int longest = 0;

void dijkstra(int start){
	ans[start] = 0;
	
	// pq <cost, end>
	priority_queue<pair<int, int> > pq; // min cost array 
	pq.push({0, start});
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int end = pq.top().second;
		pq.pop();
		
		// if now way is more cost, pass it
		if(ans[end] < cost)
			continue;
			
		int s = d[end].size();
		
		for(int i=0; i<s; i++){
			int next = d[end][i].first;
			int ncost = d[end][i].second;
			
			if(ans[next] > cost + ncost){
				ans[next] = cost + ncost;
				pq.push({-ans[next], next});
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
		
		d[s].push_back({e, c});
	}
	// go to X
	for(int i=1; i<=N; i++){ 
		for(int j=1; j<=N; j++) ans[j] = INF;
		dijkstra(i);
		time[i] = ans[X];
	}
	// go back
	for(int j=1; j<=N; j++) ans[j] = INF;
	dijkstra(X);
	
	// add both + find longest
	for(int i=1; i<=N; i++){
		time[i] += ans[i];
		if(time[i] > longest)
			longest = time[i];
	}
	
	cout << longest;
	
	return 0;
}