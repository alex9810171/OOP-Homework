#include <iostream>

using namespace std;

class MOB{
	public:
		MOB();
		~MOB();

		void Input();
		int doAtk();
		int beAtked(int out_atk, string sCat);
		int showHP();
		string showName();
		string showCategory();

	private:
		string m_sCategory;
		string m_sName;
		int m_nHP;
		float m_fATK;
		float m_fDEF;
};

MOB::MOB(){
	m_sCategory = "";
	m_sName = "";
	m_nHP = -1;
	m_fATK = -1;
	m_fDEF = -1;
}

MOB::~MOB(){

}

void MOB::Input(){
	cin >> m_sCategory;
	cin >> m_sName;
	cin >> m_nHP;
	cin >> m_fATK;
	cin >> m_fDEF;
	if(m_nHP < 0)m_nHP = 0;
	if(m_fATK < 0)m_fATK = 0;
	if(m_fDEF < 0)m_fDEF = 0;
}

int MOB::doAtk(){
	return (m_fATK + m_nHP) / 2;
}

int MOB::beAtked(int out_atk, string sCat){
	int getDamage = 0;
	if(m_sCategory == "Human" && sCat == "Pet")
		getDamage = out_atk * (1) / 10 + 2 * out_atk / m_fDEF;
	else if(m_sCategory == "Pet" && sCat == "Human")
		getDamage = out_atk * (-1) / 10 + 2 * out_atk / m_fDEF;
	else
		getDamage = 2 * out_atk / m_fDEF;
	if(getDamage < 0) getDamage = 0;
	m_nHP = m_nHP - getDamage;
	if(m_nHP < 0) m_nHP = 0;
	
	return getDamage;
}

int MOB::showHP(){
	if(m_nHP != 0){
		cout << m_sName << " currently has " << m_nHP << " points of HP" << endl;
		return 1;
	}
	else {
		cout << m_sName << " has been dead, game is over" << endl;
		return 0;
	}
}

string MOB::showName(){
	return m_sName;
}

string MOB::showCategory(){
	return m_sCategory;
}

int main(){
	int time = 0, playTime = 0;

	cin >> time;
	MOB mob[time];
	for(int i = 0;i < time;i ++)
		mob[i].Input();
	for(playTime = 0; ;playTime ++){
		int a = playTime % 2, b = playTime % 2 + 1;
		if(b == 2) b = 0;

		cout << mob[a].showName() << " caused " << mob[a].doAtk() << " points damage" << endl;
		cout << mob[b].showName() << " is damaged by " << mob[b].beAtked(mob[a].doAtk(),mob[a].showCategory()) << " points" << endl;
		if(mob[b].showHP() == 0) break;
	}

	return 0;
}

