void top_banner()
{
	printf("  \t#################################################################\n");
    printf("  \t#\t\t\t\t\t\t\t\t#\n");
    printf("  \t#          WELCOME TO THE PAKISTAN ONLINE VOTING BOOTH          #\n");
    printf("  \t#\t\t\t\t\t\t\t\t#\n");
    printf("  \t#################################################################\n\n");
}

void bottom_banner()
{
	 printf("  \t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("  \t|                                                                           |\n");
    printf("  \t|              Thanks for using PAKISTAN ONLINE VOTING BOOTH   :)           |\n");
    printf("  \t|                                                                           |\n");
    printf("  \t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n\n\n");
}

void login_banner()
{
	printf("  \t\t###############################\n");
    printf("  \t\t|                             |\n");
    printf("  \t\t|        LOGIN PANEL          |\n");
    printf("  \t\t|                             |\n");
    printf("  \t\t###############################\n");
}

void invalid_login()
{
	printf("  \t##################################################\n");
        printf("  \t|                                                |\n");
        printf("  \t|            Invalid username or CNIC!           |\n");
        printf("  \t|                                                |\n");
        printf("  \t##################################################\n\n\n");
}

void success_login()
{
	 printf("  \t#############################################################################\n");
        printf("  \t|                                                                           |\n");
        printf("  \t|                YOUR ACCOUNT HAS BEEN SUCCESSFULLY LOGGED IN               |\n");
        printf("  \t|                                                                           |\n");
        printf("  \t#############################################################################\n\n\n");
}

int caste_vote(char USERNAME[])
{
	printf("  \t\t##################################################\n");
        printf("  \t\t|                                                |\n");
        printf("  \t\t|         WELCOME %s , CAST YOUR VOTE!           |\n", USERNAME);
        printf("  \t\t|                                                |\n");
        printf("  \t\t##################################################\n\n\n");
}

void signup_banner()
{
	 printf("  \t##########################################\n");
    printf("  \t|                                        |\n");
    printf("  \t|        CREATE YOUR NEW ACCOUNT         |\n");
    printf("  \t|                                        |\n");
    printf("  \t##########################################\n");
}
void success_signup()
{
	printf("  \t#############################################################################\n");
        printf("  \t|                                                                           |\n");
        printf("  \t|           YOUR ACCOUNT HAS BEEN SUCCESSFULLY CREATED! CONGRATS            |\n");
        printf("  \t|                                                                           |\n");
        printf("  \t#############################################################################\n\n\n");
}

void admin_banner()
{
	printf("  \t\t#####################################\n");
    printf("  \t\t|                                   |\n");
    printf("  \t\t|        ADMIN LOGIN PANNEL         |\n");
    printf("  \t\t|                                   |\n");
    printf("  \t\t#####################################\n\n");
}

int wel_admin(char USERNAME[])
{
	 printf("  \t##################################################\n");
            printf("  \t|                                                |\n");
            printf("  \t|            WELCOME BACK TO ADMIN PANEL         |\n");
            printf("  \t|                                                |\n");
            printf("  \t##################################################\n\n\n");
}

void result_banner()
{
	printf("\n\n#####################################\n");
    printf("  \t|                                   |\n");
    printf("  \t|          VOTING RESULTS           |\n");
    printf("  \t|                                   |\n");
    printf("  \t#####################################\n\n\n");
}

void audit_banner()
{
	printf("\n\n  \t#####################################\n");
    printf("  \t|                                   |\n");
    printf("  \t|             AUDIT LOG             |\n");
    printf("  \t|                                   |\n");
    printf("  \t#####################################\n\n\n");
}

void voter_banner()
{
	printf("\n\n  \t######################################\n");
    printf("  \t|                                   |\n");
    printf("  \t|           VOTERS DETAILS          |\n");
    printf("  \t|                                   |\n");
    printf("  \t######################################\n\n\n");
}

void age_banner()
{
	printf("  \t##################################################\n");
        printf("  \t|                                                |\n");
        printf("  \t|        Not legally Eligible for Voting!        |\n");
        printf("  \t|                                                |\n");
        printf("  \t##################################################\n\n\n");
}
void age_joke()
{
	printf("  \t##################################################\n");
        printf("  \t|                                                |\n");
        printf("  \t|           Bhai tu Zinda kaisy hai ??           |\n");
        printf("  \t|                                                |\n");
        printf("  \t##################################################\n\n\n");
}
