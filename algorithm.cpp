#include <iostream>
#include <limits>
#include <cmath> // Para funciones matemáticas como sin() y cos()
using namespace std;

// FUNCIÓN PARA LIMPIAR PANTALLA
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// FUNCIÓN PARA MOSTRAR EL MENÚ PRINCIPAL
void mostrarMenu() {
    limpiarPantalla();
    cout << "=========================================\n";
    cout << " RESOLUCIÓN DE PROBLEMAS: SEGUNDA LEY DE NEWTON\n";
    cout << "=========================================\n";
    cout << "1. Calcular fuerza (F = m * a)\n";
    cout << "2. Calcular aceleración (a = F / m)\n";
    cout << "3. Calcular masa (m = F / a)\n";
    cout << "4. Cálculos en un plano inclinado\n";
    cout << "5. Conversión de unidades\n";
    cout << "6. Salir\n";
    cout << "=========================================\n";
    cout << "Seleccione una opción: ";
}

// FUNCIÓN PARA VALIDAR ENTRADA DE NÚMEROS
double leerNumeroPositivo(const string& mensaje) {
    double numero;
    while (true) {
        cout << mensaje;
        cin >> numero;
        if (cin.fail() || numero <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Por favor, ingrese un número mayor a 0.\n";
        } else {
            return numero;
        }
    }
}

// FUNCIONES PARA TRABAJAR CON GRADOS
double convertirGradosARadianes(double grados) {
    return grados * M_PI / 180;
}

double senoEnGrados(double grados) {
    return sin(convertirGradosARadianes(grados));
}

double cosenoEnGrados(double grados) {
    return cos(convertirGradosARadianes(grados));
}

// FUNCIONES DE CÁLCULO
double calcularFuerza(double masa, double aceleracion) {
    return masa * aceleracion;
}

double calcularAceleracion(double fuerza, double masa) {
    return fuerza / masa;
}

double calcularMasa(double fuerza, double aceleracion) {
    return fuerza / aceleracion;
}

// CÁLCULOS EN UN PLANO INCLINADO
void calculosPlanoInclinado() {
    limpiarPantalla();
    cout << "CÁLCULOS EN UN PLANO INCLINADO\n";
    cout << "=========================================\n";

    // Leer datos iniciales
    double masa = leerNumeroPositivo("Ingrese la masa del objeto (kg): ");
    double angulo = leerNumeroPositivo("Ingrese el ángulo del plano inclinado (grados): ");
    double fuerzaAplicada = leerNumeroPositivo("Ingrese la fuerza aplicada (N): ");

    // Cálculos principales
    double peso = masa * 9.81; // Peso del objeto
    double pesoX = peso * senoEnGrados(angulo); // Componente del peso en x
    double pesoY = peso * cosenoEnGrados(angulo); // Componente del peso en y
    double fuerzaResultante = fuerzaAplicada - pesoX; // Considerando fuerza aplicada

    cout << "\nResultados:\n";
    cout << "Peso del objeto: " << peso << " N\n";
    cout << "Componente del peso en el eje x: " << pesoX << " N\n";
    cout << "Componente del peso en el eje y: " << pesoY << " N\n";
    cout << "Fuerza resultante: " << fuerzaResultante << " N\n";

    // Posibilidad de calcular aceleración o masa
    char opcionExtra;
    cout << "\n¿Desea realizar cálculos adicionales (a = F / m o m = F / a)? (s/n): ";
    cin >> opcionExtra;

    if (opcionExtra == 's' || opcionExtra == 'S') {
        char tipoCalculo;
        cout << "¿Qué desea calcular? (a: aceleración, m: masa): ";
        cin >> tipoCalculo;

        if (tipoCalculo == 'a' || tipoCalculo == 'A') {
            double aceleracion = fuerzaResultante / masa;
            cout << "La aceleración del objeto es: " << aceleracion << " m/s²\n";
        } else if (tipoCalculo == 'm' || tipoCalculo == 'M') {
            double nuevaFuerza = leerNumeroPositivo("Ingrese la nueva fuerza (N): ");
            double nuevaAceleracion = leerNumeroPositivo("Ingrese la nueva aceleración (m/s²): ");
            cout << "La masa del objeto es: " << calcularMasa(nuevaFuerza, nuevaAceleracion) << " kg\n";
        } else {
            cout << "Opción no válida.\n";
        }
    }

    cout << "Presione Enter para regresar al menú principal...";
    cin.ignore();
    cin.get();
}

// FUNCIÓN PRINCIPAL
int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opción no válida. Intente nuevamente.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                limpiarPantalla();
                double masa = leerNumeroPositivo("Ingrese la masa (kg): ");
                double aceleracion = leerNumeroPositivo("Ingrese la aceleración (m/s²): ");
                cout << "La fuerza es: " << calcularFuerza(masa, aceleracion) << " N\n";
                break;
            }
            case 2: {
                limpiarPantalla();
                double fuerza = leerNumeroPositivo("Ingrese la fuerza (N): ");
                double masa = leerNumeroPositivo("Ingrese la masa (kg): ");
                cout << "La aceleración es: " << calcularAceleracion(fuerza, masa) << " m/s²\n";
                break;
            }
            case 3: {
                limpiarPantalla();
                double fuerza = leerNumeroPositivo("Ingrese la fuerza (N): ");
                double aceleracion = leerNumeroPositivo("Ingrese la aceleración (m/s²): ");
                cout << "La masa es: " << calcularMasa(fuerza, aceleracion) << " kg\n";
                break;
            }
            case 4:
                calculosPlanoInclinado();
                break;

            case 5:
                cout << "Funcionalidad en desarrollo.\n";
                break;

            case 6:
                cout << "Saliendo del programa. ¡Gracias por usarlo!\n";
                break;

            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }

        cout << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();

    } while (opcion != 6);

    return 0;
}
