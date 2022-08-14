#include <iostream>
using namespace std;
class PayTax{
	public:
		PayTax();
		~PayTax();
		void Tax(int);
	private:
		int Salary[12];
		int taxMoney;
};

PayTax::PayTax(){
	int i = 0;
	for(i = 0;i < 12;i ++)Salary[i] = 0;
	taxMoney = 0;
}

PayTax::~PayTax(){

}

void PayTax::Tax(int nUser){
	int i = 0, j = 0;
	for(i = 0;i < nUser;i ++){
		cout << "User" << i + 1 << "'s salary per month:";
		for(j = 0;j < 11;j ++){
			cin >> Salary[j];
			cout << Salary[j] << " ";
		}
		cin >> Salary[j];
		cout << Salary[j] << endl;
		for(j = 0;j < 12;j ++)
			taxMoney += Salary[j];
		taxMoney = taxMoney / 20;
		cout << "User" << i + 1 << " has to pay $" << taxMoney << " this year ." << endl;
		cout << "==========" << endl;
		taxMoney = 0;
	}
}

int main(){
	PayTax tax;
	int nUser = 0;
	int i = 0;

	cin >> nUser;
	tax.Tax(nUser);

	return 0;
}
