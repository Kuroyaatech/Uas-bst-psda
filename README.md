# Uas-bst-psda
Dibuat dalam Bahasa Indonesia untuk memudahkan membaca.

## Marimas lihat lebih dekat ke layar anda daripada melihat sesatu yang tidak bisa anda dapatkan!

### Yang pasti dibutuhkan!
Untuk Menjalankan File ini, anda hanya perlu mengunduh file "UAS_BST.exe" saja.
Jika Ingin Mengedit code yang ada, gunakan program-program dibawah ini teman!
```
- DEV C++
- Sublime Text 3
- Notepad++
```

## Menjalankan tests

Untuk menjalankan programanya hanya perlu mengunduh UAS_BST.exe yang ada
```
Disclaimer, karena extensionnya adalah .exe maka pengguna IOS selain OS dapat membukanya
dengan membukanya lewat IDE yang dipunya, dan dijalankan secara manual terlebih dahulu
```

### Hasil Test dan fitur dari program ini

Program ini saya namai Kono Dicky no BST DA!, seperti namanya
program ini akan membantu anda dalam:

```
- Memvisualisasikan BST pastinya!!
- Mengurutkan BST secara in-order, pre-order dan post-order dengan cepat seperti ZAWARUDOO!!!
```

Berikut beberapa code dan fitur yang ada

- *Fungsi Insert*
```
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
        printf("Data Ditambahkan!");
       }
    else if (datanew<(*root)->data)
              tambah(&(*root)->kiri,datanew);
    else if (datanew>(*root)->data)
        tambah(&(*root)->kanan,datanew);
    else if (datanew==(*root)->data)
        printf("Warning :	Data Sudah ada di Node!");
}
```

- *Fungsi In Order*
```
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
```

- *Fungsi Pre Order*
```
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

```

- *Fungsi Post Order*
```
 postOrder(Node *root)
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
```

*Disclaimer
```
Akan ada error jika dibuka dengan IDE yang berbeda seperti ROAD ROLLER!!
```

## Dibuat Menggunakan

* Sublime Text(https://www.sublimetext.com/) - Pembuatan .exe
* DEV C++(https://sourceforge.net/projects/orwelldevcpp/) - IDE Utama


## Authors
* **Dicky Darmawan - (1910512032)** 

## Lisensi
Projek ini sifatnya open source yang berarti kawand2 bisa menjadi KONO DIO DAAA!!! Dengan mudah.

## Terima Kasih Kepada
* Inspiration (Bapak DR. Achmad Solichin)
