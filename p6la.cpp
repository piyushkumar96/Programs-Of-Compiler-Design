#include<iostream>
#include<fstream>
using namespace std;
string check(string &tk);
int main()
{
string strname,tk;
ifstream f;
f.open("la.cpp");
ofstream fo;
fo.open("b.txt");
char c,d,ch[1];
int r;
while(getline(f,strname)!=NULL)
{
int n=strname.length();
for(int i=0;i<n;i++)
{
r=0;
c=strname[i];
d=strname[i+1];
if(c==' ') continue;
if(c=='\n') continue;
if(c=='\t') continue;
ch[0]=c;
fo.write(ch,1);
if((c=='+'&&d=='+')||(c=='-'&&d=='-')||(c=='!'&&d=='=')
||(c=='+'&&d=='=')||(c=='-'&&d=='=')||(c=='*'&&d=='=')
||(c=='/'&&d=='=')||(c=='='&&d=='=')||(c=='%'&&d=='d')
||(c=='%'&&d=='f')||(c=='%'&&d=='s')||(c=='%'&&d=='u')||(c=='%'&&d=='c')
||(c=='|'&&d=='|')||(c=='&'&&d=='&'))
{
i++;
r=1;
ch[0]=d;
fo.write(ch,1);
ch[0]='\n';
fo.write(ch,1);
} 
if(isdigit(c)||isalpha(c))
{
if(!isdigit(d)&&!isalpha(d))
{
ch[0]='\n';
fo.write(ch,1);
}	
}
else if(r==0)
{
ch[0]='\n';
fo.write(ch,1);
}
}
}
fo.close();
ifstream fi;
fi.open("b.txt");
while(getline(fi,tk)!=NULL)
{
string r=check(tk);
cout<<tk<<"\t\t\t"<<r<<endl;	
}
}
string check(string &tk)
{
if(tk=="void"||tk=="main"||tk=="int"||tk=="printf"
||tk=="if"||tk=="break"||tk=="float"||tk=="double"
||tk=="char"||tk=="while"||tk=="do"||tk=="for"||tk=="continue"
||tk=="scanf")
{
return "keywords";
}
else if(tk=="("||tk==")"||tk=="{"
||tk=="}"||tk==";"||tk==","||tk==""""||tk=="["||tk=="]"||tk=="%"
||tk=="@"||tk=="#"||tk=="$"||tk=="&"||tk==":"||tk=="'")
{
return "delimeters";
}
else if(tk=="="||tk=="++"||tk=="=="||tk=="+"||tk=="--"
||tk=="+="||tk=="-="||tk=="*="||tk=="/="||tk=="!="||
tk=="%d"||tk=="%f"||tk=="%u"||tk=="%s"||tk=="<"||tk==">"||tk=="%c"
||tk=="&&"||tk=="||"||tk==".")
{
return "operators";
}
else if(isdigit(tk[0]))
{
return "constants";
}
else	{
return "identifiers";
}
}
