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
			cout << "====================" << endl;

		}
		void setName(string firstName,string lastName){
			this->firstName = firstName;
			this->lastName = lastName;
		}
		void details(){
			cout<<"Name : "<<firstName<<" "<<lastName<<endl;
			cout<<"Balance : "<<balance<<endl;
			cout << "====================" << endl;
		}
		void history(int amount){
			transactions.push_back(amount);
		}
		int getBalance(){
			return balance;
		}
		int debit(int amount){
			if(amount>balance){
				cout<<firstName<<" "<<lastName<<" : Low Balance"<<endl;
				return 0;
			}
			history(-amount);
			balance -= amount;
			cout<<firstName<<" "<<lastName<<" : Balance Debited"<<endl;
			return amount;
		}
		void deposit(int amount){
			history(amount);
			balance += amount;
			cout<<firstName<<" "<<lastName<<" : Balance Deposited"<<endl;
		}
		void Pay(GPAY& RP,int amount){
			int money = debit(amount);
			if(money==0){
				return ;
			}
			RP.deposit(money);
			cout<<"Payed to : "<<firstName<<" "<<lastName<<endl;
			cout<<"Transaction Completed"<<endl;
		}
		
	
};

int main() {
    // Creating 5 users
    GPAY P1("Subham", "Kumar");
    GPAY P2("Joshy", "Thakur");
    GPAY P3("Rahul", "Sharma");
    GPAY P4("Aman", "Verma");
    GPAY P5("Arjun", "Singh");

    cout << "====================" << endl;
    // Giving initial balances
    P1.deposit(2000);
    P2.deposit(1000);
    P3.deposit(3000);
    P4.deposit(500);
    P5.deposit(2500);

    cout << "====================" << endl;

    // Joshy debits 500
    P2.debit(500);

    cout << "====================" << endl;

    // Subham pays Joshy 1000
    P1.Pay(P2, 1000);

    cout << "====================" << endl;

    // Rahul pays Aman 1200
    P3.Pay(P4, 1200);

    cout << "====================" << endl;

    // Arjun pays Rahul 700
    P5.Pay(P3, 700);

    cout << "====================" << endl;

    // Final details
    cout << "Subham: "<<endl;
    P1.details();

    cout << "Joshy: "<<endl;
    P2.details();

    cout << "Rahul: "<<endl;
    P3.details();

    cout << "Aman: "<<endl;
    P4.details();

    cout << "Arjun: "<<endl;
    P5.details();

    return 0;
}
