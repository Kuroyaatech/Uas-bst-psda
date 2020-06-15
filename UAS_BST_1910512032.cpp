#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

Node *tree_bst = NULL;

void tambah (Node **root, int datanew)
{
    if ((*root)==NULL)
       {
        Node *newnode;
        newnode = new Node;
        newnode->data=datanew;
        newnode->kiri=NULL;
        newnode->kanan=NULL;
        (*root) = newnode;
        (*root) -> kiri = NULL;
        (*root) -> kanan = NULL;
        printf("Data Behasil Ditambahkan!");
       }
    else if (datanew<(*root)->data)
              tambah(&(*root)->kiri,datanew);
    else if (datanew>(*root)->data)
        tambah(&(*root)->kanan,datanew);
    else if (datanew==(*root)->data)
        printf("Warning :	Data Sudah ada di Node!");
}

void preOrder(Node *root)
{
    if(root!=NULL)
    {
        if(root->data!=NULL)
        {
            printf("%d ",root->data);
        }
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
       if(root!=NULL)
       {
           inOrder(root->kiri);
           if(root->data!=NULL)
           {
               printf("%d ",root->data);
           }
           inOrder(root->kanan);
        }
}

void postOrder(Node *root)
{
       if(root!=NULL)
       {
         postOrder(root->kiri);
         postOrder(root->kanan);
         if(root->data!=NULL)
         {
            printf("%d ",root->data);
         }
       }
}

void search(Node **root, int cari)
{
    if((*root) == NULL)
    {
        printf("Warning :	Data tidak dapat ditemukan!");
    }
    else if(cari < (*root)->data)
        search(&(*root)->kiri,cari);
    else if(cari > (*root)->data)
        search(&(*root)->kanan,cari);
    else if(cari == (*root)->data)
        printf("Data ditemukan!");
}

int count(Node *root)
{
       if(root==NULL)
              return 0;
       else
              return count(root->kiri)+ count(root->kanan)+1;
}


int height(Node *root)
{
       if(root == NULL)
              return -1;
       else{
              int u = height(root->kiri);
        int v = height(root->kanan);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}


void hapus(Node **root, int del)
{
       Node *curr;
       Node *parent;
       curr = (*root);

       bool flag = false;
  
       while(curr != NULL)
       {
              if(curr->data == del)
              {
                     flag = true;
                      break;
                      
              }
              else
              {
                  parent = curr;
                  if(del>curr->data)
                     curr = curr->kanan;
                  else
                     curr = curr->kiri;
              }
       }

    if(!flag)
    {
        cout<<"Data tidak ditemukan. Penghapusan data dibatalkan."<<endl;
        return;
    }
       if(height(tree_bst) == 0)
       {
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     (*root) = NULL;
                    
                     return;
              }
       }
       else if(height(tree_bst) > 0)
       {
              
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     
                     if(parent->kiri == curr)
                     {
                           
                           parent->kiri = NULL;
                           delete curr;
                     }
                     else 
                     {
                           
                           parent->kanan = NULL;
                           delete curr;
                     }

                     return;
              }

              
              if((curr->kiri == NULL && curr->kanan != NULL)|| (curr->kiri != NULL && curr->kanan == NULL))
              {

                     if(curr->kiri == NULL && curr->kanan != NULL)
                     {
                           
                           if(parent->kiri == curr)
                           {
                              parent->kiri = curr->kanan;
                              delete curr;
                         }
                         else 
                         {
                              
                              parent->kanan = curr->kanan; 
                              delete curr;
                         }
                     }
                  else 
                  {
                           
                           if(parent->kiri == curr)
                           {
                                  parent->kiri = curr->kiri; 
                                  delete curr;
                           }
                           else 
                           {
                               parent->kanan = curr->kiri; 
                               delete curr;
                            }
                   }
                   return;
              }


              if (curr->kiri != NULL && curr->kanan != NULL)
              {
                     Node* bantu;
                     bantu = curr->kanan;

                     if((bantu->kiri == NULL) && (bantu->kanan == NULL))
                     {
                           curr = bantu;
                           delete bantu;
                           curr->kanan = NULL;
                     }
                     else
                     {
                           if((curr->kanan)->kiri != NULL)
                           {
                                  Node* bantu2;
                                  Node* bantu3;
                                  bantu3 = curr->kanan;         
                                  bantu2 = (curr->kanan)->kiri; 

                                  while(bantu2->kiri != NULL)
                                  {
                                         bantu3 = bantu2;
                                         bantu2 = bantu2->kiri;
                                  }
                                  
                                  curr->data = bantu2->data;
                                  delete bantu2;
                                  bantu3->kiri = NULL;
                        }
                        else 
                        {
                              Node* tmp;
                              tmp = curr->kanan;
                              curr->data = tmp->data;
                              curr->kanan = tmp->kanan;
                              delete tmp;
                        }

                     }
                     return;
              }
       }
}


