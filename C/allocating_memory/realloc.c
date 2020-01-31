#include <stdio.h>
#include <stdlib.h>

// ptr = (castType*) realloc(ptr, size);
// cái này dùng để phân bổ lại bộ nhớ, thu hẹp hay dài thêm về phía sau

int main()
{
    int *ptr, i , n1, n2;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n1);
    ptr = (int*) malloc(n1 * sizeof(int));
    printf("Dia chi cua vung nho vua cap phat: %u", ptr);
    
    printf("\nNhap lai so luong phan tu: ");
    scanf("%d", &n2);
    // phân bổ lại vùng nhớ
    ptr = (int*) realloc(ptr, n2 * sizeof(int)); // có cấu trúc giốgn malloc
    printf("Dia chi cua vung nho duoc cap phat lai: %u", ptr); // địa chỉ trước và sau như nhau vì kích thước thu nhỏ lại hoặc dài thêm về phía sau
    // giải phóng
    free(ptr);
    return 0;
}