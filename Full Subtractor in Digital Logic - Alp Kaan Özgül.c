
// Alp Kaan Özgül 2638096

#include <stdio.h>

int main() {
    int choise,basechoise;             // Seperated like this to understand which variable belongs where
    char input;
    int i = 0, length = 0, isBinary = 1;
    int vdcheck;
    int a,b,bin;
    int diff,bout,diff16,bout16;
    int input17;
    int chx;
    int bit1, bit2, bit3;

    // shows menu options
    printf("Welcome to Full Subtractor\n");
    printf("(1) Compute and Display the outputs\n");
    printf("(2) Quit\n");
    printf("You choose: ");
    scanf (" %d",&choise);


    if (choise == 1)  // If user chooses option 1
    {
        printf("Which base will you use to enter input (base 2 or base 16)? ");
        scanf("%d", &basechoise); // Asks user to choose base 2 or base 16
        if (basechoise == 2) // If user chooses base 2
        {
            while(1) { // Loops until user enters a valid binary input
                printf("Please enter your input: ");
                scanf(" %c", &input);
                while(input != '\n') {
                    if(input != '0' && input != '1') {
                        isBinary = 0;
                    }
                    i++;
                    scanf("%c", &input);
                }

                length = i;
                i = 0;

                // Checks the length of input
                if(isBinary == 1 && length > 3) {
                    printf("You entered more than 3 bits! Please try again!\n");

                } else if(isBinary == 1 && length < 3) {
                    printf("You entered less than 3 bits! Please try again!\n");

                }
                else if (isBinary==1 && length == 3){


                    vdcheck = 1;
                    break;
                }
                else { // if input is not a valid binary number
                    printf("Invalid number in base 2! Please try again!\n");
                    isBinary = 1;
                }
            }
            if (vdcheck ==1)  // If user entered a valid binary input, ask users to enter values one by one
            {
                printf("Please re-enter the most recent value that you have entered one by one\n");
                printf("till you see !!DONE!!\n ");
                scanf ("%d",&a);
                scanf ("%d",&b);
                scanf ("%d",&bin);
                printf("!!DONE!! \n");


                diff = a - b - bin;  // Calculates difference and borrow for full subtractor


                if (diff < 0) {
                    diff += 2;
                    bout = 1;
                }
                else {
                    bout = 0;
                }


                if (a < b) {
                    bout = 1;
                }
                printf(" D is %d Bout is %d",diff,bout);
            }


        }
        else if(basechoise ==16) // If user chooses base 16
        {
            printf("Enter your input: ");
            scanf(" %d",&input17);

            while (input17<0 || input17>7){  // Checks if input can be converted to a 3-digit binary number
                printf("Not possible to convert it to 3-digit binary number. Please try again!");
                scanf("%d",&input17);
            }
            chx =1;
            if(chx ==1){  //converts it to binary
                bit1 = input17 % 2;
                input17 = input17 / 2;
                bit2 = input17 % 2;
                input17 = input17 / 2;
                bit3 = input17 % 2;


            }
            diff16 =  bit3 - bit2 - bit1; // calculates d

            //calculates bout
            if (diff16 < 0) {
                diff16 += 2;
                bout16 = 1;
            }
            else {
                bout16 = 0;
            }


            if (bit3 < bit2) {
                bout = 1;
            }
            printf(" D is %d Bout is %d",diff16,bout16);





        }
    }


    else { // if quit is chosen program stops
        printf("You have chosen option %d\n", choise);
        printf("BYEE!!");
    }


    return 0;
}
