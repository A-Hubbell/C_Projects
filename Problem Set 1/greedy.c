// Greedy!!

#include <stdio.h>
#include <cs50.h>
#include <math.h>

// check50 2014/x/pset1/greedy greedy.c

int main(void)
{

//Variable declarations
float change_c=0.0;
int num_coin=0;

//Prompt user and convert from dollars to cents

do
{
printf("Change owed (in dollars): ");
change_c=GetFloat()*100;
}
while(change_c<0);


//Round the number of cents 
change_c=floorf(change_c*100+0.5)/100;


//Loop through different coin denominations, moving from largest to smallest, subtracting the denomination amount each time
//and adding one to the number of coins required
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
                    }                   
            }
    }
}

//Output the final result (number of coins required)
printf("%d\n", num_coin);
}
