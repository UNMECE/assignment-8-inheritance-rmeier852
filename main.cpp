#include<iostream>
#include<cmath>
using namespace std;

double Enot=8.85e-12;
double mu=1.26e-6;

class Field
{
	protected:
                double *value;
        public:
                //Default constructors
		Field() {value=new double[3]; value[0]=0; value[1]=0; value[2]=0;}
		//parametrized Constructor
		Field(double x, double y, double z) {value=new double[3]; value[0]=x; value[1]=y; value[2]=z;}
                //destructors
		~Field(){cout<<"Deconstructor Called"<<endl; delete[]value;}
                //create Function
                void printMagnitude()
                {
			cout<<"Value of Field:"<<endl;
                        cout<<"("<<value[0]<<", "<<value[1]<<", "<<value[2]<<")"<<endl;
                }
};

class Electric_Field:public Field
{
        private:
                double E;

        public:
		//Default Constructor
                Electric_Field():Field(){}
		//Parameterized Constructor
		Electric_Field(double x, double y, double z):Field(x,y,z){}
		//deconstructor
		~Electric_Field(){}

		//function to calculate E
		void calcElectricField(double r, double Q)
		{
			double temp=0;
			temp=4*M_PI*(pow(r,2))*Enot;
			E=Q/temp;
		}

		Electric_Field operator+(const Electric_Field& other) const
		{
			Electric_Field temp;
			temp.value[0]=this->value[0] + other.value[0];
			temp.value[1]=this->value[1] + other.value[1];
			temp.value[2]=this->value[2] + other.value[2];

			return temp;
		}

		friend ostream& operator<<(ostream& os, const Electric_Field& e1)
		{
			os<<"Electric Field Values:\n"<<"("<<e1.value[0]<<", "<<e1.value[1]<<", "<<e1.value[2]<<")\n"<<"E Value:"<<e1.E;
			return os;
		}
};

class Magnetic_Field:public Field
{

        private:
                double M;

        public:
                //Default Constructor
                Magnetic_Field():Field(){}
                //Parameterized Constructor
                Magnetic_Field(double x, double y, double z):Field(x,y,z){}
                //deconstructor
                ~Magnetic_Field(){}

                //function to calculate M
                void calcMagneticField(double r, double I)
                {
                        double temp=0.0;
			temp=2*M_PI*r*mu;
			M=I/temp;
                }
		
		Magnetic_Field operator+(const Magnetic_Field& other) const
                {
                        Magnetic_Field temp;
                        temp.value[0]=this->value[0] + other.value[0];
                        temp.value[1]=this->value[1] + other.value[1];
                        temp.value[2]=this->value[2] + other.value[2];

                        return temp;
                }

                friend ostream& operator<<(ostream& os, const Magnetic_Field& m1)
                {
                        os<<"Magnetic Field Values:\n"<<"("<<m1.value[0]<<", "<<m1.value[1]<<", "<<m1.value[2]<<")\n"<<"M Value:"<<m1.M;
                	return os;
		}
};

int main()
{
	Electric_Field e1(1.4, 2e-4, 3e2);
	Electric_Field e2(4e6, 3.7, 9e-2);
	double Q1=2.5, Q2=9e3, re1=0.25, re2= 2.3;

	Magnetic_Field m1(8.9, 3.22, 3e4);
	Magnetic_Field m2(6.7, 4e2, 1.222);
	double I1=3.6, I2=4e8, rm1=0.5, rm2=5.4;

	e1.printMagnitude();
	e2.printMagnitude();

	m1.printMagnitude();
	m2.printMagnitude();

	e1.calcElectricField(re1, Q1);
	e2.calcElectricField(re2, Q2);

	m1.calcMagneticField(rm1, I1);
	m1.calcMagneticField(rm2, I2);
	
	Electric_Field e3=e1+e2;
	double re3=9.6, Q3=34.55;
	
	cout<<e1<<endl;
	cout<<e2<<endl;
	cout<<e3<<endl;

	Magnetic_Field m3=m1+m2;
	double rm3=5.8, I3=9.99;
	m3.calcMagneticField(rm3,I3);

	cout<<m1<<endl;
	cout<<m2<<endl;
	cout<<m3<<endl;

	return 0;
}
