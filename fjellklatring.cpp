#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
#define infinity 1000000001

typedef struct {int x,y;} v2;

typedef struct {int x,y,l;}search;

int main(int argc,char** argv)
  {
    int n,m;cin>>n>>m;
    vector<vector<int> > map(n,vector<int>(m));
    vector<vector<int> > levels(n,vector<int>(m,infinity));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
      cin>>map[i][j];
    
    queue<v2> attractions;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
      {int a;cin>>a;if(a==1) attractions.push((v2){i,j});}
    v2 pivot=attractions.front();attractions.pop();
    
    queue<search> q;q.push((search){pivot.x,pivot.y,0});
    while(!q.empty())
      {
        search c=q.front();q.pop();
        if(c.x>0)
          {
            int ld=max(c.l,abs(map[c.x][c.y]-map[c.x-1][c.y]));
            if(ld<levels[c.x-1][c.y]) levels[c.x-1][c.y]=ld,q.push((search){c.x-1,c.y,ld});
          }
        if(c.y>0)
          {
            int ld=max(c.l,abs(map[c.x][c.y]-map[c.x][c.y-1]));
            if(ld<levels[c.x][c.y-1]) levels[c.x][c.y-1]=ld,q.push((search){c.x,c.y-1,ld});
          }
        if(c.x<n-1)
          {
            int ld=max(c.l,abs(map[c.x][c.y]-map[c.x+1][c.y]));
            if(ld<levels[c.x+1][c.y]) levels[c.x+1][c.y]=ld,q.push((search){c.x+1,c.y,ld});
          }
        if(c.y<m-1)
          {
            int ld=max(c.l,abs(map[c.x][c.y]-map[c.x][c.y+1]));
            if(ld<levels[c.x][c.y+1]) levels[c.x][c.y+1]=ld,q.push((search){c.x,c.y+1,ld});
          }
      }
      
    int result=0;
    while(!attractions.empty())
      {
        if(levels[attractions.front().x][attractions.front().y]>result)
          result=levels[attractions.front().x][attractions.front().y];
          attractions.pop();
      }
    cout<<result;
  }
