#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <string>

using namespace std;

struct catalog
{
	string type;
	string name;
    int number;
    string lang;
    string author; //Books only
    string genre; // Books only
    int year; //Books and magazines
    int countNumber; //Magazines and newspapers
    string theme; //Magazines and newspapers
    string date; //Newspapers only
};




int countRecords = 0;
catalog tempForRecords = {"","",0,"","","",0,0,"",""};



vector <catalog> dataBase;
vector <catalog> BookAuthor;


void showBooks();
void printMenu();
void insertBook();
void insertMagazine();
void insertNewspaper();
void showCatalog();
void generateCatalog();
void showMagazines();
void toBinaryFile();

void OutputBookAuthor();
void createBinary();


int main() {

    setlocale(LC_ALL, "Russian");

	dataBase.reserve(100);

while (true)
    {

       	printMenu();
        char ch = getchar();
        //system("clear");

        switch (ch)
        {
            case '1': showCatalog(); break;  //Вывод в алфавтином порядке книг указанного автора, выданных в указанный период
            case '2': generateCatalog(); break;  //Генерация каталога
            case '3': showMagazines(); break;  //Показать газеты и журналы
            case '5': createBinary(); break; //Вывод БД в консоль
           // case '5': toBinaryFile(); break; //вывод в бинарник
            case '4': OutputBookAuthor(); break;
            case 'q': return 0; break;
            case 'Q': return 0; break;
            default: printf("");
        }

        getchar();

    }
}


void printMenu() {


 	printf("\n\n*****Menu*****\n");
    printf("1: Show books\n");
    printf("2: Generate Catalog\n");
    printf("3: Ukrainian media\n");
    printf("4: Show catalog\n");
    printf("5: Create Binary\n");
    printf("6: Output Book \n");


    printf("Q: Exit.\n");
    printf("**************\n");
}



void showCatalog() {  //Вывод таблицы

printf("%-25s%-25s%-15s%-20s%-25s%-25s%-10s%-25s%-20s%-20s\n\n\n", "Тип", "Название", "№", "Язык", "Автор", "Жанр", "Год", "Издание №", "Тема", "Дата" );

	for (int i=0; i<dataBase.size(); ++i) {
		printf("%-20s%-20s%-10d%-20s%-20s%-20s%-10d%-10d%-20s%-20s\n", dataBase[i].type.c_str(), dataBase[i].name.c_str(), dataBase[i].number, dataBase[i].lang.c_str(), dataBase[i].author.c_str(), dataBase[i].genre.c_str(), dataBase[i].year, dataBase[i].countNumber, dataBase[i].theme.c_str(), dataBase[i].date.c_str() );
	}

}


    /*
    string type;
    string name;
    int number;
    string lang;
    string author; //Books only
    string genre; // Books only
    int year; //Books and magazines
    int countNumber; //Magazines and newspapers
    string theme; //Magazines and newspapers
    string date;  */

