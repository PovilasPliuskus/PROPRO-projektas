#include<stdio.h>
#include<stdlib.h>
#include"CVlibrary.h"

void Intro()
{
    printf("Program let's you to create your own CV\n");
}

FILE *InitFile()
{
    FILE *htmlFile;
    htmlFile = fopen("CVindex.html", "r+");

    fputs("<!DOCTYPE html>\n", htmlFile);
    fputs("<html>\n", htmlFile);
    fputs("\t<head>\n", htmlFile);
    fputs("\t\t<link rel=\"stylesheet\" href=\"styles.css\" />\n", htmlFile);
    fputs("\t</head>\n", htmlFile);
    fputs("\t<body>\n", htmlFile);
    fputs("\t\t<div class=\"header\">\n", htmlFile);
    fputs("\t\t\t<div class=\"left_header\">\n", htmlFile);

    return htmlFile;
}

char *GetStringOfData(char text[])
{
    printf("%s", text);

    int dataLength = 0;
    char *data = (char *)malloc(dataLength);
    char tempChar;

    tempChar = getchar();
    while (tempChar != '\n') {
        dataLength++;
        data = (char *)realloc(data, sizeof(char) * dataLength);
        *(data + dataLength - 1) = tempChar;
        tempChar = getchar();
    }

    data = (char *)realloc(data, (sizeof(char) * dataLength) + 1);
    *(data + dataLength) = '\0';

    return data;
}

unsigned char YesOrNoQuestion(char text[])
{
    printf("%s\n", text);
    printf("Enter y - if yes, n - if no [y/n]: ");

    char answer = getchar();
    while (getchar() != '\n') {
        answer = '?';
    }

    if (answer == 'y' || answer == 'Y') {
        return 1;
    }
    else if (answer == 'n' || answer == 'N') {
        return 0;
    }
    else {
        return YesOrNoQuestion("");
    }
}