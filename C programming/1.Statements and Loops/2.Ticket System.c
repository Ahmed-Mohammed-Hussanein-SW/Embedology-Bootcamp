#include <stdio.h>
#include <stdlib.h>

/*   The project statements is
 * 
 *   	"takes the amount of money from the user and prints
 *	“Ticket” if the amount of money is 10 
 *	“Ticket + Pepsi” if the amount of money is 20 
 *	“Ticket + Pepsi +Popcorn” if the amount of money+ is 30
 *	“Ticket + Pepsi +Popcorn + 3D glasses” if the amount of money is 40"
 * 	Using if conditions and switch case. 
 *
 */

/*Implementation Using If conditions with change */
int main()
{
	int option;
    int money;
    int change;

    while(1)
    {
    	// get options from user.
	    printf("1.Using if Condition.\n");
	    printf("2.Using switch case.\n");
	    printf("Enter a number from (1:3) > ");
	    scanf("%d", &option);

	    // get the amount of money from user.
	    printf("Please Enter the amount of money\n");
	    scanf("%d", &money);

	    // Opriont 1 using if condition.
	    if(option == 1)
	    {
	    	if (money >= 40)
		    {
		        printf("Ticket + Pepsi + Popcorn + 3D Glasses\n");
		        printf("Your change = %d $" ,money-40);
		    }
		    else if(money>=30)
		    {
		        printf("Ticket + Pepsi + Popcorn\n");
		        printf("Your change = %d $", money-30);
		    }
		    else if(money>=20)
		    {
		        printf("Ticket + Pepsi\n");
		        printf("Your change = %d $", money-20);
		    }
		    else if(money>=10)
		    {
		        printf("Ticket\n");
		        printf("Your change = %d $", money-10);
		    }
		    else
		    {
		        printf("This amount is not sufficient");
		    }
	    }
	    // Opriont 2 using switch case.
	    else if(option == 2)
	    {
	    	if(money>=50)
		    {
		        change =money-40;
		        money =40;

		    }
		    else
		    {
		     change = money % 10;
		     money = money - change;
		    }

		    switch(money)
		    {
		    case 0:
		        printf("This amount is not sufficient\n");
		        break;

		    case 10:
		        printf("Ticket\n");
		        printf("Your change = %d $",change);
		        break;

		    case 20:
		        printf("Ticket + Pepsi\n");
		        printf("Your change = %d $",change);
		        break;

		    case 30:
		        printf("Ticket + Pepsi + Popcorn\n");
		        printf("Your change = %d $",change);
		        break;

		    case 40:
		        printf("Ticket + Pepsi + Popcorn + 3D Glasses\n");
		        printf("Your change = %d $",change);
		        break;

		    default:
		        printf ("ERROR!!!!");
		    }
	    }

	    printf("\n");
	    system("pause");
	    system("cls");
    }

    printf("\n");
    system("pause");
    return 0;
}
