// Expand-Archive -Path sort.zip -DestinationPath . (use to unzip the zip's file)
// wget https://cdn.cs50.net/2024/fall/psets/3/sort.zip -OutFile sort.zip (use to install a file and put in a name of sort.zip)



// Function get_ string
char *get_string(const char *prompt)
{
    char buffer[1024];  // bộ đệm tạm
    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return NULL; // nếu nhập lỗi
    }

    // Xóa ký tự newline '\n' ở cuối (nếu có)
    buffer[strcspn(buffer, "\n")] = '\0';

    // Cấp phát bộ nhớ động để trả về chuỗi
    char *str = malloc(strlen(buffer) + 1);
    if (str == NULL)
    {
        return NULL; // hết bộ nhớ
    }
    strcpy(str, buffer);

    return str;
}


// Function get_int
int get_int(const char *prompt)
{
    int number;
    char buffer[100];

    while (true)
    {
        printf("%s", prompt);

        // Đọc input dạng chuỗi
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            // Chuyển chuỗi thành số nguyên
            char *endptr;
            number = strtol(buffer, &endptr, 10);

            // Nếu endptr trỏ tới '\n' => input hợp lệ
            if (*endptr == '\n' || *endptr == '\0')
            {
                return number;
            }
            else
            {
                printf("Invalid input. Please enter an integer.\n");
            }
        }
    }
}
