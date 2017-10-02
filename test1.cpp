#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(int argc, char* argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	char str[20][50];
	int k,n=0,l=0,i=0,j;
	bool flag=false;
	if(argc>1)
	{
		while(fgets(str[n],50,fp)!=NULL)
		   n++;
	 while(i<n)
	  {
		
		l=strlen(str[i]);
		k=l-2;
		cout<<str[i];
		for(j=0;j<((l-1)/2)+1;j++)
		{   
			if((l>3)&&(str[i][j]==str[i][k]))
			{
			   if(str[i][j]=='0')
			      cout<<"S->0S0"<<endl;
			   else if(str[i][j]=='1')
			   		 cout<<"S->1S1"<<endl;
			   else if((str[i][j]=='2')&&(j==k))
			         cout<<"S->2"<<endl;
			   else
			     {
			     	flag=false;
			     	break;
			     }
			    flag=true;
		     }
			 else 
			  {
			  	break;
			  }
			  k--;
		}
		if(flag==true)
		{
			cout<<"string is accepted"<<endl;
			flag=false;
		}
		else
		   cout<<"string is not accepted "<<endl;
		cout<<"\n";
		i++;
	  }
	}
	else
		cout<<"provide the filename at cmd line argument"<<endl;
	return 0;
	
}