int main()
{
    
    char pil;
    int del,cari;
    while (true)
    {
        system("cls"); 
        char data;
        printf("\t |PROGRAM BST|");
        printf("\n\t -------------");
        printf("\nMENU");
        printf("\n----\n");
        printf("[1] Tambah/Masukkan Data\n");
        printf("[2] Pre-Order\n");
        printf("[3] In-Order\n");
        printf("[4] Post-Order\n");
        printf("[5] Delete Data\n");
        printf("[6] Reset Tree\n");
        printf("[7] Search\n");
        printf("[8] Penghitungan Jumlah Node pada Tree\n");
        printf("[X] Keluar\n");
        printf("Pilih Menu : ");
        scanf("%c",&pil);
        fflush(stdin); 
        switch(pil)
        {
            
            case '1':
                     printf("\nINPUT : ");
                     printf("\n-------");
                     printf("\nMasukkan data: ");
                     scanf("%d", &data);
                     tambah(&tree_bst,data);
                     _getch();
                      break;

             
              case '2':
                     printf("\n In-Order : ");
                     printf("\n------------------\n");
                     if(tree_bst!=NULL)
                           inOrder(tree_bst);
                     else
                           printf("Warning :Tree masih Kosong!");
                    
                     _getch();
                     break;
                    
              case '3':
                     printf("\n Pre-Order : ");
                     printf("\n------------------\n");
                     if(tree_bst!=NULL)
                           preOrder(tree_bst);
                     else
                           printf("Warning :Tree masih Kosong!");
                    
                     _getch();
                     break;

              case '4':
                     printf("\n Post-Order : ");
                     printf("\n------------------\n");
                     if(tree_bst!=NULL)
                           postOrder(tree_bst);
                     else
                           printf("Warning :Tree masih Kosong!");

                     _getch();
                     break;
                  
              case '5':
                     if(tree_bst!=NULL)
                     { 
                           printf("\n\nMenghapus Node : ");
                           printf("\n------------------\n");
                           printf("Masukkan Node yang ingin dihapus: ");
                           scanf("%d", &del);
                        
                           hapus(&tree_bst, del);
                           printf("\n\nSetelah Node Dihapus : ");
                           printf("\n---------------------- ");
                           printf("\n In-Order	: ");
                           inOrder(tree_bst); 
                           printf("\n Pre-Order   : ");
                           preOrder(tree_bst); 
                           printf("\n Post-Order : ");
                           postOrder(tree_bst); 
                     }
                     else
                           printf("\n Warning : Tree masih kosong!");

                     _getch();
                     break;

              case '6':
                     tree_bst=NULL;
                     printf("\nWarning	: Pengosongan Semua Node!! ");
                     printf("\n------------------");
                     printf("\nTree sudah kosong!!");
                      
                     _getch();
                     break;

              case '7':
                     printf("\nOUTPUT -> Hanya untuk mengecek apakah data dimaksud terdapat dalam tree");
                     printf("\n------");
                     if(tree_bst!=NULL)
                     {
                           printf("\n\nPencarian Node");
                           printf("\n--------------");
                           printf("\nMasukkan data yang ingin dicari : ");
                           scanf("%d", &cari);
                           search(&tree_bst, cari);
                     }
                     else
                           printf("\n Warning :Tree masih kosong!");

                     _getch();
                     break;

              case '8':
                     printf("\n Jumlah Node di dalam Tree");
                     printf("\n-------------------------");
                     printf("\nJumlah Node :  %d", count(tree_bst));
                    
                     _getch();
                     break;
           
             
              case 'X'|'x':
                     exit(0);
                     break;
              }
       }
}
