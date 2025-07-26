#include stdio.h

int main() {
    int choice;
    float balance = 1000.00, amount;

    while(1) {
        printf(n=== ATM MENU ===n);
        printf(1. View Balancen);
        printf(2. Deposit Moneyn);
        printf(3. Withdraw Moneyn);
        printf(4. Exitn);
        printf(Enter your choice );
        scanf(%d, &choice);

        switch(choice) {
            case 1
                printf(Your Balance ₹%.2fn, balance);
                break;
            case 2
                printf(Enter amount to deposit ₹);
                scanf(%f, &amount);
                balance += amount;
                printf(Deposit Successful!n);  
                break;
            case 3
                printf(Enter amount to withdraw ₹);
                scanf(%f, &amount);
                if(amount = balance) {
                    balance -= amount;
                    printf(Withdrawal Successful!n);
                } else {
                    printf(Insufficient Balance!n);
                }
                break;
            case 4
                printf(Thank you! Visit Again.n);
                return 0;  ends the program
            default
                printf(Invalid Choice!n);
        }
    }

    return 0;
}

