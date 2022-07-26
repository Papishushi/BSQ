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
void put_ones(t_bsq *bsq)
{
    int i;
    int j;

    i = 0;
    while (i < bsq->n_lines)
    {
		j = 0;
        while (j < bsq->n_columns)
        {
			if ((i == 0 || j == 0) && bsq->aux_map[i][j] != '\n')
            	bsq->aux_map[i][j] = '1';
            j++;
        }
        i++;
    }
    ft_print_mat(bsq->aux_map, bsq->n_lines, bsq->n_columns);
}
void	put_obstacles(t_bsq *bsq)
{
	int i;
    int j;

    i = 0;
    while (i < bsq->n_lines)
    {
		j = 0;
        while (j < bsq->n_columns)
        {
			if (bsq->aux_map[i][j] == bsq->c_obstacle)
            	bsq->aux_map[i][j] = '0';
            j++;
        }
        i++;
    }
    ft_print_mat(bsq->aux_map, bsq->n_lines, bsq->n_columns);
}
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
		ft_putchar('\n');
        i++;
    }
}