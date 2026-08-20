#include<iostream>
#include<string>
#include<vector>
using namespace std;

class GPAY {
	private:
		int balance = 0;
		vector<int> transactions;
		string firstName;
		string lastName;
	public:
		GPAY(string firstName,string lastName) {
			this->firstName = firstName;
			this->lastName = lastName;
			cout<<"Account Created"<<endl;
			cout<<"Name : "<<firstName<<" "<<lastName<<endl;
			cout<<"Balance : "<<balance<<endl;

		}
		void setName(string firstName,string lastName){
			this->firstName = firstName;
			this->lastName = lastName;
		}
		void details(){
			cout<<"Name : "<<firstName<<" "<<lastName<<endl;
			cout<<"Balance : "<<balance<<endl;
		}
		void history(int amount){
			transactions.push_back(amount);
		}
		int getBalance(){
			return balance;
		}
		int debit(int amount){
			if(amount>balance){
				cout<<"Low Balance"<<endl;
				return 0;
			}
			history(-amount);
			balance -= amount;
			cout<<"Balance Debited"<<endl;
			return amount;
		}
		void deposit(int amount){
			history(amount);
			balance += amount;
			cout<<"Balance Deposited"<<endl;
		}
		void Pay(GPAY& RP,int amount){
			int money = debit(amount);
			if(money==0){
				return ;
			}
			RP.deposit(money);
			cout<<"Transaction Completed"<<endl;
		}
		
	
};

int main(){
	// making 2 persons
	GPAY P1("Subham","Kumar"),P2("Joshy","Thakur");
	cout<<"============="<<endl;
	// giving them initial  balance
	P1.deposit(2000);
	P2.deposit(1000);
	cout<<"============="<<endl;
	// taking 500  from P2 i.e joshy
	P2.debit(500);
	cout<<"============="<<endl;
	// transfering 1000 from   P1  i.e subham to P2 i.e joshy
	P1.Pay(P2,1000);
	cout<<"============="<<endl;
	// printing final details
	P1.details();
	P2.details();
	cout<<"============="<<endl;

	return 0;
}
