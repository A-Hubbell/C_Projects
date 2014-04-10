//Vigenere's cipher

//Libraries to include
#include <stdio.h>  //printf
#include <cs50.h>   //GetString, GetInt, GetFloat etc.
#include <math.h>   //sqrt, sin, cos etc.
#include <string.h>  //strlen etc.
#include <ctype.h>  //isupper, islower, isalpha




int main(int argc, string argv[])
{
    int int_key[]={};
    int ascii_int_text[]={}; 
    string string_key = argv[1];
    
  
    while(argc!=2)
    {
        //exit(1);
        printf("Please enter one key");
    }
    
  
  
  
  
    //Create array of integer "keys" from user's input
    for(int i=0; i<strlen(string_key); i++)
    {
        if(islower(string_key[i]))
        {
            int_key[i] = string_key[i];
            int_key[i] -= 97;
        }
        
        if(isupper(string_key[i]))
        {
            int_key[i] = string_key[i];
            int_key[i] -= 65;
        }
    }
 

    string plain_text = GetString();
 
    //Encrypt the given text
 
  //  int count = 1;
    int keyLength = strlen(string_key);
    int textLength = strlen(plain_text);
    
    for(int i = 0; i<textLength;i++)
    {
        if(isalpha(plain_text[i]))
        {  
            if((i+1) >= keyLength)
            {
                if(islower(plain_text[i]))
                {
                    ascii_int_text[i] = plain_text[i];
                    ascii_int_text[i] -= 96;
                    
                    //Check if on the last element of the "key" array
                    if((i+1)%keyLength==0)
                    {
                        ascii_int_text[i] = (ascii_int_text[i]+int_key[keyLength-1]);
                    }
                    
                    else
                    {
                        ascii_int_text[i] = (ascii_int_text[i]+int_key[(i+1)%keyLength]);
                    }

                    //wrap around from Z to A
                    
                    if(ascii_int_text[i] > 26)
                    {
                        ascii_int_text[i] = ascii_int_text[i]%26;
                    } 
                    ascii_int_text[i] += 96;
                    plain_text[i] = ascii_int_text[i];
                }
            
            
                if(isupper(plain_text[i]))
                {
                    ascii_int_text[i] = plain_text[i];
                    ascii_int_text[i] -= 64;
                    
                    //Check if on the last element of the "key" array
                    if((i+1)%keyLength==0)
                    {
                        ascii_int_text[i] = (ascii_int_text[i]+int_key[keyLength-1]);
                    }
                    
                    else
                    {
                        ascii_int_text[i] = (ascii_int_text[i]+int_key[(i+1)%keyLength]);
                    }

                    //wrap around from Z to A
                    if(ascii_int_text[i] > 26)
                    {
                        ascii_int_text[i] = ascii_int_text[i]%26;
                    } 
                    ascii_int_text[i] += 64;
                    plain_text[i] = ascii_int_text[i];


                }
            
            
            }
         
            else
            {
            
                if(islower(plain_text[i]))
                {
                    ascii_int_text[i] = plain_text[i];
                    ascii_int_text[i] -= 96;
                    
                    ascii_int_text[i] = (ascii_int_text[i]+int_key[i]);
                    if(ascii_int_text[i] > 26)
                    {
                        ascii_int_text[i] = ascii_int_text[i]%26;
                    }
                    ascii_int_text[i] += 96;
                    plain_text[i] = ascii_int_text[i];
                }
            
                
                if(isupper(plain_text[i]))
                {
                    ascii_int_text[i] = plain_text[i];
                    ascii_int_text[i] -= 64;
                    
                   
                    ascii_int_text[i] = (ascii_int_text[i]+int_key[i]);
                    //wrap around from Z to A
                    if(ascii_int_text[i] > 26)
                    {
                        ascii_int_text[i] = ascii_int_text[i]%26;
                    } 
                    ascii_int_text[i] += 64;
                    plain_text[i] = ascii_int_text[i];

                }
            }
        }  
    }
    printf("%s\n", plain_text);
}
