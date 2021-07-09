#include <bits/stdc++.h>
using namespace std;

int score=0;

class User{
   private:
        string name,password,branch;
     public:
        string subject,roll_no;
        void sign_up();
        void login();
        void score_inc(int m);
    };

void User::sign_up(){
            cout<<"----------SIGN UP-----------\n";
            cout<<"Enter your name: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter your branch: ";
            getline(cin,branch);

            cout<<"Roll no- ";
            cin>>roll_no;
            cout<<"Enter password(without spaces)- ";
            cin>>password;
            string FileName=roll_no+".txt";
            fstream NewFile(FileName,ios::in | ios::out | ios::app);
            NewFile<<roll_no<<" "<<password<<" "<<name<<" "<<branch<<endl;
            NewFile.close();
        }

void User::login(){
        cout<<"---------LOGIN----------\n";
        string rollno,pass,r,p;
        A: cout<<"Enter your roll no. : ";
        cin>>rollno;
        roll_no=rollno;
        cout<<"Enter you password: ";
        cin>>pass;
        string filename=rollno+".txt";
        ifstream File(filename);
        File>>r>>p;
        
        if (rollno==r && pass==p){
            cout<<"Login Successfull !!\n";
        }
        else{
            cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            cout<<"Your roll no or password doesn't match , Try again!!!! \n";
            cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            File.close();
            goto A;
        }
        File.close();
        }

void User::score_inc(int m){

            score+=m;
        }

//Funtion prototyping

void get_option(int n,User u1,string topic);
void ask_ques(int n,string topic);
vector<int> random_arr(string quesFile);
void add_ques(string Qfile,string Afile);
void ques_file(string topic);


//Class for Science
class Science{
    private:
        string topic;
    public:
        void get_topic(int choice){
            cout<<"Enter topic number  1: 'Physics'  2:'Chemistry'  3:'Biology' \n";
            cout<<"Enter your choice:";
            int n;
            cin>>n;
            
            topic= n==3?"Bio":(n==1?"Phy":"Chem");
            if(choice==1){
                ques_file(topic);
            }
            
        }
        void get_ques(User u1){
            string quesFile=topic+".txt";
            string ansFile=topic+"_ans.txt";
            vector<int>arr=random_arr(quesFile);
            int n=1;
            for(int i:arr){
                cout<<"\n"<<n<<": ";
                ask_ques(i,quesFile);
                cout<<"\nAns: ";
                get_option(i,u1,ansFile);
                n++;
        }
        }
        void add_result(User u1){
            string filename=u1.roll_no+".txt";
            fstream FileIn(filename,ios::in | ios::out | ios::app);
            
            FileIn<<"Subject:- "<<"Science "<<"Topic- "<<topic<<" Your Score- "<<score<<endl;
            FileIn.close();
        }
};

//class for CSE
class Cse{
     private:
        string topic;
    public:
        void get_topic(int choice){
            cout<<"Enter  topic number  1: 'C++ Fundementals'   2: 'DSA'  3:'OOPM' \n";
            cout<<"Enter your choice:";
            int n;
            cin>>n;
            topic= n==3?"oopm":(n==1?"C++":"dsa");
            
            if(choice==1){
                ques_file(topic);
            }
        }
        void get_ques(User u1){
            string quesFile=topic+".txt";
            string ansFile=topic+"_ans.txt";
            vector<int>arr=random_arr(quesFile);
            int n=1;
            for(int i: arr){
                
                cout<<"\n"<<n<<": ";
                ask_ques(i,quesFile);
                cout<<"\nAns: ";
                get_option(i,u1,ansFile);
                n++;
            }
        }
        void add_result(User u1){
            string filename=u1.roll_no+".txt";
            fstream FileIn(filename,ios::in | ios::out | ios::app);
            
            FileIn<<"Subject:- "<<"CSE, "<<"Topic- "<<topic<<" Your Score- "<<score<<endl;
            FileIn.close();
        }
};


//TO GENERATE AN ARRAY(VECTOR) OF RANDOM NOS
vector<int> random_arr(string quesFile){
    vector<int>v;
    srand(time(0));
    ifstream file(quesFile);
    int z=0;
    string line;
    
     while(getline(file,line))
    {   z++;
        }
    file.close();
    
    int k=z<15?z:15;
    
    while(v.size()!=k){
        int n=rand()%z+1;
        if (! count(v.begin(), v.end(), n)) {
           v.push_back(n); 
    }
    }
    return v;
}

