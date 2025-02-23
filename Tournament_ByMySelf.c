#include <stdio.h>
#include <stdlib.h>

void tournament(int A[], int N, int* Largest, int* SecondLargest) 
{
    int* winner = (int*)malloc((N-1)*sizeof(int));
    int* loser  = (int*)malloc((N-1)*sizeof(int));
    int* prior  = (int*)malloc((N-1)*sizeof(int));
    for (int i = 0; i < N-1; i++)
    {
        prior[i] = -1;
    }

    int idx = 0;
    for (int i = 0; i < N; i += 2)
    {
        if(A[i] < A[i+1])
        {
            winner[idx] = A[i+1];
            loser[idx]  = A[i];                                   
        }
        else
        {
            winner[idx] = A[i];
            loser[idx]  = A[i+1];
        }
        idx++;
    }

    int m = 0;
    while(idx < N-1)
    {
        if(winner[m] < winner[m+1])
        {
            winner[idx] = winner[m+1];
            loser[idx]  = winner[m];
            prior[idx]  = m+1;
        } else
        {
            winner[idx] = winner[m];
            loser[idx]  = winner[m+1];
            prior[idx]  = m;
        }
        m += 2;
        idx++;
    }

    *Largest = winner[m];
    *SecondLargest = loser[m];
    m = prior[m];

    while(m >= 0)
    {
        if(*SecondLargest < loser[m])
        {
            *SecondLargest = loser[m];
        }
        m = prior[m];
    }

    free(winner);
    free(loser);
    free(prior);
}

int main()
{
    int A[] = {3, 6, 9, 8, 5, 7, 4, 1};
    int N = sizeof(A)/(sizeof(A[0]));
    int largest, second;

    tournament(A, N, &largest, &second);
    printf("The largest number is: %d\n", largest);
    printf("The second largest number is: %d\n", second);
    return 0;
}