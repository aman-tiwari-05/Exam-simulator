#include <bits/stdc++.h>
using namespace std;



class User{
    private:
        string name,roll_no;


    public:
        static int score;
        string subject;
        void get_details(){
            cout<<"Enter your name: ";
            getline(cin,name);

            cout<<"Roll no-";
            cin>>roll_no;
            cout<<"Enter Subject of which you wanna take test: ";
            cin>>subject;


        }
        void score_inc(int m){

            score+=m;
        }
        void show_result(){
            cout<<"Name- "<<name;
            cout<<"Roll No.- "<<roll_no;
            cout<<"Your Score- "<<score;
        }
};

void get_option(int n,User u1,string topic);
void ask_ques(int n,string topic);

//Class for subject 1
class Subject1{
    private:
        string topic;
    public:
        void get_topic(){
            cout<<"Enter topic: ";
            cin>>topic;
            topic=topic;
        }
        void get_ques(User u1){
            string quesFile=topic+".txt";
            string ansFile=topic+"_ans.txt";
            int arr[3]={3,1,2};
            for(int i=0;i<3;i++){

                ask_ques(arr[i],quesFile);
                get_option(arr[i],u1,ansFile);

        }
        }
};
int User:: score=0;

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
   u1.get_details();
   cout<<u1.subject<<endl;
   if (u1.subject=="subject1"){
       Subject1 t;
       t.get_topic();
       t.get_ques(u1);
   }



   u1.show_result();
   string endd;
   getline(cin,endd);



    return 0;
}
