#include<stdio.h>
#include<stdlib.h>
#include"CVlibrary.h"

int main()
{
    HeaderInfo headerInfo;

    Intro();
    headerInfo.name = GetStringOfData("Enter your name: ");
    headerInfo.surname = GetStringOfData("Enter your surname: ");
    headerInfo.jobTitle = GetStringOfData("Enter the job title: ");
    headerInfo.email = GetStringOfData("Enter your email: ");
    headerInfo.mobileNumber = GetStringOfData("Enter your phone number: ");
    headerInfo.hasWebsite = YesOrNoQuestion("Do you have a website?\n");

    if (headerInfo.hasWebsite) {
        headerInfo.website = GetStringOfData("Enter your website: ");
    }

    headerInfo.personalProfile = GetStringOfData("Write a bit about yourself (your personal profile): ");

    unsigned char hasWorkExperience = 0;
    int jobs = 0;
    WorkExperience *workExperience = (WorkExperience *)malloc(0);

    hasWorkExperience = YesOrNoQuestion("Do you have any work experience?\n");

    if (hasWorkExperience) {        
        do {
            jobs++;
            workExperience = (WorkExperience *)realloc(workExperience, jobs * sizeof(WorkExperience));
            (workExperience + jobs - 1)->jobTitle = GetStringOfData("Enter job title: ");
            (workExperience + jobs - 1)->startingDate = GetStringOfData("Enter the year you began to work there: ");
            (workExperience + jobs - 1)->leavingDate = GetStringOfData("Enter the year you stopped working there (or 'present', if you are still working): ");
            (workExperience + jobs - 1)->experience = GetStringOfData("Write a couple of sentences on what you were responsible for in the workplace: ");
        } while (YesOrNoQuestion("Do you have any more work experience?\n"));
    }

    unsigned char wantsToListSkills = 0;
    int numberOfSkills = 0;
    Skill *skill = (Skill *)malloc(0);

    wantsToListSkills = YesOrNoQuestion("Would you like to list some relevant skills?\n");

    if (wantsToListSkills) {
        do {
            numberOfSkills++;
            skill = (Skill *)realloc(skill, numberOfSkills * sizeof(Skill));
            (skill + numberOfSkills - 1)->givenSkill = GetStringOfData("Enter your skill: ");
        } while (YesOrNoQuestion("Add one more?\n"));
    }

    int degrees = 0;
    Education *education = (Education *)malloc(0);

    do {
        degrees++;
        education = (Education *)realloc(education, sizeof(Education) * degrees);
        (education + degrees - 1)->institution = GetStringOfData("What learning institution have you finished?: ");
        (education + degrees - 1)->qualification = GetStringOfData("What did you major in?: ");
        (education + degrees - 1)->gpa = GetStringOfData("What was your GPA?: ");
        (education + degrees - 1)->coursework = GetStringOfData("Enter some relevant coursework that you did: ");
    } while (YesOrNoQuestion("Add another education institution?\n"));

}