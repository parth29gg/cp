#include <bits/stdc++.h>
using namespace std;

bool canMake(long long a, long long b, long long n) {
    long long g = __gcd(a,b);

    if(n % g != 0) return false;

    a /= g;
    b /= g;
    n /= g;

    long long frob = a*b - a - b;

    if(n > frob) return true;

    for(long long x = 0; x*a <= n; x++){
        if((n - x*a) % b == 0)
            return true;
    }

    return false;
}

int main(){
    long long a,b,n;
    cin >> a >> b >> n;

    if(canMake(a,b,n))
        cout << "YES\n";
    else
        cout << "NO\n";
}