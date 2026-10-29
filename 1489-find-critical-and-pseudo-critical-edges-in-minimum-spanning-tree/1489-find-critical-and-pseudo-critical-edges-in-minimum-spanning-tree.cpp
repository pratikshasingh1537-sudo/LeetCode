class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int V){
        parent.resize(V);
        size.resize(V,1);
        for(int i=0;i<V;i++) parent[i]=i;
    }

    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu=find(u), pv=find(v);
        if(pu==pv) return;

        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
private:
    int mst_builder(vector<vector<int>>& edges,int blocked,int forced,int n){
        DisjointSet dsu(n);
        int mst_wt=0, usedEdges=0;

        if(forced!=-1){
            dsu.unionBySize(edges[forced][0],edges[forced][1]);
            mst_wt+=edges[forced][2];
            usedEdges++;
        }

        for(int i=0;i<edges.size();i++){
            if(i==blocked || i==forced) continue;

            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            if(dsu.find(u)!=dsu.find(v)){
                dsu.unionBySize(u,v);
                mst_wt+=wt;
                usedEdges++;
            }
        }

        return usedEdges==n-1 ? mst_wt : INT_MAX;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int totalEdges=edges.size();
        vector<bool> isCritical(totalEdges,false);

        for(int i=0;i<totalEdges;i++)
            edges[i].push_back(i);

        sort(edges.begin(),edges.end(),
             [](vector<int>& a,vector<int>& b){
                return a[2]<b[2];
             });

        int mst_wt=mst_builder(edges,-1,-1,n);

        vector<int> critical, pseudoCritical;

        for(int i=0;i<totalEdges;i++){
            if(mst_builder(edges,i,-1,n)>mst_wt){
                critical.push_back(edges[i][3]);
                isCritical[i]=true;
            }
        }

        for(int i=0;i<totalEdges;i++){
            if(!isCritical[i] &&
               mst_builder(edges,-1,i,n)==mst_wt){
                pseudoCritical.push_back(edges[i][3]);
            }
        }

        return {critical,pseudoCritical};
    }
};