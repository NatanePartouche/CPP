#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>

class Complex {
private:
    double real;   // Real part
    double imag;   // Imaginary part
public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Getters
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Setters
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    // Addition operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication operator
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,  // Real part
            real * other.imag + imag * other.real   // Imaginary part
        );
    }

    // Division operator
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex(
            (real * other.real + imag * other.imag) / denominator,  // Real part
            (imag * other.real - real * other.imag) / denominator   // Imaginary part
        );
    }

    // Equality operator
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Inequality operator
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }


    // Ajoutez cette méthode pour comparer deux objets Complex
    bool operator>(const Complex& other) const {
        // Comparaison par la norme du nombre complexe (racine carrée de la somme des carrés des parties réelle et imaginaire)
        return (this->real * this->real + this->imag * this->imag) >
               (other.real * other.real + other.imag * other.imag);
    }

    // Vous pouvez aussi ajouter d'autres opérateurs si nécessaire
    bool operator<(const Complex& other) const {
        return (this->real * this->real + this->imag * this->imag) <
               (other.real * other.real + other.imag * other.imag);
    }

    // Stream output operator
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }
};

#endif // COMPLEX_HPP