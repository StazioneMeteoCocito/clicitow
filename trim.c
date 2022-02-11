#include <string.h> 
char *rtrim(char *str)
{
    size_t len;
    char *p;
    
    len = strlen(str);
    if (len > 0)
    {
        p = str + len;
        do 
        {
            p--;
            if (!isspace(*p))
                break;
            *p = '\0';
        } while (p > str);
    }

    return str;
}
char *ltrim(char *str)
{
    char *pstart;
    char *p;

    pstart = str;
    while (isspace(*pstart))
        pstart++;

    if (pstart > str)
    {
        p = str;
        while(*pstart)
        {
            *p = *pstart;
            pstart++;
            p++;
        }
        *p = '\0';
    }

    return str;
} 
char *trim(char *str)
{
    rtrim(str);
    ltrim(str);

    return str;
}