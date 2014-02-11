// Greedy!!

#include <stdio.h>
#include <cs50.h>

// check50 2014/x/pset1/greedy greedy.c

int main(void)
{

//Variable declarations
//int change_d=0;
int change_c=0;
int num_coin=0;

//Prompt user for input in dollars
//printf("Please enter the amount of change owed (in dollars): ");
//change_c=GetFloat()*100; // convert to cents

//Convert to cents
//change_c=change_d*100;
do
{
printf("Change owed (in dollars): ");
change_c=GetFloat();
change_c=change_c*100;

}
while(change_c<0);


while(change_c>0)
    {

    if(change_c>=25)
        {
        num_coin++;
        change_c-=25;
        }
    else
    {
        if(change_c>=10)
            {
            num_coin++;
            change_c-=10;
            }
            
        else
            {
                if(change_c>=5)
                    {
                    num_coin++;
                    change_c-=5;
                    }
                              
                else
                    {
                        if(change_c>=1)
                            {
                            num_coin++;
                            change_c-=1;
                            }
                            
                        else
                        {
                        
                        }        
                    }                   




            }
    }
}

//printf("Your change is: %d quarters, %d dimes, %d nickels and %d pennies\n", num_quarter, num_dime, num_nickel, num_penny);
printf("%d\n", num_coin);
}
