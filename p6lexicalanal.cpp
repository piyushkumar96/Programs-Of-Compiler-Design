#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::unique;

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
void  remduplicates(vector <string>& v)
{
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(), v.end()),v.end());

}
void display(const vector <string>& v)
{
for(int i=0;i<v.size();i++)
        cout<<v[i]<<"|";
}
int main(int argc , char *argv[] )
{
	vector <string> constt ;
	vector <string> keywor;
	vector <string> identifi;
	vector <string> extrachar;
	vector <string> delim;
	vector <string> relatopt;
	vector <string> ppdirective;
	vector <string> arthopt;
	vector <string> comments ;
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
				   keywor.push_back(str);
                   str="";
                }
              else
				 {
				  	identifi.push_back(str);
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
			    constt.push_back(str);
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
                      ppdirective.push_back(str);
                      str="";
                    }
		   	      else if(delimator(ch))
		   	       {
                     string s1(1,ch);
		   	  	     delim.push_back(s1);
                     if(ch=='"')
                        {
		   	  	          while((ch=getc(fp))!=34)
				           {
				              if(ch!='\n')
				                str=str+ch;
                           }
			              extrachar.push_back(str);
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
			               extrachar.push_back(str);
                       else
                           relatopt.push_back(str);
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
                              comments.push_back(str);
                            }
                         else
			  	              arthopt.push_back(s1);
			  	         str="";
                       }
			           else
                         {
                           if(ch!=32)
			  	              extrachar.push_back(str);
                           str="";
			             }
		            }

              }
	  cout<<endl<<"PREPROCCESSOR DIRECTIVE  :- |";
      display(ppdirective);

	  cout<<endl<<"\nKEYWORDS :- |";
	  remduplicates(keywor);
	  display(keywor);

	  cout<<endl<<"\nIDENTIFIERS  :-  |";
      remduplicates(identifi);
      display(identifi);

	  cout<<endl<<"\nCONSTANT :- |";
	  remduplicates(constt);
	  display(constt);

      cout<<endl<<"\nDELIMATORS :- |";
      remduplicates(delim);
      display(delim);

      cout<<endl<<"\nRELATIONAL OPERATORS :- |";
       remduplicates(relatopt);
       display(relatopt);

      cout<<endl<<"\nARITHMETIC OPERATORS :- |";
      remduplicates(arthopt);
      display(arthopt);

      cout<<endl<<"\nCOMMENTS  :- |";
      remduplicates(comments);
      display(comments);

      cout<<endl<<"\nEXTRAS  :- ";
      remduplicates(extrachar);
      display(extrachar);
   }
 }
	else
	cout<<" enter the filname as command line arguments";

 cout<<"\n";
return 0;
}
