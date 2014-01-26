// Mario!!


#include <stdio.h>
#include <cs50.h>

int main(void)
{
//Variable declarations
int height;

//User input and number check
printf("Please enter the desired height of the half pyramid (0-23): ");
do
{
printf("Height: ");
height=GetInt();

}
while(height>23 || height<0);


for (int i=0; i<height; i++)
{
    int numSpaces=height-(i+1);
    int numHashes=i+2;

    if(height==0)
        {
        
        }
        
        
    else
    {
    
        for(int j=0; j<numSpaces; j++)
            {
            printf(" ");
            }

        for(int k=0; k<numHashes; k++)
            {
            printf("#");
            }

        printf("\n");
    }

}

}

