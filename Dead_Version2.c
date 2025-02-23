#include <stdio.h>
#include <string.h>

int dead(char *str, int N)
{
    int ans = 255;
    int start = 0, end =0;
    int idx = 0;

    for(int i = 0; i<N; i++)
    {
        if(str[i] == 'D')
        {
            start = i;
            idx = i;
            for(idx++; idx<N; idx++)
            {
                if(str[idx] == 'E')
                {
                    for(idx++; idx<N; idx++)
                    {
                        if(str[idx] == 'A')
                        {
                            for(idx++; idx<N; idx++)
                            {
                                if(str[idx] == 'D')
                                {
                                    end = idx;
                                    if(ans>(end-start))
                                    {
                                        ans = end - start;
                                    }
                                    break;
                                }
                            }
                        }
                        // else if(str[idx] == 'D')
                        // {
                        //     break;
                        // }
                    }
                }
                else if(str[idx] == 'D')
                {
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    char str[] = "DADEDEAEAADEDADDADEDAD";
    int N = strlen(str);
    printf("Result of minimum DEAD in the string is: %d\n", dead(str, N));
}