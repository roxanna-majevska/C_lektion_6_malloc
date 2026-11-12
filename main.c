#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char type;
    size_t n;

    printf("Do you want to enter (i)nteger or (f)loat values? ");
    if (scanf(" %c", &type) != 1 || (type != 'i' && type != 'I' && type != 'f' && type != 'F'))
    {
        fprintf(stderr, "Invalid choice. Exiting.\n");
        return 1;
    }

    printf("How many values do you want to enter? ");
    if (scanf("%zu", &n) != 1)
    {
        fprintf(stderr, "Invalid number.\n");
        return 1;
    }
    if (n == 0)
    {
        printf("Nothing to do (n = 0).\n");
        return 0;
    }

    if (type == 'i' || type == 'I')
    {
        int *arr = calloc(n, sizeof(int));
        if (arr == NULL)
        {
            fprintf(stderr, "Out of memory\n");
            return 1;
        }

        for (size_t i = 0; i < n; i++)
        {
            do
            {
                printf("Value %zu: ", i + 1);
                scanf("%d", &arr[i]);
                if (arr[i] <= 0)
                {
                    printf("Only values > 0!\n");
                }
            } while (arr[i] <= 0);

            for (size_t j = 0; j < n; j++)
            {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }    
    
        free(arr);
    }
    else if (type == 'f' || type == 'F')
    {
        float *arr = calloc(n, sizeof(float));
        if (arr == NULL)
        {
            fprintf(stderr, "Out of memory\n");
            return 1;
        }

        for (size_t i = 0; i < n; i++)
        {
            do
            {
                printf("Value %zu:  ", i + 1);
                scanf("%f", &arr[i]);
                if (arr[i] <= 0)
                {
                    printf("Only values > 0!\n");
                }
            } while (arr[i] <= 0);

            for (size_t j = 0; j < n; j++)
            {
                printf("%.2f ", arr[j]);
            }
            printf("\n");
        }
    
        free(arr);
    }    
    return 0;
}