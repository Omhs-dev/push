#include "../../includes/push_swap.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char **ft_split(char *str, char del)
{
    char **tab;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    tab = malloc(sizeof(char *) * (ft_strlen(str) + 1));
    while (str[i])
    {
        if (str[i] == del)
        {
            tab[j] = malloc(sizeof(char) * (k + 1));
            k = 0;
            j++;
        }
        else
            k++;
        i++;
    }
    tab[j] = malloc(sizeof(char) * (k + 1));
    i = 0;
    j = 0;
    k = 0;
    while (str[i])
    {
        if (str[i] == del)
        {
            tab[j][k] = '\0';
            k = 0;
            j++;
        }
        else
        {
            tab[j][k] = str[i];
            k++;
        }
        i++;
    }
    tab[j][k] = '\0';
    tab[j + 1] = NULL;
    return (tab);
}
