#include <iostream>
using namespace std;

class BaseAccount {
protected:
    double balance;
public:
    BaseAccount(double b) : balance(b) {}
    void SendMoney(double amt) { cout << "Denied: account flagged\n"; }
    virtual void ReceiveMoney(double amt) {
        balance += amt;
        cout << "Received " << amt << " | Balance: " << balance << "\n";
    }
    virtual ~BaseAccount() {}
};

class ConsumerAccount : public BaseAccount {
public:
    ConsumerAccount(double b) : BaseAccount(b) {}
    void SendMoney(double amt) {
        if (amt > balance) { cout << "Denied: insufficient funds\n"; return; }
        balance -= amt;
        cout << "Sent " << amt << " | Balance: " << balance << "\n";
    }
    void ReceiveMoney(double amt) override {
        balance += amt;
        cout << "Received " << amt << " | Balance: " << balance << "\n";
    }
};

int main() {
    ConsumerAccount acc(1000);

    BaseAccount* flagged = &acc;
    flagged->SendMoney(200);
    flagged->ReceiveMoney(500);

    ConsumerAccount* active = static_cast<ConsumerAccount*>(flagged);
    active->SendMoney(200);
}
