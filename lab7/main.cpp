#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

char str[100];  //строка, с которой оперируем
char newstr[100]; //конечная строка
void change(char [],char []); // функция,


int main()
{
    puts("enter string:");
    gets(str);            //вводим строку
    change(str,newstr);             //вызов функции
    puts (newstr);        //выводим новую строку
    return 0;
}

void change(char str[], char newstr[])       //функция
{
    int counter=0;               //счетчик
    char delimitr[]={' ','\0'};  //разделитель
    char *p;                     // бъявление строка
    char strrevers[100];         //объявление вспомагательной строки

    p=strtok(str,delimitr);      //разделяем строку
    counter++;

    strcat(newstr,p);            //добавляем в новую строку

     while (p!=NULL){

       p=strtok(NULL, delimitr);
       counter++;
       if (p!=NULL){
         if (counter%2==0){

           for (int i=0;i<strlen(p);i++){
            strrevers[i]=p[strlen(p)-(i+1)];   //инвертируем строку

           }
        strrevers[strlen(p)]='\0';          //конец строки на strlen(p) -том елементе
        strcat(newstr," ");
        strcat(newstr,strrevers);

        } else
          {
           strcat(newstr," ");
           strcat(newstr,p);
          }
      }

    }


}
