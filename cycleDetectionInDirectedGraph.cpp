#include<unordered_map>
#include<list>
bool checkcycledfs(int node, unordered_map<int, bool>&visited, unordered_map<int, bool>&dfsvisited, 
unordered_map<int,list<int>> &adj)
{
  visited[node]=true;
  dfsvisited[node]=true;
  for(auto neighbour: adj[node])
  {
    if(!visited[neighbour])
    {
      bool cycledtected=checkcycledfs(neighbour, visited, dfsvisited, adj);
      if(cycledtected)
      return true;
    } else if (dfsvisited[neighbour]) {
      return true;
    }
  }
    dfsvisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adj list
      unordered_map<int, list<int>>adj;
      for(int i=0; i<edges.size(); i++)
      {
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
      }
      //call the dfs for all components
      unordered_map<int, bool>visited;
      unordered_map<int,bool>dfsvisited;
      for(int i=1; i<=n; i++)
      {
        if(!visited[i])
        {
          bool cyclefound=checkcycledfs(i, visited, dfsvisited, adj);
          if (cyclefound)
            return true;
        }
      }
      return false;
}
