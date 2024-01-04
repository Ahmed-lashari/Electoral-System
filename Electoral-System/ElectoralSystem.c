#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>
#include "banner2.h"

void top_banner();
void bottom_banner();
void login_banner();
void invalid_login();
void success_login();
void signup_banner();
void success_signup();
void admin_banner();
void result_banner();
void audit_banner();
void voter_banner();
void age_banner();
void age_joke();
int Create_Account();
int caste_vote();

int CNIC_checker(const char *CNIC);
void save_info(char *Full_Name, char *Father_Name, int Age, char *Qualification, char *userid, char *Cnic);

int Login_Account();
int LOGIN(char *ENTERED_name, char *ENTERED_cnic);
void PARTIES_VOTING(char USERNAME[], char CNIC[]);

int Admin_Login();
void results();
void Audit_log();
void voters();

void EXIT_PROGRAM();

int main()
{
    // BEEP VOICE FUNCTION
    for (int x = 0; x < 2; x++)
    {
        Beep(5000, 100);
    }

    int select;
    top_banner();

    while (1)
    {
        printf("\n\n\t\t\t1. ACCOUNT SIGNUP\n");
        printf("\t\t\t2. ACCOUNT LOGIN\n");
        printf("\t\t\t3. ADMIN LOGIN\n\n");
        printf("\t\t\t0. EXIT PROGRAM\n\n");

        printf("SELECT OPTION: ");

        scanf("%d", &select);

        printf("\n");

        while (select != 0 && select != 1 && select != 2 && select != 3)
        {
            // BEEP VOICE FUNCTION
            // for (int x = 0; x < 3; x++)
            // {
            //     Beep(500, 700);
            //     Sleep(50);
            // }
            printf("\n\nPlease select from given options i.e., (0 to 3)\n\n");
            printf("SELECT OPTION: ");
            scanf("%d", &select);
            printf("\n");
        }

        switch (select)
        {
        case 1:
            Create_Account();
            break;

        case 2:
            Login_Account();
            break;

        case 3:
            Admin_Login();
            break;

        case 0:
            EXIT_PROGRAM();
            return 0;
        }
    }
    return 0;
}

int Login_Account()
{
    // BEEP VOICE FUNCTION
    for (int x = 0; x < 2; x++)
    {
        Beep(5000, 100);
    }

    login_banner();

    char ENTERED_Name[50];
    char ENTERED_username[50];
    char ENTERED_cnic[50];
    char ENTERED_password[50];

    printf("\n\nENTER YOUR USER-ID: ");
    scanf(" %[^\n]", ENTERED_username);

    printf("\nENTER YOUR CNIC: ");
    scanf(" %[^\n]", ENTERED_cnic);

    printf("\n\n");

    // capatalize the user name
    for (int i = 0; ENTERED_username[i] != '\0'; i++)
    {
        ENTERED_username[i] = toupper((unsigned char)ENTERED_username[i]);
    }

    // correct name and CNIC
    if (LOGIN(ENTERED_username, ENTERED_cnic)) // (1)
    {
        PARTIES_VOTING(ENTERED_username, ENTERED_cnic);
    }
    else
    {
        // incorrect name or CNIC
        invalid_login();
        printf("\t\t\t1. TRY AGAIN\n");
        printf("\t\t\t2. BACK\n\n");

        int invalid_access;
        // printf("SELECT YOUR CHOICE: ");
        // scanf("%d", &invalid_access);

        while (invalid_access != 1 && invalid_access != 2)
        {
            printf("\n\n\t\t\tPLEASE SELECT FROM THE GIVEN OPTIONS:\n\n");
            printf("SELECT YOUR CHOICE (1 and 2): ");
            scanf("%d", &invalid_access);
        }
        switch (invalid_access)
        {
        case 1:
            Login_Account(); // function recursion call
            break;

        case 2:
            return 0;
            break;
        }
    }

    return 0;
}

