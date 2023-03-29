//
// Created by Valentin Gouriev on 21.03.23.
//
#include "loccale.h"
#define MAX_DATE_LEN 10
#define MAX_NAME_LEN 50


int input(int min, int max){
    int x;
    while (scanf("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void task2() {

#define MAX_DATE_LEN 10
#define MAX_NAME_LEN 50

    typedef struct {
        int count;
        char *name;
        struct {
            char date[MAX_DATE_LEN];
            int lifespan;
        } info;
    } Animal;



    int n; // количество животных
    char search_name[MAX_NAME_LEN]; // название для поиска
    int search_count; // количество особей для удаления

    // запрашиваем количество животных
    printf("Enter the number of animals: ");
    scanf("%d", &n);

    // создаем массив структур
    Animal *animals = (Animal *) malloc(n * sizeof(Animal));

    // заполняем массив структур данными
    for (int i = 0; i < n; i++) {
        animals[i].name = (char *) malloc(MAX_NAME_LEN * sizeof(char));
        printf("Enter the name of the animal: ");
        scanf("%s", animals[i].name);
        printf("Enter the count of the animal: ");
        while (scanf("%d", &animals[i].count) != 1) {
            printf("Error: invalid input\n");
            fflush(stdin);
        }
        printf("Enter the date of admission (DD.MM.YYYY): ");
        scanf("%s", animals[i].info.date);
        /*char date[DATE_LENGTH];
        int day, month, year, timeBack;
        do {
            printf("Введите дату в формате DD.MM.YYYY: ");
            fgets(date, DATE_LENGTH, stdin);

            // Проверяем правильность формата ввода
            if (strlen(date) != DATE_LENGTH - 1 || date[2] != '.' || date[5] != '.') {
                printf("Неправильный формат даты.\n");
                timeBack = 0;
            }

            // Извлекаем значения дня, месяца и года
            day = atoi(date);
            month = atoi(date + 3);
            year = atoi(date + 6);

            // Проверяем, что значения дня, месяца и года находятся в допустимых пределах
            if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 9999) {
                printf("Неверная дата.\n");
                timeBack = 0;
            } else {
                timeBack = 1;
                strcpy(date, animals[i].info.date);
            }

        }
        while(timeBack=0);

*/
        printf("Enter the average lifespan of the animal: ");
        while (scanf("%d", &animals[i].info.lifespan) != 1) {
            printf("Error: invalid input\n");
            fflush(stdin);
        }
    }

        // запрашиваем название для поиска
        printf("Enter the name of the animal to search: ");
        scanf("%s", search_name);

        // ищем животных с заданным названием
        for (int i = 0; i < n; i++) {
            if (strcmp(animals[i].name, search_name) == 0) {
                printf("Found: %s (count: %d)\n", animals[i].name, animals[i].count);
            }
        }

        // запрашиваем количество особей для удаления
        printf("Enter the count of animals to delete: ");
        while (scanf("%d", &search_count) != 1) {
            printf("Error: invalid input\n");
            fflush(stdin);
        }

        // удаляем животных с заданным количеством особей
        int new_n = 0; // новое количество животных
        for (int i = 0; i < n; i++) {
            if (animals[i].count != search_count) {
                animals[new_n++] = animals[i];
            } else {
                free(animals[i].name);
            }
        }
    printf("\nAnimals after deletion:\n");
    for (int i = 0; i < new_n; i++) {
        printf("Name: %s\n", animals[i].name);
        printf("Count: %d\n", animals[i].count);
        printf("Date: %s\n", animals[i].info.date);
        printf("Lifespan: %d\n", animals[i].info.lifespan);
        printf("\n");
    }
        // изменяем размер массива структур
        animals = (Animal *) realloc(animals, new_n * sizeof(Animal));

        // освобождаем память
        for (int i = 0; i < new_n; i++) {
            free(animals[i].name);
        }
        free(animals);
    }


    void task1() {
        int num;

        printf("Введите целое число: ");
        while (scanf("%d", &num) != 1 || num % 1 != 0 || getchar() != '\n') {
            printf("Error. Try again: ");
            rewind(stdin);
        }

        // Маска для получения младших 2 битов числа
        unsigned int mask = 0x03; // 0b00000011

        // Получение младших 2 битов числа
        int r = num & mask;

        // Если r == 0, то num делится на 4 без остатка
        // Иначе искомый остаток равен r
        if (r == 0) {
            printf("%d делится на 4 без остатка\n", num);
        } else {
            printf("Остаток от деления %d на 4 равен %d\n", num, r);
        }


    }

