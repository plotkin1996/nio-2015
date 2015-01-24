#include <iostream>
#include <vector>
using namespace std;

#define LEN 100

int main(int argc,char** argv)
  {
    int N,M;cin>>N>>M;
    int cells[100];
    
    for(int i=0;i<LEN;i++) cells[i]=i;
    
    for(int i=0;i<N;i++) {int a,b;cin>>a>>b;cells[a-1]=b-1;}
    
    int pos[2]; pos[0]=pos[1]=0;//cells[0];
    
    for(int turn=0;turn<M;turn++)
      {
        int d;cin>>d;
        if(pos[turn%2]+d>=LEN-1)
          {cout<<((turn%2==0)?"Martin ":"Lise ")<<turn/2+1<<" "<<pos[(turn+1)%2]+1;return 0;}
        pos[turn%2]=cells[pos[turn%2]+d];
      }
    cout<<pos[0]+1<<" "<<pos[1]+1;
  }
