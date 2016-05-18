#include <iostream>

using namespace std;
int a[10];
int n=3,k=3,t;
void ex();
int main()
{
    t=-1;
    ex();
    return 0;
}
 void ex() {
  int i,j;

    if (t == n) {
    for (i=0;i<n;i++){
          cout<<a[i];
          }
     cout<<endl;
     } else if (t<n) {
     for (j=1;j<=k;j++){
            t++;
     a[t-1]=j;
     ex();
    t=t-1;
    }
    }
    }
