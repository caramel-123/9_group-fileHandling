#include <stdio.h>
#include <string.h>

struct Product {
	char code[10];
	char name[50];
	int quantity;
};

void saveInventory(struct Product products[], int n) {
	FILE *fp = fopen("Inventory.txt", "a");
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%s\t%20s\t%20d\n", products[i].code, products[i].name, products[i].quantity);
	}
	fclose(fp);
}

void displayInventory() {
	printf("\nProduct Code\t\tProduct Name\t\tQuantity\n");
	FILE *fp;
	fp = fopen("Inventory.txt", "r");
	char code[10], name[50];
  int qty;
	while (fscanf(fp, "%s %s %d", code, name, &qty) != EOF) {
		printf("%s\t\t\t%s\t\t\t%d\n", code, name, qty);
	}
	fclose(fp);
}
int findProduct(struct Product products[], int n, char code[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(products[i].code, code) == 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	struct Product products[100];
	int n;
	char choice[5];

	printf("Please enter how many products: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("\nProduct Code: ");
		scanf(" %9s", products[i].code);
		printf("Product Name: ");
		scanf(" %49s", products[i].name);
		printf("Quantity: ");
		scanf("%d", &products[i].quantity);
	}

	saveInventory(products, n);
	printf("\nInventory saved to Inventory.txt\n");

	printf("\nInitial Inventory:\n");
	displayInventory();

	printf("\nDo you want to update the inventory? [Y/N]: ");
	scanf(" %s", choice);

	if (choice[0] == 'N' || choice[0] == 'n') {
		return 0;
	}

	do {
		char code[10];
		int index = -1;
		while (index == -1) {
			printf("\nProduct Code: ");
			scanf(" %9s", code);
			index = findProduct(products, n, code);
			if (index == -1) {
				printf("Record not found. Please enter again.\n");
			}
		}

		char updateCode[5];
		int qty;
		printf("Update Code (A = Add Quantity / S = Subtract Quantity): ");
		scanf(" %4s", updateCode);
		printf("Quantity: ");
		scanf("%d", &qty);

		if (updateCode[0] == 'A' || updateCode[0] == 'a') {
			products[index].quantity += qty;
		} else if (updateCode[0] == 'S' || updateCode[0] == 's') {
			products[index].quantity -= qty;
		} else {
			printf("Invalid update code.\n");
		}

		printf("Update more? [Y/N]: ");
		scanf(" %s", choice);

	} while (choice[0] == 'Y' || choice[0] == 'y');

	saveInventory(products, n);

	printf("\nUpdated Inventory.txt\n");
	displayInventory();

	return 0;
}