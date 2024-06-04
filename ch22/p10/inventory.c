#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
  int number; // 4
  char name[NAME_LEN+1]; // 4 + 26 = 32
  int on_hand; // 32 + 4 => 40
  struct part *next;
};

struct part *inventory = NULL;   /* points to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

void dump(void);
void restore(void);

int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': insert();
                break;
      case 's': search();
                break;
      case 'u': update();
                break;
      case 'p': print();
                break;
	  case 'd': dump();
				break;
	  case 'r': restore();
				break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

void dump(void) {
	FILE *fp;
	char fname[FILENAME_MAX];
	struct part *temp;

	printf("Enter name of output file: ");
	read_line(fname, FILENAME_MAX - 1);
	
	fp = fopen(fname, "wb");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", fname);
		exit(EXIT_FAILURE);
	}

	temp = inventory;
	while (temp != NULL) {
		fwrite(temp, sizeof(struct part) - sizeof(struct part *), 1, fp);
		temp = temp->next;
	}
	
	fclose(fp);
}

void restore(void) {
	FILE *fp;
	char fname[FILENAME_MAX];
	struct part *prev, buff;

	printf("Enter name of input file: ");
	read_line(fname, FILENAME_MAX - 1);
	
	fp = fopen(fname, "rb");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", fname);
		exit(EXIT_FAILURE);
	}
	
	prev = NULL;
	while (fread(&buff, sizeof(struct part) - sizeof(struct part *), 1, fp) > 0) {
		inventory = malloc(sizeof(struct part));
		if (inventory == NULL) {
			fprintf(stderr, "malloc fail\n");
			exit(EXIT_FAILURE);
		}

		inventory->number= buff.number;
		strcpy(inventory->name, buff.name);
		inventory->on_hand = buff.on_hand;
		inventory->next = prev;

		prev = inventory;
		inventory = NULL;
	}
	inventory = prev;
	
	fclose(fp);
}


/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            list. Returns a pointer to the node         *
 *            containing the part number; if the part     *
 *            number is not found, returns NULL.          *
 **********************************************************/
struct part *find_part(int number)
{
  struct part *p;

  for (p = inventory;
       p != NULL && number > p->number;
       p = p->next)
    ;
  if (p != NULL && number == p->number)
    return p;
  return NULL;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         inventory list; the list remains sorted by     *
 *         part number. Prints an error message and       *
 *         returns prematurely if the part already exists *
 *         or space could not be allocated for the part.  *
 **********************************************************/
void insert(void)
{
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;
  if (cur != NULL && new_node->number == cur->number) {
    printf("Part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL)
    inventory = new_node;
  else
    prev->next = new_node;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
  int number;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
  int number, change;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Part numbers will appear in   *
 *        ascending order.                                *
 **********************************************************/
void print(void)
{
  struct part *p;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next)
    printf("%7d       %-25s%11d\n", p->number, p->name,
           p->on_hand);
}
