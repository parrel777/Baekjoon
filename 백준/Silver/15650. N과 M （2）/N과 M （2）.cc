#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int arr[9];
bool visited[9];


void dfs(int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
        	for(int j=0; j<=i; j++)
            	visited[j] = true;
            arr[cnt] = i;
            dfs(cnt+1);
            for(int j=0; j<=i; j++)
            	visited[j] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0);
    return 0;
}
