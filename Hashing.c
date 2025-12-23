#include <stdio.h>

#define MAX 100

int main()
{
    int HT[MAX];      // Hash Table
    int m, n;         // m = size of hash table, n = number of keys
    int key, index;
    int i, j;

    // Initialize hash table with -1 (empty)
    for (i = 0; i < MAX; i++)
        HT[i] = -1;

    // Input size of hash table
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    // Input number of keys
    printf("Enter number of employee records (n): ");
    scanf("%d", &n);

    // Insert keys into hash table
    for (i = 0; i < n; i++)
    {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);

        index = key % m;   // Hash function

        // Linear probing for collision resolution
        if (HT[index] == -1)
        {
            HT[index] = key;
        }
        else
        {
            j = (index + 1) % m;
            while (HT[j] != -1)
            {
                j = (j + 1) % m;
            }
            HT[j] = key;
        }
    }

    // Display hash table
    printf("\nHash Table:\n");
    printf("Address  Key\n");
    for (i = 0; i < m; i++)
    {
        if (HT[i] != -1)
            printf("%2d       %d\n", i, HT[i]);
        else
            printf("%2d       --\n", i);
    }

    return 0;
}

