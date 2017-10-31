#include<iostream>
#include<ctime>
#include<cmath>
#include<fstream>
#include<vector>
#include<array>
#include<string>
#include<sstream>
//#include<native/task.h> //need to find out how to fix this.
using namespace std;

class IoPin{
//could add  owned-by property by adding a pointer
private:
int pinNumber;
public:
	IoPin(int pin){
 		 initPin();
		pinNumber=pin;
		 setDirection(1);//1 is writing, 0 is reading
}
//initialise pin
void initPin(){
	ofstream myfile;
	myfile.open ("/sys/class/gpio/export");
	myfile << pinNumber ;
	myfile.close();
}
//set direction of pin
void setDirection(bool isOutput){
std::stringstream file_name;
file_name << "/sys/class/gpio/gpio" <<pinNumber << "/direction";
ofstream myfile;
myfile.open(file_name.str());
if(!myfile){
std::cout << "Could not write to gpio file";
return;
}
if(isOutput){
myfile << "out" ;
}
else{
myfile << "in";
}

myfile.close();


std::cout<<file_name.str();
}

//method to write to GPIO pin (May need to be improved, file ia now opened and closed every execution loop
int setValue(string value){
    std::stringstream  setval;
setval <<  "/sys/class/gpio/gpio" <<  pinNumber << "/value";
    ofstream setvalgpio(setval.str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< pinNumber <<" ."<< endl;
            return -1;
        }
        setvalgpio << value ;//write value to value file
        setvalgpio.close();// close value file
        return 0;
}



};


class Motor {
public:
    Motor(int maxVel, int maxAcc, int jerk,int dirPinNum,int stepPinNum){
       m_maxVel = maxVel;
       m_maxAcc = maxAcc;
       m_jerk = jerk;
       IoPin dirPin(dirPinNum);
       IoPin stepPin(stepPinNum);
	pins.push_back(dirPin);
        pins.push_back(stepPin);
    }

private:
    int m_maxVel;
    int m_maxAcc;
    int m_jerk;
    std::vector<IoPin> pins;

public:
void rotate(int steps,bool direction){
IoPin(0).setValue("1");
for (int i=0; i<steps;i++){
std::cout << "step: " << i <<"\n";
}
}

};

class Builderclass {
public:
		Builderclass(){
			int dirPin=17;
			int stepPin=18;
			int maxVel=10;
			int maxAcc=10;
			int jerk=10;
			Motor motor1(maxVel,maxAcc,jerk,dirPin,stepPin);
			motor1.rotate(200,1);//Test if basic motor rotation works.
}
};



int main(){
	Builderclass builder;
	clock_t t;
	t=clock();
	sqrt(6666666);
	t = clock() - t;
	cout << t  << "\n";
	return 0;
}





