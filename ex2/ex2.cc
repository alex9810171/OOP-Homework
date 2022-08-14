#include <iostream>
using namespace std;
int main(void){
	int i,ans=0;
	int month,date,week,manyday;
	int monthday[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
	int day[13]={0,11,39,67,102,130,165,193,221,256,284,312,347};
	string weekday[8]={"\0","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	string message[13]={
	"\0",
	"Nphone 6 30\% off\n",
	"Nphone 6 50\% off\n",
	"Nphone 6 for free\n",
	"Nphone 6s 30\% off\n",
	"Nphone 6s 50\% off\n",
	"Nphone 6s for free\n",
	"Nphone 7 30\% off\n",
	"Nphone 7 50\% off\n",
	"Nphone 7 for free\n",
	"Nphone 8 30\% off\n",
	"Nphone 8 50\% off\n",
	"Nphone 8 for free\n"};
	while(cin >> month >> date){
		manyday = monthday[month]+date;
		week = manyday%7;
		cout << weekday[week] << endl;
		for(i=1;i<13&&ans==0;i++){
			if(day[i]==manyday)ans=1;
		}
		if(ans==1)cout << message[month];
		else cout << "Sorry, no discount today !" << endl;
		ans=0;
	}
	return 0;
}
