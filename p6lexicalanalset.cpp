#include<iostream>
#include<string.h>
#include<set>
#include<stdio.h>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::string;

char del[9]={'{','}','(',')','[',']',';',',','"'};
char relopt[3]={'<','>','='};
char arthopt[5]={'/','+','-','*','%'};
string key[12]={"int","main","cout","cin","float","char","return","void","endl","getch","if","else"};

bool isalpha(char ch)
{
	if(((ch>=65)&&(ch<=90))||((ch>=97)&&(ch<=122)))
	   	return true;
	else
	  	return false;
}
bool isnum(char ch)
{
	if((ch>='0')&&(ch<='9'))
	   	return true;
	else
	  	return false;
}
bool keywords(string str)
{
    for(int i=0;i<12;i++)
	{
	   if(key[i]==str)
	     return true;
	}
	return false;
}

bool delimator(char ch)
{
  for(int i=0;i<9;i++)
	{
	   if(del[i]==ch)
	     return true;
	}
	return false;
}
bool relationalopt(char ch)
{

  for(int i=0;i<3;i++)
	{
	   if(relopt[i]==ch)
	     return true;
	}
	return false;
}
bool arithmaticopt(char ch)
{
  for(int i=0;i<5;i++)
	{
	   if(arthopt[i]==ch)
	     return true;
	}
	return false;
}
void display(const set <string>& v)
{
for(set <string>::iterator it=v.begin();it!=v.end();++it)
        cout<<*it<<"|";
}
int main(int argc , char *argv[] )
{
	set <string> constt ;
	set <string> keywor;
	set <string> identifi;
	set <string> extrachar;
	set <string> delim;
	set <string> relatopt;
	set <string> ppdirective;
	set <string> arthopt;
	set <string> comments ;
	char ch;
	string str="";
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
         if(ch==32)
            ;
         else if(isalpha(ch))
	   	   {
	   	      if(ch!='\n')
	   	         str=str+ch;
              while((ch=getc(fp))!=32)
				{
				  if(ch!='\n')
		   	       str=str+ch;
			    }
                 //str.erase(remove(str.begin(), str.end(), ' '), str.end());
              if(keywords(str))
				{
				   keywor.insert(str);
                   str="";
                }
              else
				 {
				  	identifi.insert(str);
				  	str="";
                 }
		     }
           else if(isnum(ch))
		     {
               if(ch!='\n')
		          str=str+ch;
		   	   while((ch=getc(fp))!=32)
				{
				   if(ch!='\n')
		   	         str=str+ch;
			    }
			    constt.insert(str);
			    str="";
             }
           else
		      {
		         if(ch==35)
		   	       {
                      if(ch!='\n')
		   	              str=str+ch;
		   	          while((ch=getc(fp))!='\n')
		   	             {
		   	                 if(ch!='\n')
		   	                    str=str+ch;
                        }
                      ppdirective.insert(str);
                      str="";
                    }
		   	      else if(delimator(ch))
		   	       {
                     string s1(1,ch);
		   	  	     delim.insert(s1);
                     if(ch=='"')
                        {
		   	  	          while((ch=getc(fp))!=34)
				           {
				              if(ch!='\n')
				                str=str+ch;
                           }
			              extrachar.insert(str);
			              str="";
		   	  	         }
			        }
			       else if(relationalopt(ch))
			         {
			           if(ch!='\n')
                          str=str+ch;
                       while((ch=getc(fp))!=32)
				         {
				           if(ch!='\n')
		   	                  str=str+ch;
			             }
                       if((str=="<<")||(str==">>"))
			               extrachar.insert(str);
                       else
                           relatopt.insert(str);
                       str="";
			          }
			         else if(arithmaticopt(ch))
			          {
			             string s1(1,ch);
			             if((ch=getc(fp))=='/')
			               {
                             while((ch=getc(fp))!='\n')
				                {
				                    if(ch!='\n')
		   	                        str=str+ch;
			                     }
                              comments.insert(str);
                            }
                         else
			  	              arthopt.insert(s1);
			  	         str="";
                       }
			           else
                         {
                           if(ch!=32)
			  	              extrachar.insert(str);
                           str="";
			             }
		            }

              }
	  cout<<endl<<"PREPROCCESSOR DIRECTIVE  :- |";
      display(ppdirective);

	  cout<<endl<<"\nKEYWORDS :- |";
	  display(keywor);

	  cout<<endl<<"\nIDENTIFIERS  :-  |";
      display(identifi);

	  cout<<endl<<"\nCONSTANT :- |";
	  display(constt);

      cout<<endl<<"\nDELIMATORS :- |";
      display(delim);

      cout<<endl<<"\nRELATIONAL OPERATORS :- |";
       display(relatopt);

      cout<<endl<<"\nARITHMETIC OPERATORS :- |";
      display(arthopt);

      cout<<endl<<"\nCOMMENTS  :- |";
      display(comments);

      cout<<endl<<"\nEXTRAS  :- ";
      display(extrachar);
   }
 }
	else
	cout<<" enter the filname as command line arguments";

 cout<<"\n";
return 0;
}
