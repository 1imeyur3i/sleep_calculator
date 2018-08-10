#include <stdio.h>
#include <stdbool.h>

int menu () {

	int choice = 0;
	printf ("\nMENU\n");
	printf ("Choose an option :\n");
	printf ("0. quit;\n");
	printf ("1. Find out when you should wake up;\n");
	printf ("2. Find out when should go to sleep;\n");
	printf ("3. About;\n\n");
	printf ("Your choice : ");
	scanf ("%d", &choice);
	printf ("\n");
	return choice;
}

void print_time (int hours, int minutes) {

	if (hours >= 0 && hours <= 9 && minutes >= 0 && minutes <= 9)
		printf (" * 0%d:0%d\n", hours, minutes);
	else if (hours >= 0 && hours <= 9 && minutes > 9)
		printf (" * 0%d:%d\n", hours, minutes);
	else if (hours > 9 && minutes >= 0 && minutes <= 9)
		printf (" * %d:0%d\n", hours, minutes);
	else
		printf (" * %d:%d\n", hours, minutes);	
}

bool correct_time (int hours, int minutes) {

	if (hours < 0 || hours >= 24 || minutes < 0 || minutes >=60)
		return false;
	return true;	
}

void calc_time (int hours, int minutes) {

	for (int i = 0; i < 6; i++) {
		hours += 1;
		minutes += 30;
		if (hours >= 24)
			hours -= 24;
		if (minutes >= 60) {
			hours += 1;
			minutes -= 60;
		}
		print_time (hours, minutes);
	}

} 

void wake_up (int hours, int minutes) {

	printf ("Time you should wake up at:\n");
	minutes += 15;
	calc_time (hours, minutes);
}

void go_to_sleep (int hours, int minutes) {

	hours -= 10;
	minutes -= 45;
	if (minutes < 0) {
		hours -= 1;
		minutes += 60;
	}
	if (hours < 0)
		hours += 24;
	printf ("Time you should go to sleep at :\n");	
	calc_time (hours, minutes);
		
	
}

void about ();

void main () {

	int hours, minutes;
	int choice = 0;	
	while ((choice = menu ()) != 0) {
		switch (choice) {
			case 1: printf ("Enter time when you plan to go to sleep : ");
					scanf ("%d:%d", &hours, &minutes);
					if (correct_time (hours, minutes))
						wake_up (hours, minutes);
					else printf ("Incorrect input\n");
					break;
			case 2: printf ("Enter time when you plan to wake up : ");
					scanf ("%d:%d", &hours, &minutes);
					if (correct_time (hours, minutes))
						go_to_sleep (hours,  minutes);
					else
						printf ("Incorrect input\n");
					break;
			case 3: about ();
					break;
		}
	}

}

void about () {

	printf ("\n1) It takes approximately 15 minutes for a person to fall asleep,\n this is already factored in this calculator.\n");
	printf ("2) Each cycle lasts about 90 minutes. For a good sleep, a person\n should pass through 5-6 cycles a night.\n");
	printf ("3) It is best to wake up when a cycle is finished because waking\n up in the middle of it will leave you feeling tired.\n");
	printf ("4) By using this calculator, you can find out the right time for\n waking up with a smile.\n\n");
}