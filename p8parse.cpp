#include<iostream>
#include<string.h>
#include<stdio.h>

using std::cout;
using std::cin;
using std::endl;

bool A(char ch)
{
   if((ch=='p')||(ch=='q'))
   {
        cout<<"S->AaB"<<endl<<"A->"<<ch<<endl;
        return true;
   }
    else
        return false;
}
bool B(char ch)
{
   if(ch=='x')
    {
       cout<<"B->"<<ch<<"C"<<endl;
        return true;
    }
   else if(ch=='z')
    {
	   cout<<"B->"<<ch<<endl;
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
              if(A(ch))
                {
				   ch=getc(fp);
                    if(ch=='a')
                     {
                     	ch=getc(fp);
                        if(B(ch))
                        {
                        	if(ch=='z')
                        	{
                        		if(((ch=getc(fp))=='\n')||(ch=getc(fp))!=EOF)
                                  {
                                    flag=true;
							      }
                                else
                                  flag=false;
                                if((ch==EOF)||(ch!='\n'))
                                      {
                                        flag=false;
                                        cout<<"Extra character "<<endl;
                                        while((ch=getc(fp))!='\n') ;
                                      }
                            }
                           else if(ch=='x')
                             {
                               while((ch=getc(fp))=='x')
							      {
							      	 cout<<"C->xC"<<endl;
								   }

                                if((ch=='z')||(ch=='y'))
                                 {
                                 	 char c=ch;
                                 	if(((ch=getc(fp))=='\n')||(ch=getc(fp))!=EOF)
                                 	  {
									   cout<<"C->"<<c<<endl;
								       flag=true;
							          }
                                    else
                                      {
                                       flag=false;
                                      }
                                    if((ch==EOF)||(ch!='\n'))
                                      {
                                        flag=false;
                                        cout<<"Extra character "<<endl;
                                        while((ch=getc(fp))!='\n') ;
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
           }
           else
             flag=false;
     if(ch!='\n')
         while((ch=getc(fp))!='\n') ;

     if((ch=='\n')&&(flag==true))
         {
           cout<<" string is accepted "<<endl;
           flag=false;
        }
     else
         cout<<" string is  not accepted "<<endl;
   }
  }
 }
 else
    cout<<" enter the filname as command line arguments ";
   return 0;

}
