#include <iostream>

using namespace std;

struct Tree{
    char symbol;
    int depth;
    Tree *parent;
    Tree *left;
    Tree *right;
};
Tree *mainvertex;
int depth;
void add_symbol(char c,Tree *&MyTree)
{
	if (NULL==MyTree)
	{
		MyTree=new Tree;
		MyTree->symbol=c;
		MyTree->depth=0;
		MyTree->parent=NULL;
		MyTree->left=MyTree->right=NULL;
	}

                   if (int(c)<int(MyTree->symbol))
                      {
                          if (MyTree->left!=NULL) add_symbol(c,MyTree->left);
                          else
                          {
                              MyTree->left=new Tree;
                              MyTree->left->left=MyTree->left->right=NULL;
                              MyTree->left->symbol=c;
                              MyTree->left->parent=MyTree;
                              MyTree->left->depth=MyTree->depth+1;
                          }
                      }

                    if (int(c)>int(MyTree->symbol))
                      {
                          if (MyTree->right!=NULL) add_symbol(c,MyTree->right);
                          else
                          {
                              MyTree->right=new Tree;
                              MyTree->right->left=MyTree->right->right=NULL;
                              MyTree->right->symbol=c;
                              MyTree->right->parent=MyTree;
                              MyTree->right->depth=MyTree->depth+1;
                          }
                      }
}

void show(Tree *MyTree)
{
	if (MyTree!=NULL)
	{
	   show(MyTree->left);
	   cout<<MyTree->symbol;
	   show(MyTree->right);
	}
}

void find_symbol(char c,Tree *MyTree){
    if (c==MyTree->symbol){
        cout<<"depth="<<MyTree->depth<<endl;
    }
    if (int(c)<int(MyTree->symbol)){
        find_symbol(c,MyTree->left);
    }
    if (int(c)>int(MyTree->symbol)){
        find_symbol(c,MyTree->right);
    }
}


int main()
{
    Tree *MyTree=NULL;
      char c;
	  for (int i=5;i>0;i--) {
        cout<<"Enter symbol"<<endl;
        cin>>c ;
        add_symbol(c,MyTree);

	  }
	 show(MyTree);
	 depth=0;
        cout<<endl<<"what symbol to find"<<endl;
        cin>>c;

        find_symbol(c,MyTree);
    return 0;
}
