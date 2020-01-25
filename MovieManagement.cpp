#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void datafromFile();

//Overall user for the MTMS
int totalUser=0;
//Overall Count of the Movie in MTMS
int totalMovie=0;

//Structure to store the name, login and password for the user
struct userData{

    string userName;
    string userLogin;
    string userPassword;

};

//Structure to store the Movie Name, Genre, Format, Language, Show Date, Show Time, Ticket Price, Total Tickets
struct movieData{

    string movieName;
    string movieGenre;
    string movieFormat;
    string movieLanguage;
    string movieDate;
    string movieTime;
    float ticketPrice;
    int totalTickets;

};

//Vector for the dynamic memory allocation for user data
vector<userData> finalUserData;
//Vector for the dynamic memory allocation for movie data
vector<movieData> finalMovieData;

class Administrator{

    public:

        void adminLogin();
        void movieDetails();

};

//Admin login credentials
void Administrator::adminLogin(){

    string adminUsername, adminPassword="";
    cout<<"Hi Admin, Welcome Back!"<<endl<<endl;

    //Login Credential from Administrator
    cout<<"Login Credential"<<endl;
    cout<<"________________"<<endl;
    do{
        //Getting username of Admin
        cout<<"\nUser-name: ";
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
                cout<<"\nInvalid Password! Try again";
            }
        }
        else{
            cout<<"\nInvalid User-name! Try again";
        }
    }while(adminPassword!="admin");

    cout<<"\n\n!Access Granted for the Administrator Rights!"<<endl;
}

//Movie Details adding and viewing
void Administrator::movieDetails(){

    int select00;
    cout<<"\n1->Edit the Movie List\n2->View the list of Movies\n0->Exit"<<endl;
    cout<<"\nPress the key as per above list: ";
    cin>>select00;
    if (select00==1){
        int select10;
        cout<<"\n1->Add the Movie to the List\n2->Change Data of the Movie List\n3->Delete Movie from the List\n4->Exit"<<endl;
        cout<<"\nPress the key as per above list: ";
        cin>>select10;
        if (select10==1){
            cout<<"\nBelow Data to add in the List";
            cout<<"\n-----------------------------"<<endl<<endl;
            finalMovieData.push_back(movieData());
            cout<<"Movie Name: ";
            cin>>finalMovieData[totalMovie].movieName;
            cout<<"\nMovie Genre: ";
            cin>>finalMovieData[totalMovie].movieGenre;
            cout<<"\nMovie Format: ";
            cin>>finalMovieData[totalMovie].movieFormat;
            cout<<"\nMovie Language: ";
            cin>>finalMovieData[totalMovie].movieLanguage;
            cout<<"\nMovie Date: ";
            cin>>finalMovieData[totalMovie].movieDate;
            cout<<"\nMovie Time: ";
            cin>>finalMovieData[totalMovie].movieTime;
            cout<<"\nTicket Price: ";
            cin>>finalMovieData[totalMovie].ticketPrice;
            cout<<"\nTotal Tickets: ";
            cin>>finalMovieData[totalMovie].totalTickets;
            cout<<"\n--------------------------------------";

            ofstream writeMovieFile;
            writeMovieFile.open("./allData/listMovie.txt", ios::app);
            writeMovieFile<<finalMovieData[totalMovie].movieName<<','<<finalMovieData[totalMovie].movieGenre<<',';
            writeMovieFile<<finalMovieData[totalMovie].movieFormat<<','<<finalMovieData[totalMovie].movieLanguage<<',';
            writeMovieFile<<finalMovieData[totalMovie].movieDate<<','<<finalMovieData[totalMovie].movieTime<<',';
            writeMovieFile<<finalMovieData[totalMovie].ticketPrice<<','<<finalMovieData[totalMovie].totalTickets<<'\n';
            writeMovieFile.close();

            //Changing the value of total movie in the file
            totalMovie=totalMovie+1;
            ofstream temptotalMovieFile;
            temptotalMovieFile.open("./allData/totalMovie.txt");
            temptotalMovieFile<<totalMovie;
            temptotalMovieFile.close();

            char backOption10;
            cout<<"\nb->Go Back\n0->Exit"<<endl;
            cout<<"\nPress the key as per above list: ";
            cin>>backOption10;
            if (backOption10=='b'){
                movieDetails();
            }
            else if(backOption10=='0') {
                cout<<"\nThank you, Visit Soon for the Update!";
            }
            else{
                cout<<"\nUnknown Entry, Thank you!";
            }

        }

    }
    else if (select00==2){
        char backOption00;
        if (totalMovie>0){
            for(int i=0; i<totalMovie; i++){
                cout<<finalMovieData[i].movieName<<"\t";
                cout<<finalMovieData[i].movieGenre<<"\t";
                cout<<finalMovieData[i].movieFormat<<"\t";
                cout<<finalMovieData[i].movieLanguage<<"\t";
                cout<<finalMovieData[i].movieDate<<"\t";
                cout<<finalMovieData[i].movieTime<<"\t";
                cout<<finalMovieData[i].ticketPrice<<"\t";
                cout<<finalMovieData[i].totalTickets<<"\n";
            }
            cout<<"\nb->Go Back\n0->Exit"<<endl;
            cout<<"\nPress the key as per above list: ";
            cin>>backOption00;
            if (backOption00=='b'){
                movieDetails();
            }
            else if(backOption00=='0') {
                cout<<"\nThank you, Visit Soon for the Update!";
            }
            else{
                cout<<"\nUnknown Entry, Thank you!";
            }

        }
        else{
            char backOption01;
            cout<<"\nNo Movies added to the list till now!\n";
            cout<<"\nb->Go Back\n0->Exit"<<endl;
            cout<<"\nPress the key as per above list: ";
            cin>>backOption01;
            if (backOption01=='b'){
                movieDetails();
            }
            else if(backOption01=='0') {
                cout<<"\nThank you, Visit Soon for the Update!";
            }
            else{
                cout<<"\nUnknown Entry, Thank you!";
            }

        }

    }
    else if (select00==0){
        cout<<"Thank you, Visit Soon for the Update!";
    }
    else{
        cout<<"Unknown Entry, Thank you!";
    }
}