// TO ADD QUESTIONS INTO A FILE
void add_ques(string Qfile,string Afile){
    fstream QuesIn(Qfile,ios::in | ios::out | ios::app);
    fstream AnsIn(Afile,ios::in | ios::out | ios::app);
    cout<<"*********************************************************************************";
    cout<<"\nNOTE: DO NOT USE SPACES IN OPTIONS INSTEAD USE UNDERSCORE('_') IF YOU WANT \n\n";
    cout<<"*********************************************************************************\n";
    cout<<"Enter the no. of questions you wanna add- ";
    int no ;
    cin>>no;
    for(int i=0;i<no;i++){
        string q,oa,ob,oc,od;
        char ans;
        cout<<"Enter Question:- ";
        cin.ignore();
        getline(cin,q);
        QuesIn<<q<<"\n";
        cout<<"Enter option-a: "; cin>>oa;
        cout<<"Enter option-b: "; cin>>ob;
        cout<<"Enter option-c: "; cin>>oc;
        cout<<"Enter option-d: "; cin>>od;
        cout<<"Enter correct option no. like 'a','b','c' or 'd': "; cin>>ans;
        AnsIn<<"a)"<<oa<<" b)"<<ob<<" c)"<<oc<<" d)"<<od<<" "<<ans<<endl;
        cout<<endl;
    }
    QuesIn.close();
    AnsIn.close();
}

//To open file for adding questions
void ques_file(string topic){
    string Qfile=topic+".txt";
    string Afile=topic+"_ans.txt";
    cout<<"\nchoose:  1- Add questions in existing file\n         2- Clear the existing file and then add questions \n";
    cout<<"Enter your choice:";
    int m;
    cin>>m;
    if(m==2){
        ofstream ofs;
        ofs.open(Qfile, ofstream::out | ofstream::trunc);
        ofs.close();
        ofs.open(Afile, ofstream::out | ofstream::trunc);
        ofs.close();
    }
    add_ques(Qfile,Afile);
}

//To show user's file(marksheet)
void show_file(User u1){
    string filename=u1.roll_no + ".txt";
    fstream FileOut(filename,ios::in | ios::out | ios::app);
    string ou;
    cout<<endl;
    while(getline(FileOut,ou)){
    cout<<ou<<"\n";
    }
    FileOut.close();
}


//Input user's choice
void get_ans(char anss,User u1){
    char choice;
    cin>>choice;
    
    if((char)tolower(choice)==(char)tolower(anss)){
        cout<<"Your ans is correct !!\n";
        u1.score_inc(1);

    }
    else{
        cout<<"Your ans is incorrect!!\n";
        cout<<"Correct ans is option "<<anss<<"\n";
    }

}

//DISPLAY OPTION
void get_option(int n,User u1,string topic){
    ifstream an(topic);
    string opt1,opt2,opt3,opt4;
    char anss;
    for(int i=0;i<n;i++){
        an>>opt1>>opt2>>opt3>>opt4>>anss;
    }
    cout<<opt1<<" "<<opt2<<" "<<opt3<<" "<<opt4<<"\n";
    an.close();

    get_ans(anss,u1);
}



//Display question
void ask_ques(int n,string topic){
    ifstream in(topic);

    string ques;
    for(int i=0;i<n;i++){

    getline(in,ques);

    }
    cout<<ques;

    in.close();
    }


// MAIN FUNCTION
int main(){ 
    cout<<"************************************************************************";
    cout<<"\n---------------------WELCOME TO EXAM SIMULATOR--------------------\n\n";
    cout<<"*************************************************************************\n";
    int q,k;
    cout<<"Enter  1: Add Ques\n       2: Take Test\n";
    cout<<"Enter your choice:";
    cin>>q;
    if(q==1){
            cout<<"Choose subject in which you wanna add ques:  1: Science  2: CSE\n ";
            cout<<"Enter your choice:";
            cin>>k;
            if(k==1){
                Science t;
                t.get_topic(1);
                
            }
            else{
                Cse t;
                t.get_topic(1);
            }
            cout <<"\nQuestions Added Successfully !! \n";
    }
    else{
    
        User u1;
        int n;
        
        E:cout<<"\nEnter '1' if you are existing user\n"<<"      '2' for New user \n";
        cout<<"Your choice :";
        cin>>n;
        if(n==1){
            u1.login();
        }
        else if(n==2){
            u1.sign_up();
        }
        else{
            cout<<"************************************\n    INCORRECT CHOICE!!!!!";
            cout<<"\n PLEASE CHOOSE FROM GIVEN OPTION!!\n************************************\n";
            goto E;
            
        }
        
       
       int m;
       
       B:cout<<"\nPress '1' to get your marksheet\n      '2' to take test\n      '3' to Exit \n" ;
       cout<<"Enter your choice:";
       cin>>m;
       cout <<"\033[2J\033[1;1H";
       switch(m){
           case 1:
                show_file(u1);
                goto B;
                break;
           case 2 :{
                
                cout<<"Choose Subject- Press->  1: 'Science' 2: 'CSE'\n ";
                cout<<"Enter your choice:";
                int sub;
                cin>>sub;
                if (sub==1){
                   Science t;
                   u1.subject="Science";
                   t.get_topic(0);
                    t.get_ques(u1);
                    t.add_result(u1);
                    score=0;
                    goto B;
                    break;
                }
                else{
                    Cse t;
                    u1.subject="CSE";
                    t.get_topic(0);
                    t.get_ques(u1);
                    t.add_result(u1);
                    score=0;
                    goto B;
                    break;
                }
                }
                   
            case 3:
                cout<<"Logging out.....\n";
                break;
          }
    }
   
   string endd;
   getline(cin,endd);

    return 0;
}
