#include <stdio.h>
#include <stdlib.h>

/*   The project statements is
 * 
 *      " take a number from the user and count the number of ones 
 *          in the binary value of this number for example if the number is 20 , the binary 
 *          value of it is 00010100 so it contain two ones. 
 *
 */

int main()
{
    int number = 0;
    int c = 0;

    while(1)
    {
        puts("Enter the number please.");
        scanf("%d", &number);
        printf("The number of ones in binary representation is ");
        while(number != 0)
        {
            if(number & 1 == 1)
                c++;
            number >>= 1 ;
        }

        printf("%d", c);
        c = 0;

        printf("\n");
        system("pause");
        system("cls");
    }

    return 0;
}
