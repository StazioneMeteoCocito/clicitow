#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>
#include "zip.c"
int download(CONF conf)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen(conf.ZIP,"wb");
        printf("\nConnessione al server\n");
        curl_easy_setopt(curl, CURLOPT_URL, conf.REMOTE_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        printf("\nDati compressi scaricati\n");
        fclose(fp);
        return 1;
    }
    return 0;
}
int on_extract_entry(const char *filename, void *arg){
    static int i = 0;
    //int n = *(int *)arg;
    //printf("Estratto %s, (n. %d)\n",filename, ++i);
    //printf("|");
    return 0;
}
void extract(){
    int arg = 2;
    printf("\nEstrazione dei dati\n");
    zip_extract("station.zip",".", on_extract_entry, &arg);
    printf("\nFatto!\n");
}
void clean(CONF conf){
    printf("\nPulizia dell'archivio\n");
    unlink(conf.ZIP);
}
char * report_path(CONF conf,char * path){
     sprintf(path,"%s/%s",conf.PATH,conf.REPORT);
}
int exists(CONF conf){
        char path[400];
        report_path(conf, path);
	return access(path, F_OK) == 0;
}
void lastUpdate(CONF conf){
    char path[400];
    report_path(conf, path);
    FILE *f = fopen(path,"r");
    char line[100];
    fgets(line, 100, f); // Dump line
    fgets(line, 100, f);
    printf("\nDati aggiornati a\n\t%s\n",line);
}
void printReport(CONF conf){
    char path[400];
    report_path(conf, path);
    FILE *f = fopen(path,"r");
    char c;
    while((c= fgetc(f))!=EOF){
       printf("%c",c);
   }
}
int update(CONF conf){
    clean(conf);
    download(conf);
    extract(conf);
    lastUpdate(conf);
}
