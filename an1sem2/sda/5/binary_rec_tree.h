#ifndef REC_TREE
#define REC_TREE
typedef struct muzeu {
    char denumirea[100];
    char adresa[100];
    char telefonul[10];
    int numar_exponate;
    float pret_bilet;
} Muzeu;

typedef struct node {
    Muzeu data;
    struct node* left;
    struct node* right;
} Node;

void Menu();
void read_struct(Muzeu* curr);
void createNode(Node** root);
void showTreeRSD(Node* root);
void showTreeRDS(Node* root);
void showTreeSRD(Node* root);
void showTreeDRS(Node* root);
void showTreeSDR(Node* root);
void showTreeDSR(Node* root);
void searchTree(Node* root, char* target);
void modifyNode(Node* root);
int sizeTree(Node* root);
int heightTree(Node* root);
void freeTree(Node** root);

#endif