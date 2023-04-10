
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Define a function that calculates the loan payment
void calculate_loan(float* loan, float* interest, float* this_month_interest, float* monthly_payment, float* remaining_monthly_payment);

int main() {
   string def_program = "This program takes loan amount and interest rate as an input and calculates the monthly payment and the remening loan for each month";
   cout<< def_program<<"\n"<<endl;
   program:
   cout<<"Enter the loan amount\t";
   float loan;
   cin>>loan;
  
   cout<<"Inter the interest rate(%)\t";
   float interest;
   cin>>interest;
   interest /= 100;
   float monthly_payment = loan/20;
   float this_month_interest;
   float remaining_month_payment;
   int month = 1;
   if (interest >= 0.6){
      cout <<"This loan can not be paid off forever since the interest rate is greater than or equal to the paying rate";
      goto end_program;
   }
   cout << "\nMONTH \tMONTHLY PAYMENT \tREMAINING LOAN\n";
   cout << "----------------------------------------\n";
    while (loan > 0){
        calculate_loan(&loan, &interest, &this_month_interest, &monthly_payment, &remaining_month_payment);
        
        cout << fixed << setprecision(2) << setw(3) << month;
        cout << fixed << setprecision(2) << setw(17) << monthly_payment;
        cout << fixed << setprecision(2) << setw(18) << loan << endl;
      month += 1;
       
   }
   end_program:
      char choice;
      cout<<"\nDo You Want to Exit (y/n)\t";
      cin>>choice;
      if(choice != 'Y' && choice != 'y')
         goto program;
   
}

void calculate_loan(float* loan, float* interest, float* this_month_interest, float* monthly_payment, float* remaining_monthly_payment) {
    
    *this_month_interest = (*loan * *interest) / 12;

    
    *remaining_monthly_payment = *monthly_payment - *this_month_interest;

    
    if (*loan >= *remaining_monthly_payment) {
        *loan -= *remaining_monthly_payment;
    }
    else {
        *monthly_payment = *loan;
        *loan = 0;
    }
}
