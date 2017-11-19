#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN 50

typedef struct _person{
  int ssn;
  char name[STR_LEN];
  char addr[STR_LEN];
} Person;

int getSSN(Person *p);
void showPerInfo(Person *p);
Person *makePersonData(int ssn, char *name, char *addr);


#endif
