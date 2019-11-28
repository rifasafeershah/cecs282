class Complex
{
    public:
        Complex();
        Complex(int r, int i, int d);
        int re; //real part of a complex number
        int im; //imaginary part of a complex number
        int dem; //denominator part of a complex number
        string toString() const; //Format [re + imi]/dem
};

//Overloading operator for easy arithmetic
Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
ostream& operator<< (ostream& stream, Complex a);

//Find gcd and lcm to reduce fraction and add fraction
int gcd(int a, int b);
int lcm(int a, int b);
