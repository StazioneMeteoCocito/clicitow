#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int is_file(const char * path){
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
int dirMenu(char * path, char * result) {
     DIR *d;
     struct dirent *dir;
     d = opendir(path);
     if (d) {
        char pl[267];
        int i = 1;
        char pathList[100][100];
        while ((dir = readdir(d)) != NULL) {
            sprintf(pl, "%s/%s", path, dir->d_name);
            sprintf(pathList[i-1],"%s",dir->d_name);
            if(dir->d_name[0]=='.' || is_file(pl)) continue;
            printf("\n%d> %s", i, dir->d_name);
            i++;
        }
        if(i == 1) return 0;
        int c = 0;
        scanf("%d",&c);
        sprintf(result,"%s/%s",path, pathList[c-1]);
        closedir(d);
     }
     return 1;
}
void readf(FILE *f){
    ft_table_t *table = ft_create_table();
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    char * token;
    char time[200];
    char value[200];
    char row[400];
    ft_write_ln(table, "N", "Data ed Ora", "Valore");
    int i = 1;
    char l[10];
    while(!feof(f)){
        fgets(row, 400, f);
        token = strtok(row,",");
        sprintf(time,"%s",token);
        token = strtok(NULL, ",");
        sprintf(value,"%s",token);
        sprintf(l,"%d",i);
        ft_write_ln(table, l, time, value);
        i++;
    }
    printf("%s",ft_to_string(table));
    ft_destroy_table(table);
}
int dirmenuw(CONF config){
    char path[500];
    sprintf(path,"%s",config.PATH);
    char p[100];
    char titles [3][100];
    sprintf(titles[0],"%s","Anno");
    sprintf(titles[1],"%s","Mese");
    sprintf(titles[2],"%s","Giorno");
    int i = 1;
    printf("\n---------\n%s\n---------\n",titles[0]);
    while(dirMenu(path,p)){
        printf("\n---------\n%s\n---------\n",titles[i]);
        sprintf(path,"%s",p);
        i++;
    }
    char filename[700];
    char fn[6][200];
    char actualfn[6][200];
    int l = 6, c;
    sprintf(fn[0],"%s","Temperatura");
    sprintf(actualfn[0],"%s","temperature.csv");
    sprintf(fn[1],"%s","Umidità");
    sprintf(actualfn[1],"%s","humidity.csv");
    sprintf(fn[2],"%s","Pressione");
    sprintf(actualfn[2],"%s","pressure.csv");
    sprintf(fn[3],"%s","PM10");
    sprintf(actualfn[3],"%s","pm10.csv");
    sprintf(fn[4],"%s","PM2,5");
    sprintf(actualfn[4],"%s","pm25.csv");
    sprintf(fn[5],"%s","Fumo e vapori infiammabili");
    sprintf(actualfn[5],"%s","smoke.csv");
    printf("\n---------\nDato\n---------\n");
    for(int i = 0; i < l;i++){
        printf("%d>\n %s\n",i+1,fn[i]);
    }
    scanf("%d",&c);
    sprintf(filename,"%s/%s",path,actualfn[c-1]);
    FILE *fe = fopen(filename,"r");
    readf(fe);
}
