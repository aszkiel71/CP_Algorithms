vector<int> leaders;
vector<int> sz;

void make_set(int x){
    leaders[x] = x;
}

int find_set(int x){
    if(x == leaders[x]) return x;
    return (leaders[x] = find_set(leaders[x])); // Compression
}

void make_set(int u, int v){
    u = find_set(u); v = find_set(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    leaders[v] = leaders[u]; // Compression - Small to Large
}

void solve(){
    int n; cin >> n;
    leaders.resize(n+1); sz.resize(n+1);
}
