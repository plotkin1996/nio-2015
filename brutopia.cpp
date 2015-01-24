#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(int argc,char** argv)
  {
    int K,N;
    map<int,int> m;
    int result=0,group=0,maxgroup=0;
    
    for(cin>>K>>N;N!=0;N--)
      {
        int a,b;cin>>a>>b;
        if(m.find(a)==m.end()) m[a]= 1; else m[a]+=1;
        if(m.find(b)==m.end()) m[b]=-1; else m[b]-=1;
      }
    for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
      {
        group+=i->second;
        if(group==0) result+=maxgroup,maxgroup=group=0;
        if(group>maxgroup) maxgroup=group;
      }
    cout<<result;
  }
