#include <bits/stdc++.h>
using namespace std;

bool canMake(vector<long long> &coins, long long n){
    
    long long g = coins[0];
    for(auto c:coins) g = __gcd(g,c);
    
    if(n % g != 0) return false;

    for(auto &c:coins) c/=g;
    n/=g;

    long long m = *min_element(coins.begin(),coins.end());

    vector<long long> dist(m,LLONG_MAX);
    priority_queue<pair<long long,long long>,
        vector<pair<long long,long long>>,
        greater<pair<long long,long long>>> pq;

    dist[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d,r]=pq.top();
        pq.pop();

        if(d!=dist[r]) continue;

        for(auto c:coins){
            long long nr=(r+c)%m;
            long long nd=d+c;

            if(nd<dist[nr]){
                dist[nr]=nd;
                pq.push({nd,nr});
            }
        }
    }

    return dist[n % m] <= n;
}

int main(){
    int k;
    cin>>k;

    vector<long long> coins(k);
    for(auto &x:coins) cin>>x;

    long long n;
    cin>>n;

    cout<<(canMake(coins,n)?"YES":"NO");
}