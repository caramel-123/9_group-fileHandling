#include <stdio.h>
#include <string.h>
struct Product {
  char code[80];
  char name[80];
  int qty;
};

int loadInventory(struct Product product[]) {
  FILE *fp;
  fp = fopen("Inventory.txt", "r");
  if (fp == NULL) {
    return 0;
  }
  int count = 0;
  while (fscanf(fp, "%s %s %d", product[count].code, product[count].name, &product[count].qty) == 3) {
    count++; //2
  }
  fclose(fp);
  return count;
}

void saveInventory(struct Product product[], int existingProductSize) {
  FILE *fp;
  fp = fopen("Inventory.txt", "w");

  if (fp == NULL) {
    printf("Error opening file.\n");
    return;
  }
  for (int i=0; i<existingProductSize; i++) {
    fprintf(fp, "%s\t%s\t%d\n", product[i].code, product[i].name, product[i].qty);
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
		printf("%s\t\t\t%s\t\t\t%d\n", code, name, qty);
	}
	fclose(fp);
}

int findProduct(struct Product product[], int productSize, char searchCode[]) {
  for (int i=0; i<productSize; i++) {
    if (strcmp(product[i].code, searchCode) == 0) {
      return i;
    } 
  }
  return -1;
}
int main() {
  struct Product product[100];

  int existingProductSize = loadInventory(product);
  if (existingProductSize > 0) {
    printf("\nLoaded %d existing product(s).\n", existingProductSize);
    displayInventory();
  }

  int productSize;
  printf("\nPlease enter how many products: ");
  scanf("%d", &productSize);

  char updateCode;
  int updateQty;

  for (int i=0; i<productSize; i++) {
    char inputCode[80];
    char inputName[80];
    int inputQty;

    printf("\nProduct Code: ");
    scanf("%s", inputCode);

    int existing = findProduct(product, existingProductSize, inputCode);
    if (existing != -1) {
      printf("Product already exists. Update Code instead.\n");
      printf("Update Code (A = Add Quantity / S = Subtract Quantity): ");
      scanf(" %c", &updateCode);
      printf("Quantity: ");
      scanf("%d", &updateQty);

      if (updateCode == 'A' || updateCode == 'a') {
        product[existing].qty += updateQty;
      } else if (updateCode == 'S' || updateCode == 's') {
        product[existing].qty -= updateQty;
      } else {
        printf("Invalid update code.\n");
      }
    } else {
      printf("Product Name: ");
      scanf("%s", inputName);
      printf("Quantity: ");
      scanf("%d", &inputQty);

      strcpy(product[existingProductSize].code, inputCode);
      strcpy(product[existingProductSize].name, inputName);
      product[existingProductSize].qty = inputQty;
      existingProductSize++;
    }
  }

  saveInventory(product, existingProductSize);
  printf("\nInventory saved to Inventory.txt\n");
  
  char toUpdate;
  printf("\nDo you want to update the inventory? [Y/N]: ");
  scanf(" %c", &toUpdate);
  if (toUpdate == 'N' || toUpdate == 'n') {
    displayInventory();
    return 0;
  }
  do {
    
    char searchCode[80];
    int sameIndex = -1;
    
    while (sameIndex == -1) {
      printf("Product Code: ");
      scanf("%s", searchCode);
      sameIndex = findProduct(product, existingProductSize, searchCode);
      if (sameIndex == -1) {
        printf("Record Not Found. Please enter again.\n");
      }
    } 
    
    printf("Update Code (A = Add Quantity / S = Subtract Quantity): ");
    scanf(" %c", &updateCode);
    printf("Quantity: ");
    scanf("%d", &updateQty);
    if (updateCode == 'A' || updateCode == 'a') {
      product[sameIndex].qty += updateQty;
    } else if (updateCode == 'S' || updateCode == 's') {
      product[sameIndex].qty -= updateQty;
    } else {
      printf("Invalid update code.\n");
    }
    printf("Update more? [Y/N]: ");
    scanf(" %c", &toUpdate);
    
  } while (toUpdate == 'Y' || toUpdate == 'y');
  
  saveInventory(product, existingProductSize);

  printf("\nUpdated Inventory.txt\n");
  displayInventory();

  return 0;
}