int main(){

    //Reading the data from the file
    datafromFile();
    //To check the type of user( Admin or User)
    int checkUser;
    //Title Card
    cout<<"|-----------------------------------------------------------------------------------|"<<endl;
    cout<<"|                     Welcome to Movie Ticket Booking System                        |"<<endl;
    cout<<"|-----------------------------------------------------------------------------------|"<<endl;

    //Checking the type of User
    cout<<"\n1->Admin\n"<<"2->User"<<endl<<endl;
    cout<<"For Admin(1) or User(2) or Exit(0):\t";
    cin>>checkUser;
    cout<<endl<<endl;

    if (checkUser==1){
        //Declaring the object for the class administrator
        Administrator adminAccess;
        //Admin Login Credentials
        adminAccess.adminLogin();
        //Movie details add and view
        adminAccess.movieDetails();
    }
}

//Reading the data from the file to use in the program
void datafromFile(){
    //Total Number of Users for Movie Ticker Management System
    ifstream totaluserFile;
    totaluserFile.open("./allData/totalUser.txt");
    totaluserFile>>totalUser;
    totaluserFile.close();

    //Storing the data from '.txt' file to Structure Vector
    if(totalUser>0){
        ifstream userdataFile;
        userdataFile.open("./allData/userDetails.txt");
        for(int i=0; i<totalUser; i++){
            //Creating the Vector array to store the data
            finalUserData.push_back(userData());
            getline(userdataFile, finalUserData[i].userName, ',');
            getline(userdataFile, finalUserData[i].userLogin, ',');
            getline(userdataFile, finalUserData[i].userPassword, '\n');
        }
    }

    //Total Number of Movie
    ifstream totalmovieFile;
    totalmovieFile.open("./allData/totalMovie.txt");
    totalmovieFile>>totalMovie;
    totalmovieFile.close();

    //Storing the data from '.txt' file to Structure Vector
    if(totalMovie>0){
        ifstream moviedataFile;
        moviedataFile.open("./allData/listMovie.txt");
        for(int j=0; j<totalMovie; j++){
            //For converting the string to number
            string tempSrno;
            string tempPrice;
            string tempTickets;
            //Creating the Vector array to store the data
            finalMovieData.push_back(movieData());
            getline(moviedataFile, finalMovieData[j].movieName, ',');
            getline(moviedataFile, finalMovieData[j].movieGenre, ',');
            getline(moviedataFile, finalMovieData[j].movieFormat, ',');
            getline(moviedataFile, finalMovieData[j].movieLanguage, ',');
            getline(moviedataFile, finalMovieData[j].movieDate, ',');
            getline(moviedataFile, finalMovieData[j].movieTime, ',');
            getline(moviedataFile, tempPrice, ',');
            stringstream stringfloatConvert(tempPrice);
            stringfloatConvert>>finalMovieData[j].ticketPrice;
            getline(moviedataFile, tempTickets, '\n');
            stringstream stringIntConvert(tempTickets);
            stringIntConvert>>finalMovieData[j].totalTickets;
        }
    }

}

