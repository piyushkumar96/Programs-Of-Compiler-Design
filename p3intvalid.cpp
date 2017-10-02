#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main(int argc,char* argv[])
{
int n=0,i=0,c=0,s=0,j,l=0;
char str[10][50];
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
      if(j==0)
      {
         if((str[i][0]=='-')||(str[i][0]=='+'))
           {
              c++;
              s++;
           }
           else if ((str[i][0]>='1')&&(str[i][0]<='9'))
           {
              c++;
           }
           else
           {
            j=l-1;
            c=0;
           }
      }
      else  if((str[i][j]>='0')&&(str[i][j]<='9'))
      {

               c++;
               j++;
               while(j<l-1)
               {
                  if((str[i][j]>='0')&&(str[i][j]<='9'))
                  {
                     j++;
                  }
                  else
                  {
                     c=0;j=l-1;
                     break;
                  }
               }


     }
      else
        {
          c=0;
          j=l;
        }

}
 if(s==0)
     {
        if(c==1)
        {
          cout<<"valid integer"<<endl;
        }
        else
        {
          cout<<"invalid integer "<<endl;
        }
     }
     if(s==1)
     {
        if(c==2)
        {
          cout<<"valid integer"<<endl;
        }
        else
        {
          cout<<"invalid integer "<<endl;
        }
     }
   cout<<endl;
   c=0;s=0;
   i++;
}
}
else
  cout<<"provide file name as cmd line argument"<<endl;
return 0;
}
