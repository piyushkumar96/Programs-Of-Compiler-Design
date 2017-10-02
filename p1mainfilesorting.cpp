#include<bits/stdc++.h>
using namespace std;

extern sorting(int [],int );
int main()
{
  int n,a[100],i;
  cin>>n;

  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sorting(a,n);
  cout<<"sorted array";
  for(i=0;i<n;i++)
  {
    cout<<a[i]<<"\t";
  }
return 0;
}
