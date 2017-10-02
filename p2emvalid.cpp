#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(int argc,char* argv[])
{
FILE *fp;
fp=fopen(argv[1],"r");
int n=0,c=0,i=0,j,l;
char email[10][50];
if(argc>1)
 {
	while(fgets(email[n],50,fp)!=NULL)
		n++;
while(i<n)
 {
    l=strlen(email[i]);
    cout<<email[i];
    for(j=0;j<l-1;j++)
    {
          if(j==0)
          {
             if(((email[i][0]>='a')&&(email[i][0]<='z'))||((email[i][0]>='A')&&(email[i][0]<='Z'))||((email[i][0]>='0')&&(email[i][0]<='9')))
                 {
                    c++;
                 }

          }
          else{

                while(j<l-1)
                {
                   if(((email[i][j]>='a')&&(email[i][j]<='z'))||((email[i][j]>='A')&&(email[i][j]<='Z'))||((email[i][j]>='0')&&(email[i][j]<='9')))
                    {
                      j++;
                    }
                   else if(email[i][j]=='@')
                    {
                          break;
                    }
                    else
                    {
                      j=l-1;
                      c=0;
                    }
                }
                if(email[i][j]=='@')
                {
                    c++;
                    j++;
                    if(((email[i][j]>='a')&&(email[i][j]<='z'))||((email[i][j]>='A')&&(email[i][j]<='Z'))||((email[i][j]>='0')&&(email[i][j]<='9')))
                    {
                      j++;
                      c++;
                      while(j<l-1)
                      {
                        if(((email[i][j]>='a')&&(email[i][j]<='z'))||((email[i][j]>='A')&&(email[i][j]<='Z'))||((email[i][j]>='0')&&(email[i][j]<='9')))
                         {
                          j++;
                         }
                         else if (email[i][j]=='.')
                         {
                           break;
                         }
                         else
                         {
                           c=0;
                           j=l-1;
                           break;
                         }
                       }
                       if(email[i][j]=='.')
                       {
                           c++;
                           j++;
                               if(((email[i][j]>='a')&&(email[i][j]<='z'))||((email[i][j]>='A')&&(email[i][j]<='Z'))||((email[i][j]>='0')&&(email[i][j]<='9')))
                                 {
                                    j++;
                                    c++;
                                    while(j<l-1)
                                    {
                                        if(((email[i][j]>='a')&&(email[i][j]<='z'))||((email[i][j]>='A')&&(email[i][j]<='Z'))||((email[i][j]>='0')&&(email[i][j]<='9')))
                                        {
                                            j++;
                                        }
                                        else
                                          {
                                            c=0;
                                            j=l-1;
                                            break;
                                          }
                                    }
                                 }
                                else
                                 {
                                    c=0;
                                    j=l-1;
                                 }
                        }
                        else
                         {
                           c=0;
                           j=l-1;
                         }
                     }
                     else
                      {
                       c=0;
                       j=l-1;
                      }
               }
               else
                {
                c=0;
                j=l-1;
                }
         }
    }
        if(c==5)
        cout<<"email address is valid"<<endl;
        else{
        cout<<"email address is not valid"<<endl;
            }
    cout<<"\n";
     c=0;
     i++;
}
}
else
  cout<<"provide filename as cmd line argument "<<endl;
return 0;
}
