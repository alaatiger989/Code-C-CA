#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

// Function prototype declaration
void subtraction();
void division();
void find_maximum();
void power();
int factorial();

void getSin();
void getCos();
void getTan();
void isTriangle();
void isSquare();
void isRectangle();

void displayOperations();

// Start of Main Program
int main()
{
    char Calc_oprn;

    // Display Calculator operations
    displayOperations();

    while(1)
    {
        printf("%s : ", "\nEnter the calculator Operation you want to do ");

        Calc_oprn = getche(); //read char with click 'enter' key

        switch(Calc_oprn)
        {
            case '-':
                subtraction();
                break;

            case '/':
                division();
                break;

            case '!':
                factorial();
                break;

            case '^':
                power();
                break;

            case '1':
                find_maximum();
                break;

            case '2':
                getSin();
                break;

            case '3':
                getCos();
                break;

            case '4':
                getTan();
                break;

            case '5':
                isTriangle();
                break;

            case '6':
                isSquare();
                break;

            case '7':
                isRectangle();
                break;

            case 'Q':
            case 'q':
                exit(0);
                break;

            default :
				system("cls");

			printf("\n***** You have entered unavailable option *****\n");
            displayOperations();
        }
    }
}

//Function Definitions

void displayOperations()
{
    printf("*************************************************");
    printf("\n  Welcome to C Scientific Calculator \n");
    printf("*************************************************");
    printf("\n**** Please select one of the below options  ****\n\n");
    printf(" > Enter - symbol for Subtraction \n");
    printf(" > Enter / symbol for Division \n");
    printf(" > Enter ^ symbol for Power \n");
    printf(" > Enter ! symbol for Factorial \n\n");
    printf(" Others : \n");
    printf(" > Enter 1 for Get max of list \n");
    printf(" > Enter 2 for Get Sin \n");
    printf(" > Enter 3 for Get Cos \n");
    printf(" > Enter 4 for Get Tan \n");

    printf(" > Enter 5 for Check Triangle \n");
    printf(" > Enter 6 for Check Square \n");
    printf(" > Enter 7 for Check Rectangle \n");

    printf("***** Press 'Q' or 'q' to quit the program ******\n");
    printf("*************************************************");
}

void subtraction()
{
    int a, b, c = 0;
    printf("\nPlease enter first number  : ");
    scanf("%d", &a);
    printf("Please enter second number : ");
    scanf("%d", &b);
    c = a - b;
    printf("\n%d - %d = %d\n", a, b, c);
}

void division()
{
    int a, b, d=0;
    printf("\nPlease enter first number  : ");
    scanf("%d", &a);

    printf("Please enter second number : ");
    scanf("%d", &b);

    d = a / b;
    printf("\nDivision of entered numbers = %d\n",d);
}

void power()
{
    double a,num, p;
    printf("\nEnter two numbers to find the power \n");

    printf("number: ");
    scanf("%lf",&a);

    printf("power : ");
    scanf("%lf",&num);

    p = pow(a, num);

    printf("\n%lf to the power %lf = %lf \n",a,num,p);
}

int factorial()
{
    int i, fact=1, num;

    printf("\nEnter a number to find factorial : ");
    scanf("%d",&num);

    if (num<0)
    {
        printf("\nPlease enter a positive number to");
        printf(" find factorial and try again. \n");
        printf("\nFactorial can't be found for negative");
        printf(" values. It can be only positive or 0  \n");
        return 1;
    }

    // calculate factorial
    for(i=1; i <= num; i++)  //5
     fact = fact * i;  // 5 * 4 * 3 * 2 * 1

    printf("\nFactorial of entered number %d is:%d\n",num,fact);
    return 0;
}

void find_maximum() {
  int array[100], size, c, location = 0;

  printf("\nEnter the number of elements in array (maximum: 100)\n");
  scanf("%d", &size);

  printf("Enter %d integers\n", size);
  for (c = 0; c < size; c++)
    scanf("%d", &array[c]);

  // get max element location
  for (c = 1; c < size; c++)
    if (array[c] > array[location])
      location = c;

  printf("\nMaximum element is present at location %d and its value is %d.\n",
         location+1, array[location]);
}

void getSin(){
    float input;
    printf("\n Enter number to get Sin : \n");
    scanf("%f", &input);

    float sin_value = sin(input);

    printf("The value of sin(%f) : %f \n", input, sin_value);
}

void getCos(){
    float input;
    printf("\n Enter number to get Cos : \n");
    scanf("%f", &input);

    float cos_value = cos(input);

    printf("The value of cos(%f) : %f \n", input, cos_value);
}

void getTan(){
    float input;
    printf("\n Enter number to get Tan : \n");
    scanf("%f", &input);

    float tan_value = tan(input);

    printf("The value of tan(%f) : %f \n", input, tan_value);
}

void isTriangle(){
    float a , b, c;

    printf("\nEnter side 1 : \n");
    scanf("%f", &a);

    printf("Enter side 2 : \n");
    scanf("%f", &b);

    printf("Enter side 3 : \n");
    scanf("%f", &c);

    if (a + b <= c || a + c <= b || b + c <= a){
        printf("Invalid Triangle .\n");
    }else{
        printf("Valid Triangle .\n");
    }

}

void isSquare(){
    float a , b, c, d;

    printf("\nEnter side 1 : \n");
    scanf("%f", &a);

    printf("Enter side 2 : \n");
    scanf("%f", &b);

    printf("Enter side 3 : \n");
    scanf("%f", &c);

    printf("Enter side 4 : \n");
    scanf("%f", &d);

    if(a == b && b == c && c == d){
        printf("Valid Square .\n");
    }else{
        printf("Invalid Square .\n");
    }
}

void isRectangle(){
    float a , b, c, d;

    printf("\nEnter side 1 : \n");
    scanf("%f", &a);

    printf("Enter side 2 : \n");
    scanf("%f", &b);

    printf("Enter side 3 : \n");
    scanf("%f", &c);

    printf("Enter side 4 : \n");
    scanf("%f", &d);

    int isValid;

    // Square is also a rectangle
    if (a == b == c == d)
        isValid = 1;
    else if (a == b && c == d)
        isValid = 1;
    else if (a == d && c == b)
        isValid = 1;
    else if (a == c && d == b)
        isValid = 1;
    else
        isValid = 0;

    if(isValid){
        printf("Valid Rectangle .\n");
    }else{
        printf("Invalid Rectangle .\n");
    }
}


