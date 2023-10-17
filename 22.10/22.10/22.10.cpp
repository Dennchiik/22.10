#include <iostream>
#include <cstring>

int mystrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int StringToNumber(const char* str) {
    int result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

char* NumberToString(int number) {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", number);
    char* result = new char[strlen(buffer) + 1];
    strcpy(result, buffer);
    return result;
}

char* Uppercase(char* str) {
    char* ptr = str;
    while (*ptr) {
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = *ptr - ('a' - 'A');
        }
        ptr++;
    }
    return str;
}

char* Lowercase(char* str) {
    char* ptr = str;
    while (*ptr) {
        if (*ptr >= 'A' && *ptr <= 'Z') {
            *ptr = *ptr + ('a' - 'A');
        }
        ptr++;
    }
    return str;
}

char* mystrrev(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    return str;
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "World";

    int compareResult = mystrcmp(str1, str2);
    std::cout << "mystrcmp result: " << compareResult << std::endl;

    const char* numStr = "42";
    int number = StringToNumber(numStr);
    std::cout << "StringToNumber result: " << number << std::endl;

    int num = 12345;
    char* numStrResult = NumberToString(num);
    std::cout << "NumberToString result: " << numStrResult << std::endl;
    delete[] numStrResult;

    char text[] = "abcde";
    Uppercase(text);
    std::cout << "Uppercase result: " << text << std::endl;

    char text2[] = "ABCDE";
    Lowercase(text2);
    std::cout << "Lowercase result: " << text2 << std::endl;

    char text3[] = "reverse";
    mystrrev(text3);
    std::cout << "mystrrev result: " << text3 << std::endl;

    return 0;
}
