// *Time Complexity: O( N ) { Additional log(N) of time eliminated here because we’re using a simple queue rather than a priority queue which is usually used in Dijkstra’s Algorithm }.

// Where N = Number of flights / Number of edges.

// Space Complexity:  O( |E| + |V| ) { for the adjacency list, priority queue, and the dist array }.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //create the adjcent list of pair, the form of a graph
        vector<pair<int,int>> adj[n];

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }


        // Create a queue which stores the node and their distances from the
        // source in the form of {stops, {node, cost}} with ‘stops’ indicating 
        // the no. of nodes between src and current node.

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});


         // Distance array to store the updated distances from the source.
        vector<int> dist(n,1e9);
        dist[src]=0;


        // code 
        while(!q.empty()){

            auto it =q.front();
                q.pop();
            
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;

            if(stops>k)
                continue;

            for(auto itr : adj[node]){
                int adjNode = itr.first;
                int edW = itr.second;

                // We only update the queue if the new calculated dist is
                // less than the prev and the stops are also within limits.  

                if(stops<=k and edW+cost<dist[adjNode]){
                    dist[adjNode]=edW+cost;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                } 
            }
        }

        // If the destination node is unreachable return ‘-1’
        // else return the calculated dist from src to dst.


        if(dist[dst]==1e9)
            return -1;
        return dist[dst];

    }
};
