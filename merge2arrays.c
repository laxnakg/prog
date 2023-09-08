#include <stdio.h>
#include <stdlib.h>

int *merge (int *a, int n, int *b, int m)
{
    int *res = malloc((n+m)*sizeof(int));
    int i,j,k;
    i=j=k=0;

    while ((i < n) && (j < m))
    {
        if (a[i] < b[j])
        {
            res[k] = a[i];
            i++;
            k++;
        }
        else
        {
            res[k] = b[j];
            j++;
            k++;
        }
    }
    while (i<n) res[k++] = a[i++];
    while (j<m) res[k++] = b[j++];
    return res;
}
int main (int argc, char *argv[])
{
    int a[] = {0,1,2,3,5,7,9};
    int b[] = {2,4,8,10,11,12,16};
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);
    int *result = merge(a,m, b, n);
    for (int i=0; i<(n+m); i++)
    {
        printf ("[%d] %u\n", i, result[i]);
    }
    return 1;
}
