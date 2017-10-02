#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
#include<stdio.h>
using namespace std;
vector <char> r= {'E','D','T','S','F'};
vector <char> c={'(','i','+','*',')','$'};
stack <char> st ;
queue <char> que;
string arr[30]={"TD","TD","","","","","","","+TD","","@","@","FS","FS","","","","","","","@","*FS","@","@","(E)","i","","","",""};
map <pair <char,char> , string > m;
FILE *fp,*fpp;
char top,ch,chh;
int i=0;
bool flag=false;
string s1;
void dispstack() {
for (auto u = st; !u.empty(); u.pop())
      cout << u.top();
cout<<"       ";
}
void dispexp() {
for(auto u = que ; !u.empty();u.pop())
    cout<<u.front();
cout<<"       ";
}
void stackpush(string s1,char top) {
int l;
dispstack(); dispexp();
cout<<st.top()<<"->";
st.pop();
l=s1.length();
char c1[l];
strcpy(c1,s1.c_str());
cout<<c1<<endl;;
l=sizeof(c1)-1;
if(s1!="@") {
while(l>=0) {
st.push(c1[l]);
--l;
} } }
void stackpop(char top ) {
if(top==ch) {
st.pop(); que.pop();
dispstack(); dispexp();
cout<<"poping "<<ch;
if(ch==EOF)
    cout<<" string is accepted"<<endl;
ch=getc(fp);
if(top=='$')
    flag=true;
}
else {
cout<<" String is not accepted "<<endl;
exit(0);
}
cout<<"\n";
}
int main(int argc , char *argv[]) {
fp=fopen(argv[1],"r");
fpp=fopen(argv[1],"r");
while((chh=getc(fpp))!=EOF) {
if(chh!='\n')
que.push(chh);
}
int i=0;
for (auto q = r.begin();q!=r.end();++q ) {
   for (auto w = c.begin() ; w != c.end();++w) {
        m.insert(make_pair(make_pair(*q,*w),arr[i++]));
      }
}
cout<<"Parsing table"<<endl;
for (auto q = r.begin();q!=r.end();++q ) {
     for (auto w = c.begin() ; w != c.end();++w) {
         cout<<m[(make_pair(*q,*w))]<<" ";
       }
  cout<<endl;
}
cout<<"\n\n";
st.push('$'); st.push('E');
if(argc>1) {
  if(fp==NULL)
   cout<<" file cannot be opened or not exist ";
else {
cout<<" TOP  STACK   EXPRESS   ACTION  "<<"\n";
ch=getc(fp);
while(ch!=EOF) {
top=st.top();
cout<<top<<"     ";
switch(top)
{
 case 'E':  s1=m[make_pair('E',ch)];
 			stackpush(s1,top);
			break;
case 'D':  s1=m[make_pair('D',ch)];
			stackpush(s1,top);
			break;
case 'T' : s1=m[make_pair('T',ch)];
			stackpush(s1,top);
			break;
case 'S':  s1=m[make_pair('S',ch)];
			stackpush(s1,top);
			break;
case 'F':  s1=m[make_pair('F',ch)];
			stackpush(s1,top);
			break;
case 'i':  stackpop(top);
			break;
case '+':  stackpop(top);
			break;
case '$':  stackpop(top);
			break;
case '*':  stackpop(top);
			break;
case '(':  stackpop(top);
			break;
case ')':  stackpop(top);
			break;
default:   cout<<" String is not accepted "<<endl;
		exit(0);
}

if(flag==true)
{
cout<<" string accepted "<<endl;
break;
}
}
}
}
else
cout<<"filename at cmd line "<<"\n";
return 0;
}
