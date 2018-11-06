#include <stdio.h>
int main()
{
    int yearly_salary = 0;
	int monthly_budget = 0;
	int savings_goal = 0;
	int months_to_goal = 0;
	
	int basic_salary = 0;
	int higher_salary = 0;
	int additional_salary = 0;
	int salary_after_tax = 0;
	
	int monthly_income = 0;
	int disposable_income = 0;
	
	int cutoff_1 = 11850;
	int cutoff_2 = 46350;
	int cutoff_3 = 150000;
	
	int student_tax_cutoff = 25000;
	int student_tax_payment = 0;

    printf("Yearly salary: ");
    scanf("%d", &yearly_salary);
    printf("Monthly budget: ");
    scanf("%d", &monthly_budget);
    printf("Savings goal: ");
    scanf("%d", &savings_goal);

    if (yearly_salary >= cutoff_1)
	{
		basic_salary = yearly_salary - cutoff_1;
		if (yearly_salary >= cutoff_2)
		{
			basic_salary = cutoff_2 - cutoff_1;
			higher_salary = yearly_salary - cutoff_2;
			if (yearly_salary >= cutoff_3)
			{
				higher_salary = cutoff_3 - cutoff_2;
				additional_salary = yearly_salary - cutoff_3;
			}
		}
		salary_after_tax = cutoff_1 + 0.8*basic_salary + 0.6*higher_salary + 0.55*additional_salary;
	}
	else 
	{
		salary_after_tax = yearly_salary;
	}
	
	if (yearly_salary >= student_tax_cutoff)
	{
		student_tax_payment = 0.09 * (yearly_salary - student_tax_cutoff);
	}
	
	salary_after_tax = salary_after_tax - student_tax_payment;
	monthly_income = salary_after_tax / 12;
	disposable_income = monthly_income - monthly_budget;
	months_to_goal = (savings_goal / disposable_income) + 1;
	
	printf("Yearly income after tax will be %d \n", salary_after_tax);
	printf("Student loan payment per month will be %d \n", student_tax_payment/12);
	printf("Monthly income after rent will be %d \n", disposable_income);
	printf("Months to savings goal will be %d \n", months_to_goal);
	
    
    return 0;
}