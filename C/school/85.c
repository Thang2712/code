#include <stdio.h>
#include <string.h>
 
typedef struct
{
    char masach[20];
    char tensach[50];
    int soluong;
    char nxb[50];
    int namxb;
} dausach;

void nhapdausach(dausach ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nnhap thong tin sach thu %d:\n", i + 1);
        printf("nhap ma sach: ");
        fgets(ds[i].masach);
        printf("nhap ten sach: ");
        gets(ds[i].tensach);
        printf("nhap so luong: ");
        scanf("%d", &ds[i].soluong);
        fflush(stdin);
        printf("nhap nha xuat ban: ");
        gets(ds[i].nxb);
        printf("nhap nam xuat ban: ");
        scanf("%d", &ds[i].namxb);
        fflush(stdin);  
    }
}

void sapxep(dausach ds[], int n)
{
    dausach tg;
    int i, j; 
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp(ds[i].masach, ds[j].masach) > 0)
            {
                tg = ds[i];
                ds[i] = ds[j];
                ds[j] = tg;
            }
}

void indanhsach(dausach ds[], int n)
{
    printf("\n%-20s %-50s %-10s %-30s %-10s\n", "Ma sach", "Ten sach", "So luong", "Nha xuat ban", "Nam xb");
    for (int i = 0; i < n; i++)
        printf("%-20s %-50s %-10d %-30s %-10d\n", ds[i].masach, ds[i].tensach, ds[i].soluong, ds[i].nxb, ds[i].namxb);

}

int demkhacnxb(dausach ds[], int n, char x[])
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(ds[i].nxb, x) != 0)
            dem++;
    return dem;
}


int main()
{
    int n;
    dausach ds[100];
    char nxbyc[50];

    printf("nhap so luong dau sach: ");
    scanf("%d", &n);
    fflush(stdin);
    nhapdausach(ds, n); 
    sapxep(ds, n);

    printf("\ndanhsach sau khi sap xep theo ma sach:\n");
    indanhsach(ds, n);

    printf("\nnhap nha xuat ban can dem: ");
    gets(nxbyc);
    int ketqua = demkhacnxb(ds, n, nxbyc);
    printf("so luong dau sach khong thuoc nha xuat ban %s la: %d\n", nxbyc, ketqua);
    return 0;
    
}