// comparing entered cnic with stored cnic
int LOGIN(char *ENTERED_username, char *ENTERED_cnic)
{
    FILE *Login_Pointer;
    Login_Pointer = fopen("Final_Project_Login_Data.txt", "r");

    char STORED_name[50];
    char STORED_cnic[50];

    if (Login_Pointer == NULL)
    {
        printf("((=====FILE NOT FOUND=====))\n");
    }
    else
    {
        while (fscanf(Login_Pointer, "%s %[^\n]", STORED_name, STORED_cnic) == 2)
        {
            if (((strcmp(STORED_name, ENTERED_username)) == 0) && ((strcmp(STORED_cnic, ENTERED_cnic)) == 0))
            {
                fclose(Login_Pointer);

                return 1; // means successful login (1)(any positive value)
            }
        }
    }
    fclose(Login_Pointer);
    return 0;
}

// after login process
void PARTIES_VOTING(char USERNAME[], char CNIC[])
{
    char STORED_username[100];
    char STORED_CNIC[50];
    char PARTY_NAME[100];

    FILE *VOTING_DATA;

    // creates the file for those voters who have casted their vote (only stores their CNIC)
    VOTING_DATA = fopen("Final_Project_Casted_Voters.txt", "r");

    bool hasVoted = false; // Variable to track voting status

    while ((fscanf(VOTING_DATA, "%s\n", STORED_CNIC)) == 1)
    {

        if (strcmp(STORED_CNIC, CNIC) == 0)
        {
            fclose(VOTING_DATA);
            hasVoted = true; // true = 1
            break;           // exit the loop as the vote has been found
        }
    }

    fclose(VOTING_DATA);

    if (hasVoted) // 1
    {
        printf("\nYou have already voted. Multiple voting is not allowed.\n");
        printf("ACCOUNT LOGGED OUT\n");
    }
    else
    {
        success_login();
        int VOTE_casting;

        caste_vote(USERNAME);

        printf("\t\t\t1. PAKISTANI DEMOCRATIC ARMY\n");
        printf("\t\t\t2. PAKISTANI CIVIL BUREAUCRACY\n");
        printf("\t\t\t3. PAKISTANI CORRUPT POLITICIANS\n");
        printf("\t\t\t4. AZAAD UMEED-WAR\n");
        printf("\n\t\t\t0. EXIT\n\n");

        printf("Select your political party: ");
        scanf("%d", &VOTE_casting);

        while (VOTE_casting < 0 || VOTE_casting > 4)
        {
            printf("\nError! Please select the given options i-e (0 to 4)\n");
            scanf("%d", &VOTE_casting);
        }

        // stores data of the votes in single file
        FILE *WHOLE_DATA = fopen("Final_Project_Electoral_Data.txt", "a");

        // stores data of the votes in seperate files,
        FILE *PARTY_A = fopen("Final_Project_PARTY_A.txt", "a");
        FILE *PARTY_B = fopen("Final_Project_PARTY_B.txt", "a");
        FILE *PARTY_C = fopen("Final_Project_PARTY_C.txt", "a");
        FILE *PARTY_D = fopen("Final_Project_PARTY_D.txt", "a");

        // creates the file for those voters who have casted their vote (only stores their CNIC)
        VOTING_DATA = fopen("Final_Project_Casted_Voters.txt", "a");

        if (WHOLE_DATA != NULL && VOTING_DATA != NULL)
        {
            switch (VOTE_casting)
            {
            case 1:
                if (PARTY_A != NULL)
                {
                    fprintf(PARTY_A, "RESPECTED CITIZEN: %s, having CNIC: %s, voted for: PAKISTANI DEMOCRATIC ARMY\n", USERNAME, CNIC);
                }
                fprintf(WHOLE_DATA, "RESPECTED CITIZEN: %s, having CNIC: %s, voted for: PAKISTANI DEMOCRATIC ARMY\n", USERNAME, CNIC);
                fprintf(VOTING_DATA, "%s\n", CNIC);

                break;
            case 2:
                if (PARTY_B != NULL)
                {
                    fprintf(PARTY_B, "RESPECTED CITIZEN: %s, having CNIC: %s, voted for: PAKISTANI CIVIL BUREAUCRACY\n", USERNAME, CNIC);
                }
                fprintf(WHOLE_DATA, "RESPECTED CITIZEN: %s, having CNIC: %s, voted for: PAKISTANI CIVIL BUREAUCRACY\n", USERNAME, CNIC);
                fprintf(VOTING_DATA, "%s\n", CNIC);

                break;
            case 3:
                if (PARTY_C != NULL)
                {
                    fprintf(PARTY_C, "RESPECTED CITIZEN: %s, having CNIC: %s, voted for: PAKISTANI CORRUPT POLITICIANS\n", USERNAME, CNIC);
                }

                fprintf(WHOLE_DATA, "RESPECTED CITIZEN: %s, having CNIC: %s, voted for: PAKISTANI CORRUPT POLITICIANS\n", USERNAME, CNIC);
                fprintf(VOTING_DATA, "%s\n", CNIC);

                break;
            case 4:
                if (PARTY_D != NULL)
                {
                    fprintf(PARTY_D, "RESPECTED CITIZEN: %s, having CNIC: %s, voted for: AZAAD UMEED-WAR\n", USERNAME, CNIC);
                }
                fprintf(WHOLE_DATA, "RESPECTED CITIZEN: %s, having CNIC: %s, voted for: AZAAD UMEED-WAR\n", USERNAME, CNIC);
                fprintf(VOTING_DATA, "%s\n", CNIC);

                break;
            }
            fclose(PARTY_A);
            fclose(PARTY_B);
            fclose(PARTY_C);
            fclose(PARTY_D);

            fclose(VOTING_DATA);
            fclose(WHOLE_DATA);

            printf("YOUR VOTE HAS BEEN RECORDED. THNAK YOU, %s!\n", USERNAME);
            printf("\n\nACCOUNT LOGGED OUT\n\n");
        }
    }
}

