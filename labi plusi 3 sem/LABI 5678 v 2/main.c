/*Структура содержит информацию о футбольных командах: количество побед (число), название (указатель), вложенную структуру – год последней победы (строка фиксированной длины) и количество проигрышей. Найти команды с количеством побед больше заданного. Удалить команды с заданным названием.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tablef {
    int win;
    char *name;
    struct louse_yar {
        char years[10];
        int count_loss;
    } dop_date;
};

int main()
{
    int n;
    printf("Enter the number of team:   ");
    scanf("%d", &n);
    struct tablef team[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nteam[%d]\n", i+1);
        printf("Enter the number of win:    ");
        scanf("%d", &team[i].win);
        team[i].name = (char *)calloc(255, sizeof(char));
        printf("Enter the team name:    ");
        scanf("%s", team[i].name);
        printf("Enter the year of the last win from point:  ");
        scanf("%s", team[i].dop_date.years);
        printf("Enter the number of losing:    ");
        scanf("%d", &team[i].dop_date.count_loss);
    }
    printf("Enter the min number of win");
    int n_win;
    scanf("%d", &n_win);
    printf("teams with the most wins");
    for (int i = 0; i < n; i++)
    {
        if(team[i].win > n_win)
        {
            printf("\nteam[%d]\n", i+1);
            printf("win=%d, team name=%s, last win=%s, losing=%d\n", team[i].win, team[i].name, team[i].dop_date.years, team[i].dop_date.count_loss);
        }
    }
    printf("Command name to delete: ");
    char *delete = (char *)calloc(255, sizeof(char));
    scanf("%s", delete);
    for (int i = 0; i < n; i++)
    {
        if(strcmp(team[i].name, delete) == 0 )
        {
            for (int j = i;j<n; j++)
            {
                team[j].win=team[j+1].win;
                strcpy(team[j].name, team[j+1].name);
                strncpy(team[j].dop_date.years, team[j+1].dop_date.years, 10);
                team[j].dop_date.count_loss=team[j+1].dop_date.count_loss;
            }
            n--;
        }
    }
   for (int i = 0; i < n; i++)
    {
        printf("\nteam[%d]\n", i+1); 
        printf("win=%d, team name=%s, last win=%s, losing=%d\n", team[i].win, team[i].name, team[i].dop_date.years, team[i].dop_date.count_loss);
    }
    return 0;
}

