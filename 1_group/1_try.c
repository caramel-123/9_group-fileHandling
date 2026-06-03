#include <stdio.h>

struct Product {
  char code[80];
  char name[80];
  int qty;
};

int main() {
  FILE *fp;
  fp = fopen("Inventory.txt", "a");



  int productSize;
  struct Product product;
  printf("Please enter how many products: ");
  scanf("%d", &productSize);
  printf("Product Code: ");
  scanf("%s", product.code);
  printf("Product Name: ");
  scanf("%s", product.name);
  printf("Quantity: ");
  scanf("%d", &product.qty);

  fprintf(fp, "\n%s\t%20s\t%20d\n", product.code, product.name, product.qty);

  printf("Do you want to update the inventory: ");

  fclose(fp);


  return 0;
}