// account creation
int Create_Account()
{

    // BEEP VOICE FUNCTION
    for (int x = 0; x < 2; x++)
    {
        Beep(5000, 100);
    }
    signup_banner();

    char userid[50]; // it will bw saved as username
    char Cnic[50];   // it will be used as password

    char First_Name[50];
    char Last_Name[50];
    char Father_Name[50];
    int Age;
    char Qualification[200];

    printf("\n\t\t\tENTER FIRST NAME: ");
    scanf(" %[^\n]", First_Name);

    printf("\n\t\t\tENTER LAST NAME: ");
    scanf(" %[^\n]", Last_Name);

    printf("\n\t\t\tENTER YOUR FATHER FULL NAME: ");
    scanf(" %[^\n]", Father_Name);

    printf("\n\t\t\tENTER YOUR AGE: ");
    scanf("%d", &Age);

    if (Age < 18)
    {

        age_banner();
        return 0;
    }
    else if (Age > 120)
    {
        age_joke();
        return 0;
    }

    else
    {
        printf("\n\t\t\tENTER YOUR QUALIFICATION: ");
        scanf(" %[^\n]", Qualification);

        printf("\n\t\t\tINPUT USERNAME, (with-no-spaces): ");
        scanf(" %[^\n]", userid);

        printf("\n\t\t\tENTER YOUR CNIC: ");
        scanf(" %[^\n]", Cnic);

        // checks for samilar existing CNIC in the file
        while (CNIC_checker(Cnic)) // expecting 1 (to become true)
        {
            // BEEP VOICE FUNCTION
            // for (int x = 0; x < 3; x++)
            // {
            //     Beep(300, 100);
            // }
            printf("This CNIC already exists!\n\n");
            printf("1. Try different cnic?\n");
            printf("0. Exit\n");

            int option;
            printf("SELECT OPTION: ");
            scanf("%d", &option);

            while (option < 0 || option > 1)
            {
                printf("INVALID OPTION! Please select either 0 or 1.\n\n");
                printf("SELECT OPTION (0 or 1): ");
                scanf("%d", &option);
            }

            switch (option)
            {
            case 0:
                return 0;
                break;

            case 1:
                printf("\t\t\tENTER YOUR CNIC: ");
                scanf(" %[^\n]", Cnic);
                break;
            }
        }

        printf("\n");

        strcat(First_Name, " ");
        strcat(First_Name, Last_Name);

        // capatalize user name
        for (int i = 0; First_Name[i] != '\0'; i++)
        {
            First_Name[i] = toupper((unsigned char)First_Name[i]);
        }

        // capatalize user ID
        for (int i = 0; userid[i] != '\0'; i++)
        {
            userid[i] = toupper((unsigned char)userid[i]);
        }

        save_info(First_Name, Father_Name, Age, Qualification, userid, Cnic);

        success_signup();
    }
    return 0;
}

