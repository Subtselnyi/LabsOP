#include <iostream>
#include <stdio.h>
//#include <string.h>
#include <errno.h>
#include <cstring>
#include <istream>


using namespace std;


int create(char name[20]){
FILE *f;
char str[200];
int y=0;
int index=0;
char ch;

f=fopen(name,"wt+");

 cout<<"Enter string in to file "<<name<<endl;
 ch=getchar();
    while (int(ch)!=123){
             if (ch=='\n') index++;
        str[++y]=ch;
        ch=getchar();
    }
    str[y+2]='\0';
fputs (str,f);
fflush(f);
fclose(f);
return index;
}

void input(char *name, char words[20][50]){
FILE *f;
int i = 0;
f = fopen(name, "rt");
while(!feof(f)){
    fgets( words[++i],50,f);
}

}

void output(char name[20]){
FILE *f;
char ch;
char str[200];
int i=0;
f=fopen(name,"rt");

while((ch=getc(f))!=EOF)

    str[++i]=ch;

str[i+1]='\0';
printf("%s \n",str);
fclose(f);
}

void find_Equal(char array1[20][50],char array2[20][50],int index1,int index2){
    FILE *f;
    f = fopen("newfile.txt","wt+");
    for (int i=0;i<index1+1;i++){
        for (int j=0;j<index2+1;j++){
            if (!strcmp(array1[i],array2[j])){
                fputs(array2[j],f);
                fflush(f);
            }

        }
    }
    fclose(f);
}

void add(char name[20]){
   FILE *f;
   char str[200];
int y=0;
int index=0;
char ch;
   f = fopen(name,"at");
   ch=getchar();
        while (int(ch)!=123) {

        str[++y]=ch;
        ch=getchar();
    }
    str[y]='\0';
fputs (str,f);
fflush(f);
   fclose(f);
}


