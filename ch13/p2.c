#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+3];
  char day_str[3], msg_str[MSG_LEN+1];
  char time_str[6];
  int day, i, j, num_remind = 0;
  int hours, minutes;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day, time, and reminder(d hh:mm - r..): ");
    scanf("%2d", &day);

    if (day == 0)
        break;
	if (day < 0 || day > 31) {
		printf("Day can't be less than 0 or greater than 31\n");
		continue;
	}

	scanf("%2d:%2d", &hours, &minutes);

	if (hours < 0 || hours > 24 || minutes < 0 || minutes > 60) {
		printf("Wrong input for hours and minutes\n");
		continue;
	}
    sprintf(day_str, "%2d", day);
	sprintf(time_str, "%2d:%.2d", hours, minutes);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++) {
      if (strncmp(day_str, reminders[i], 2) <= 0
		  && strncmp(time_str, &reminders[i][3], 5) < 0) {
        break;
	  }
	  if (strncmp(day_str, reminders[i], 2) < 0) {
		  break;
	  }
	}
    for (j = num_remind; j > i; j--) {
      	strcpy(reminders[j], reminders[j-1]);
	}

    strcpy(reminders[i], day_str);
	strcat(reminders[i], " ");
	strcat(reminders[i], time_str); 
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
