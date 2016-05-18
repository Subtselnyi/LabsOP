
#include<iostream>
const int n = 4; //кол-ство цыфр
int arr[n]; //масив из цыфр
const int k = 4; //цыфры
void gex (int ); //рекурсивная функция
using namespace std;
int main()
{
int t = 0; //глубина заглубления рекурсии
gex( t);

return 0;
}
void gex( int t)  //рекурсивная функция
{
if (t == n)
{
for (int i = 0; i < n; i++)
cout<<arr[i];
cout << endl;
}
else if (t < n)
{
for (int j = 1; j < k+1; j++)
{
t++;
arr[t-1] = j;
gex( t);
t--;
}

}




}

