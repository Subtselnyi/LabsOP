#include <iostream>

using namespace std;

struct Node{
    float number;
    Node *Next;
    Node *Prev;
};

    Node *head=NULL;
    Node *last=NULL;
    Node *current=NULL;
    Node *temp=NULL;
    Node *newList=NULL;

  void add_number(float num)
{
    if(head!=NULL)
     {
        newList=new Node;
        newList->number=num;
        newList->Next=NULL;
        newList->Prev=current;
        current->Next=newList;
        last=newList;
        current=newList;
     }
     else
     {
         newList=new Node;
         newList->number=num;
         head=newList;
         newList->Next=NULL;
         newList->Prev=NULL;
         current=newList;
          last=head;
     }
}

void search_number(float num)
{
     newList=head;
     while(newList!=last->Next)
     {
         if(newList->number==num)
         {
             cout<<"Element was found\n";
         }
        newList=newList->Next;
     }
}

void show_list()
{
  struct Node *info;
  info = head;
  while(info)
  {
    cout<<info->number<<" ";
    info = info->Next;
  }
  cout<<"\n";
}

int main()
{
    float num,lastnum;
    int n;

    cout<<"kol-tvo el-ov"<<endl;
    cin>>n;
    float *p = new float [n];
    for (int i=0;i<n;i++){
        cout<<"vvodi number"<<i+1<<endl;
        cin>>num;
        *(p++)=num;
    }
    lastnum=*(--p);
    for (int i=0;i<n-1;i++){
            add_number(*(p-n+i+1)*lastnum);
    }
    show_list();
    return 0;
}
