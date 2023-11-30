#include <bits/stdc++.h>
using namespace std;
long long st[4*100000+1];
long long value[100000+1];

long n;
long long con(int a,int l,int r)
{
    if(l==r)
    {
        st[a]=value[l];
        return st[a];
    }
    int mid;
    mid=(l+r)/2;
    st[a]=con((2*a)+1,l,mid)+con((2*a)+2,mid+1,r);
    return st[a];
}

long long getsum(int a,int x,int y,int l,int r)
{
    
    
    int mid;
    if(x>r || l>y)
    {
        return 0;
    }
    else if(l<=x && y<=r)
    {
        return st[a];
    }
    else
    {
        mid=(x+y)/2;
        return getsum((2*a)+1,x,mid,l,r)+getsum((2*a)+2,mid+1,y,l,r);
    }
}
void update(int a,int x,int y,int pos,int val)
{
    int mid;
    mid=(x+y)/2;
    if(x>pos || y<pos)
    {
        return;
    }
      st[a]+=(val-value[pos]);
     if(x!=y)
    {
      
        update((2*a)+1,x,mid,pos,val);
        update((2*a)+2,mid+1,y,pos,val);
    }
}



int main()
{
    
    cin>>n;
 
    long long  i,j;
    vector <long long> dp(n,0);
    for(i=0; i<n; i++)
    {
       cin>>value[i]; 
    }
    
}


