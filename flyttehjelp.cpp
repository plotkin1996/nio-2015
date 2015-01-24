#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef struct node {int parent,nextleaf;set<int> children;} node;
int root=0,lastleaf=-1,nlastleaf;

int main(int argc,char** argv)
  {
    int N;cin>>N;
    vector<node> nodes(N);
    
    for(int i=0;i<N;i++)
      {
        nodes[i].children=set<int>();
        nodes[i].parent=-1;
        nodes[i].nextleaf=-1;
      }
      
    for(int i=0;i<N-1;i++)
      {
        int a,b;cin>>a>>b;
        if(nodes[b].parent!=-1) swap(a,b);
        nodes[a].children.insert(b);
        nodes[b].parent=a;
      }
    
    for(int i=0;i<N;i++)
      {
        if(nodes[i].children.size()==0)
          {nodes[i].nextleaf=lastleaf;lastleaf=i;}
        else if(nodes[i].parent==-1) root=i;
      }
    
    while(nodes[root].children.size()!=0){
    if(nodes[root].children.size()==1)
      {
        nodes[root].nextleaf=lastleaf;lastleaf=root;
        nodes[root].parent=*nodes[root].children.begin();
        nodes[root].children.clear();
        nodes[nodes[root].parent].children.insert(root);
        root=nodes[root].parent;
        nodes[root].parent=-1;
      }
    
    
    for(nlastleaf=-1;lastleaf!=-1;lastleaf=nodes[lastleaf].nextleaf)
      {
        nodes[nodes[lastleaf].parent].children.erase(lastleaf);
        if(nodes[nodes[lastleaf].parent].children.size()==0)
          {nodes[nodes[lastleaf].parent].nextleaf=nlastleaf;nlastleaf=nodes[lastleaf].parent;}
      }
    lastleaf=nlastleaf;
    }
    
    
    cout<<root;
  }