void generateCatalog() {     //Авто-генерация пользователей

const int types = 3;
const int bookNames = 7;
const int magazineNames = 7;
const int newspaperNames = 5;
const int langs = 3;
const int authors = 10;
const int genres = 7;
const int years = 20;
//const int numbers = 12;
const int themes = 5;
const int dates = 5;


    string typicalTypes[types] =
    {
        "Book",
        "Newspaper",
        "Magazine"
    };

    string typicalBooksNames[bookNames] =
    {
        "50 shades of gray",
        "Human's centipede",
        "Harry Potter",
        "Pussy - killer",
        "The Hunger Games",
        "Twilight",
        "Animal farm"   //Books list end

    };

    string typicalMagazinesNames[magazineNames] =
    {
        "Game Informer",
        "National Geographic",
        "Men's Health",
        "PlayBoy",
        "Maxim",
        "Woman's day",
        "IGM"

    };

    string typicalNewspapersNames[newspaperNames] =
    {

        "The NY Times",
        "Forbes",
        "Washington Post",
        "Daily news",
        "LA Times" //Newspapers list end


    };

    string typicalLangs[langs] =
    {
        "Russian",
        "English",
        "Ukrainian"
    };

string typicalAuthors[authors] =
    {
        "Author1",
        "Author2",
        "Author3",
        "Author4",
        "Author5",
        "Author6",
        "Author7",
        "Author8",
        "Author9",
        "Author10"
    };


string typicalGenres[genres] =
{
    "Horror",
    "Humor",
    "Triller",
    "Drama",
    "Science",
    "Erotica",
    "AnimalTechnoPunk"

};

    int typicalYears[years] =
    {
        1961,
        1967,
        1972,
        1973,
        1986,
        1989,
        1990,
        1995,
        1960,
        1962,
        1967,
        1971,
        1983,
        1984,
        1974,
        1950,
        1952,
        2000,
        1999,
        1949
    };

string typicalThemes[themes] =
{
    "Theme 1",
    "Theme 2",
    "Theme 3",
    "Theme 4",
    "Theme 5"
};

string typicalDates[dates] =
{
    "11.11.2011",
    "12.54.2072",
    "09.01.1998",
    "07.43.1002",
    "04.16.2009"

};



int n;
//string name;
//string surname;
//int year;

cout<<"Сколько записей генерировать? "; cin>>n;
    for (int i=0;i<n;i++) {
        int fuck = (rand() % 3) + 1;

        if (fuck == 1) {
                string type = "book";
                string name = typicalBooksNames[rand() % bookNames];
                countRecords++;
                string lang = typicalLangs[rand() % langs];
                string author = typicalAuthors[rand() % authors];
                string genre = typicalGenres[rand() % genres];
                int year = typicalYears[rand() % years];

                 catalog temp = {type,name,countRecords,lang,author,genre,year,-1,"",""};
                 dataBase.push_back(temp);

           }

        if (fuck == 2) {
                string type = "magazine";
                string name = typicalMagazinesNames[rand() % magazineNames];
                countRecords++;
                int number = (rand() % 99) + 1;
                string lang = typicalLangs[rand() % langs];
                int year = typicalYears[rand() % years];
                string theme = typicalThemes[rand() % themes];

                 catalog temp = {type,name,countRecords,lang,"","",year,number,theme,""};
                 dataBase.push_back(temp);

                    }
        if (fuck == 3) {
                string type = "newspaper";
                string name = typicalNewspapersNames[rand() % newspaperNames];
                countRecords++;
                int number = (rand() % 99) + 1;
                string lang = typicalLangs[rand() % langs];
                string date = typicalDates[rand() % dates];
                string theme = typicalThemes[rand() % themes];

               catalog temp = {type,name,countRecords,lang,"","",-1,number,theme,date};
                 dataBase.push_back(temp);

            }



        }



printf("Записи добавлены в базу данных\n");

}

void showMagazines(){
    int countM=0,countN=0;
        cout<<dataBase[2].type;
    for (int i=0;i<dataBase.size();i++){

        if ((dataBase[i].lang=="Ukrainian")&&(dataBase[i].type=="magazine")){
            countM++;
        }
        if ((dataBase[i].lang=="Ukrainian")&&(dataBase[i].type=="newspaper")) {
            countN++;
        }
    }
    cout<<"количество журналов украинского производителя "<<countM<<endl;
    cout<<"количество газет украинского производителя "<<countN<<endl;

}

