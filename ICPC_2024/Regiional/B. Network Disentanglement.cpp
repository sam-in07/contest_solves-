#include <bits/stdc++.h>
using namespace std;


struct Point {
    long long x, y;
};


int orientation(const Point& p, const Point& q, const Point& r) {
    long long val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if (val == 0LL) return 0; 
    return (val > 0LL) ? 1 : 2; 
}


bool onSegment(const Point& p, const Point& q, const Point& r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}


bool doIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {

    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);
    
    
    if (o1 != o2 && o3 != o4)
        return true;
    
    
    
    if (o1 == 0 && onSegment(p1, p3, p2)) return true;
    
  
    if (o2 == 0 && onSegment(p1, p4, p2)) return true;
    
   
    if (o3 == 0 && onSegment(p3, p1, p4)) return true;
    
   
    if (o4 == 0 && onSegment(p3, p2, p4)) return true;
    
    return false; 
}


struct HopcroftKarp {
    int n, m;
    vector<vector<int>> adj;
    vector<int> pair_u, pair_v, dist;
    
    HopcroftKarp(int size_u, int size_v) : n(size_u), m(size_v), adj(size_u + 1, vector<int>()),
        pair_u(size_u + 1, 0), pair_v(size_v + 1, 0), dist(size_u + 1, 0) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    bool bfs() {
        queue<int> q;
        for(int u=1; u<=n; u++) {
            if(pair_u[u]==0) {
                dist[u]=0;
                q.push(u);
            }
            else {
                dist[u]=INT32_MAX;
            }
        }
        dist[0] = INT32_MAX;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u != 0) {
                for(auto &v: adj[u]) {
                    if(dist[pair_v[v]] == INT32_MAX) {
                        dist[pair_v[v]] = dist[u] + 1;
                        q.push(pair_v[v]);
                    }
                }
            }
        }
        return dist[0] != INT32_MAX;
    }
    
    bool dfs(int u) {
        if(u != 0) {
            for(auto &v: adj[u]) {
                if(dist[pair_v[v]] == dist[u] + 1) {
                    if(dfs(pair_v[v])) {
                        pair_u[u] = v;
                        pair_v[v] = u;
                        return true;
                    }
                }
            }
            dist[u] = INT32_MAX;
            return false;
        }
        return true;
    }
    
    int max_matching() {
        int matching = 0;
        while(bfs()) {
            for(int u=1; u<=n; u++) {
                if(pair_u[u]==0) {
                    if(dfs(u))
                        matching++;
                }
            }
        }
        return matching;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        int N, M;
        cin >> N >> M;
        
        vector<Point> routers(N+1); 
        for(int i=1; i<=N; i++) {
            cin >> routers[i].x >> routers[i].y;
        }
        
        struct Wire {
            int index; 
            int SU, Vj;
            int ISP;
            Point p1, p2;
        };
        vector<Wire> wires(M+1); 
        for(int i=1; i<=M; i++) {
            int SU, Vj, IS;
            cin >> SU >> Vj >> IS;
            wires[i].index = i;
            wires[i].SU = SU;
            wires[i].Vj = Vj;
            wires[i].ISP = IS;
            wires[i].p1 = routers[SU];
            wires[i].p2 = routers[Vj];
        }
       
        vector<Wire> A; 
        vector<Wire> B; 
        for(int i=1; i<=M; i++) {
            if(wires[i].ISP == 1) A.push_back(wires[i]);
            else B.push_back(wires[i]);
        }
        int sizeA = A.size();
        int sizeB = B.size();

        HopcroftKarp hk(sizeA, sizeB);
        
        for(int i=0; i<sizeA; i++) {
            for(int j=0; j<sizeB; j++) {
                // Check if A[i] and B[j] cross or touch
                Wire wa = A[i];
                Wire wb = B[j];
                if(doIntersect(wa.p1, wa.p2, wb.p1, wb.p2)) {
                    // Add edge between A[i+1] and B[j+1]
                    hk.addEdge(i+1, j+1);
                }
            }
        }
        
        int matching = hk.max_matching();
        
        vector<bool> freeA(sizeA+1, false);
        for(int u=1; u<=sizeA; u++) {
            if(hk.pair_u[u]==0) freeA[u] = true;
        }
        
        vector<bool> visitedA(sizeA+1, false);
        vector<bool> visitedB(sizeB+1, false);
        queue<int> q;
        
        for(int u=1; u<=sizeA; u++) {
            if(freeA[u]) {
                q.push(u);
                visitedA[u] = true;
            }
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &v : hk.adj[u]) {
                if(!visitedB[v]) {
                    visitedB[v] = true;
                    if(hk.pair_v[v]!=0 && !visitedA[hk.pair_v[v]]) {
                        visitedA[hk.pair_v[v]] = true;
                        q.push(hk.pair_v[v]);
                    }
                }
            }
        }

        vector<int> vertexCover;
       
        for(int u=1; u<=sizeA; u++) {
            if(!visitedA[u]) {
                
                vertexCover.push_back(A[u-1].index);
            }
        }
        
        for(int v=1; v<=sizeB; v++) {
            if(visitedB[v]) {
                
                vertexCover.push_back(B[v-1].index);
            }
        }
        
        cout << "Case #" << test_case << ":\n";
        cout << vertexCover.size() << "\n";
        if(vertexCover.empty()) {
            cout << "\n";
        }
        else {
          
            sort(vertexCover.begin(), vertexCover.end());
            for(int i=0; i<vertexCover.size(); i++) {
                if(i > 0) cout << " ";
                cout << vertexCover[i];
            }
            cout << "\n";
        }
    }
}
