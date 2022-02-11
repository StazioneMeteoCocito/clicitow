/**
 * @file fmath.c
 * @author Mattia Mascarello (mattia.mascarello@outlook.it)
 * @brief Math utilities to convert florats
 * @version 0.1
 * @date 2022-02-11
 *
 * @copyright  2022, The MIT License
 *
 */
/**
 * @brief Reverse string
 * 
 * @param str string
 * @param len length
 */
void reverse(char *str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

/**
 * @brief int to string
 *  Converts a given integer x to string str[].
 *  d is the number of digits required in the output.
 *  If d is more than the number of digits in x,
 *  then 0s are added at the beginning.
 * @param x  integer
 * @param str string
 * @param d lenght
 * @return int
 */
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}
/**
 * @brief float to string
 * 
 * @param n float
 * @param res result
 * @param afterpoint number of decimals 
 */
void ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}