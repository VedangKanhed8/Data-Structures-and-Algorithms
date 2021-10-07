class DSU {

  private:
    int* parent;
    int* rank;

  public:
    // constructor to initialise
    DSU(int size) {
        this->parent = new int[size+1];
        this->rank = new int[size+1];
        this->isCycle = false;
        for(int i = 1 ; i <= size ; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    // find function finds super parent of queried node
    // due to path compression it works in O(log N)
    int find(int node) {
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    
    // merge function performs merging of two components 
    // using rank optimization O(log N)
    void merge(int node1,int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        
        if(root1 == root2) return;
        
        
        if(rank[root1] > rank[root2]) {
            parent[root2] = root1;
            rank[root1] += rank[root2];
        }
        else {
            parent[root1] = root2;
            rank[root2] += rank[root1];
        }
    }
};
