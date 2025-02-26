#include <stdio.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

char Is_palindrome(char *str, int N)
{
    N -= 1;
    for(int idx = 0; idx <= N/2; idx++)
    {
        if(str[idx] != str[N-idx])
        {
            return FALSE;
        }
    }
    return TRUE;
}

int main()
{
    char str[] = "madam";
    int N = strlen(str);

    if((N%2 != 0) && (Is_palindrome(str, N) == TRUE))
    {
        printf("This string is palindrome string: %s\n", str);
    }
    else
    {
        printf("This string is not palindrome string\n");
    }
    return 0;
}