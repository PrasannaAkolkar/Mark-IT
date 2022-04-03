#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
#include <sstream>
#include<ctime>
// second code

using namespace std;


bool isNumber(string s)  // to check if the string is a number
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}



vector<string> names = {

"ABHINAV SHARMA",
"ADNAN SHAHID SADAR",
"AGRAWAL RAUNAK KISHOR",
"AKOLKAR PRASANNA PRASAD",
"ARYAN KUMAR GUPTA",
"AYUSH CHANDAK",
"BHALE KAUSTUBH PRADIP",
"BIJAWE SANKET SANJAY",
"CHIM SWATI KASHIRAM",
"CHOUNDE RUSHIKESH SUNIL",
"DALWAI OMKAR SHANKAR",
"DESHMUKH RUTVIK RAJENDRA",
"DESHPANDE OM RAJESH",
"DHADIWAL AKASH VISHAL",
"DHOKARIKAR KEDAR PRAVIN",
"DIVSEHAJ SINGH ANAND",
"FANDADE PRATIK PRAVIN",
"GAWAI ABHIJIT KAILASH",
"GHANMODE ASTITVA BHIMRAO",
"HIMANSHU RAMAN PANDEY",
"JADHAV SWAPNIL BABA",
"JADHAV YASH SHANKAR",
"KABRA PURVA PANKAJ",
"KACHARE TEJAS VIKAS",
"KADAM SHAILESH NITIN",
"KALASH R CHAUHAN",
"KANDEWAR ADARSH SANTOSH",
"KANKURTI TASMIYA TAMREEN NOOR AHMED",
"KAWALE SHYAM VILAS",
"KHARE SHREYAS VIVEK",
"KOLHE YASH DHIRAJ",
"KULKARNI VARAD SANJAY",
"LAPSHETWAR VEDANT",
"LATKAR MEHUL SHAILESH",
"MAHAJANI MIHIR VIJAY",
"MAL CHANCHAL SUNIL",
"MALVIYA SANGEETA RAMESHKUMAR",
"MEERA TAMBOLI",
"NAGARGOJE MAHESH NAGORAO",
"NAMAN CHANDAK",
"NIKAM SHRUTI VINOD",
"NIKHIL RAVULAPARTHY",
"NISHANT BHAT",
"OSWAL PREETI DEVICHAND",
"OSWAL YASH RAJESH",
"PADALKAR AKSHADA BABAN",
"PANDE RITU BHIMRAO",
"PATIL NIKITA KAILAS",
"PATIL SUNITA SHANTINATH",
"PAWAR BHARGAV SANDEEP",
"PAWAR RUTUJA LAXMAN",
"PINGALE SHANTANU CHANGDEO",
"PRADUNYA DEVIDAS MALADHARI",
"RUCHITA PRAMOD ARJAPURE",
"S. ABHISHEK",
"SABALE UDDHAV BHANUDAS",
"SAPTARSHI ROY",
"SARA SANJAY DIXIT",
"SHARMA ADARSH MOHAN",
"SHARMA DHEERAJ RAJESH",
"SHELKE RUSHIKESH HANUMAN",
"SHINDE ADITYA KAKASAHEB",
"SHINGADE PRAJWAL SHANKAR",
"SHIVAM MANUBHAI TANDEL",
"SIKCHI SAGAR OMPRAKASH",
"SONTAKKE SHANTANU PRAFULLA",
"SURYAWANSHI GITANJALI MADHUKAR",
"TALIB HUSSAIN",
"TAPADIYA PRACHI HARISH",
"TAYDE UTSAV PRASHANT",
"TIWARI KARTIK RAHUL",
"TODASAM AKSHAY BHASKAR",
"VARGHAT SUMIT ASHOK",
"VARTAK TANAY PRAFULLA",
"VASWANI ASHISH SANJAY",
"VIDHATE KALYANI ASHISH",
"WASO PRATIK VINOD",
"ANKITA GHOSH",
};

