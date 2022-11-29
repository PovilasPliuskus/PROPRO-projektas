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