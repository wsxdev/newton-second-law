#include <iostream>
using namespace std;

// FUNCIÓN PARA MOSTRAR EL MENÚ PRINCIPAL
void mostrarMenu() {
    //system("clear");
    cout << "RESOLUCIÓN DE PROBLEMAS: SEGUNDA LEY DE NEWTON\n";
    cout << "1. Calcular fuerza\n";
    cout << "2. Calcular aceleración\n";
    cout << "3. Calcular masa\n";
    cout << "4. Salir\n";
    cout << "\nSeleccione una opción: ";
}

// FUNCIÓN PARA CALCULAR LA FUERZA
double calcularFuerza(double masa, double aceleracion) {
    return masa * aceleracion;
}

// FUNCIÓN PARA CALCULAR LA ACELERACIÓN
double calcularAceleracion(double fuerza, double masa) {
    return fuerza / masa;
}

// FUNCIÓN PARA CALCULAR LA MASA
double calcularMasa(double fuerza, double aceleracion) {
    return fuerza / aceleracion;
}

// FUNCIÓN PRINCIPAL
int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        double fuerza, masa, aceleracion;
        switch (opcion) {
            case 1:
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                cout << "Ingrese la aceleración (m/s²): ";
                cin >> aceleracion;
                cout << "La fuerza es: " << calcularFuerza(masa, aceleracion) << " N\n";
                break;
            case 2:
                cout << "Ingrese la fuerza (N): ";
                cin >> fuerza;
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                if (masa == 0) {
                    cout << "Error: La masa no puede ser cero.\n";
                } else {
                    cout << "La aceleración es: " << calcularAceleracion(fuerza, masa) << " m/s²\n";
                }
                break;

            // CALCULO DE LA MASA - MAEL-MC
            case 3:
                cout << "Ingrese la fuerza (N): ";
                cin >> fuerza;
                cout << "Ingrese la aceleracion (m/s^2): ";
                cin >> aceleracion;
                if (aceleracion == 0) {
                    cout << "Error: La aceleracion no puede ser cero.\n";
                } else {
                    cout << "La masa es: " << calcularMasa(fuerza, aceleracion) << " kg\n";
                }
                break;
            case 4:
                cout << "Saliendo del programa. ¡Gracias!\n";
                break;
            default:
                system("clear");
                cout << "Opción no válida. Intente de nuevo.\n\n";
        }
    } while (opcion != 4);

    return 0;
}
