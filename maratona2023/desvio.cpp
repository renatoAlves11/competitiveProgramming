#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

void dykstra(vector<vector<pair<int,int>>> adj, int a, int b, int n){
    priority_queue<pair<int,int>> q;
    vector<bool> processed(n, false);
    vector<int> distance(n, 1e9);
    distance[a] = 0;
    q.push({0,a});
    while(!q.empty()){
        int node = q.top().second; 
        q.pop();
        if(processed[node]){
            continue;
        }
        processed[node] = true;
        for(pair<int,int> u : adj[node]){
             int w = u.first, destino = u.second;
           if(node == a && destino == b){
                continue;
            }
            if(distance[node] + w < distance[destino]){
                distance[destino] = distance[node] + w;
                q.push({-(distance[destino]), destino});
            }
        }
    }
    if(distance[b] == 1e9){
        cout << -1 << endl;
    }
    else{
        cout << distance[b] << endl;
    }
}

int main(){
    int nodes, paths, a, b, weigth;
    cin >> nodes >> paths;
     vector<vector<pair<int,int>>> adj (nodes+1); 
     vector<pair<int, int>> searches;
     for(int i = 0; i < paths; i ++){
        cin >> a >> b >> weigth;
        searches.push_back({a,b});
        adj[a].push_back({weigth, b});
        adj[b].push_back({weigth, a});
     }
    for(pair<int,int> i : searches){
        dykstra(adj, i.first, i.second, nodes + 1);
    }
    return 0;
}