void OutputBookAuthor(){
    string Author;
    int amount = 0;
    printf("\nВведіть автора\n");
    cin >> Author;

    int first_year;
    int second_year;

    printf("\nВведіть початок проміжку\n");
    cin >> first_year;

    printf("\nВведіть кінець проміжку\n");
    cin >> second_year;


    BookAuthor.reserve(100);

    for(int i = 0; i < dataBase.size(); i++){
        if(dataBase[i].type == "book" && Author == dataBase[i].author && dataBase[i].year > first_year && dataBase[i].year < second_year){
            amount++;
            catalog temp = {dataBase[i].type, dataBase[i].name, dataBase[i].number,  dataBase[i].lang, dataBase[i].author, dataBase[i].genre, dataBase[i].year, -1, "", ""};
            BookAuthor.push_back(temp);
        }
    }

    for (int i = 0; i < BookAuthor.size(); i++){
		for (int j = BookAuthor.size() - 1; j > i; j--) {     // внутренний цикл прохода
			if (BookAuthor[j - 1].name > BookAuthor[j].name) {
				swap(BookAuthor[j - 1].type, BookAuthor[j].type);
				swap(BookAuthor[j - 1].name, BookAuthor[j].name);
				swap(BookAuthor[j - 1].number, BookAuthor[j].number);
				swap(BookAuthor[j - 1].lang, BookAuthor[j].lang);
				swap(BookAuthor[j - 1].author, BookAuthor[j].author);
				swap(BookAuthor[j - 1].genre, BookAuthor[j].genre);
				swap(BookAuthor[j - 1].year, BookAuthor[j].year);
			}
        }

	}

	printf("%-25s%-25s%-15s%-20s%-25s%-25s%-10s%-25s%-20s%-20s\n\n\n", "Тип", "Название", "№", "Язык", "Автор", "Жанр", "Год", "Издание №", "Тема", "Дата" );

	for (int i = 0; i<BookAuthor.size(); ++i) {
		printf("%-20s%-20s%-10d%-20s%-20s%-20s%-10d%-10d%-20s%-20s\n", BookAuthor[i].type.c_str(), BookAuthor[i].name.c_str(), BookAuthor[i].number, BookAuthor[i].lang.c_str(), BookAuthor[i].author.c_str(), BookAuthor[i].genre.c_str(), BookAuthor[i].year, BookAuthor[i].countNumber, BookAuthor[i].theme.c_str(), BookAuthor[i].date.c_str() );
	}
    printf("\nAmount = %d\n", amount);
}

void createBinary(){

    int first_year;
    int second_year;
    int amount = 0;
    printf("\nВведіть початок проміжку\n");
    cin >> first_year;

    printf("\nВведіть кінець проміжку\n");
    cin >> second_year;

    BookAuthor.reserve(100);

    for(int i = 0; i < dataBase.size(); i++){
        if(dataBase[i].lang == "English" && dataBase[i].year > first_year && dataBase[i].year < second_year){
            amount++;
            catalog temp = {dataBase[i].type, dataBase[i].name, dataBase[i].number,  dataBase[i].lang, dataBase[i].author, dataBase[i].genre, dataBase[i].year, -1, "", ""};
            BookAuthor.push_back(temp);
        }
    }

     for (int i = 0; i < BookAuthor.size(); i++){
		for (int j = BookAuthor.size() - 1; j > i; j--) {     // внутренний цикл прохода
			if (BookAuthor[j - 1].type > BookAuthor[j].type) {
				swap(BookAuthor[j - 1].type, BookAuthor[j].type);
				swap(BookAuthor[j - 1].name, BookAuthor[j].name);
				swap(BookAuthor[j - 1].number, BookAuthor[j].number);
				swap(BookAuthor[j - 1].lang, BookAuthor[j].lang);
				swap(BookAuthor[j - 1].author, BookAuthor[j].author);
				swap(BookAuthor[j - 1].genre, BookAuthor[j].genre);
				swap(BookAuthor[j - 1].year, BookAuthor[j].year);
			}
        }

	}

	FILE *f;
	f= fopen("output","wb+");
	for (int i=0;i<BookAuthor.size(); i++){
        fwrite((char*)&BookAuthor[i],sizeof(BookAuthor[i]),i,f);
	}
	fclose(f);



}
