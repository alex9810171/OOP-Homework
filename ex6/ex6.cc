#include <iostream>
using namespace std;
class Complex{
	public:
		Complex();
		Complex operator+(Complex temp);
		Complex operator-(Complex temp);
		Complex operator*(Complex temp);
		Complex operator/(Complex temp);
		Complex &operator++();
		Complex operator++(int);
		Complex &operator--();
		Complex operator--(int);
		void PN();

		double real, image;
};

Complex::Complex(){
	real = 0;
	image = 0;
}

Complex Complex :: operator+(Complex temp){
	Complex end;
	end.real = real + temp.real;
	end.image = image + temp.image;
	return end;
}

Complex Complex :: operator-(Complex temp){
	Complex end;
	end.real = real - temp.real;
	end.image = image - temp.image;
	return end;
}

Complex Complex :: operator*(Complex temp){
	Complex end;
	end.real = real * temp.real - image * temp.image;
	end.image = real * temp.image + image * temp.real;
	return end;
}

Complex Complex :: operator/(Complex temp){
	Complex end;
	end.real = (real * temp.real + image * temp.image) / (temp.real * temp.real + temp.image * temp.image);
	end.image = (image * temp.real - real * temp.image) / (temp.real * temp.real + temp.image * temp.image);
	return end;
}

Complex &Complex :: operator++(){
	real = real + 1;
	image = image + 1;
	return *this;
}

Complex Complex :: operator++(int){
	Complex output;
	output.real = real;
	output.image = image;
	real = real + 1;
	image = image + 1;
	return output;
}

Complex &Complex :: operator--(){
	real = real - 1;
	image = image - 1;
	return *this;
}

Complex Complex :: operator--(int){
	Complex output;
	output.real = real;
	output.image = image;
	real = real - 1;
	image = image - 1;
	return output;
}

void Complex :: PN(){
	if(image >= 0) cout << '+';
}

int main(){
	Complex count[2], result;

	for(int i = 0;i < 2;i ++){
		cin >> count[i].real >> count[i].image;
	}
	cout << "C1 = " << count[0].real; 
	count[0].PN();
	cout << count[0].image << "i" << endl;
	cout << "C2 = " << count[1].real;
	count[1].PN();
	cout << count[1].image << "i" << endl;
	result = count[0] + count[1];
	cout << "C1+C2 = " << result.real;
	result.PN();
	cout << result.image << "i" << endl;
	result = count[0] - count[1];
	cout << "C1-C2 = " << result.real;
	result.PN();
	cout << result.image << "i" << endl;
	result = count[0] * count[1];
	cout << "C1*C2 = " << result.real;
	result.PN();
	cout << result.image << "i" << endl;
	result = count[0] / count[1];
	cout << "C1/C2 = " << result.real;
	result.PN();
	cout << result.image << "i" << endl;
	result = count[0]++;
	cout << "C1++ = " << result.real;
	result.PN();
	cout << result.image << "i" << endl;
	result = count[0]++;
	cout << "C1++ = " << result.real;
	result.PN();
	cout << result.image << "i" << endl;
	++count[0];
	cout << "++C1 = " << count[0].real;
	count[0].PN();
	cout << count[0].image << "i" << endl;
	++count[0];
	cout << "++C1 = " << count[0].real;
	count[0].PN();
	cout << count[0].image << "i" << endl;
	result = count[1]--;
	cout << "C2-- = " << result.real;
	result.PN();
	cout << result.image << "i" << endl;
	result = count[1]--;
	cout << "C2-- = " << result.real;
	result.PN();
	cout << result.image << "i" << endl;
	--count[1];
	cout << "--C2 = " << count[1].real;
	count[1].PN();
	cout<< count[1].image << "i" << endl;
	--count[1];
	cout << "--C2 = " << count[1].real;
	count[1].PN();
	cout << count[1].image << "i" << endl;
	return 0;
}
