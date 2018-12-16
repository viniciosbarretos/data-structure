#include "customer.h"
#include "file.h"
//#include "hashing.h"
#include <math.h>

Customer * newCostumer() {

    Customer *c = (Customer*) malloc(sizeof(Customer));
    printf("\nAcount Number:");
    scanf("%d ", &c->id);
    printf("\nName:");
    scanf("%s ", c->name);

    //Validating customer type.
    do {
        //clearScreen();
        //P: Person, O: Organization
        printf("\nType('P' or 'O'):");
        scanf("%c ", c->customerType);

        if(*(c->customerType) != 'P' && *(c->customerType) != 'p' && *(c->customerType) != 'O' && *(c->customerType) != 'o') {
            printf("\nWrong value.");
            getchar();
        }

    } while (*(c->customerType) != 'P' && *(c->customerType) != 'p' && *(c->customerType) != 'O' && *(c->customerType) != 'o');

    printf("\nOverbalance:");
    scanf("%f", &c->overbalance);

    return c;
}

void registerCustomer(int id) {
    Customer *c = newCostumer();

//    insertOnDir(dir, id, c);

    createFile(c->id, c->name, c->customerType, c->overbalance);
}

void removeCustomer(int id) {

    int cId = 0;
    printf ("\nType the Client Account Number");
    scanf ("%d", &cId);

//    int hash = calcHash(id, dir->globalDepth);
//    int pos = searchInBucket(dir->key[hash], cId);
//    int line = dir->key[hash]->items[pos].line;
//
//    removeFromDir(dir, id);
//    removeFileLine(line);
}

void searchCustomer(int id) {

}
