#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
#define FRAME 1000003
#define COLORS 100

int main(int argc,char** argv)
  {
    int result=0;
    int R;cin>>R;
    vector<set<int> > knights(R);
    for(int i=0;i<R;i++)
      {
        int n;for(cin>>n;n>0;n--){int m;cin>>m;knights[i].insert(m);}
      }
      
    for(set<int>::iterator startcolor=knights[0].begin();startcolor!=knights[0].end();startcolor++)
      {long long int total=1; vector<long long int> state(COLORS,0); state[*startcolor]=1;
        for(vector<set<int> >::iterator knight=knights.begin()+1;knight!=knights.end();knight++)
          {
            vector<long long int> newstate(COLORS,0);long long newtotal=0;
            for(set<int>::iterator color=knight->begin();color!=knight->end();color++)
              newtotal=(newtotal+(newstate[*color]=(total-state[*color])%FRAME));
            total=newtotal;state=newstate;
          }
        result=(result+total-state[*startcolor])%FRAME;
      }
    cout<<result;
  }
