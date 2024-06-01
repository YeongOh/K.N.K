#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+3];
  char month_str[3], day_str[3], msg_str[MSG_LEN+1];
  char time_str[6];
  int month, day, i, j, num_remind = 0;
  int hours, minutes;

  printf("%d", strcmp("06","12") <= 0);

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter month, day, time, and reminder(mm/dd hh:mm - r.. 0 to quit): ");
    scanf("%2d/%2d", &month, &day);

    if (month == 0)
        break;
	if (day < 0 || day > 31) {
		printf("Day can't be less than 0 or greater than 31\n");
		continue;
	}
	if (month < 0 || month > 12) {
		printf("Month can't be less than 0 or greater than 12\n");
		continue;
	}

	scanf("%2d:%2d", &hours, &minutes);

	if (hours < 0 || hours > 24 || minutes < 0 || minutes > 60) {
		printf("Wrong input for hours and minutes\n");
		continue;
	}
	sprintf(month_str, "%2d", month);
    sprintf(day_str, "%.2d", day);
	sprintf(time_str, "%2d:%.2d", hours, minutes);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++) {
	  if (strncmp(month_str, reminders[i], 2) <= 0
		  && strncmp(day_str, &reminders[i][3], 2) <= 0
		  && strncmp(time_str, &reminders[1][6], 5) < 0) {
		  break;
	  }
	  if (strncmp(month_str, reminders[i], 2) <= 0
		  && strncmp(day_str, &reminders[i][3], 2) < 0) {
		  break;
	  }
      if (strncmp(month_str, reminders[i], 2) < 0) {
		  break;
	  } 
	}
    for (j = num_remind; j > i; j--) {
      	strcpy(reminders[j], reminders[j-1]);
	}

    strcpy(reminders[i], month_str);
	strcat(reminders[i], "/");
    strcat(reminders[i], day_str);
	strcat(reminders[i], " ");
	strcat(reminders[i], time_str); 
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nYear Reminder\n");
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
