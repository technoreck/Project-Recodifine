#include <bits/stdc++.h>
using namespace std;

int unsigned long long Acc_no_gen(){
    int unsigned long long s=0;
    for(int i=0;i<12;i++){
        s=(s+(pow(10,(12-i))*(rand()%10)));
    }
    return s;
}

class SBI{
    public:
        string Cust_name;
        string Br_name;
        int unsigned long long Acc_no;
        double Acc_bal;
        int pin;
    private:
        string DOB;
    protected:
        int unsigned long Mob_no;
    public:
        
        SBI(){}
       
        SBI(string Br_name,string Cust_name,int unsigned long long Acc_no,int unsigned long Mob_no,string DOB,double Acc_bal,int pin){
            this->Br_name=Br_name;
            this->Cust_name=Cust_name;
            this->Acc_no=Acc_no;
            this->Mob_no=Mob_no;
            this->DOB=DOB;
            this->Acc_bal=Acc_bal;
            this->pin=pin;
        }
        ~SBI(){}
       
};

class Deposit_money:public SBI{
    public:
    	string input_name;
    	double Dep_amt;
        Deposit_money(){}
        Deposit_money(string input_name,double Dep_amt){
		    this->input_name=input_name;
		    this->Dep_amt=Dep_amt;
        }
        void Deposit(SBI* sarr,int size){
          int sec_pin;
       	    for(int i=0; i<size; i++){
       	    	if(sarr[i].Cust_name==input_name){
                 cout<<"user exists with this name\n";
                 cout<<"enter your security pin";
                 cin>>sec_pin;
                 if(sec_pin==sarr[i].pin){
                   sarr[i].Acc_bal=sarr[i].Acc_bal+Dep_amt;
                   cout<<"Your Updated Balance is :"<<sarr[i].Acc_bal;
                 }
              }

       	    	else{
       	    	    cout<<"No user exists with this name";
       	    	}
       	    	break;
			      }
        }
       ~Deposit_money(){}
};

class Withdrawal_money:public SBI{
	public:
    	string input_name;
    	double Wid_amt;
        Withdrawal_money(){}
        Withdrawal_money(string input_name,double Wid_amt){
		    this->input_name=input_name;
		    this->Wid_amt=Wid_amt;
        }
        void Withdrawal(SBI* sarr,int size){
          int sec_pin;
       	  for(int i=0; i<size; i++){
       	  	if(input_name==sarr[i].Cust_name){
                 cout<<"user exists with this name\n";
                 cout<<"enter your security pin";
                 cin>>sec_pin;
                 if(sec_pin==sarr[i].pin){
                   sarr[i].Acc_bal=sarr[i].Acc_bal-Wid_amt;
                   try {
                     if(sarr[i].Acc_bal<0){
                       throw runtime_error("withdrawing more than available amount is not allowed");
                     }
                     else{
                       cout<<"Your Updated Balance is :"<<sarr[i].Acc_bal;
                     }
                   }
                   catch(runtime_error e){
                     cerr<<e.what();
                   }            
                 }
            }
       	  	else{
       	      cout<<"Error \n Name doesn't match";
       	  	}
       	  	break;
			    }
        }
       ~Withdrawal_money(){}
};

class Loan:public SBI{
    private:
		float loan_rate;
		int loan_time;
	public:
		string input_name;
		double loan_amt;
		
		Loan(){}
		
		Loan(string input_name,double loan_amt,float loan_rate){
			this->input_name=input_name;
			this->loan_amt=loan_amt;
			this->loan_rate=loan_rate;
			if(loan_amt<=400000){
				loan_time=5;
			}
			else if(loan_amt>400000 && loan_amt<=1000000){
				loan_time=10;
			}
			else{
				loan_time=15;
			}
		}
		friend void display(Loan);
		void Loan_cal(SBI* sarr,int size){
		    for(int i=0; i<size; i++){
		        if(input_name==sarr[i].Cust_name){
			        double loan_bal=(loan_amt*loan_rate*loan_time)/100;
			        double EMI=(loan_amt+loan_bal)/(loan_time*12);
			        cout<<"Your monthly EMI is:"<<EMI<<endl;
		        }
			    else{
       	    	    cout<<"Error \n Name doesn't match";
       	    	}
		        break;
		  	
            }
        }
};
void display(Loan L){
    cout<<"Interest rate is "<<L.loan_rate<<"% \n";
    }
    
class Acc_details:public SBI{
    private:
        string Dsgn;
        int PassCode=1260;
        int a=3;
    public:
        int unsigned long long Account_no;
        
