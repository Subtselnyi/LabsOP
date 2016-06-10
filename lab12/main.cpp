#include <iostream>
#include <stdio.h>
#define EMPTY

#define period(k, ...) int l=1, r = 1; \
  int c, k, b,f=0; \
  printf(__VA_ARGS__); \
  while (l != (n + 1)) { r = ((10 * r) % n); l++;} \
  c = r; \
  r = (10 * r) % n; \
  k = 1; \
  while (r != c) { r = (10 * r) % n; k++; } \
  while (l != c) { l = (10 * l) % n; f++; } \
  if (r) cout << "Max period " << k << endl; else cout<< "No period"<<endl; \
  if (r) cout<<"Pre period "<<k-f<<endl;


using namespace std;

int main()
{
  int n;
  cout << "Please enter n" << endl;
  cin >> n;
  period(2,"1/8 %s ","1/28");
  cin.get();
}
