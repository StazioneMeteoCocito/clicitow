/**
 * @file trim.c
 * @author Mattia Mascarello (mattia.mascarello@outlook.it)
 * @brief Trimming utilities for strings
 * @version 0.1
 * @date 2022-02-11
 *
 * @copyright  2022, The MIT License
 *
 */
#include <string.h>
/**
 * @brief Right trim
 *
 * @param str Origin
 * @return char* destination
 */
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
/**
 * @brief Left trim
 *
 * @param str origin
 * @return char* destination
 */
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
        while (*pstart)
        {
            *p = *pstart;
            pstart++;
            p++;
        }
        *p = '\0';
    }

    return str;
}
/**
 * @brief Trim both sides
 *
 * @param str origin
 * @return char* destination
 */
char *trim(char *str)
{
    rtrim(str);
    ltrim(str);

    return str;
}