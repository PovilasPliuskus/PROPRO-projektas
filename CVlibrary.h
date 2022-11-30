#ifndef CVLIBRARY_H
#define CVLIBRARY_H

struct HeaderInfo {
    char *name;
    char *surname;
    char *email;
    unsigned char hasWebsite;
    char *website;
    char *mobileNumber;
    char *personalProfile;
    char *jobTitle;
};

struct WorkExperience {
    char *jobTitle;
    char *startingDate;
    char *leavingDate;
    char *experience;
};

struct Skill {
    char *givenSkill;
};

struct Education {
    char *institution;
    char *qualification;
    char *gpa;
    char *coursework;
};

typedef struct HeaderInfo HeaderInfo;
typedef struct WorkExperience WorkExperience;
typedef struct Skill Skill;
typedef struct Education Education;

void Intro();
FILE *InitFile();
char *GetStringOfData(char text[]);
unsigned char YesOrNoQuestion(char text[]);

#endif