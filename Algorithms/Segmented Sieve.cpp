#include <bits/stdc++.h>
using namespace std;
#define int long long
using dd = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define test int t;cin>>t;while(t--)
#define testx int t;cin>>t;for(int x=1;x<=t;x++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'


int32_t main() {
    
    
    int s = 1e6;
    vector<int>prime(s);
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2;i<s;i++){
        if(prime[i])continue;
        for(int j = 2*i;j<s;j+=i){
            prime[j] = 1;
        }
    }
    test{
        int x , y;
        cin>>x>>y;
        vector<int>rp;
        for(int i = 2;i*i<=y;i++){
            if(prime[i]==0)rp.push_back(i);
        }
        vector<int>sieve(1e6);
        for(auto u: rp){
            int start = (x%u==0)?x : x+(u-(x%u));
            
            
            int i = start-x;
                for(int j =i+u ;j<=y-x;j+=u){
            sieve[j] = 1;}
            
           if(start!=u) sieve[start-x] = 1;
            
            
        }
        if(x==1){sieve[0] = 1;}
        for(int i = 0;i<=y-x;i++){
             if(sieve[i]==0)cout<<x+i<<endl;
        }
        sieve.clear();
        cout<<endl;
        
    }
}



