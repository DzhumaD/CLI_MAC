#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
extern char *optarg;

/*
* 0...9 = 48...57
* : = 58
* A...F = 65...70
*/
int main(int argc, char* argv[]){
    if (argc == 1){
        printf("Hello, world!\n");
    }
    char *opts = "m:"; // доступные опции, каждая принимает аргумент
    char *a; // тут храним мак - адрес
    //char b[17]; 
    //char op; // а тут оператор
    int opt; // каждая следующая опция попадает сюда
    while((opt = getopt(argc, argv, opts)) != -1) { // вызываем getopt пока она не вернет -1
        switch(opt) {
            case 'm': // если опция -a, преобразуем строку с аргументом в число
                a = optarg;
                //b = atoi(a);
                printf("Мак-адрес для проверки: %s\n",a);//printf("");
                break;
            default:
                return 1; //неизвестный тест    
        }
    }
    /*if(a[17] == '\0'){
        printf("Конец строки\n");
    }*/
    int count = 0;
    int i=0;
    //int check = 0;
    while(a[i] != '\0'){    
        if((i+1)%3){
            if( !(48<=a[i] && a[i]<=57 || 'A'<=a[i] && a[i]<='F' || 'a'<=a[i] && a[i]<='f') ){
                printf("Некорректный MAC-адрес: недопустимые символы. Символ № %d.\n", i+1);
                return 2; //недопустимые символы
            }           
        }
        i++;
    }
    if(i < 17){
        printf("Некорректный MAC-адрес: нехватка данных");
        return 2; // нехватка данных
    } 
    printf("Корректный MAC-адрес\n");
    return 0;
}