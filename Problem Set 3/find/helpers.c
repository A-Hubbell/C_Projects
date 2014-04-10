/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //Searching algorithm
    int min=0;
    int midpoint;
    int max=n;
 
    do
    {
        midpoint=(max+min)/2;
 
        if(value==values[midpoint])
        {
            
            return true;
        }

        
        if (value<values[midpoint])
        {     
            max=midpoint;
        }
  
        if (value>values[midpoint])
        { 
            min=midpoint;
        }
    }
 
    while(value!=values[midpoint] && midpoint!=0);
 
    return false;

}




/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int counter;
    do
    {
        counter = 0;
        for (int i=0; i<n; i++)
        { 
    
            if (values[i]>values[i+1])
            {
                int scrap = 0;
                scrap = values[i];
                values[i] = values[i+1];
                values[i+1] = scrap;
                counter++;
            }
    
        }
    }
    while(counter!=0); 

}


    





