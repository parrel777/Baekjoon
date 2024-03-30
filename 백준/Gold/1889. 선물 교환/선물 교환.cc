#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
bool able = false;
vector<int> graph[200001];
vector<int> ans;
int inDegree[200001] = {0,};
bool excepted[200001] = {0,};
queue<int> q;

void TopologySort(){
	for(int i=1; i<=N; i++){
		if(inDegree[i] < 2){
			q.push(i);
			excepted[i] = true;
		}
	}
	
	while(!q.empty()){
		int a = q.front();
		q.pop();
		
		for(int i=0; i<graph[a].size(); i++){
			int temp = graph[a][i];
			inDegree[temp]--;
			
			if(inDegree[temp] < 2 && !excepted[temp]){
				q.push(temp);
				excepted[temp] = true;
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		if(inDegree[i] == 2)
			ans.push_back(i);
	}
	
	
}

int main(){
	cin >> N;
	
	for(int i=1; i<=N; i++){
		int a, b;
		cin >> a >> b;
		graph[i].push_back(a);
		graph[i].push_back(b);
		inDegree[a]++;
		inDegree[b]++;
	}
	
	TopologySort();
	
	int num = ans.size();
	cout << num << '\n';
	
	if(num > 0){
		for(int i=0; i<num; i++){
			cout << ans[i] << ' ';
		}
	}
	
	return 0;
}