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
    count++;
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
    fprintf(fp, "%-10s\t%-20s\t%d\n", product[i].code, product[i].name, product[i].qty);
  }
  fclose(fp);
}

void displayInventory() {
  printf("\n%-15s %-20s %s\n", "Product Code", "Product Name", "Quantity");
  FILE *fp;
  fp = fopen("Inventory.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return;
  }
  char code[10], name[50];
  int qty;
  while (fscanf(fp, "%s %s %d", code, name, &qty) == 3) {
    printf("%-15s %-20s %d\n", code, name, qty);
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

  // Error handling for productSize input
  int productSize;
  printf("\nPlease enter how many products: ");
  while (scanf("%d", &productSize) != 1 || productSize <= 0) {
    printf("Invalid input. Please enter a positive number: ");
    while (getchar() != '\n');  // clear buffer
  }

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

      // Error handling for update code inside add loop
      do {
        printf("Update Code (A = Add Quantity / S = Subtract Quantity): ");
        scanf(" %c", &updateCode);
        if (updateCode != 'A' && updateCode != 'a' && updateCode != 'S' && updateCode != 's') {
          printf("Invalid input. Please enter A or S only.\n");
        }
      } while (updateCode != 'A' && updateCode != 'a' && updateCode != 'S' && updateCode != 's');

      // Error handling for quantity input
      printf("Quantity: ");
      while (scanf("%d", &updateQty) != 1 || updateQty <= 0) {
        printf("Invalid input. Please enter a positive number: ");
        while (getchar() != '\n');
      }

      if (updateCode == 'A' || updateCode == 'a') {
        product[existing].qty += updateQty;
      } else {
        product[existing].qty -= updateQty;
      }
    } else {
      printf("Product Name: ");
      scanf("%s", inputName);

      // Error handling for quantity input
      printf("Quantity: ");
      while (scanf("%d", &inputQty) != 1 || inputQty <= 0) {
        printf("Invalid input. Please enter a positive number: ");
        while (getchar() != '\n');
      }

      strcpy(product[existingProductSize].code, inputCode);
      strcpy(product[existingProductSize].name, inputName);
      product[existingProductSize].qty = inputQty;
      existingProductSize++;
    }
  }

  saveInventory(product, existingProductSize);
  printf("\nInventory saved to Inventory.txt\n");

  // Error handling for Y/N input
  char toUpdate;
  do {
    printf("\nDo you want to update the inventory? [Y/N]: ");
    scanf(" %c", &toUpdate);
    if (toUpdate != 'Y' && toUpdate != 'y' && toUpdate != 'N' && toUpdate != 'n') {
      printf("Invalid input. Please enter Y or N only.\n");
    }
  } while (toUpdate != 'Y' && toUpdate != 'y' && toUpdate != 'N' && toUpdate != 'n');

  if (toUpdate == 'N' || toUpdate == 'n') {
    displayInventory();
    return 0;
  } else {
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

      // Error handling for update code inside update loop
      do {
        printf("Update Code (A = Add Quantity / S = Subtract Quantity): ");
        scanf(" %c", &updateCode);
        if (updateCode != 'A' && updateCode != 'a' && updateCode != 'S' && updateCode != 's') {
          printf("Invalid input. Please enter A or S only.\n");
        }
      } while (updateCode != 'A' && updateCode != 'a' && updateCode != 'S' && updateCode != 's');

      // Error handling for quantity input
      printf("Quantity: ");
      while (scanf("%d", &updateQty) != 1 || updateQty <= 0) {
        printf("Invalid input. Please enter a positive number: ");
        while (getchar() != '\n');
      }

      if (updateCode == 'A' || updateCode == 'a') {
        product[sameIndex].qty += updateQty;
      } else {
        product[sameIndex].qty -= updateQty;
      }

      // Error handling for update more Y/N
      do {
        printf("Update more? [Y/N]: ");
        scanf(" %c", &toUpdate);
        if (toUpdate != 'Y' && toUpdate != 'y' && toUpdate != 'N' && toUpdate != 'n') {
          printf("Invalid input. Please enter Y or N only.\n");
        }
      } while (toUpdate != 'Y' && toUpdate != 'y' && toUpdate != 'N' && toUpdate != 'n');
    } while (toUpdate == 'Y' || toUpdate == 'y');
  }

  saveInventory(product, existingProductSize);
  printf("\nUpdated Inventory.txt\n");
  displayInventory();

  return 0;
}