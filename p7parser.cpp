#include<iostream>
#include<string.h>
#include<stdio.h>

using std::cout;
using std::cin;
using std::endl;

bool A(char ch)
{
   if(ch=='b')
     {  cout<<"A->bB"<<endl;
        return true;
    }
    else
        return false;
}

int main(int argc , char *argv[])
{
   char ch;
   bool flag=false;
	FILE *fp;
	fp=fopen(argv[1],"r");

if(argc>1)
 {
   if(fp==NULL)
      cout<<" file cannot be opened or not exist ";
   else
    {
	  while((ch=getc(fp))!=EOF)
	   {
          if(ch=='c')
           {  cout<<"S->cAd"<<endl;
             ch=getc(fp);
              if(A(ch))
                {   ch=getc(fp);
                    if(ch=='d')
                     {
                        ch=getc(fp);
                        if((ch=='\n')||(ch==EOF))
                               {
                                 flag=true;
                                 cout<<"B->@"<<endl;
                                }
                              else
                               { cout<<"Extra Character"<<endl;
                                flag=false;
                                }
                     }
                    else if(ch=='a')
                    {
                        cout<<"B->aB"<<endl;
                        while((ch=getc(fp))=='a')
						{
							 cout<<"B->aB"<<endl;
						 }
						 cout<<"B->@"<<endl;
                        if(ch=='d')
                          {
                              ch=getc(fp);
                                if((ch=='\n')||(ch==EOF))
                                {
                                  flag=true;
                                }
                              else
                               { cout<<"Extra Character"<<endl;
                                flag=false;
                                }
                          }
                         else
                           flag=false;
                    }
                    else
                      flag=false;
                }
                else
                  flag=false;
           }
           else
             flag=false;
     if(ch!='\n')
         while((ch=getc(fp))!='\n') ;
     if((ch=='\n')&&(flag==true))
         {
           cout<<" string is accepted "<<"\n"<<endl;;
           flag=false;
        }
     else
         cout<<" string is  not accepted "<<"\n"<<endl;
   }
  }
 }
 else
    cout<<" enter the filname as command line arguments "<<"\n";
   return 0;

}
