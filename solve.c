//to do
#include "bsq.h"

void    create_aux_mat(char **map, char **map_aux, int lines, int counter)
{
    int i;
    int j;

    i = 0;
    while (i < lines)
    {
        j = 0;
        while (j < counter)
        {
            map_aux[i][j] = map[i][j];
            j++;
        }
        i++;
    }
}
/*void solve_cube(t_bsq)
{




 }*/
void    ft_print_mat(char **mat, int lines , int counter)
{
    int i;
    int j;

    i = 0;
    while (i < lines)
    {
        j = 0;
        while (j < counter)
        {
            ft_putchar(mat[i][j]);
            j++;
        }
        i++;
    }
}
