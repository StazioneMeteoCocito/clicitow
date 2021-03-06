/**
 * @file dat.c
 * @author Mattia Mascarello (mattia.mascarello@outlook.it)
 * @brief fetch data from dat file
 * @version 0.1
 * @date 2022-02-11
 *
 * @copyright  2022, The MIT License
 *
 */
#include "trim.c"
/**
 * @brief Configuration file string
 * 
 */
typedef struct CONF{
    char REMOTE_URL[300];
    char ZIP[300];
    int DELETE_ZIP;
    char PATH[300];
    char REPORT[300];
    char JSONFILE[300];
} CONF;
/**
 * @brief Load configuration file from path
 * 
 * @param path 
 * @return CONF 
 */
CONF loadConf(char * path){
    CONF conf;
    FILE *f;
    f  = fopen(path,"r");
    char oid[300]; // temp bucket, used to skip line and for trim operations
    fgets(oid,300,f);
    fgets(conf.REMOTE_URL,300,f);
    sprintf(oid,"%s",trim(conf.REMOTE_URL));
    sprintf(conf.REMOTE_URL,"%s",oid);
    fgets(oid,300,f);
    fgets(conf.ZIP,300,f);
    sprintf(oid,"%s",trim(conf.ZIP));
    sprintf(conf.ZIP,"%s",oid);
    fgets(oid,300,f);
    fscanf(f,"%d\n",&conf.DELETE_ZIP);
    fgets(oid,300,f);
    fgets(conf.PATH,300,f);
    sprintf(oid,"%s",trim(conf.PATH));
    sprintf(conf.PATH,"%s",oid);
    fgets(oid,300,f);
    fgets(conf.REPORT,300,f);
    sprintf(oid,"%s",trim(conf.REPORT));
    sprintf(conf.REPORT, "%s", oid);
    fgets(oid, 300, f);
    fgets(conf.JSONFILE, 300, f);
    sprintf(oid, "%s", trim(conf.JSONFILE));
    sprintf(conf.JSONFILE, "%s", oid);
    return conf;
}
/**
 * @brief Dumps configuration
 * 
 * @param conf Configuration
 */
void dump_conf(CONF conf){
    printf("\nREMOTE_URL = %s\nZIP= %s\nDELETE_ZIP = %d\nPATH = %s\n",conf.REMOTE_URL,conf.ZIP,conf.DELETE_ZIP,conf.PATH);
}
