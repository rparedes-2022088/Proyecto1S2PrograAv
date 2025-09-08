#include <iostream>
#include <string> 
#include <vector>
using namespace std;

class Animal {
public:
    int id;
    string tipo;
    int comidaDiaria;
    int probabilidadCrias;
    int probabilidadEnfermar;
    int estadoAlimentacion;
    float precio;
    bool estado;
    int diasEnfermo;
    string gravedad;
    bool estadoVida;
};

class Ave : public Animal {

};

class Mamifero : public Animal {

};

class Reptil : public Animal {

};

class Pez : public Animal {

};

class Anfibio : public Animal {

};

struct Habitat {
    int id = 0;
    string tipo = "";
    vector<int> asignados;
    vector<string> permitidos;
};

class Zoologico {
public:
    int AlimentarAnimales()
    {
        int costoAlimeto = 50;
        cout << "Costo de unidad de aliemtos: $ 50.00" << endl;
        return costoAlimeto;
    }

    void PantallaZoologico() {

    }

    void generarHabitats(int cantidadAGenerar, Habitat* habitats) {
        int* generados = new int[cantidadAGenerar]();
        int aleatorio;

        for (int i = 0; i < cantidadAGenerar; i++) {
            bool repetido;
            do {
                aleatorio = rand() % 4 + 1;
                repetido = false;
                for (int a = 0; a < i; a++) {
                    if (generados[a] == aleatorio) {
                        repetido = true;
                        break;
                    }
                }
            } while (repetido);
            generados[i] = aleatorio;
            habitats[i].id = i + 1;
            switch (aleatorio) {
            case 1:
                habitats[i].tipo = "Aviario";
                habitats[i].permitidos = { "Ave" };
                break;
            case 2:
                habitats[i].tipo = "Acuario";
                habitats[i].permitidos = { "Pez" };
                break;
            case 3:
                habitats[i].tipo = "Laguna";
                habitats[i].permitidos = { "Anfibio", "Reptil", "Pez" };
                break;
            case 4:
                habitats[i].tipo = "Bosque";
                habitats[i].permitidos = { "Mamifero", "Reptil" };
                break;
            }
        }

        delete[] generados;
    }

    void generarAnimales(int cantidad, Animal* animal, Habitat* habitats) {

    }

};

int main()
{
    int numHabitat;
    int numAnimales;
    int numDias;
    int moneda = 1500;
    Zoologico zoologico;
    string nomZoo;

    cout << "Nombre del juego " << endl;
    cout << "Bienvenido al simulador, configura los siguientes aspectos: " << endl;

    while (true) {
        cout << "Numero de habitat (maximo de habitatas 4): " << endl;
        if (cin >> numHabitat && numHabitat > 0 && numHabitat <= 4) break;
        cout << "Dato no valido. Intente nuevamente. " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Habitat* habitats = new Habitat[numHabitat];
    zoologico.generarHabitats(numHabitat, habitats);

    while (true) {
        cout << "Numero de animales (maximo de animales iniciales 15): " << endl;
        if (cin >> numAnimales && numAnimales > 0 && numAnimales <= 15) break;
        cout << "Dato no valido. Intente nuevamente. " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Animal* animales = new Animal[numAnimales];
    zoologico.generarAnimales(numAnimales, animales, habitats);

    while (true) {
        cout << "Numero de dias para administrar: " << endl;
        if (cin >> numDias && numDias > 0) break;
        cout << "Dato no valido. Intente nuevamente. " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();

    while (true) {
        cout << "Ingrese nombre del zoo: " << endl;
        if (getline(cin, nomZoo) && !nomZoo.empty()) {
            break;
        }
        cout << "Dato no válido. Intente nuevamente." << endl;
    }

    cout << "Cantidad de monedas iniciales: $ " << moneda << ".00 " << endl;
    cout << "!!!Gracias por ingresar los datos iniciales!!!" << endl;
    cout << "Simulacion iniciada. " << endl;

    for (int i = 1; i <= numDias; i++) {
        cout << "Zoologico:  " << nomZoo << ", Dia: " << i << endl;
        cout << "Reporte Animales: " << endl;
    }

    delete[] habitats;
}