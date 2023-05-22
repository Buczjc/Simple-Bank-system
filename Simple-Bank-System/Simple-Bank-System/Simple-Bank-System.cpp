#include <iostream>
#include <windows.h>
using namespace std;

void digitChecker(double& cash)
{
    while (!(cin >> cash))
    {
        system("cls");
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t                       -------------------------------                           \n";
        cout << "\t\t\t                            Error: Invalid input.                          \n";
        cout << "\t\t\t                       -------------------------------                           \n";
        cout << "\n\n\n\n\n";
        cout << "\t\t\t                         Please enter a digit only: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
}

void loading()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t           Loading please wait";
    for (int i = 0; i < 3; i++)
    {
        Sleep(1000);
        cout << ".";
    }
}

void cashNegaMSG()
{
    cout << "\n\n\n\n\n";
    cout << "\t\t\t                 ---------------------------------------------              \n";
    cout << "\t\t\t                 [ You cannot deposit 0 or a negative amount ]              \n";
    cout << "\t\t\t                 ---------------------------------------------              \n";
}

void cashLimitMSG()
{
    cout << "\n\n\n\n\n";
    cout << "\t\t\t                          -------------------------                                               \n";
    cout << "\t\t\t                        [ Cash limit only : 500,000 ]                                             \n";
    cout << "\t\t\t                          -------------------------                                               \n";
}

void errorDefaultMSG()
{

    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t                   -----------------------                         \n";
    cout << "\t\t\t\t                  [ Error: Invalid input. ]                        \n";
    cout << "\t\t\t\t                   -----------------------                         \n";
    cout << "\n\n\n\n";
    cout << "\t\t\t\t             Please try again with a valid option.                  \n";
    cout << "\n\n\n";
    Sleep(2000);
    system("cls");

}

void doYouwantAnotherTransacMSG(char& transac)
{
    cout << "\t\t                       Would you like another transaction?[Y/N] : ";
    cin >> transac;
    while (transac != 'y' && transac != 'Y' && transac != 'n' && transac != 'N')
    {
        system("cls");
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t                           [Y] = YES      [N] = NO                    \n\n\n\n\n";
        cout << "\n\n";
        cout << "\t\t\t                          You can only input Y/N : ";
        cin >> transac;

    }
}

void youChosetoWithdrawMSG()
{
    cout << "\n\n\n\n\n";
    cout << "\t\t\t                        ----------------------------                               \n";
    cout << "\t\t\t                       [   You chose to withdraw!   ]                              \n";
    cout << "\t\t\t                        ----------------------------                               \n";
}

void youChosetoDepositMSG()
{
    cout << "\n\n\n\n\n";
    cout << "\t\t\t                        ----------------------------                               \n";
    cout << "\t\t\t                       [    You chose to deposit!   ]                                \n";
    cout << "\t\t\t                        ----------------------------                               \n";
}
void cashNotEnoughMSG()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t                        ----------------------------------------------------------                    \n";
    cout << "\t                        there is not enough cash available to fulfill your request                    \n";
    cout << "\t                        ----------------------------------------------------------                    \n";
    Sleep(2000);
    system("cls");
}

void bankLogo()
{
    cout << "\n\n\n";
    cout << "\t                                     ----------------------------------                                           \n";
    cout << "\t                                     |    Welcome to BUCZ Landbank    |                                           \n";
    cout << "\t                                     ----------------------------------                                           \n";
    cout << "\n";
}

void End()
{
    cout << "\n\n\n\n\n\n\n";
    cout << "\t                                    --------------------------------------                                           \n";
    cout << "\t                                   |    THANK YOU 4 USING THE PROGRAM !   |                                          \n";
    cout << "\t                                    --------------------------------------                                          \n";
    cout << "\n\n\n\n\n";
}

int main()
{
    system("color f0");
    double bankCash = 0;
    double cash = 0;
    char choice;
    char transac = 'y';
    double cashLimit = 500000;
    double cashDown = 0;
    do {
        bankLogo();
        cout << "\n";
        cout << "\t\t\t\t              [ You have " << bankCash << "$ in your account ]                     \n";
        cout << "\n\n";
        cout << "\t\t\t                      [1]Deposit          [2]Withdraw                                \n";
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t                                Choose : ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case '1':
            youChosetoDepositMSG();
            do {
                cout << "\n\n\n\n\n";
                cout << "\t\t\t                     How much do you want to deposit : ";
                digitChecker(cash);
                loading();
                if (cash > cashLimit)
                {
                    system("cls");
                    cashLimitMSG();
                }

                if (cash <= cashDown)
                {
                    system("cls");
                    cashNegaMSG();
                }
            } while (cash > cashLimit || cash <= cashDown);

            bankCash += cash;
            cout << "\n";
            system("cls");
            cout << "\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t           [ " << cash << "$ has been added to your account ]             \n\n\n\n\n";
            doYouwantAnotherTransacMSG(transac);
            system("cls");
            break;

        case '2':
            do {
                youChosetoWithdrawMSG();
                cout << "\n\n\n\n\n\n\n\n";
                cout << "\t\t\t                     How much do you want to withdraw : ";
                digitChecker(cash);
                loading();
                if (cash > bankCash) {
                    cashNotEnoughMSG();
                }
            } while (cash > bankCash);
            bankCash -= cash;
            system("cls");
            cout << "\n\n\n\n\n\n";
            cout << "\t\t                --------------------------------------------------------                            \n";
            cout << "\t\t\t                 " << cash << "$ has been taken out of your account                              \n";
            cout << "\t\t                --------------------------------------------------------                            \n";
            cout << "\n\n\n";
            cout << "\t\t\t                 You now have " << bankCash << "$ in your account.                                 \n";
            cout << "\n\n\n";
            doYouwantAnotherTransacMSG(transac);

            system("cls");
            break;

        default:
            errorDefaultMSG();
            break;
        }
    } while (transac == 'y' || transac == 'Y');
    system("cls");
    End();
    return 0;
}