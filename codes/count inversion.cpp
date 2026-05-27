#include <vector>
using namespace std;

long long merge(vector<int>& a, int l, int mid, int r){
    int i=l, j=mid+1;
    vector<int> temp;
    long long inv=0;

    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            temp.push_back(a[i++]);
        }
        else{
            temp.push_back(a[j++]);
            inv += (mid-i+1);
        }
    }

    while(i<=mid) temp.push_back(a[i++]);
    while(j<=r) temp.push_back(a[j++]);

    for(int k=l;k<=r;k++)
        a[k]=temp[k-l];

    return inv;
}

long long mergesort(vector<int>& a,int l,int r){
    if(l>=r) return 0;

    int mid=(l+r)/2;

    long long inv=0;
    inv+=mergesort(a,l,mid);
    inv+=mergesort(a,mid+1,r);
    inv+=merge(a,l,mid,r);

    return inv;
}