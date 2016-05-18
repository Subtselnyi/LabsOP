#include <iostream>
#include <stdio.h>
#include "header.h"
#include <errno.h>
#include <cstring>
#include <istream>


using namespace std;

char name1[20],name2[20],nameNew[20]="newfile.txt";
char array1[20][50], array2[20][50];
int index1,index2;
/*int create(char name[20]){
FILE *f;
char *str;
int y=0;
int index=0;
char ch;

f=fopen(name,"wt+");

 cout<<"Enter string in to file "<<name<<endl;
 cout<<"how many strings"<<endl;
 cin>>index;
     do{
   // scanf("%s",str);
   cin.getline(str,40);
   //ch=getchar();
    strcat(str,"\n");
    fputs (str,f);
     y++;
     //index++;
     }while (y<index+1);



fclose(f);
return index+1;
}

void input(char *name, char words[20][50]){
FILE *f;
int i = 0;
f = fopen(name, "rt");
while(!feof(f)){
    fgets( words[i++],50,f);
}

}

void output(char name[20]){
FILE *f;
char ch;
char str[200];
int i=0;
f=fopen(name,"rt");

while((ch=getc(f))!=EOF)
    str[i++]=ch;

str[i]='\0';
printf("%s",str);
fclose(f);
}

void find_Equal(){
    FILE *f;
    f = fopen("newfile.txt","wt+");
    for (int i=0;i<index1;i++){
        for (int j=0;j<index2;j++){
            if (!strcmp(array1[i],array2[j])){
                fputs(array1[i],f);
            }

        }
    }
    fclose(f);
}*/
/*void getArray(char name[20]){
    FILE *f;
    f=fopen(name,"rt");

    char ch;
    int i=0,j=0;

    while((ch=getc(f))!=EOF){
            j=0;
        while(ch!='\n'){
            if (!strcmp(name,name1)){
            array1[i][j++]=ch;
            }
            if (!strcmp(name,name2)){
            array2[i][j++]=ch;
            }
            ch=getc(f);

            if (ch==EOF){break;}
        }
        i++;

    }

    fclose(f);
}*/



/*void findEqual(){
    char str_help[20],*str1,*str2;

    for (int i=0;i<index1;i++){
        str1=strtok(text1,"\n");
    cout<<"str1="<<str1<<endl;
            for (int k=0;k<i;k++)
            str1=strtok(NULL,"\n");
        strcpy(str_help,text2);
        str2=strtok(str_help,"\n");
        cout<<"str1= "<<str1<<endl;
        for (int j=0;j<index2;j++){

            cout<<"str2= "<<str2<<endl;
            if (strcmp(str1,str2)==0){
                cout<<"yep";
            }
            str2=strtok(NULL,"\n");
        }

    }
}
*/

int main()
{

    cout<<"Enter first file name"<<endl;
    gets(name1);
    cout<<"Enter second file name"<<endl;
    gets(name2);

    index1= create(name1);
    index2= create(name2);


    cout<<endl;
    input(name1,array1);
    input(name2,array2);

    find_Equal(array1,array2,index1,index2);

    cout<<"First file "<<name1<<endl<<endl;
    output(name1);
    cout<<endl;
    cout<<"Second file "<<name2<<endl;
    output(name2);
    cout<<endl;

    cout<<"New file "<<nameNew<<endl;
   output(nameNew);
   cout<<endl<<"Add ti file"<<name1<<endl;
   add(name1);
   cout<<"first file"<<name1<<endl;
   output(name1);
    return 0;
}
