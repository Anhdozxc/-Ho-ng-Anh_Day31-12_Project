
#include <stdio.h>
#include "functions.h"
#include "datatypes.h"

int main() {
    int choice;
    while (1) {
        showMenu();  // Hien thi menu
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks(); // Hien thi danh sach sach
                break;
            case 2:
                addBook(); // Them sach moi
                break;
            case 3:
        		editBook(); // Sua thong tin sach
                break;
            case 4:
                // Xoa sach
                break;
            case 5:
                // Cap nhat thong tin sach
                break;
            case 6:
                // Tim kiem sach
                break;
            case 7:
                printf("\nCam on ban da su dung chuong trinh cua minh!\n");
                return 0;  // Thoat
            default:
                printf("\nLua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}
