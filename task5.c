#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#include "constants.h"

void random_fill_boxes_and_trays(unsigned boxes_and_tray[EGG_TRAY_ROWS][EGG_TRAY_COLS][EGG_TRAYS][EGG_STACKS])
{
    srand(time(NULL));

    // Итерация по "строкам" лотка
    for (int row = 0; row < EGG_TRAY_ROWS; row++)
    {
        // Итерация по "колонкам" лотка
        for (int col = 0; col < EGG_TRAY_COLS; col++)
        {
            // Итерация по лоткам в коробке
            for (int tray = 0; tray < EGG_TRAYS; tray++)
            {
                // Итерация по стопкам в коробке
                for (int stack = 0; stack < EGG_STACKS; stack++)
                {
                    // Представим битое яйцо 0, целое - 1
                    boxes_and_tray[row][col][tray][stack] = rand() % 2;
                }
            }
        }
    }
}

double percentage_of_broken_eggs(unsigned boxes_and_tray[EGG_TRAY_ROWS][EGG_TRAY_COLS][EGG_TRAYS][EGG_STACKS])
{
    // Количество разбитых яиц
    int count = 0;

    for (int row = 0; row < EGG_TRAY_ROWS; row++)
    {
        for (int col = 0; col < EGG_TRAY_COLS; col++)
        {
            for (int tray = 0; tray < EGG_TRAYS; tray++)
            {
                for (int stack = 0; stack < EGG_STACKS; stack++)
                {
                    // Если яйцо разбито, увеличиваем переменную 'count'
                    if (boxes_and_tray[row][col][tray][stack] == 0)
                        count++;
                }
            }
        }
    }

    return (((double)count * 100.0) / EGG_COUNT_IN_ONE_BOX);
}

int main()
{
    setlocale(LC_ALL, "rus");

    unsigned boxes_and_tray[EGG_TRAY_ROWS][EGG_TRAY_COLS][EGG_TRAYS][EGG_STACKS];
    random_fill_boxes_and_trays(boxes_and_tray);

    for (int row = 0; row < EGG_TRAY_ROWS; row++)
    {
        for (int col = 0; col < EGG_TRAY_COLS; col++)
        {
            for (int tray = 0; tray < EGG_TRAYS; tray++)
            {
                for (int stack = 0; stack < EGG_STACKS; stack++)
                {
                    printf("%u ", boxes_and_tray[row][col][tray][stack]);
                }
                printf("\t");
            }
            printf("\n");
        }
    }

    printf("Процент разбитых яиц = %0.2f%%\n", percentage_of_broken_eggs(boxes_and_tray));

    return 0;
}
