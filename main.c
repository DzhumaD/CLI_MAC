#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
extern char *optarg;
void announce(void);
int valid_mac(char *m);

int main(int argc, char* argv[]){
    
    const char *opts = "m:"; // доступные опции, каждая принимает аргумент
    char *mac_addr; // тут храним мак - адрес
    int opt; // каждая следующая опция попадает сюда

    if (argc == 1){ //команда без аргументов
        announce(); 
        return 0;
    }
    /**
     * Чтение команды. Проверка опции. Возврат MAC-адреса.
    */
    while((opt = getopt(argc, argv, opts)) != -1) { // вызываем getopt пока она не вернет -1
        switch(opt) {
            case 'm': 
                mac_addr = optarg;
                printf("Мак-адрес для проверки: %s\n",mac_addr);//printf("");
                break;
            default:
                printf("Неизвестный тест\n");
                return 1; //неизвестный тест    
        }
    }
    return valid_mac(mac_addr); 
}
/**
 * Приветствие пользователя. Описание функционала.
*/
void announce (void){
    printf("Утилита проверки MAC-адреса.\n");
    printf("usage: test [-m] <mac_adress>\n");
    printf("Пример команды: $ test -m 01:02:03:AA:BB:CC\n");
    //return 0;
}
/**
 *  Проверка корректности MAC-адреса. 0 - корректный. 2 - некорректный.
*/
int valid_mac(char *m){
    int i=0;
    int n=0; //число адреса
    while(m[i] != '\0'){  
        n = m[i]; 
        if((i+1)%3){
            if(!(48<=n && n<=57 || 'A'<=n && n<='F' || 'a'<=n && n<='f')){
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
}



