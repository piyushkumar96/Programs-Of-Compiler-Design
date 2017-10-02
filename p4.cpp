#include<iostream>
#include<stdio.h>
#include<string.h>

using std::cout;
using std::cin;
using std::endl;

int main( int argc, char *argv[] )
{
    bool flag = true;
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
                       cout<<"b is expected after a"<<endl;
                       flag=false;
                    }
                    else if (c==2)
                    {
                       cout<<"c or b is expected after b"<<endl;
                       flag=false;
                    }
                    else
                    {
                      cout<<"extra character is entered"<<endl;
                      flag=false;
                    }
                    break;
        case 'b':   if(c==0)
                      {
                      cout<<" a is expected before b"<<endl;
                      flag=false;
                      }
                    else if(c==1)
                      c++;
                    else if(c==2)
                      { }
                    else
                      {
                      cout<<" extra character is entered"<<endl;
                      flag=false;
                      }
                      break;
        case 'c':  if(c==0)
                      {
                      cout<<"a is expected before c"<<endl;
                      flag=false;
                      }
                    else if (c==1)
                      {
                       cout<<"b is expected before c"<<endl;
                       flag=false;
                      }
                   else if (c==2)
                        c++;
                   else
                       {
                        cout<<" extra character is entered"<<endl;
                        flag=false;
                       }
                     break;
        case '\n': break;
        default: cout<<"extra character is entered"<<endl;
                 flag=false;
                  break;

        }
    if(flag==false)
    {
      c=0;
      cout<<" string is not accepted \n "<<endl;
      while((choice=getc(fp))!='\n'){ }
      flag=true;
    }
   else
    {
     if(((choice=='\n')||(choice==EOF))&&(flag==true))
      {
        cout<<"string is accepted \n"<<endl;
        c=0;
      }
    }
   }
 }
 else
 {
  cout<<" provide filename as command line arguments \n";
 }
return 0;

}
