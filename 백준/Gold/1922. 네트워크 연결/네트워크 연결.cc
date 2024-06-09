#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

int N, M;
int sum=0;
vector<P> com[1001];
bool visit[1001] = {0,};

void Prim(){
	priority_queue<P, vector<P>, greater<P> > pq;
	pq.push({0, 1});
	
	while(!pq.empty()){
		int cost = pq.top().first;
		int next = pq.top().second;
		pq.pop();
		
		if(visit[next]) continue;
		visit[next] = 1;
		
		sum += cost;
		
		for(int i=0; i<com[next].size(); i++){
			if(!visit[com[next][i].second]){
				pq.push(com[next][i]);
			}
		}
		
	}
}

int main(){
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		com[a].push_back({c, b});
		com[b].push_back({c, a});
	}
	
	Prim();
	
	cout << sum;
	
	return 0;
}