#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;
vector <char> c= {'+','*','(',')','i','$'};
vector <char> r={'f','g'};
stack <char> st ;
int arr[12]={2,4,0,4,4,0,1,3,5,0,5,0};
queue <char> que;
map <pair <char,char> , int > m;
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
void stackpush(char ch) {
st.push(ch);  que.pop();
cout<<st.top()<<"     ";
dispstack(); dispexp();
cout<<"    Shift ->"<<ch<<endl;
}
void calculation1() {
c1=st.top(); st.pop(); c2=st.top(); st.pop(); c3=st.top(); st.pop(); st.push('E');
if((c3=='(')&&(c1==')'))
{  cout<<st.top()<<"     ";
dispstack(); dispexp();
cout<<"      F->"<<c3<<c2<<c1<<" T->F E->T"<<endl;
}
else if(c2=='+') {  
cout<<st.top()<<"     ";
dispstack(); dispexp();
cout<<"      E->T E->"<<c3<<c2<<"T"<<endl;
}
else if(c2=='*') {  cout<<st.top()<<"     ";
dispstack(); dispexp();
cout<<"      E->T E->T T->F E->T*F"<<endl;
}
else { cout<<"String is not accepted "<<endl;
exit(0);
} }
void calulation2() {
st.pop();
st.push('E');
cout<<st.top()<<"     ";
dispstack(); dispexp();
cout<<"     F->i T->F E->T"<<endl;
}
void stackpop(char ch ) {
if((ch!='$')&&(st.top()=='i'))
calulation2();
else if((ch!='$')&&(st.top()!='i'))
calculation1();
else if (ch=='$') {
if(st.top()=='i')
calulation2();
calculation1();
if((st.size()==2)&&(st.top()=='E')) {
cout<<" String is accepted "<<endl;
exit(0);
} }
else
calculation1();
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
} }
st.push('$');
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
if((u.top()=='+')||(u.top()=='$')||(u.top()=='*')||(u.top()=='(')||(u.top()==')')||(u.top()=='i')) {
top=u.top();
break;
}
}
if((m[make_pair('f',top)])<=(m[make_pair('g',ch)])) {
if(ch!='$') {
stackpush(ch);
ch=getc(fp);
}
else
break;
}
else
stackpop(ch);
} } }
else
cout<<" filename as cmd line args "<<"\n";

cout<<" String is not accepted "<<endl;
return 0;
}

