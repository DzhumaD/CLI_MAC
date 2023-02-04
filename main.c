#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
extern char *optarg;

int main(int argc, char* argv[]){
    //getch();
    if (argc == 1){
        printf("Hello, world!\n");
    }
    /*int a1 = atoi(argv[1]); 
    int a2 = atoi(argv[2]);
    printf("%d \n", a1);
    printf("%d \n", a2);  */
    //char *opts = «a:b:o:»; // доступные опции, каждая принимает аргумент
    char *opts = "a:b:o:"; // доступные опции, каждая принимает аргумент
    int a, b; // тут храним числа
    char op; // а тут оператор
    int opt; // каждая следующая опция попадает сюда
    while((opt = getopt(argc, argv, opts)) != -1) { // вызываем getopt пока она не вернет -1
        switch(opt) {
            case 'a': // если опция -a, преобразуем строку с аргументом в число
                a = atoi(optarg);
                //printf("case a");
                break;
             case 'b': // тоже для -b
                 b = atoi(optarg);
                 //printf("case b");
                 break;
             case 'o': // в op сохраняем оператор
                 op = optarg[0];
                 //printf("case o");
                 break;
        }
    }
    switch(op) {
        case '+': // если опаратор + складываем, и т.д.
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d — %d = %d\n", a, b, a);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            printf("%d / %d = %d\n", a, b, a / b);
            break;
    }    
    return 0;
}