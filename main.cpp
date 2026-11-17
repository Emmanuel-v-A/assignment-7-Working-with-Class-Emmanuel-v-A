#include<iostream>
#include<cmath>
class Electric_field
{
    private:
	double *E;
    public:
	Electric_field()
	{
	    E = new double[3];
	    E[0] = 0;
	    E[1] = 0;
	    E[2] = 0;
	}
	~Electric_field(){delete[] E;}
	Electric_field(double x, double y, double z)
	{
	    E = new double[3];
	    E[0] = x;
	    E[1] = y;
	    E[2] = z;
	}

	double getX(){return E[0];}
	void setX(double x){E[0] = x;}
	double getY(){return E[1];}
	void setY(double y){E[1] = y;}
	double getZ(){return E[2];}
	void setZ(double z){E[2] = z;}

	double calculateMagnitude()//sqrt x^2 + y^2 + z^2
	{
            double magnitude = std::sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
	    return magnitude;
	}

        double innerproduct()// x^2 + y^2 + z^2
        {
	    double inner = (E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
            std::cout << "inner product: "<< inner << "\n";
            return inner;
        }

};

class Magnetic_field
{
    private:
	double *M;
    public:
	Magnetic_field()
	{
	    M = new double[3];
	    M[0] = 0;
	    M[1] = 0;
	    M[2] = 0;
	}
	~Magnetic_field(){delete[] M;}
	Magnetic_field(double x, double y, double z)
	{
	    M = new double[3];
	    M[0] = x;
	    M[1] = y;
	    M[2] = z;
	}

	double getX(){return M[0];}
	void setX(double x){M[0] = x;}
	double getY(){return M[1];}
	void setY(double y){M[1] = y;}
	double getZ(){return M[2];}
	void setZ(double z){M[2] = z;}

	double calculateMagnitude()//sqrt x^2 + y^2 + z^2
	{
            double magnitude = std::sqrt(M[0] * M[0] + M[1] * M[1] + M[2] * M[2]);
	    return magnitude;
        }   
     
        void unitVector()// x y z / magnitude
        {
            double magnitude = calculateMagnitude();
            std::cout <<" unit vector " << M[0] / magnitude << "," << M[1] / magnitude << "," << M[2] / magnitude << "\n";
        }
};

int main()
{
    Electric_field E_default;
    E_default.setX(1);
    E_default.setY(2);
    E_default.setZ(3);
    Electric_field E_components(1e5, 10.9, 1.7e2);
    Magnetic_field M_default;
    M_default.setX(3);
    M_default.setY(4);
    M_default.setZ(5);
    Magnetic_field M_components(6, 7, 8);

    std::cout << "E_default: " << E_default.calculateMagnitude() << "\n";
    std::cout << "E_components: " << E_components.calculateMagnitude() << "\n";
    std::cout << "M_default: " << M_default.calculateMagnitude() << "\n";
    std::cout << "M_components: " << M_components.calculateMagnitude() << "\n";
    E_default.innerproduct();
    std::cout << "\n component";
    E_components.innerproduct();
    M_default.unitVector();
    std::cout << "\n component";
    M_components.unitVector();

    return 0;
}