        Acc_details(string Dsgn){
            this->Dsgn=Dsgn;
        }
        void Disp_details(SBI* sarr,int size){
            int temp_pass;
            if(Dsgn=="Manager"){
                cout<<"enter the pass code:";
                cin>> temp_pass;
                if(temp_pass==PassCode){
                    for(int i=0;i<size;i++){
                        cout<<"Account details of Account holder"<<i+1<<":"<<"\n";
                        cout<<"Branch Name:"<<sarr[i].Br_name<<"\n";
                        cout<<"name:"<<sarr[i].Cust_name<<"\n";
                        cout<<"Account number:"<<sarr[i].Acc_no<<"\n";
                        cout<<"Account balance:"<<sarr[i].Acc_bal<<"\n\n";
                    }
                }
                else{
                    cout<<"incorrect pass code\n";
                    a=a-1;
                    if(a>0){
                        cout<<"re-enter the pass code\n";
                        Disp_details(sarr,size);
                    }
                    else{
                        cout<<"you lost your all three chances";
                        exit(0);
                    }
                }
            }
            else if(Dsgn=="Customer"){
              string name;
              int sec_pin;
                cout<<"enter your name:";
                cin>>name;
                for(int i=0; i<size; i++){
       	    	    if(name==sarr[i].Cust_name){
                     cout<<"user exists with this name\n";
                     cout<<"enter your security pin:";
                     cin>>sec_pin;
                     if(sec_pin==sarr[i].pin){
                        cout<<"Branch Name:"<<sarr[i].Br_name<<"\n";
                        cout<<"name:"<<sarr[i].Cust_name<<"\n";
                        cout<<"Account number:"<<sarr[i].Acc_no<<"\n";
                        cout<<"Account balance:"<<sarr[i].Acc_bal<<"\n";
                     } 
                  }
                  else{
                      cout<<"no such user found with this Account number\n";
                  }
                  break;
                }
            }
            else{
                cout<<"wrong designation\n";
            }
        }
        ~Acc_details(){}
};

int main(){
  int N;
  string Cust_name;
  int unsigned long long Acc_no;
  int unsigned long Mob_no;
  double Acc_bal;
	string DOB;
	string Br_name;
	string Dsgn;
  int pin;
    
	cout<<"enter the number of customers who want to create their account:";
  cin>>N;
	SBI* sarr= new SBI[N];
  for(int i=0;i<N;i++){
    cout<<"enter your prefered branch name....1)Br_delhi  2)Br_lucknow Br_jaipur:";
		cin>>Br_name;
		cout<<"enter your name:";
		cin>>Cust_name;
		cout<<"enter your mobile number:";
		cin>>Mob_no;
		cout<<"enter your date of birth:";
		cin>>DOB;
    cout<<"enter the security pin:";
    cin>>pin;
		cout<<"enter your Account balance for creating account:";
		cin>>Acc_bal;
		Acc_no=Acc_no_gen()+i;
    sarr[i]= SBI(Br_name ,Cust_name, Acc_no, Mob_no, DOB, Acc_bal,pin);
  }
    
	string name;
	double amount;
	float loan_rate=9.5;
  int choice;
  cout<<"Enter 1 for depositing money,\n,Enter 2 for withdrawing money,\n,Enter 3 for taking loan,\n,Enter 4 for displaying Account Details\n";
  cin>>choice;
  switch(choice){
	    case 1:{
		    cout<<"Enter your name";
		    cin>>name;
		    cout<<"Enter your amount";
		    cin>>amount;
		    Deposit_money D=Deposit_money(name,amount);
		    D.Deposit(sarr,N);
		    break;
	    }
      case 2:{
    	    cout<<"Enter your name";
		    cin>>name;
		    cout<<"Enter your amount";
		    cin>>amount;
            Withdrawal_money W=Withdrawal_money(name,amount);
            try {
                if(amount==0)
                    throw runtime_error("Invalid withdrawing amount error!");
                else if(amount>25000)
                    throw runtime_error("Withdrawing limit exceeded error!");
                else
                    Withdrawal_money W=Withdrawal_money(name,amount);
                    W.Withdrawal(sarr,N);
            } 
            catch (runtime_error e){
                cerr<<e.what();
            }
		    break;
	    }
	    case 3:{
	        cout<<"Enter your name";
		    cin>>name;
		    cout<<"Enter your loan amount";
		    cin>>amount;
		    Loan L= Loan(name,amount,loan_rate);
		    L.Loan_cal(sarr,N);
		    display(L);
		    break;
	    }
	    case 4:{
            cout<<"are you a Manager or a Customer:";
            cin>>Dsgn;
            Acc_details A=Acc_details(Dsgn);
            A.Disp_details(sarr,N);
            break;
      }
	
	}
    return 0;
}