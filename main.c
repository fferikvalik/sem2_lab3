/*

char date[DATE_LENGTH];
            int day, month, year, TimeBack;
            while (TimeBack == 1) {
                printf("Введите дату в формате DD.MM.YYYY: ");
                fgets(date, DATE_LENGTH, stdin);

                // Проверяем правильность формата ввода
                if (strlen(date) != DATE_LENGTH - 1 || date[2] != '.' || date[5] != '.') {
                    printf("Неправильный формат даты.\n");
                    TimeBack = 1;
                }

                // Извлекаем значения дня, месяца и года
                day = atoi(date);
                month = atoi(date + 3);
                year = atoi(date + 6);

                // Проверяем, что значения дня, месяца и года находятся в допустимых пределах
                if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 9999) {
                    printf("Неверная дата.\n");
                    TimeBack = 1;
                } else
                    TimeBack = 0;
                strcpy(date, animals[i].info.date);
            }
}
}*/
#include "loccale.h"
int main() {
    int t=0;
    while (t != 2) {
        int choose;
        printf("\nAvailable tasks:\n1.Find and display the remainder of the division of an integer by 4 without\n performing division and without using the operation of taking the remainder of the division.\n");
        printf("\n2.The structure contains information about zoo animals: the number of individuals (number),\n name (pointer), nested structure - date of entry to the zoo (fixed-length string) and average\n life expectancy. Find animals with a given name. Remove animals with a given number of individuals.");
        printf("\nChoose task: ");
        choose = input(1, 2);
        if (choose == 1) {
            task1();
        } else {
            if (choose == 2) {
                task2();
            }
        }
        printf("\n\nDo you want to choose one more task?\n1.Yes\n2.No\n");
        t = input(1, 2);
    }

    return 0;
}
