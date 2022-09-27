#include <stdio.h>
#include <stdlib.h>

/*   The project statements is 
 *   "take a 3-digit number from the user and print it reversed"
 *
 */

int main()
{
    // ask user to enter the number. 
    int number = 0;
    puts("Enter the number please.");

    // get the number from the user.
    scanf("%d", & number);
    printf("The reversed number is ");

    // print the number with reversed order.
    while( number != 0)
    {
        printf("%d", number%10);
        number = number / 10 ;
    }

    printf("\n");
    system("pause");
    return 0;
}