int main()
{
    cout<<"Please enter the date of attendance\n Format: 21 May 2020 or 4 June 2019......\n";
    string string_date_input;
    getline(cin,string_date_input);
    string myText;
    vector<string> v;
    set<int> s1;
    vector<int> absentees;
    int x=0;
    cout<<"Absentees are \n";
    //ifstream MyReadFile("tyit0810.txt");  // to read the file
    //ifstream MyReadFile("test for sp.txt");  // to read the file

    ifstream MyReadFile("daa.txt");  // to read the file

    while (getline (MyReadFile, myText))  // line by line extraction
    {
        if(myText.find(':')== string::npos)  // to ignore the time (11:00)
        {

            string str1="";
            for(auto i:myText)
            {
                if(i==' ')   // extract the roll
                    break;
                if(i!=' ')
                    str1+=i;
            }
            //cout<<str1<<endl;
            if(str1!="" && isNumber(str1))  // check for blank string and if the extracted digit is a no.
                v.push_back(str1);
        }
    }
    for(auto i: v)
    {
       stringstream extract(i);  // convert to int
       int x=0;
       extract>>x;
       if(s1.find(x)==s1.end())  // set find
            s1.insert(x);
   }
    for(int j=1;j<=78;j++)
    {
        bool x = binary_search(s1.begin() , s1.end() , j);  // search on set
        if(!x)
            absentees.push_back(j); // absentees list
    }
    for(auto i:absentees)
        cout<<i<<endl;
    cout<<"\nNo. of Presentees :: "<<s1.size()<<endl; // gives no. of presentees
    cout<<"\nNo. of Absentees :: "<<absentees.size()<<endl; //  gives no. of absentees

    ofstream myWriteFile;

    myWriteFile.open("test2.csv",ios::app);
    //myWriteFile.open("test2.csv",ios::in);
    //myWriteFile.open("test2.csv");


    time_t now = time(0);
    char* dt = ctime(&now);

    //cout << "The local date and time is: " << dt << endl;
    string s_date = dt;
    //cout << "The local date and time is: " << s_date.substr(0,10) << endl;
   // myWriteFile<<"Today's Date is: "<<","<<dt<<endl;

    //myWriteFile<<"Present/Absent"<<",Roll Number"<<endl;
    int var=0;
    vector<string> absentee_dates_of_students;

    for(int j=1;j<=78;j++)
    {
        bool x = binary_search(s1.begin() , s1.end() , j);  // search on set
        if(!x)
        {
            //myWriteFile<<0<<","<<j<<","<<names[j-1]<<endl;
            myWriteFile<<names[j-1]<<","<<j<<","<<0<<endl;

            absentee_dates_of_students.push_back(string_date_input);
        }
        else{
                var=1;
            //myWriteFile<<1<<","<<j<<","<<names[j-1]<<endl;
            myWriteFile<<names[j-1]<<","<<j<<","<<1<<endl;
            absentee_dates_of_students.push_back("NULL");
        }
    }
    //cout<<"Hello"<<endl;

//    for(int i=0;i<absentee_dates_of_students.size();i++)
//    {
//        if(absentee_dates_of_students[i]!="NULL")
//            cout<<i+1<<"  "<<absentee_dates_of_students[i]<<endl;
//    }






    myWriteFile.close();

    ifstream myWriteFile1;
    myWriteFile1.open("test2.csv");
    int c1=0;

    vector<string> daily_attendance;

 while(myWriteFile1.good())
    {
        //c1++;
        string line1;
        getline(myWriteFile1, line1 , '\n');
        int x = line1.length();
        cout<<line1[x-1]<<endl;
        daily_attendance.push_back(to_string(line1[x-1]));
    }

    myWriteFile1.close();


MyReadFile.close();
    daily_attendance.erase(daily_attendance.end()-1);
//    for(auto i:daily_attendance)
//        cout<<i<<endl;
    map<int,int> m;
    int sizeAtt = daily_attendance.size();
    cout<<sizeAtt<<endl;

    int count_of=0;
    int number_of_lectures_conducted=0;

    for(int i=0;i<sizeAtt;i++)
    {
        if(i%78==0)
        {
            count_of=0;
            number_of_lectures_conducted++;
        }
        //cout<<"Count of value"<<endl;
        //cout<<count_of<<endl;
        if(daily_attendance[i]=="49")
        {
            m[count_of]++;
        }
        else if(daily_attendance[i]=="48"){
            m[count_of]=m[count_of]+0;
        }
        count_of++;
    }

    for(auto i:m)
    {
        cout<<i.first + 1<<" "<<i.second<<endl;
    }


    //----------------------------FINAL PART OF PROGRAM----------------------------------------------------
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ofstream defaulter_list_file;

    defaulter_list_file.open("defaulter.csv");


    cout<<"\n\nTotal Number of Lectures Conducted are:----->"<<number_of_lectures_conducted;

    char ch;
    cout<<"Do you want to generate final attendance for this month(Y/N)??\n";
    cin>>ch;
    if(ch=='Y')
    {
        defaulter_list_file<<"Number of Lectures Conducted"<<","<<number_of_lectures_conducted<<endl;

        defaulter_list_file<<"Roll Number"<<","<<"Name"<<","<<"Email id"<<","<<"Number of Lectures Attended"
        <<","<<"Defaulter/Not Defaulter"<<","<<"Percentage Attendance"<<","<<"Lectures reqd to avoid detention"<<endl;

        for(auto i:m)
        {
            defaulter_list_file<<i.first+1<<","<<names[i.first]<<","<<"prasanna.akolkar@gmail.com"<<","<<i.second<<",";
            double val = float(i.second)/float(number_of_lectures_conducted);

            if(val < 0.75)
            {
                int temp_lec = number_of_lectures_conducted;
                int temp_att = i.second;
                int count_=0;
                while(float(temp_att)/float(temp_lec) <0.75 )
                {   count_++;
                    temp_att++;
                    temp_lec++;
                }

                defaulter_list_file<<"Defaulter Student"<<","<<(val)*100<<","<<count_<<endl;
            }
            else
            {
                 defaulter_list_file<<"Non Defaulter Student"<<","<<(val)*100<<","<<0<<endl;
            }


        }
    }

//    else{
//        //exit(0);
//        //break;
//    }

    defaulter_list_file.close();


    ofstream absentees_date_file;

    absentees_date_file.open("absentees.csv",ios::app);
    //absentees_date_file.open("absentees.csv");
    //cout<<"File Written"<<endl;

    absentees_date_file<<"Absentees list for:-->:";
    absentees_date_file<<string_date_input<<endl;
     for(int i=0;i<78;i++)
    {
        if(absentee_dates_of_students[i]!="NULL")
            absentees_date_file<<i+1<<endl;
    }
    absentees_date_file<<"\n\n";

    absentees_date_file.close();


}


