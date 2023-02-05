#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
extern char *optarg;

int main(int argc, char* argv[]){
    /*Описание функций пользователю*/
    if (argc == 1){
        printf("Утилита проверки MAC-адреса.\n");
        printf("usage: test [-m] <mac_adress>\n");
        printf("Пример команды: $ test -m 01:02:03:AA:BB:CC\n");
        return 0;
    }

    char *opts = "m:"; // доступные опции, каждая принимает аргумент
    char *a; // тут храним мак - адрес
    int opt; // каждая следующая опция попадает сюда
    while((opt = getopt(argc, argv, opts)) != -1) { // вызываем getopt пока она не вернет -1
        switch(opt) {
            case 'm': // если опция -a, преобразуем строку с аргументом в число
                a = optarg;
                printf("Мак-адрес для проверки: %s\n",a);//printf("");
                break;
            default:
                printf("Неизвестный тест\n");
                return 1; //неизвестный тест    
        }
    }
    int i=0;
    while(a[i] != '\0'){    
        if((i+1)%3){
            if( !(48<=a[i] && a[i]<=57 || 'A'<=a[i] && a[i]<='F' || 'a'<=a[i] && a[i]<='f') ){
                printf("Некорректный MAC-адрес: недопустимые символы. Символ № %d.\n", i+1);
                return 2; //недопустимые символы
            }           
        }
        i++;
    }
    if(i != 17){
        printf("Некорректный MAC-адрес: несоответствие числа символов\n");
        return 2; // нехватка данных
    } 
    printf("Корректный MAC-адрес\n");
    return 0;
}

void annonce()