#include <bits/stdc++.h>
using namespace std;

map <pair <int,int>,int> store;
map <pair <int,int>,bool> check;
vector <int> a;

int seg(int l,int r)
{
    int mid=(l+r)/2;
    check[{l,r}]=true;
    if((l==r))
    {
        return store[{l,l}];
    }
    if(l>r)
    {
        return 0;
    }
    seg(l,mid);
    seg(mid+1,r);
    return store[{l,r}]=seg(l,mid)+seg(mid+1,r);
}

int query(int l,int r,int a,int b)
{ 
    int ans=0;
    int mid=(a+b)/2;
    
      if(l>b || r<a || a>b || l>r)
      {
         ans=max(ans,0);
         return ans;
      }
      else if(check[{a,b}]==true && l<=a && r>=b)
      {
          
         ans+=store[{a,b}];
         return ans;
      }
      else
      {
          ans+=query(l,r,a,mid);
          ans+=query(l,r,mid+1,b);
      return ans;
      }
}
int update(int index,int val,int a,int b)
{
    int mid=(a+b)/2;
    int ans=0;
    if(a==b && a==index)
    {
        return store[{index,index}]=val;
    }
    if(a>b)
    {
        return 0;
    }
    if(index>b || index<a)
    {
       ans+=store[{a,b}];
       return ans;
    }
    ans+=update(index,val,a,mid);
    ans+=update(index,val,mid+1,b);
    return store[{a,b}]=ans;
}
int main()
{
    int n;
    a.clear();
    int x;
    int i,j;
    int l,r;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        a.push_back(x);
        store[{i,i}]=x;
    }
    seg(0,n-1);
    update(0,100,0,n-1);
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            cout<<query(i,j,0,n-1)<<" ";
        }
        cout<<endl;
    }
    
}
