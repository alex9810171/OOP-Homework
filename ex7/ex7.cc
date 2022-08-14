#include <iostream>
using namespace std;
class Room{
	public:
		Room();
		int id, posX, posY;
		string name, description, forCategory;
};

Room::Room(){
	id = 0;
	posX = 0;
	posY = 0;
}

int main(){
	int nRooms = 0, nowX = 0, nowY = 0;
	cin >> nRooms;
	Room room[nRooms];
	for(int i = 0;i < nRooms;i ++){
		cin >> room[i].id >> room[i].name >> room[i].posX
			>> room[i].posY >> room[i].description
			>> room[i].forCategory;
	}
	char direction = '\0';
	for(int i = 0;i <= 3;i ++){
		int findRoom = 0, find = 0;
		for(findRoom = 0;findRoom < nRooms;findRoom ++)
			if(room[findRoom].posX == nowX && room[findRoom].posY == nowY){
				find = 1;
				break;
			}
		if(find == 0){
			if(direction == 'n') nowY--;
			else if(direction == 'w') nowX++;
			else if(direction == 'e') nowX--;
			else nowY ++;
			for(findRoom = 0;findRoom < nRooms;findRoom ++)
				if(room[findRoom].posX == nowX && room[findRoom].posY == nowY){
					find = 1;
					break;
				}
		}
		cout << "Room#" << room[findRoom].id << endl;
		cout << room[findRoom].name << endl;
		cout << "(" << room[findRoom].posX
			<< "," << room[findRoom].posY << ")" << endl;
		cout << room[findRoom].description << endl;
		cout << room[findRoom].forCategory << endl;
		cin >> direction;
		if(direction == 'n') nowY++;
		else if(direction == 'w') nowX--;
		else if(direction == 'e') nowX++;
		else nowY --;
	}
	return 0;
}
