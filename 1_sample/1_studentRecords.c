#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char studentNumber[20];
	char studentName[50];
	char subject[50];
	float midGrade;
	float finalGrade;
	float average;
	int deleted;
} Student;

void loadRecords(Student records[], int *count) {
	*count = 0;
	FILE *fp = fopen("grades.txt", "r");
	if (fp == NULL) return;

	while (fscanf(fp, "%19s %49s %49s %f %f %f %d\n",
		records[*count].studentNumber,
		records[*count].studentName,
		records[*count].subject,
		&records[*count].midGrade,
		&records[*count].finalGrade,
		&records[*count].average,
		&records[*count].deleted) == 7) {
		(*count)++;
	}
	fclose(fp);
}

void saveRecords(Student records[], int count) {
	FILE *fp = fopen("grades.txt", "w");
	if (fp == NULL) {
		printf("Error: Could not save records.\n");
		return;
	}
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s %s %.2f %.2f %.2f %d\n",
			records[i].studentNumber,
			records[i].studentName,
			records[i].subject,
			records[i].midGrade,
			records[i].finalGrade,
			records[i].average,
			records[i].deleted);
	}
	fclose(fp);
}

void printRecord(Student s) {
	printf("%-10s %-15s %-12s %.2f        %.2f        %.2f\n",
		s.studentNumber,
		s.studentName,
		s.subject,
		s.midGrade,
		s.finalGrade,
		s.average);
}

void addStudent(Student records[], int *count) {
	Student s;
	s.deleted = 0;

	printf("\nAdd New Student\n");
	printf("Student Number: ");
	scanf(" %19s", s.studentNumber);
	printf("Student Name  : ");
	scanf(" %49s", s.studentName);
	printf("Subject       : ");
	scanf(" %49s", s.subject);
	printf("MidGrade      : ");
	scanf("%f", &s.midGrade);
	printf("FinalGrade    : ");
	scanf("%f", &s.finalGrade);

	s.average = (s.midGrade + s.finalGrade) / 2.0;

	records[*count] = s;
	(*count)++;

	saveRecords(records, *count);
	printf("Record added successfully.\n");
}

void editStudent(Student records[], int count) {
	char studNum[20], subject[50];

	printf("\nSearch and Edit Student Information:\n");
	printf("Student Number: ");
	scanf(" %19s", studNum);
	printf("Subject       : ");
	scanf(" %49s", subject);

	int found = -1;
	for (int i = 0; i < count; i++) {
		if (strcmp(records[i].studentNumber, studNum) == 0 &&
			strcmp(records[i].subject, subject) == 0 &&
			records[i].deleted == 0) {
			found = i;
			break;
		}
	}

	if (found == -1) {
		printf("Record not found!\n");
		return;
	}

	printf("\n");
	printRecord(records[found]);

	printf("\nInput new Student information\n");
	printf("MidGrade  : ");
	scanf("%f", &records[found].midGrade);
	printf("FinalGrade: ");
	scanf("%f", &records[found].finalGrade);

	records[found].average = (records[found].midGrade + records[found].finalGrade) / 2.0;

	saveRecords(records, count);
	printf("Record updated successfully.\n");
}

void deleteStudent(Student records[], int count) {
	char studNum[20], subject[50];

	printf("\nSearch and Delete Student Information\n");
	printf("Student Number: ");
	scanf(" %19s", studNum);
	printf("Subject       : ");
	scanf(" %49s", subject);

	int found = -1;
	for (int i = 0; i < count; i++) {
		if (strcmp(records[i].studentNumber, studNum) == 0 &&
			strcmp(records[i].subject, subject) == 0 &&
			records[i].deleted == 0) {
			found = i;
			break;
		}
	}

	if (found == -1) {
		printf("Record not found!\n");
		return;
	}

	printf("\n");
	printRecord(records[found]);

	char confirm[5];
	printf("\nDo you want to delete [yes/no]? ");
	scanf(" %4s", confirm);

	if (strcmp(confirm, "yes") == 0) {
		records[found].deleted = 1;
		saveRecords(records, count);
		printf("Record deleted.\n");
	} else {
		printf("Delete cancelled.\n");
	}
}

void viewAllRecords(Student records[], int count) {
	printf("\nView all records:\n\n");

	int hasRecord = 0;
	for (int i = 0; i < count; i++) {
		if (records[i].deleted == 0) {
			printRecord(records[i]);
		} else {
			printf("%-10s %-15s %-12s %.1f        %.1f        %.1f\t[Deleted Record]\n",
				records[i].studentNumber,
				records[i].studentName,
				records[i].subject,
				records[i].midGrade,
				records[i].finalGrade,
				records[i].average);
		}
		hasRecord = 1;
	}

	if (!hasRecord) {
		printf("No records found.\n");
	}
}

int main() {
	Student records[100];
	int count = 0;
	char choice;

	FILE *fp = fopen("grades.txt", "a");
	if (fp) fclose(fp);

	loadRecords(records, &count);

	do {
		printf("\n[A]dd\n");
		printf("[E]dit\n");
		printf("[D]elete\n");
		printf("[V]iew\n");
		printf("E[X]it\n");
		printf("Please select: ");
		scanf(" %c", &choice);

		if (choice >= 'a' && choice <= 'z') choice -= 32;

		switch (choice) {
			case 'A':
				addStudent(records, &count);
				break;
			case 'E':
				editStudent(records, count);
				break;
			case 'D':
				deleteStudent(records, count);
				break;
			case 'V':
				viewAllRecords(records, count);
				break;
			case 'X':
				printf("Exiting program...\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}

	} while (choice != 'X');

	return 0;
}