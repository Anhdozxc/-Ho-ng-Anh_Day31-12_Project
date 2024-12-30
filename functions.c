#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "datatypes.h"

struct Book books[100];  
int bookCount = 0; 
// Hien thi Menu
void showMenu() {
    printf("==== Quan Li Thu Vien Sach ====\n");
    printf("========MENU========\n");
    printf("1. Hien thi danh sach sach\n");
    printf("2. Them sach moi\n");
    printf("3. Sua thong tin sach\n");
    printf("4. Xoa sach\n");
    printf("5. Cap nhat thong tin sach\n");
    printf("6. Tim kiem sach\n");
    printf("7. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}
// Quay lai menu chinh
void goBackToMenu() {
    printf("\nNhan phim bat ky de quay lai menu chinh...\n");
    getchar();
    getchar();
}
// Them sach moi
void addBook() {
    if (bookCount >= 100) {
        printf("Danh sach da day.\n");
        goBackToMenu();
        return;
    }
    printf("\n=====Them Sach Moi=====\n");
    struct Book newBook;
    newBook.id = bookCount + 1;
    printf("Moi ban nhap ten sach: ");
    getchar(); 
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';  
    printf("Nhap tac gia: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; 
    printf("Nhap nam xuat ban: ");
    scanf("%d", &newBook.year);

    printf("Nhap gia sach: ");
    scanf("%d", &newBook.price);

    books[bookCount] = newBook;
    bookCount++;

    printf("Ban da them sach thanh cong!\n");
    goBackToMenu();
    return;
}
// Hien thi danh sach sach

void displayBooks() {
    if (bookCount == 0) {
        printf("\nChua co sach nao trong danh sach.\n");
        goBackToMenu();
        return;
    }
    printf("\n====== Danh Sach Sach ======\n");
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    printf("| ID | %-28s | %-28s | %-10s | %-10s |\n", "Ten Sach", "Tac Gia", "Nam XB", "Gia");
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    for (int i = 0; i < bookCount; i++) {
        printf("| %-2d | %-28s | %-28s | %-10d | %-10d |\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].year,
               books[i].price);
    }
    printf("+----+------------------------------+------------------------------+------------+------------+\n");
    goBackToMenu();
    return;
}

void editBook() {
    int id;
    printf("\nNhap ID sach ban muon sua: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("\nThong tin sach hien tai:\n");
            printf("ID: %d\n", books[i].id);
            printf("Ten sach: %s\n", books[i].title);
            printf("Tac gia: %s\n", books[i].author);
            printf("Nam xuat ban: %d\n", books[i].year);
            printf("Gia: %d\n", books[i].price);
            printf("\nNhap thong tin moi:\n");
            printf("Moi ban nhap ten sach moi: ");
            getchar();
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0';
            printf("Nhap tac gia moi: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = '\0';
            printf("Nhap nam xuat ban moi: ");
            scanf("%d", &books[i].year);
            printf("Nhap gia sach moi: ");
            scanf("%d", &books[i].price);
            printf("\nBan da sua thong tin sach thanh cong!\n");
            goBackToMenu();
            return;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sach voi ID %d.\n", id);
        goBackToMenu();
        return;
    }
}
