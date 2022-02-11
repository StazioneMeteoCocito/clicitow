/**
 * @file dashboard.c
 * @author Mattia Mascarello (mattia.mascarello@outlook.it)
 * @brief Dashboard with current data
 * @version 0.1
 * @date 2022-02-11
 *
 * @copyright  2022, The MIT License
 *
 */
#include <math.h>
#include "fmath.c"
/**
 * @brief Struct holding latestdata
 * 
 */
typedef struct latestData
{
    float T;
    float H;
    float P;
    float PM10;
    float PM25;
    float S;
} latestData;
/**
 * @brief Load latest data from json
 * 
 * @param config Configuraton
 * @return latestData LatestData struct
 */
latestData loadLatest(CONF config)
{
    latestData ld;
    char *token;
    char path[700];
    sprintf(path, "%s/%s", config.PATH, config.JSONFILE);
    FILE *f = fopen(path, "r");
    char oid[300]; // temp bucket, used to skip line and for trim operations
    fgets(oid, 300, f);
    fgets(oid, 300, f);
    token = strtok(oid, ":");
    token = strtok(NULL, ":");
    ld.T = atof(token);
    fgets(oid, 300, f);
    token = strtok(oid, ":");
    token = strtok(NULL, ":");
    ld.H = atof(token);
    fgets(oid, 300, f);
    token = strtok(oid, ":");
    token = strtok(NULL, ":");
    ld.P = atof(token);
    fgets(oid, 300, f);
    token = strtok(oid, ":");
    token = strtok(NULL, ":");
    ld.PM10 = atof(token);
    fgets(oid, 300, f);
    token = strtok(oid, ":");
    token = strtok(NULL, ":");
    ld.PM25 = atof(token);
    fgets(oid, 300, f);
    token = strtok(oid, ":");
    token = strtok(NULL, ":");
    ld.S = atof(token);
    return ld;
}
/**
 * @brief Dump Latest Data structure
 * 
 * @param conf 
 */
void dumpLatest(latestData conf)
{
    printf("\n T = %f\n H = %f \n P = %f \n PM10 = %f\n PM25 = %f\n S = %f\n", conf.T, conf.H, conf.P, conf.PM10, conf.PM25, conf.S);
}

/**
 * @brief Print current data board
 * 
 * @param ld LatestData struct
 */
void currentBoard(latestData ld)
{
    ft_table_t *table = ft_create_table();
    /* Set "header" type for the first row */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);

    ft_write_ln(table, "Temperatura", "Umidità", "Pressione", " PM10", "PM2,5", "Fumo");
    char T[20];
    char H[20];
    char P[20];
    char PM10[20];
    char PM25[20];
    char S[20];
    ftoa(ld.T, T, 2);
    ftoa(ld.H, H, 2);
    ftoa(ld.P, P, 2);
    ftoa(ld.PM10, PM10, 2);
    ftoa(ld.PM25, PM25, 2);
    ftoa(ld.S, S, 2);
    ft_write_ln(table, T, H, P, PM10, PM25, S);
    printf("%s", ft_to_string(table));
    ft_destroy_table(table);
}