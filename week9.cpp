#include<stdio.h>
#include<iostream>
#include<locale>


char GradeFromPercentage(float a) // Calculates the letter grade based on %
{
	char grades[5] = { 'A','B','C','D','F' }; // Saves letter grades in 1d array

	// If else loops determine which element in array to access

	if (a >= 90) { return grades[0]; }

	if (a >= 70 && a < 90) { return grades[1]; }

	if (a >= 50 && a < 70) { return grades[2]; }

	if (a >= 30 && a < 50) { return grades[3]; }

	else { return grades[4]; }
}

char GradeFromRawMarks(float a, float b)
{
	// a = marks awarded        b = marks available
	float percentage;
	percentage = (a / b) * 100;

	return GradeFromPercentage(percentage); // Plug percentage into previous function

}

int CaseCheck(char a, char b) { // Checks if letters are the same (whether upper or low case)

	int one = 1;
	int zero = 0;

	if (a == b) { return one; }
	if (b == toupper(a)) { return one; } // User the toupper function to make character upper case
	if (a == toupper(b)) { return one; }
	else { return zero; } // If characters are different return zero (which = 0)

}

char GradeFromTotalRawMarks()
{
	// Initalise a variable for marks awarded
	float marks_awarded;
	// Initialise an array to hold all the values of marks awarded
	float marks_awarded_array[100];

	// Initialise a variable for marks available (corresponding to marks awarded)
	float marks_available;
	// Initialise an array for marks available for each assignment
	float marks_available_array[100];

	int total_assignments;
	int count = 0;

	char yes_no = 'y';
	int one_zero = 1;

	// While loop adds all of the marks awarded and marks available floats to the correct array
	while (count <= 100 && one_zero == 1) {

		// Adds marks awarded to marks awarded array, using count as an index variable
		printf("Please input the amount of marks you awarded for this assignment");
		scanf("%f", &marks_awarded);
		marks_awarded_array[count] = marks_awarded;

		// Adds marks available to marks available array, using count as an index variable
		printf("Please input the amount of marks available for this assignment");
		scanf("%f", &marks_available);
		marks_available_array[count] = marks_available;

		// If user would like to continue, yes_no = y, if not yes_no = n
		printf("Would you like to add another assignment? Please enter y or n ");
		scanf(" %c", &yes_no);
		one_zero = CaseCheck(yes_no, 'y');// Use the casecheck function to assign value

		count++; // Keeps count of how many assignments there are in total so far
	}

	int i;
	float total_awarded = marks_awarded_array[0]; // starts of variable with 1st element
	float total_available = marks_available_array[0];

	for (i = 1; i < count; ++i) { // count represents assingment number, so is used

		total_awarded += marks_awarded_array[i]; // add up all of the elements

		total_available += marks_available_array[i]; // add up all of the elements


	}

	return GradeFromRawMarks(total_awarded, total_available); // plug variables into previous function
}

// Displays marks for individual assignments, and overall grade
char DisplayAllRawMarks(float marks_awarded_array[], float marks_available_array[], int max_assignments) {


	// For loop accesses each element in array and assigns marks
	for (int i = 0; i < max_assignments; i++) {

		char Grade;
		Grade = GradeFromRawMarks(marks_awarded_array[i], marks_available_array[i]);

		int assignment_number = i + 1; // Assignment number is +1 because array starts at 0

		printf("%d: %f/%f -> %c \n", assignment_number, marks_awarded_array[i], marks_available_array[i], Grade);
		// Outputs assignment number, marks and grade
	}

	// Initialise variables used for overall marks (all marks added)
	float total_awarded = 0;
	float total_available = 0;

	// for loop adds each element in the array to appropiate variable
	for (int i = 0; i < max_assignments; i++) {
		total_awarded = total_awarded + marks_awarded_array[i];

		total_available = total_available + marks_available_array[i];
	}

	// total grade is set to the ouput of GradeFromRawMarks function using the previous two variables as input
	char TotalGrade = GradeFromRawMarks(total_awarded, total_available);
	printf("================== \n");
	printf("Overall Grade %c", TotalGrade);

	return 0;
}

// function edits assignments, by editing one element in each array
void EditAssignment(float marks_awarded[], float marks_available[], int max) {

	int actual_position = max - 1; // actual position is -1 because arrays start at 0


	printf("Please enter the new marks awarded");
	scanf("%f", &marks_awarded[actual_position]); // Replaces element "position" with user input

	printf("Please enter the new marks available");
	scanf("%f", &marks_available[actual_position]); // Replaces element "position" with uer input
}

// Function adds an additional assignment, by adding one element to each array
void AddAssignment(float marks_awarded[], float marks_available[], int &max) {

	max = max++; // pass by reference the new value of max

	EditAssignment(marks_awarded, marks_available, max); // new max is input into previous function

}

void RemoveAssignments(float marks_awarded[], float marks_available[],int &max) {
	int user_input;
	printf("Please input the the assingment you would like to remove");
	scanf("%d", &user_input);
	


	for (int i = user_input-1; i < max; i++)
	{
		marks_awarded[i] = marks_awarded[i + 1];
		marks_available[i] = marks_available[i + 1];
	}


	//max = max - 1;



}


int main()
{
	char Grade;
	char userInput = '?'; // some place to store input from the user
	int max = 0;          // the maximum assignment count (i.e. how many assignements we have
	float marksAwarded[100];     // place to store the marks
	float marksAvailable[100]; // place to store the available marks

	// Since we've not got any code to add new assignments yet,
	// here's some test assignments manually assigned.

	/* Testing code: default assignment scores */
	marksAwarded[0] = 10; marksAvailable[0] = 10;
	marksAwarded[1] = 7;  marksAvailable[1] = 11;
	marksAwarded[2] = 5;  marksAvailable[2] = 11;
	marksAwarded[3] = 3;  marksAvailable[3] = 11;
	marksAwarded[4] = 0;  marksAvailable[4] = 100;
	max = 5; // update how many items we have

/* End of testing code */

	while (1) // forever
	{
		int counter = 0;

		// Print the main menu
		printf("\nA) Display Marks\nB) Edit Assignment\nC) Add Assignment\nD) Remove Assignment\nQ) Quit\n\n>");

		// Grab the option from the user
		scanf(" %c", &userInput);

		if (CaseCheck(userInput, 'A'))
		{
			// Display all the marks we have

			DisplayAllRawMarks(marksAwarded, marksAvailable, max);

		}

		if (CaseCheck(userInput, 'B'))
		{
			int position;// initalise variable needed for edit assignment function
			printf("Please input the assignment number");
			scanf("%d", &position); // assigns user input to variable
			EditAssignment(marksAwarded, marksAvailable, position); // edit assignment

			printf("\n Would you like to go back to the menu? (Y for yes, Q for quit): ");
			scanf(" %c", &userInput);


		}

		if (CaseCheck(userInput, 'C')) // if user enter 'c' then add assignment
		{
			AddAssignment(marksAwarded, marksAvailable, max);

			printf("\n Would you like to go back to the menu? (Y for yes, Q for quit): ");
			scanf(" %c", &userInput);
		}


		if (CaseCheck(userInput, 'D'))
		{
			RemoveAssignments(marksAwarded, marksAvailable, max);
			max = max - 1;
			printf("\n Would you like to go back to the menu? (Y for yes, Q for quit): ");
			scanf(" %c", &userInput);

		}

		if (CaseCheck(userInput, 'Q'))
		{
			// If 'Q' or 'q' entered, break out of the while loop
			break;
		}

		// Keep going around the while loop if the user didn't quit
	}

	return 0;
}
