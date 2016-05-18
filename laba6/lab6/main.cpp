#include <iostream>

using namespace std;
int n=3,k=3,l;
int arr[10];
int *p;
void ex();
void ix();
int main()
{
    for (int i=0;i<n;i++)
        arr[i]=1;
        l=n-1;
        p=arr;
        for (int i=0;i<n;i++)
            cout<<arr[i];
        cout<<endl;
        ex();
        l=n;
        ix();
    return 0;
}

void ex ()
{

    for (int j=2;j<=k;j++)
    {
        *(p+l)=j;
        for (int i=0;i<n;i++)
            cout<<*(p+i);
            cout<<endl;
    }
    l--;
    if (*p!=arr[n-1]){
    ex();

    }


}

void ix ()
{

    for (int j=k;j>=1;j--)
    {
        *(p+l)=j;
        for (int i=0;i<n;i++)
            cout<<*(p+i);
            cout<<endl;
    }
    l--;
    if (*p!=arr[n-1]){
    ix();

    }


}
