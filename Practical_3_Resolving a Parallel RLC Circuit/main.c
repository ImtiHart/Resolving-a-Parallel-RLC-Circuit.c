#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Initialize components of code
float XL, Xc, sum, Z, R, L, f, c, Is, IR, IL, Ic, Vs, n, m, k;
char choice;
int main()
{
    //Allow user to input what they want to calculate
    printf("Choose what you would like to calculate by its associated letter: \na-Impedance\nb-Current through voltage source\nc-Current through resistor\nd-Current through inductor\ne-Current through capacitor\n");
    scanf("%c", &choice);
    //Assign variables with 'choice' of users calculation to form the solution
    switch(choice)
    {
    case 'a':
        impedance();
        break;
    case 'b':
        I_S();
        break;
    case 'c':
        I_R();
        break;
    case 'd':
        I_L();
        break;
    case 'e':
        I_C();
         break;
    default:
        printf("NO SOLUTION");
    }
}

//Create functions to solve the 'choice' of user
void impedance()
{
    printf("What is the value of AC frequency and inductance? ");
    scanf("%f %f", &f, &L);
    XL=(2*3.141592654*f*L);
    printf("What is the value of AC frequency and capacitance? ");
    scanf("%f %f", &f, &c);
    Xc=1/(2*3.141592654*f*c);
    printf("What is the value of the resistance?");
    scanf("%f", &R);
    n=(1/XL)-(1/Xc);
    m=pow(n, 2);
    k=pow(R, 2);
    sum=(1/(k)) + (m);
    Z=1/(sqrt(sum));
    printf("The value is: %.2fOhms", Z);
}
void I_S()
{
    printf("What is the source voltage? ");
    scanf("%f", &Vs);
    impedance();
    Is= Vs/Z;
    printf("The value is: %.2fA", Is);
}
void I_R()
{
    printf("What is the value of the source voltage and the resistor? ");
    scanf("%f %f", &Vs, &R);
    IR=Vs/R;
    printf("The value is: %.2fA", IR);
}
void I_L()
{
    printf("What is the value of AC frequency and inductance? ");
    scanf("%f %f", &f, &L);
    XL=(2*3.141592654*f*L);
    printf("What is the source voltage? ");
    scanf("%f", &Vs);
    IL=Vs/XL;
    printf("The value is: %.2fA", IL);
}
void I_C()
{
    printf("What is the value of AC frequency and capacitance? ");
    scanf("%f %f", &f, &c);
    Xc=1/(2*3.141592654*f*c);
    printf("What is the source voltage? ");
    scanf("%f", &Vs);
    Ic=Vs/Xc;
    printf("The value is: %.2fA", Ic);
}
