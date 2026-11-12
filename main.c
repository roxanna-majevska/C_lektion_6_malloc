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
        // Kapacitet = n + 10 %
        size_t capacity = n + n / 10;
        if (capacity == n)
        {
            capacity = n + 1;
        }
        size_t count = 0;

        // Calloc med capacity
        int *arr = calloc(capacity, sizeof(int));
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

            count++;
        }

        // Fråga om fler
        char more;
        printf("Add another value? (y/n): ");
        scanf(" %c", &more);

        while (more == 'y' || more == 'Y')
        {
            // Är det fullt?
            if (count == capacity)
            {
                size_t new_capacity = capacity * 2;
                int *tmp = realloc(arr, sizeof(int) * new_capacity);
                if (tmp == NULL)
                {
                    fprintf(stderr, "Out of memory\n");
                    free(arr);
                    return 1;
                }
                arr = tmp;
                capacity = new_capacity;
                printf("(reallock: capacity is now %zu)\n", capacity);
            }

            // Läsa in ett värde till arr[count] 
            do
            {
                printf("Value %zu: ", count + 1);
                scanf("%d", &arr[count]);
                if (arr[count] <= 0)
                {
                    printf("Only values > 0\n");
                }
            } while (arr[count] <= 0);
            count++;

            // Fråga igen
            printf("Add another value? (y/n)");
            scanf(" %c", &more);
        }
        // Skriva ut alla värden
        for (size_t i = 0; i < count; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    }

    else if (type == 'f' || type == 'F')
    {
        // Kapacitet = n + 10 %
        size_t capacity = n + n / 10;
        if (capacity == n)
        {
            capacity = n + 1;
        }
        size_t count = 0;
        float *arr = calloc(capacity, sizeof(float));
        if (arr == NULL)
        {
            fprintf(stderr, "Out of memory\n");
            return 1;
        }
        // Läsa in de n första värdena
        for (size_t i = 0; i < n; i++)
        {
            do
            {
                printf("Value %zu: ", i + 1);
                scanf("%f", &arr[i]);
                if (arr[i] <= 0)
                {
                    printf("Only values > 0!\n");
                }
            } while (arr[i] <= 0);

            count++;
        }
        // Fråga om  fler
        char more;
        printf("Add another value? (y/n): ");

        scanf(" %c", &more);

        while (more == 'y' || more == 'Y')
        {
            // Är det fullt?
            if (count == capacity)
            {
                size_t new_capacity = capacity * 2;
                float *tmp = realloc(arr, sizeof(float) * new_capacity);
                if (tmp == NULL)
                {
                    fprintf(stderr, "Out of memory\n");
                    free(arr);
                    return 1;
                }
                arr = tmp;
                capacity = new_capacity;
                printf("(reallok: capacity is now %zu)\n", capacity);
            }

            // Läsa in ett värde till arr[count] 
            do
            {
                printf("Value %zu: ", count + 1);
                scanf("%f", &arr[count]);
                if (arr[count] <= 0)
                {
                    printf("Only values > 0!\n");
                }
            } while (arr[count] <= 0);
            count++;

            // Fråga igen
            printf("Add another value? (y/n): ");
            scanf(" %c", &more);
        }
        // Skriva ut alla värden
        for (size_t i = 0; i < count; i++)
        {
            printf("%.2f ", arr[i]);
        }
        printf("\n");
        free(arr);
    }
    return 0;
}