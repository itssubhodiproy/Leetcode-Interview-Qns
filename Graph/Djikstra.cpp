priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> dis(n + 1, INT_MAX);// 1-indexed array for calculating shortest paths;
    dis[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty()){
        int node = pq.top().second;pq.pop();
        for (auto it : adj[node]){
            int nextNode = it.first;
            int wt = it.second;
            if (dis[nextNode] > dis[node] + wt){
                dis[nextNode] = dis[node] + wt;
                pq.push({dis[nextNode], nextNode});
            }
        }
    }
