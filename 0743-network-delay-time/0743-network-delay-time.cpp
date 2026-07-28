class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
    // Step 1: Create graph
    vector<pair<int,int>> adj[n+1];
    
    for(auto &t : times){
        int u = t[0];
        int v = t[1];
        int w = t[2];
        adj[u].push_back({v, w});
    }
    
    // Step 2: Distance array
    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;
    
    // Step 3: Min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, k});
    
    // Step 4: Dijkstra
    while(!pq.empty()){
        auto t = pq.top();
        int d = t.first;
        int node = t.second;
        pq.pop();
        
        if(d > dist[node]) continue;
        
        for(auto it : adj[node]){
            int next = it.first;
            int wt = it.second;
            
            if(dist[node] + wt < dist[next]){
                dist[next] = dist[node] + wt;
                pq.push({dist[next], next});
            }
        }
    }
    
    // Step 5: Find answer
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }
    
    return ans;
}
    
};