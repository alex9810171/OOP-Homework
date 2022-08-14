#include <iostream>

using namespace std;

class MOB{
	public:
		MOB();
		~MOB();

		void Input();
		int Command();
		void doAtk();
		void beAtked();
		void showHP();
	
	protected:
	private:
		string m_sCategory;
		string m_sName;
		int m_nHP;
		float m_fATK;
		float m_fDEF;
		string m_sCommand;
};

MOB::MOB(){
	m_sCategory = "";
	m_sName = "";
	m_nHP = -1;
	m_fATK = -1;
	m_fDEF = -1;
	m_sCommand = "";	
}

MOB::~MOB(){

}

void MOB::Input(){
	cin >> m_sCategory;
	cin >> m_sName;
	cin >> m_nHP;
	if(m_nHP < 0)m_nHP = 0;
	cin >> m_fATK;
	cin >> m_fDEF;
	cin >> m_sCommand;
}

int MOB::Command(){
	if(m_sCommand == "Attack") return 1;
	else if(m_sCommand == "UnderAttack") return 2;
	else if(m_sCommand == "ShowHP") return 3;
	else return 0;
}

void MOB::doAtk(){
	int nATK = 0;

	nATK = (m_fATK + m_nHP) / 2;
	
	cout << m_sName;
	cout << " caused ";
	cout << nATK;
	cout << " points damage" << endl;
}

void MOB::beAtked(){
	int nOAtk = 0, nUAtk = 0;
	
	cin >> nUAtk;
	nUAtk = 2 * nUAtk / m_fDEF;

	cout << m_sName;
	cout << " is damaged by ";
	cout << nUAtk;
	cout << " points" << endl;
}

void MOB::showHP(){
	cout << m_sName;
	cout << " currently has ";
	cout << m_nHP;
	cout << " points of HP" << endl;
}


int main(){
	int nCommand = 0;
	MOB doit;

	doit.Input();
	nCommand = doit.Command();
	if(nCommand == 1) doit.doAtk();
	else if(nCommand == 2) doit.beAtked();
	else if(nCommand == 3) doit.showHP();

	return 0;
}

