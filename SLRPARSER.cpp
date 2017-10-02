#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;
vector <char> r= {'0','1','2','3','4','5','6','7','8','9','@','#'};
vector <char> c={'+','*','(',')','i','$','E','T','F'};
vector <string> pr={"","EE+T","ET","TT*F","TF","F(E)","Fi"};
stack <char> st ;
queue <char> que;
string arr[108]={"","","s4","","s5","","1","2","3",
                 "s6","","","","","A","","","",
				 "r2","s7","","r2","","r2","","","",
				 "r4","r4","","r4","","r4","","","",
				 "","","s4","","s5","","8","2","3",
				 "r6","r6","","r6","","r6","","","",
				 "","","s4","","s5","","","9","3",
				 "","","s4","","s5","","","","@",
				 "s6","","","s#","","","","","",
				 "r1","s7","","r1","","r1","","","",
				 "r3","r3","","r3","","r3","","","",
				 "r5","r5","","r5","","r5","","",""};
map <pair <char,char> , string > m;
FILE *fp,*fpp;
char top,ch,chh,c1,c2,c3;
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
void stackpush(char ch,char c1) {
st.push(ch); st.push(c1); que.pop();
cout<<st.top()<<"     ";
dispstack(); dispexp();
cout<<"    Shift to state "<<c1<<endl;
}
void stackpop(int i ) {
st.pop(); st.pop(); 
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
} }
for (auto q = r.begin();q!=r.end();++q ) {
for (auto w = c.begin() ; w != c.end();++w) {
cout<<m[(make_pair(*q,*w))]<<" ";
} 
cout<<endl;
}
st.push('0');
if(argc>1) {
if(fp==NULL)
cout<<" file cannot be opened or not exist ";
else {
cout<<"\nPR  E->E+T|T T->T*F|F F->(E)|i \n"<<endl;
cout<<" TOP  STACK   EXPRESS "<<"\n";
cout<<st.top()<<"     ";
dispstack(); dispexp();
cout<<endl;
ch=getc(fp);
while(ch!=EOF) {
for (auto u = st; !u.empty(); u.pop()) {
   if((u.top()=='0')||(u.top()<='1')||(u.top()<='2')||(u.top()<='3')||(u.top()<='4')||(u.top()<='5')||(u.top()<='6')||(u.top()<='7')||(u.top()<='8')||(u.top()<='9')||(u.top()=='#')||(u.top()=='@')) {
      top=u.top();
       break;
}
}
string s1,s2,s3;
char c1,c2,c0;
s1=(string)(m[make_pair(top,ch)]);
c0=(char)s1[0];
if(c0=='s')
{
	//cout<<"push called"<<"    ";
	c1=(char)s1[1];
  	stackpush(ch,c1);
  	ch=getc(fp);
  	
}
else if(c0=='r')
{
	//cout<<"pop called"<<"    ";
	 c1=(char)s1[1];
	 int i=(int)c1-48;
	 s2=pr[i];
	 int l=s2.length()-1;
	// cout<<"l= "<<l<<"   ";
	 while(l>0)
	 {
	 	stackpop(i);
	 	l--;
	 }
	c2=(char)s2[0];
	 st.push(c2);
	 for (auto u = st; !u.empty(); u.pop()) {
   if((u.top()=='0')||(u.top()<='1')||(u.top()<='2')||(u.top()<='3')||(u.top()<='4')||(u.top()<='5')||(u.top()<='6')||(u.top()<='7')||(u.top()<='8')||(u.top()<='9')||(u.top()=='#')||(u.top()=='@')) {
      top=u.top();
       break;
}
}
	 s3=(string)(m[make_pair(top,c2)]);
	 c2=(char)s3[0];
	 st.push(c2);
	 cout<<st.top()<<"     ";
dispstack(); dispexp();
cout<<"      Reduce using PR "<<pr[i]<<endl;
}
else if(c0=='A'){
	cout<<"String is accepted"<<endl;
	exit(0);
}
else{
	cout<<"String is not accepted"<<endl;
exit(0);
}
} 
} 
}
else
cout<<" filename as cmd line args "<<"\n";

cout<<" String is not accepted "<<endl;
return 0;
}

