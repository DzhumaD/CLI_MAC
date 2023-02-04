#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
extern char *optarg;


int main(int argc, char* argv[]){
    if (argc == 1){
        printf("Hello, world!\n");
    }
    char *opts = "m:"; // доступные опции, каждая принимает аргумент
    char a; // тут храним мак - адрес
    int b; 
    char op; // а тут оператор
    int opt; // каждая следующая опция попадает сюда
    while((opt = getopt(argc, argv, opts)) != -1) { // вызываем getopt пока она не вернет -1
        switch(opt) {
            case 'm': // если опция -a, преобразуем строку с аргументом в число
                //a = optarg[2];
                //b = atoi(a);
                printf("%s",optarg);printf("\n");
                break;
        }
    } 
    return 0;
}