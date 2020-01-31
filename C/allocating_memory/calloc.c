#include <stdio.h>
#include <stdlib.h>

// ptr = (castType*)calloc(n, size);
 
int main()
{
    int n, i, *ptr, sum = 0;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
 
    // Nếu không thể cấp phát, 
    // hàm calloc sẽ trả về con trỏ NULL
    if (ptr == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }
    printf("Nhap cac gia tri: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Tong = %d", sum);
 
    // Giải phóng vùng nhớ cho con trỏ
    free(ptr);
    return 0;
}