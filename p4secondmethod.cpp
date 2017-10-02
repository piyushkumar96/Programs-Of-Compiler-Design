#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int main(int argc ,char* args[])
{   string   str ;
 string strch,strline;
 char ch;
    int i,n,c=0,line=0;
    FILE *fp;
      fp=fopen("input.txt","r");
    while((ch=getc(fp))!=EOF)
    {
       	  str=str+ch;
     if(ch=='\n')


     n=str.length()-1;
 }
    for(i=0;i<n;i++)
       {
       	 if(i==0)
       	 {
       	 	if(str[0]=='a')
       	 	  c++;
       	 	else
       	 	{
       	 	   cout<<" 'a' is expected as starting \n ";
       	 	   c=0;
       	 	   i=n;
       	   }
       	}
       	else
       	{
       		if(str[i]=='b')
       		{
       		   while(i<n)
       		   {
       		         if(str[i]=='b')
						{
							i++;
						}
					  else if(str[i]=='c')
					  {
					  	c++;
					  	break;
					  }
					  else
					  {
					  	cout<<"'c' is expected after 'b' ";
					  	i=n;
					  	c=0;
					  }
			  }
			  if(str[i]=='c')
			  {
			  	c++;
			  	i++;
			  	while(i<n)
			  	{
			  		cout<<"extra character in string  ";
			  		i=n;
			  		c=0;
				}
			  }
		   }
		  else
		   {
		     cout<<"'b' is expected after 'a' ";
			 i=n;
			 c=0;
		   }

		}
	 }



    if(c==3)
	cout<<" string is accepted  ";
	else
	cout<<" string is not accepted ";
	return 0;
}
