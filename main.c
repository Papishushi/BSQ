/*********************************/
#include "bsq.h"

int main(int argc, char *argv[])
{
    int m;
    int i;
	t_bsq	bsq;

    

    m = 1;
    i = 0;
    if(argc == 1)
    {
        printf("************* falta la movida de la entrada estandar **************");
    }
    // while(m < argc)
    // {
        check_mapas(argv[m], &bsq);

        printf("FILAS => %d\n", bsq.n_lines);
        printf("COL => %d\n", bsq.n_columns);

        bsq.map = (char **)malloc(sizeof(char *) * bsq.n_lines); 
        bsq.aux_map = (char **)malloc(sizeof(char*) * bsq.n_lines);
        while (i < bsq.n_lines)
        {
            bsq.map[i]=(char *)malloc(sizeof(char) * bsq.n_columns);
            bsq.aux_map[i]=(char *)malloc(sizeof(char) * bsq.n_columns);
            i++;
        }
        if (bsq.map == 0 || bsq.aux_map == 0)
        {   
            ft_putstr(ERROR_MSG);
            return (0);
        }
        create_map(bsq.map, argv[m]);
        ft_print_mat(bsq.map, bsq.n_lines, bsq.n_columns);
        create_aux_mat(bsq.map, bsq.aux_map, bsq.n_lines, bsq.n_columns);
        ft_putchar('\n');
        ft_print_mat(bsq.aux_map, bsq.n_lines, bsq.n_columns);
        put_ones(&bsq);
		put_obstacles(&bsq);
        //ft_print_mat(map, dim[0], dim[1]);
        //ft_print_mat(map);

        //create map
        // resuelveme el puto algoritmo PD: gracias       
    // }

}