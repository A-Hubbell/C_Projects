// Caesar's Cipher
// Get cipher "key" from user
// Take in a message from the user
// Encrypt user's message
// Print cipher text




//Libraries to include
#include <stdio.h>  //printf
#include <cs50.h>   //GetString, GetInt, GetFloat etc.
#include <math.h>   //sqrt, sin, cos etc.
#include <string.h>  //strlen etc.
#include <ctype.h>  //isupper, islower, isalpha

int cipher_key = 0;

// argc is number of arguments passed to command line (should be 2 in this case, one for ./caesar and one for the key)
// argv is a list of the arguments passed in, argv[0] is always the program name
int main(int argc, string argv[])
{

//Variable declarations
// cipher_key = 0;
int ascii_int_text[]={}; 
string plain_text = "";


//Check to make sure only 2 inputs (program name and cipher key) from user and that the cipher key is a non-negative integer

if ((argc > 2) || ((atoi(argv[1])==0) && ((int)argv[1]>0)) || (atoi(argv[1])<0))
{
printf("Please run the program again and enter a single integer for the cipher key and nothing else.\n");
return 1;
}

cipher_key = atoi(argv[1]);

//Comment below line
printf("%i\n", cipher_key);


printf("Please enter your plain text to be encrypted. \n");

plain_text=GetString();




for(int i = 0; i<(strlen(plain_text));i++)
{
      
     printf("YOU SHOULD SEE THIS %i   CKEY: %i\n", i, cipher_key);
     if(isupper(plain_text[i]))
     {

        printf("Letter: %c\n", plain_text[i]);
        printf("Cipher Key BEFORE: %i ASCII text BEFORE %i\n", cipher_key, ascii_int_text[i]);
        ascii_int_text[i] = plain_text[i];    ////////////////THIS IS THE PROBLEM LINE!!
        printf("Cipher Key AFTER: %i ASCII text AFTER %i\n", cipher_key, ascii_int_text[i]);
        ascii_int_text[i] = (ascii_int_text[i])-64;
        printf("CKEY: %i\n", cipher_key);
        printf("1-26 alphabet: %i\n", ascii_int_text[i]);
        
        
        //ascii_int_text[i] = (((ascii_int_text[i])+(cipher_key))%26);
    //    printf("Cipher Key BEFORE: %i text BEFORE %i\n", cipher_key, ascii_int_text[i]);
        ascii_int_text[i] = (ascii_int_text[i]+cipher_key);
     //   ascii_int_text[i] = ((ascii_int_text[i])+1);
    //    printf("Cipher Key AFTER: %i\n", cipher_key); 
    //   ascii_int_text[i]= ascii_int_text[i]+cipher_key;
       printf("SUM: %i\n", ascii_int_text[i]);
   //    ascii_int_text[i]= ((ascii_int_text[i])%26);
     //  printf("ASCII: %i\n", ascii_int_text[i]);
        
        ascii_int_text[i] = (ascii_int_text[i])+64;
        plain_text[i]=ascii_int_text[i];
     }

//only executes if the text is upper case
     if(islower(plain_text[i]))
     { 
        printf("THIS SHOULD NOT SHOW UP\n");
        ascii_int_text[i] = plain_text[i];
        ascii_int_text[i] = ascii_int_text[i]-96;
      //  ascii_int_text[i] = (ascii_int_text[i]+cipher_key)%26;
        ascii_int_text[i] = ascii_int_text[i]+96;
        plain_text[i] = ascii_int_text[i];
     }
    
     else
     {
     }
     printf("THE END CKEY: %i\n", cipher_key);
}
  
//printf("%s\n", plain_text);

  



//char alphabet[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v'};
//Cool functions: isalpha(' '), isupper(' '), islower(' ')




}


