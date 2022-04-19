#include <bits/stdc++.h>
using namespace std;
//#define int long long
using dd = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define test int t;cin>>t;while(t--)
#define testx int t;cin>>t;for(int x=1;x<=t;x++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
vector<int>sz(1000007);
vector<int>id(1000007);
int numberOfComponents;

 
int find(int u){
    int root = u;
    while(root!=id[root]) root = id[root];//finding the root
    
    //path compression
    while(u!=root){
        int next = id[u];
        id[u] = root;
        u = next;
    }
    return root;
    
}

bool isConnected(int u , int v) 
{return (find(u)==find(v));}

void unify(int u , int v){
    int root1 = find(u);
    int root2 = find(v);
    if(root1==root2){return;}
    if (sz[root1] < sz[root2]) {
      sz[root2] += sz[root1];
      id[root1] = root2;
      sz[root1] = 0;
    } else {
      sz[root1] += sz[root2];
      id[root2] = root1;
      sz[root2] = 0;
    }
    numberOfComponents--;
}

int32_t main() {
    IOS
    int n ;
    cin>>n;
    vector<pair<int,int>>v1;
    vector<int>v2;
    numberOfComponents = n;
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
      id[i] = i; 
      sz[i] = 1; 
    }
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        if(isConnected(u,v))
        {v1.push_back({u,v});
        ans++;
        }
        unify(u,v);
    }
    for(int i = 1;i<=n;i++){
        if(find(i)!=find(1)){unify(1,i);v2.push_back(i);}
    }
    cout<<ans<<endl;
    for(int i =0;i<ans;i++){
        cout<<v1[i].first<<" "<<v1[i].second<<" "<<1<<" "<<v2[i]<<endl;
    }



}
