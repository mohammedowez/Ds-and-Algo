class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // make a adjcent list 
        vector<pair<int,int>> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }  

        // use the same as dijkstra algorithm 
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<int>> dist;

        for(int i=0;i<n;i++){
            vector<int> temp(n,1e9);
            temp[i]=0;

            pq.push({0,i});
            while(!pq.empty()){

                int node =pq.top().second;
                int dis=pq.top().first;
                pq.pop();

                for(auto it : adj[node]){
                    int adjdis=it.first;
                    int edgW=it.second;
                    
                    if(edgW+dis < temp[adjdis]){
                        temp[adjdis]=edgW+dis;
                        pq.push({temp[adjdis],adjdis});
                    }
                } 
            } 
            dist.push_back(temp);
        } 

// find the minimum city as this 
         int mini = INT_MAX;
        int city = -1;
        for(int i = 0; i<n ; i++){
            int count = 0;
            for(int j = 0; j<n ; j++){
                if(dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            // cout << "COUNT: " << count << endl;
            if(count <= mini){
                mini = count;
                city = i;
            }
        }
        
        return city;





    }
};
