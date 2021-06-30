#include <bits/stdc++.h>
using namespace std;



class User{
   private:
        string name , password;


    public:
        static int score;
        string subject,roll_no;
        
        void sign_up(){
            cout<<"----------SIGN UP-----------\n";
            cout<<"Enter your name: ";
            cin.ignore();
            getline(cin,name);

            cout<<"Roll no- ";
            cin>>roll_no;
            cout<<"Enter password- ";
            cin>>password;
            string FileName=roll_no+".txt";
            fstream NewFile(FileName,ios::in | ios::out | ios::app);
            NewFile<<roll_no<<" "<<password<<" "<<name<<endl;
            NewFile.close();
        }
        
        void login(){
            cout<<"---------LOGIN----------\n";
            string rollno,pass,r,p;
            A: cout<<"Enter your roll no. : ";
            cin>>rollno;
            roll_no=rollno;
            cout<<"Enter you password: ";
            cin>>pass;
            string filename=rollno+".txt";
            fstream File(filename,ios::in | ios::out | ios::app);
            File>>r>>p;
            
            if (rollno==r && pass==p){
                cout<<"Login Successfull !!\n";
            }
            else{
                cout<<"Your roll no or password does'nt match , Try again!! \n";
                File.close();
                goto A;
            }
            File.close();
            
            
            
            
        }
        
        void score_inc(int m){

            score+=m;
        }
        
};

int User:: score=0;

void get_option(int n,User u1,string topic);
void ask_ques(int n,string topic);

//Class for subject 1
class Science{
    private:
        string topic;
    public:
        void get_topic(){
            cout<<"Enter topic from : 'Physics' or 'Chemistry' ";
            
            cin>>topic;
            
            
        }
        void get_ques(User u1){
            string quesFile=topic+".txt";
            string ansFile=topic+"_ans.txt";
            int arr[5]={3,1,2,5,4};
            for(int i=0;i<5;i++){

                ask_ques(arr[i],quesFile);
                get_option(arr[i],u1,ansFile);

        }
        }
        void add_result(User u1){
            string filename=u1.roll_no+".txt";
            fstream FileIn(filename,ios::in | ios::out | ios::app);
            
            FileIn<<"Topic- "<<topic<<" Your Score- "<<u1.score<<endl;
            FileIn.close();
            
            
            
        }
};
//To show user's file
void show_file(User u1){
    string filename=u1.roll_no+".txt";
    fstream FileOut(filename,ios::in | ios::out | ios::app);
    string ou;
    cout<<endl;
    while(getline(FileOut,ou)){
    cout<<ou<<"\n";

    }
    FileOut.close();
}


//Input user choice
void get_ans(string anss,User u1){
    string choice;
    cin>>choice;
    if(choice==anss){
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
    string opt1,opt2,opt3,opt4,anss;
    for(int i=0;i<n;i++){
        an>>opt1>>opt2>>opt3>>opt4>>anss;
    }
    cout<<"\n"<<opt1<<" "<<opt2<<" "<<opt3<<" "<<opt4<<"\n";
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
    cout<<"\n"<<ques;

    in.close();
    }


// MAIN FUNCTION
int main()
{  User u1;
    int n;
    cout<<"Enter '1' if you are existing user\n"<<"'2' for New user \n";
    
    cin>>n;
    if(n==1){
        u1.login();
    }
    else{
        u1.sign_up();
        u1.login();
    }
    
   cout<<u1.subject<<endl;
   int m;
   B:cout<<"\nPress '1' to get your marksheet , '2' to take test";
   cin>>m;
   switch(m){
       case 1:
            show_file(u1);
            break;
       case 2:
            string sub;
            cout<<"Enter Subject- ";
            cin>>sub;
            u1.subject=sub;
            if (u1.subject=="Science"){
               Science t;
               t.get_topic();
               t.get_ques(u1);
               t.add_result(u1);
               goto B;
               break;
       
   }
            
   }
    
   
   



   
   string endd;
   getline(cin,endd);



    return 0;
}
