#include <stdio.h>
#include <stdlib.h>

/*
Name:
Date:
Description:
Sample Input:
Sample Output:
 */

struct student
{
    int id;
    char name[50];
    char address[50];
    char mob[10];
};

void add_Student()
{

    FILE *fp = fopen("data.txt", "a");

     // rewind(fp);

    if(fp == NULL)
    {
	printf("Invalid File");
	return;
    }

    struct student s;

    printf("Enter your ID: ");
    scanf("%d", &s.id);
    getchar();

    printf("Enter Your Name: ");
    scanf("%[^\n]", s.name);
    getchar();

    printf("Enter your address: ");
    scanf("%[^\n]", s.address);
    getchar();

    printf("Enter your Mobile Number: ");
    scanf("%[^\n]", s.mob);
    getchar();

    fprintf(fp, "%d %s %s %s\n", s.id, s.name, s.address, s.mob);

    printf("Student Details Added Successfully.\n");

    fclose(fp);
}

void display()
{
    FILE *fp = fopen("data.txt", "r");
     // rewind(fp);

    if(fp == NULL)
    {
	printf("Invalid File");
	return;
    }

    struct student s;
     
    printf("------------------------------------------------------------------------\n");

    printf("\t\t\t::Student Address Book::\n");
    printf("------------------------------------------------------------------------\n");
    printf("ID\t\t Name\t\t Address\tMobile\n");
    printf("-------------------------------------------------------------------------\n");
    while(fscanf(fp, "%d %s %s %s", &s.id,s.name,s.address,s.mob) != EOF)
    {
	printf("%d\t\t %s\t\t %s\t\t%s\n", s.id,s.name,s.address,s.mob);
    }

    fclose(fp);
}

void delete_student()
{
    FILE *fp = fopen("data.txt", "r");
   //  rewind(fp);

    if(fp == NULL)
    {
	printf("Invalid File\n");
	return;
    }

    FILE *fp2 = fopen("temp.txt", "w");
    if(fp2 == NULL)
    {
	printf("Invalid File\n");
	fclose(fp);
	return;
    }

    struct student s;
    int id;

    printf("Enter the ID of the student to delete: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d %s %s %s", &s.id, s.name, s.address, s.mob) != EOF)
    {
	if(id != s.id)
	{
	    fprintf(fp2, "%d %s %s %s\n", s.id, s.name, s.address, s.mob);
	}
    }

    fclose(fp);
    fclose(fp2);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    printf("Student Details Deleted Successfully.\n");
}

void search_Student()

{

    FILE *fp=fopen("data.txt","r");
   // rewind(fp);

    if(fp == NULL)
    {
	printf("Invalid File");

    }
   

    struct student s;
    int id;
    int found=0;

    printf("Enter The Student ID :");
    scanf("%d",&id);


    while(fscanf(fp, "%d %s %s %s", &s.id, s.name, s.address, s.mob) != EOF)
    {
	if(id == s.id)
	{
	    printf("------------------------------------------------------------------\n");
	    printf("Student Present:\n");
	    printf("ID: %d\nName: %s\nAddress:%s\nMobile:%s\n",s.id,s.name,s.address,s.mob);
	    found=1;

	  //  fprintf(fp, "%d %s %s %s\n", s.id, s.name, s.address, s.mob);
	}
    }

    if(!found)
    {
	printf("Student Id %d is not present in the student record.\n",id);
    }

    fclose(fp);
    
  

}


void update()

{

    FILE *fp=fopen("data.txt","r");
   // rewind(fp);

    if(fp == NULL)
    {
	printf("Invalid File");

    }

    FILE *fp3=fopen("temp.txt","w");

    if(fp3 == NULL)
    {
	printf("Invalid File");
	fclose(fp);
	return;

    }
    struct student s;
    int id;

    printf("Enter The Student ID to Update:");
    scanf("%d",&id);
    getchar();


    while(fscanf(fp, "%d %s %s %s", &s.id, s.name, s.address, s.mob) != EOF)
    {
	if(id == s.id)
	{


	    printf("Enter your ID: ");
	    scanf("%d", &s.id);
	    getchar();

	    printf("Enter Your Name: ");
	    scanf("%[^\n]", s.name);
	    getchar();

	    printf("Enter your address: ");
	    scanf("%[^\n]", s.address);
	    getchar();

	    printf("Enter your Mobile Number: ");
	    scanf("%[^\n]", s.mob);
	    getchar();

            }
	    fprintf(fp3, "%d %s %s %s\n", s.id, s.name, s.address, s.mob);
	
    }

    fclose(fp);
    fclose(fp3);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    printf("Student Details Updated Successfully.\n");

}


int main()
{
    int i = 1;
    int opts;

    while(i)
    {
	printf("-------------------Menu-----------------------------------------------\n");
	printf("1. Add Student\n2. Display\n3. Delete\n4.SearchStudent.\n5.Update\n6.Exit\n");
	printf("Select one option from above Menu: ");
	scanf("%d", &opts);

	switch (opts)
	{
	    case 1:
		add_Student();
		break;

	    case 2:
		display();
		break;

	    case 3:
		delete_student();
		break;

	    case 4:search_Student();
		   break;

	    case 5:update();
		   break;

	    case 6:
		   exit(0);

	    default:
		   printf("Invalid Option. Please try again.\n");
	}

	printf("Do You Want To Continue? (1-Yes / 0-No): ");
	scanf("%d", &i);
    }

    return 0;
}





