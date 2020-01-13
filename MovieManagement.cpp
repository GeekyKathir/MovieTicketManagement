/***************************************************************************************************
Name:           Kathir N S

Created Date:   02-Jan-2020

Program Name:   Movie Ticket Management System

Objective:      1. Theater administrator should enter the list of movies in Portal
                2. Movies details should contain,
                   Movie Name, Genre, Format, Language, Show date, Show time, Ticket Price
                3. List of Movies should be displayed
                4. User can choose to Enter movie name or Exit (Ask User for Login Details)
                5. When user Enter the Movie name all details in Point no.2 should be listed
                6. User have to given the Option of Book Movie or Exit to Main menu
                7. When user choose Book Movie-> Seating Layout shown,
                   1,2,3...- Seats Available
                   B- Booked
                8. When user choose a Number, Number should change to B
                9. Finally E-ticket will be shown to user and And ask for book other ticker or Exit


***************************************************************************************************/
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void loginCredential();
//Overall user for the MTMS
int totalUser=0;

//Structure to store the name, login and pass for the user
struct userData{

    string userName;
    string userLogin;
    string userPassword;

};

//Vector for the dynamic memory allocation
vector<userData> finalData;

int main(){

    //Total Number of Users for Movie Ticker Management System
    ifstream totalFile;
    totalFile.open("./TotalUser/totalUser.txt");
    totalFile>>totalUser;
    totalFile.close();

    //Storing the data from '.txt' file to Structure Vector
    if(totalUser>0){
        ifstream inputFile;
        inputFile.open("./UserNamePassword/userDetails.txt");
        for(int i=0; i<totalUser; i++){
            //Creating the Vector array to store the data
            finalData.push_back(userData());
            getline(inputFile, finalData[i].userName, ',');
            getline(inputFile, finalData[i].userLogin, ',');
            getline(inputFile, finalData[i].userPassword, '\n');
        }
    }
    //To check the type of user( Admin or User)
    int checkUser;

    //Title Card
    cout<<"\n*************************** Welcome to Movie ticket Booking System***********************************"<<endl<<endl<<endl;

    //Checking the type of User
    cout<<"1. Admin\n"<<"2. User"<<endl<<endl;
    cout<<"For Admin(1) or User(2) or Exit(0):\t";
    cin>>checkUser;
    cout<<endl<<endl;

    //Administrator
    if (checkUser==1){
        string adminUsername, adminPassword="";
        cout<<"Hi Admin"<<endl<<endl;

        //Login Credential from Administrator
        cout<<"Enter Login Credential"<<endl<<endl;
        do{
            //Getting username of Admin
            cout<<"Username: ";
            cin>>adminUsername;
            if(adminUsername=="admin"){
                cout<<"\n";
                //Getting Password  of Admin
                char passChar;
                cout << "Password: ";
                passChar = _getch();
                while(passChar != 13){
                adminPassword.push_back(passChar);
                cout << '*';
                passChar = _getch();
                }

                if(adminPassword!="admin"){
                   cout<<"Invalid Password! Try again";
                }
            }
            else{
                cout<<"Invalid Username! Try again";
            }
        }while(adminPassword!="admin");

        cout<<"\n\nAccess Granted"<<endl<<endl;

    }


    //New User and Registered User
    else if(checkUser==2){
        int outsideUser;
        cout<<"Hi User! Welcome Back!"<<endl<<endl;
        cout<<"1. New User\n2. Registered User\n\n";
        cout<<"For New User(1) or Registered User (2) or Exit(0):\t";
        cin>>outsideUser;

        //New User
        if (outsideUser==1){
            //New User Details
            string outName, outUsername, outPassword;
            cout<<"\nHi New User"<<endl;
            //Asking Details of the User
            cout<<"\nEnter the Below Details for Registration";
            cout<<"\nName: ";
            cin>>outName;
            cout<<"\nUsername: ";
            cin>>outUsername;
            cout<<"\nPassword: ";
            cin>>outPassword;

            //Storing the user details in vector array
            finalData.push_back(userData());
            finalData[totalUser].userName=outName;
            finalData[totalUser].userLogin=outUsername;
            finalData[totalUser].userPassword=outPassword;

            //Appending the Data to a single file
            ofstream appendFile;
            appendFile.open("./UserNamePassword/userDetails.txt", ios::app);
            appendFile<<finalData[totalUser].userName<<","<<finalData[totalUser].userLogin<<","<<finalData[totalUser].userPassword<<'\n';
            appendFile.close();

            //Changing the value of total user in the file
            totalUser=totalUser+1;
            ofstream totalFile;
            totalFile.open("./TotalUser/totalUser.txt");
            totalFile<<totalUser;
            totalFile.close();

            cout<<"\nYou have successfully registered with us!"<<endl;
            loginCredential();

        }

        //Registered User
        else if(outsideUser==2){
            if(totalUser>0){
               loginCredential();
            }
            else{
                cout<<"\nSorry, No User registered with us till now";
            }
        }

        //Exit Option
        else if(outsideUser==0){
            cout<<"\nThank you for Visiting Us!"<<endl;
        }

        //Unknown Entry option
        else{
            cout<<"\nYou have entered unknown Entry, Thank you for Visiting Us!"<<endl;
        }

    }


    //Exit Option
    else if(checkUser==0){
        cout<<"Thank you for Visiting Us!"<<endl;
    }


    //Unknown Entry, it will exit
    else{
        cout<<"You have entered unknown Entry, Thank you for Visiting Us!"<<endl;
    }
}


void loginCredential(){

    string regUsername, regPassword;

    cout<<"\nHi Registered User! Welcome Back!"<<endl;
    cout<<"\nEnter the below Login Credential"<<endl;
    cout<<"\nUsername: ";
    cin>>regUsername;
    int k=-1;
    for (int j=0; j<totalUser; j++){
        if(regUsername==finalData[j].userLogin){
            k=j;
        }
    }
    if(k==-1){
        cout<<"\nSorry, Invalid Username thanks for Visiting us";
    }
    else{

        do{
            char userpassChar;
            cout << "Password: ";
            userpassChar = _getch();
            while(userpassChar != 13){
                regPassword.push_back(userpassChar);
                cout << '*';
                userpassChar = _getch();
            }
            if(regPassword!=finalData[k].userPassword){
                cout<<"Invalid Password! Try again";
            }

        }while(regPassword!=finalData[k].userPassword);


        cout<<"\n\nContinue to Book ticket"<<endl;
    }


}
