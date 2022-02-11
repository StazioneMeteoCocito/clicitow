#include <stdio.h>
#include "fort.h"
#include "fort.c"
#include "dat.c"
#include "archive.c"
#include "dir.c"
int logo(){
    printf("\n\t\tS  T  A  Z  I  O  N  E\n");
    printf("\t\tM  E  T  E  O\n");
    printf("\t\tC  O  C  I  T  O\n");
}
int menu(CONF conf){
    ft_table_t *table = ft_create_table();
    /* Set "header" type for the first row */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);

    ft_write_ln(table, "N", "Opzione");

    ft_write_ln(table, "1", "Aggiorna dati");
    ft_write_ln(table, "2", "Naviga nei dati");
    ft_write_ln(table, "3", "Cruscotto");
    ft_write_ln(table, "4", "Report hadrware");
    ft_write_ln(table, "5", "Chiudi");

    printf("\n    Menù principale\n%s\n", ft_to_string(table));
    ft_destroy_table(table);
    int c;
    scanf("%d", &c);
    switch(c){
       case 1:
           update(conf);
           break;
       case 2:
           if(!exists(conf)) update(conf);
           else lastUpdate(conf);
           dirmenuw(conf);
           break;
       case 4:
           if(!exists(conf)) update(conf);
           printReport(conf);
           break;
       default:
       case 5:
           return 0;
           break;
   }
   return 1;
}

int main(){
    CONF conf = loadConf("conf.dat");
    //dump_conf(conf);
    logo();
    int counter = 0;
    while(menu(conf)){
        counter += 1;
    }
    return 0;
}
