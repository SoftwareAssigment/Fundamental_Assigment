//calculate loan interest rate included.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Define a function that calculates the loan payment
void calculate_loan(float* loan, float* interest, float* this_month_interest, float* monthly_payment);

int main() {
   string def_program = "This program takes loan amount and interest rate as an input and calculates the monthly payment and the remaining loan for each month";
   cout<< def_program<<"\n"<<endl;
   program:
   cout<<"Enter the loan amount\t";
   float loan;
   cin>>loan;
  
   cout<<"Enter the interest rate(%)\t";
   float interest;
   cin>>interest;
   interest /= 100;
   float monthly_payment = loan/20;
   float this_month_interest;
   float remaining_month_payment;
   int month = 1;
   // Check if the loan can ever be paid off
   if (interest >= 0.6){
      cout <<"This loan can not be paid off forever since the interest rate is greater than or equal to the paying rate";
      goto end_program;
   }
   cout << "\nMONTH \tMONTHLY PAYMENT \tREMAINING LOAN\n";
   cout << "----------------------------------------\n";
    while (loan > 0)
    {
        calculate_loan(&loan, &interest, &this_month_interest, &monthly_payment);
        
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

void calculate_loan(float* loan, float* interest, float* this_month_interest, float* monthly_payment) {
   //calculate this month's interest, monthly payment and remaining loan
    *this_month_interest = (*loan * *interest) / 12;

    if(*loan + *this_month_interest >= *monthly_payment){
            *loan -= (*monthly_payment - *this_month_interest);
        }

    else{
        *monthly_payment = *this_month_interest + *loan;
        *loan = 0;
    }
    return;
}
