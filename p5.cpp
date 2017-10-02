#include<iostream>
#include<stdio.h>
#include<string.h>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[])
{
    bool flag = false;
    char choice;
    int c=0;
 FILE *fp;
 fp=fopen(argv[1],"r");
if(argc>1)
{
  while((choice=getc(fp))!=EOF)
  {
     switch(choice)
     {  case 'a' : if(c==0)
                        c++;
                    else if((c==1))
                    {
                       c=1;
                       flag=false;
                    }
                    else if (c==2)
                    {
                      c=0;
                      flag=false;
                    }
                    else if(c==3)
                    {
                      c=1;
                      flag=false;
                    }
                    else
                    {
                      c=0;
                      flag=false;
                    }
                    break;
        case 'b':   if(c==0)
                      {
                      }
                    else if(c==1)
                      c++;
                    else if(c==2)
                      { c++;
                       flag=true;
                      }
                    else
                      {
                      c=0;
                      flag=false;
                      }
                      break;
        case '\n': break;
       }
    if((choice=='\n')&&(flag==false))
      {
        cout<<"String is not accepted \n"<<endl;
        c=0;
      }

     if(((choice=='\n')||(choice==EOF))&&(flag==true))
      {
        cout<<"string is accepted \n"<<endl;
        c=0;
        flag=false;
      }

   }
 }
else
  cout<<" provide filename as command line arguments \n";
return 0;

}