// checks the cnics in file
int CNIC_checker(const char *CNIC)
{
    FILE *CNIC_FILE_ptr;
    CNIC_FILE_ptr = fopen("Final_Project_Login_Data.txt", "r");

    char STORED_username[50];
    char STORED_Cnic[50];

    if (CNIC_FILE_ptr != NULL)
    {
        while (fscanf(CNIC_FILE_ptr, "%s\t%[^\n]", STORED_username, STORED_Cnic) == 2)
        {
            if (strcmp(STORED_Cnic, CNIC) == 0)
            {
                fclose(CNIC_FILE_ptr);
                return 1; // cnic exists (ASCcI COMPARISON)
            }
        }
    }
    fclose(CNIC_FILE_ptr);
    return 0; // cnic does not exists (ASCcI COMPARISON)
}

// save the provided user details in file
void save_info(char *Full_Name, char *Father_Name, int Age, char *Qualification, char *userid, char *Cnic)
{

    FILE *VOTERS_DATA;
    // stores the complete information of user in the file
    VOTERS_DATA = fopen("Final_Project_Data_Storing.txt", "a");
    fprintf(VOTERS_DATA, "NAME = %s || Father name = %s || Age = %d || Qualification = %s || User_ID = %s || CNIC = %s\n", Full_Name, Father_Name, Age, Qualification, userid, Cnic);
    fclose(VOTERS_DATA);

    // stores the login info of users in a seperate file
    VOTERS_DATA = fopen("Final_Project_Login_Data.txt", "a");
    fprintf(VOTERS_DATA, "%s\t%s\n", userid, Cnic);
    fclose(VOTERS_DATA);
}

// admin login
int Admin_Login()
{
    // BEEP VOICE FUNCTION
    for (int x = 0; x < 2; x++)
    {
        Beep(5000, 100);
    }

    admin_banner();

    char username[50]; // default ADMIN USERNAME
    char cnic[50];     // default ADMIN cnic

    printf("ENTER ADMIN USERNAME: ");
    scanf("%s", username);

    for (int i = 0; username[i] != '\0'; i++)
    {
        username[i] = toupper((unsigned char)username[i]);
    }

    printf("ENTER ADMIN CNIC: ");
    scanf("%s", cnic);

    for (int i = 0; username[i] != '\0'; i++)
    {
        username[i] = toupper((unsigned char)username[i]);
    }

    FILE *Admin = fopen("admin_data.txt", "w");
    fprintf(Admin, "ADMIN 123", stdin);
    fclose(Admin);

    Admin = fopen("admin_data.txt", "r");
    if (Admin == NULL)
    {
        printf("NO DATA STORED\n");
        return 0;
    }

    char fileusername[50];
    char fileCNIC[50];
    bool Valid = false;

    while (fscanf(Admin, "%s %s", fileusername, fileCNIC) == 2)
    {
        if (strcmp(username, fileusername) == 0 && strcmp(cnic, fileCNIC) == 0)
        {
            Valid = true; // 1
            fclose(Admin);
            break;
        }
    }

    if (Valid) // 1
    {
        int adminOption;
        do
        {

            printf("\t\t\t1. VOTING RESULTS\n");
            printf("\t\t\t2. AUDIT LOG\n");
            printf("\t\t\t3. VOTERS DETAILS\n");
            printf("\t\t\t0. Exit Admin Panel\n");

            printf("SELECT OPTION: ");
            scanf("%d", &adminOption);

            while (adminOption < 0 || adminOption > 3)
            {
                printf("========Invalid Option Selected========\nPlease select from given options, (0-3): ");
                scanf("%d", &adminOption);
            }

            switch (adminOption)
            {
            case 1:
                results();
                break;

            case 2:
                Audit_log();
                break;

            case 3:
                voters();
                break;

            case 0:
                return 0;
            }
        } while (adminOption < 0 || adminOption > 3);
    }
    else
    {
        printf("Invalid Admin Username or Password. Please try again.\n");
        return 0;
    }
}

