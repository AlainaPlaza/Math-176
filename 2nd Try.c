// Programmers: Alaina Rose Plaza and Abegail Romas | 3 BS Applied Mathematics
// This program implements Bisection, Secant, and False Position Method

#include<stdio.h>
#include<math.h>
#include<ctype.h>

// Function declarations
	void Bisection();
	void Secant();
	void False_Position();

// Test function
	double F(double x) {
	    return(pow(x,2) - 1); 
	}

int main() {
	
	printf("This program implements the Bisection, Secant, and False Position Method\n");
	printf("Test function: x^2 - 1\n");
	
	char cho;
																											
	printf("\nMenu:"
		"\n\t[a] Bisection Method"
		"\n\t[b] Secant Method"
		"\n\t[c] False Position Method"
		"\n\t[d] Exit Program"
		"\nEnter Choice:");
		
	scanf("%s", &cho);
	cho = tolower(cho);
	system("cls");
		
   switch(cho) {
      case 'a' :
         Bisection();
         break;
      case 'b' :
      	Secant();
      	break;
      case 'c' :
         False_Position();
         break;
      case 'd' :
         printf("Program Terminated.\n");
         return 0;
      default :
         printf("Invalid choice. Program Terminated.\n" );
    }
}

void Bisection() {									// Function for Bisection Method
	
	printf("Bisection Method for (x^2 - 1)");
	
	double a, b;									// Variables for endpoints
	int i;											// Variable for maximum iteration

	INPUT:
	printf("\n\nEnter left interval endpoint: ");
	scanf("%lf", &a);
	printf("\nEnter right interval endpoint: ");
	scanf("%lf", &b);

	if ((a*b) > 0) {								// Error checker: if inputs have the same sign, asks for new input
		printf("Error. Interval endpoints should have opposite signs. Try again.");
		goto INPUT;
	}
	else if (b < a) {
		printf("Error. Left interval enpoint should be smaller than right interval endpoint. Try again.");
		goto INPUT;
	}
	else {
		printf("\nEnter maximum number of iterations: ");
		scanf("%d", &i);
		
		int count = 0;
		double p; 										// Variable for approximation
								
		while (count < i){	// Using maximum iteration 
			p = ((a + b) / 2);
			printf("\nIteration Number: %d | Approximation: %lf \n", count, p);
			
			if (F(p) == 0){							// Checks for root. Stops the iteration process incase root is found
				printf("Root is found. \n Root value is: %lf", p);
				break;
				}
			else {
				count++; 
				
				if (F(a)*F(p) > 0)					// They have the same sign because (+)*(+) = + and (-)*(-) = +
					a = p;
				else								// They have opposite signs 
					b = p;				
					printf("New Interval: [%lf, %lf]", a, b);
			}
		}		
	}
}


void Secant() {										// Function for Secant Method
	
	printf("Secant Method for (x^2 - 1)");
	
	double p0, p1;									// Variables for endpoints
	int i;											// Variable for maximum iteration
	
	printf("\n\nEnter left interval endpoint: ");
	scanf("%lf", &p0);
	printf("\nEnter right interval endpoint: ");
	scanf("%lf", &p1);
	printf("\nEnter maximum number of iterations: ");
	scanf("%d", &i);
	
	int count = 0;
	double p2; 										// Variable for approximation
	
	while (count < i){
		
		if ((F(p1) - F(p0)) == 0){
			printf("\n\nCannot Proceed. \nCause: Division by zero.");
			break;
		}
		else {
			p2 = p1 - ((F(p1)*(p1 - p0)) / (F(p1) - F(p0)));
			printf("\nIteration Number: %d | Approximation: %lf\n", count, p2);
			count++;
			p0 = p1;
			p1 = p2;
			printf("New Interval: [%lf, %lf]", p0, p1);
		}
	}	
}

void False_Position() {
	
	printf("False Position for (x^2 - 1)");
	
	









	
}
