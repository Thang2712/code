#include <stdio.h>

int laNamNhuan(int nam);
int soNgayTrongThang(int thang, int nam);
int kiemTraNgayThang(int ngay, int thang, int nam);

int main() 
{
    int ngay, thang, nam;

    printf("Nhap ngay: ");
    scanf("%d", &ngay);
    printf("Nhap thang: ");
    scanf("%d", &thang);
    printf("Nhap nam: ");
    scanf("%d", &nam);
    
    printf("\nKet qua kiem tra:\n");
    if (kiemTraNgayThang(ngay, thang, nam) == 1) {
        printf("%d/%d/%d la ngay thang hop le.\n", ngay, thang, nam);
    } else {
        printf("%d/%d/%d KHONG hop le.\n", ngay, thang, nam);
    }

    return 0;
}


int laNamNhuan(int nam) 
{
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}


int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31; 
        case 4:
        case 6:
        case 9:
        case 11:
            return 30; 
        case 2:
            return laNamNhuan(nam) ? 29 : 28;
        default:
            return 0; 
    }
}


int kiemTraNgayThang(int ngay, int thang, int nam) 
{
    if (nam <= 0) 
    {
        return 0; 
    }
    if (thang < 1 || thang > 12) 
    {
        return 0; 
    }
    
    if (ngay < 1) 
    {
        return 0; 
    }

    int maxNgay = soNgayTrongThang(thang, nam);
    if (ngay > maxNgay) 
    {
        return 0;
    }

    return 1; 
}