void results()
{

    int partychoice;

    result_banner();

    // printf("\n\t\t\tVIEW VOTING RESULTS\n");
    printf("\t\t\t1. PARTY A\n");
    printf("\t\t\t2. PARTY B\n");
    printf("\t\t\t3. PARTY C\n");
    printf("\t\t\t4. PARTY D\n");
    printf("\t\t\t0. Back to Main Menu\n");

    printf("\nSelect the party whose results you want to view (1-4): ");
    scanf("%d", &partychoice);

    FILE *partyFile;
    int voteCount = 0;
    char line[100];
    switch (partychoice)
    {
    case 1:
        partyFile = fopen("PARTY_A.txt", "r");
        printf("\n\n________________________");
        printf("\nPARTY A:\n\n");

        while (fgets(line, sizeof(line), partyFile) != NULL)
        {
            printf("%s\n", line);
            voteCount++;
        }
        printf("\n________________________\n\n");
        break;

    case 2:
        partyFile = fopen("PARTY_B.txt", "r");
        printf("\n\n________________________");
        printf("\nPARTY_B:\n\n");

        while (fgets(line, sizeof(line), partyFile) != NULL)
        {
            printf("%s\n", line);
            voteCount++;
        }
        printf("\n\n________________________\n\n");
        break;

    case 3:
        partyFile = fopen("PARTY_C.txt", "r");
        printf("\n\n________________________");
        printf("\nPARTY C:\n\n");

        while (fgets(line, sizeof(line), partyFile) != NULL)
        {
            printf("%s\n", line);
            voteCount++;
        }
        printf("\n\n________________________\n\n");

        break;

    case 4:
        partyFile = fopen("PARTY_D.txt", "r");
        printf("\n\n________________________");
        printf("\nPARTY D:\n\n");

        while (fgets(line, sizeof(line), partyFile) != NULL)
        {
            printf("%s\n", line);
            voteCount++;
        }
        printf("\n\n________________________\n\n");

        break;

    case 0:
        printf("Returning to Main Menu...\n");
        return;

    default:
        printf("Invalid choice. Please select from the given options.\n");
        return;
    }

    if (partyFile == NULL)
    {
        printf("NO STORED DATA FOUND\n");
        return;
    }

    printf("Total Votes: %d\n", voteCount);
    voteCount = 0;

    fclose(partyFile);
}

void Audit_log()
{

    FILE *dataFile = fopen("Final_Project_Electoral_Data.txt", "r");
    char line[200];
    if (dataFile == NULL)
    {
        printf("ERROR: Could not open data file.\n");
        return;
    }

    audit_banner();
    // printf("\n\t\t\tAUDIT LOG\n");

    while (fgets(line, sizeof(line), dataFile) != NULL)
    {
        printf("%s\n", line);
    }
    fclose(dataFile);
}

void voters()
{
    FILE *VOTERS_DATA = fopen("Final_Project_Data_Storing.txt", "r");

    if (VOTERS_DATA == NULL)
    {
        printf("ERROR: Could not open data file.\n");
        return;
    }

    voter_banner();

    // printf("\n\t\t\tVOTERS DATA\n");
    char line[200];

    while (fgets(line, sizeof(line), VOTERS_DATA) != NULL)
    {
        printf("%s\n", line);
    }
    fclose(VOTERS_DATA);
}

// program ends
void EXIT_PROGRAM()
{

    bottom_banner();

    // BEEP VOICE FUNCTION
    // for (int x = 0; x < 3; x++)
    // {
    //     Beep(500, 50);
    // }
}
