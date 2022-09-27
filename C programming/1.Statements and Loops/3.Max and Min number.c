#include <stdio.h>
#include <stdlib.h>

/*   The project statements is
 * 
 *      " take from the user 4 numbers and prints the maximum and 
 *          the minimum number of them"
 *  
 */

int main()
{
    int c; // counter

    int max = 0;
    int min = 0;
    int number = 0;

    while(1)
    {
        puts("Enter 4 Numbers please to get the minimum and maximum.");
        scanf("%d", &number);
        min = number;
        max = number;
        
        for( c = 1; c < 4; c++)
        {
            scanf("%d", &number);
            if (number <= min)
                min = number;

            else if (number > max)
                max = number;
        }

        if (min == max)
            printf("You Entered Equals Numbers.");

        else
        {
            printf("The minimum number is %d\n", min);
            printf("The maximum number is %d", max);
        }

        printf("\n");
        system("pause");
        system("cls");   
    }


    printf("\n");
    system("pause");
    return 0;
}
