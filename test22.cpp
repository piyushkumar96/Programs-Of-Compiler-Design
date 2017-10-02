//(a/b)*a(a/b)
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(int argc, char *argv[])
{
	char str[10][50];
	int n=0,l,j,i=0,c=0;
	bool flag =true;
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(argc>1)
	{
		 while(fgets(str[n],50,fp)!=NULL)
		    n++;
		 while(i<n)
		 {
		 	l=strlen(str[i]);
		 	cout<<str[i];
		 	for(j=0;j<l-1;j++)
		 	{
		 		switch(str[i][j])
		 		{
		 			case 'a': if(c==0)
		 			             {
		 			             	c++;
		 			             }
		 			             else if(c==1)
		 			             {
		 			             	c++;
		 			             	flag=true;
		 			             }
		 			             else 
		 			             {
		 			             }
		 			             break;
		 			case 'b':if(c==0) {
		 				                 flag=false;
		 			                  }
		 			         else if(c==1)
		 			         {
		 			         	c++;
		 			         	flag=true;
		 			         }
		 			         else
		 			         {
		 			         	if(j!=l-2)
		 			         	  {
		 			         	  	flag=false;
		 			         	c=0;
		 			         	  }
		 			         }
		 			          break;
		 			default:flag=false;j=l;
		 			        break;
		 			        
		 		}
		 	}
		 	if((flag==true)&&(c!=0))
		 	   cout<<"String is accepted "<<endl;
		 	else 
		 		cout<<"String is not accepted "<<endl;
		 	cout<<"\n";
		 	i++;
		 	c=0;
		 	
		 }   
	}
	else 
	 	cout<<" provide the filename as cmd line input"<<endl;
	return 0;
}
