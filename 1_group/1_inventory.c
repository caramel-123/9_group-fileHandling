#include <stdio.h>
#include <string.h>

struct Product {
	char code[10];
	char name[50];
	int quantity;
};

int loadInventory(struct Product products[]) {
	FILE *fp = fopen("Inventory.txt", "r");
	if (fp == NULL) return 0;
	int count = 0;
	while (fscanf(fp, "%s %s %d", products[count].code, products[count].name, &products[count].quantity) == 3) {
		count++;
	}
	fclose(fp);
	return count;
}

void saveInventory(struct Product products[], int n) {
	FILE *fp = fopen("Inventory.txt", "w");
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
	if (fp == NULL) {
		printf("Error opening file.\n");
		return;
	}
	char code[10], name[50];
	int qty;
	while (fscanf(fp, "%s %s %d", code, name, &qty) == 3) {
		printf("%s\t\t\t\t%s\t\t\t%d\n", code, name, qty);
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
	char choice[5];

	int count = loadInventory(products);
	if (count > 0) {
		printf("\nLoaded %d existing product(s).\n", count);
		displayInventory();
	}

	int n;
	printf("\nPlease enter how many products to add: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char inputCode[10], inputName[50];
		int inputQty;

		printf("\nProduct Code: ");
		scanf(" %9s", inputCode);

		int existing = findProduct(products, count, inputCode);
		if (existing != -1) {
			char updateCode[5];
			int qty;
			printf("Product already exists. Update Code instead.\n");
			printf("Update Code (A = Add Quantity / S = Subtract Quantity): ");
			scanf(" %4s", updateCode);
			printf("Quantity: ");
			scanf("%d", &qty);

			if (updateCode[0] == 'A' || updateCode[0] == 'a') {
				products[existing].quantity += qty;  // fixed: was products[index]
			} else if (updateCode[0] == 'S' || updateCode[0] == 's') {
				products[existing].quantity -= qty;  // fixed: was products[index]
			} else {
				printf("Invalid update code.\n");
			}
		} else {
			printf("Product Name: ");
			scanf(" %49s", inputName);
			printf("Quantity: ");
			scanf("%d", &inputQty);

			strcpy(products[count].code, inputCode);
			strcpy(products[count].name, inputName);
			products[count].quantity = inputQty;
			count++;
		}
	}

	saveInventory(products, count);
	printf("\nInventory saved to Inventory.txt\n");

	printf("\nCurrent Inventory:\n");
	displayInventory();

	printf("\nDo you want to update the inventory? [Y/N]: ");
	scanf(" %s", choice);

	if (choice[0] == 'N' || choice[0] == 'n') {
		displayInventory();
		return 0;
	}

	do {
		char code[10];
		char updateCode[5];
		int qty;
		int index = -1;  // fixed: reset to -1 each iteration

		while (index == -1) {
			printf("\nProduct Code: ");
			scanf(" %9s", code);
			index = findProduct(products, count, code);
			if (index == -1) {
				printf("Record not found. Please enter again.\n");
			}
		}

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

	saveInventory(products, count);

	printf("\nUpdated Inventory.txt\n");
	displayInventory();

	return 0;
}