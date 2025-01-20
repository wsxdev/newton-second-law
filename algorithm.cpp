#include <iostream>
#include <cmath>
using namespace std;

// Prototipos
void menuPrincipal();
void planoHorizontal();
void planoInclinado();
void menuConvertidor();
void conversionFuerza();
void conversionAceleracion();
void conversionMasa();
void conversionAngulos();

// Función principal
int main() {
    menuPrincipal();
    return 0;
}

// Menú principal
void menuPrincipal() {
    int opcion;
    do {
        cout << "\n========== MENU PRINCIPAL ==========\n";
        cout << "1. Problemas en plano horizontal\n";
        cout << "2. Problemas en plano inclinado\n";
        cout << "3. Convertidor de unidades\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                planoHorizontal();
                break;
            case 2:
                planoInclinado();
                break;
            case 3:
                menuConvertidor();
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 4);
}

// Problemas en plano horizontal
void planoHorizontal() {
    int estado, calcular;
    double masa, fuerza, peso, aceleracion, friccion, normal, coef_friccion, gravedad = 9.81;
    string direccion;

    cout << "\nPLANO HORIZONTAL\n";
    cout << "1. En reposo\n";
    cout << "2. En movimiento\n";
    cout << "Seleccione el estado del cuerpo: ";
    cin >> estado;

    if (estado == 1) {
        cout << "\nEn reposo, puede calcular:\n";
        cout << "1. Peso\n";
        cout << "2. Masa\n";
        cout << "3. Fuerza normal\n";
        cout << "Seleccione lo que desea calcular: ";
        cin >> calcular;

        switch (calcular) {
            case 1:
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                peso = masa * gravedad;
                cout << "El peso es: " << peso << " N\n";
                break;
            case 2:
                cout << "Ingrese el peso (N): ";
                cin >> peso;
                masa = peso / gravedad;
                cout << "La masa es: " << masa << " kg\n";
                break;
            case 3:
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                normal = masa * gravedad;
                cout << "La fuerza normal es: " << normal << " N\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } else if (estado == 2) {
        cout << "\nEn movimiento, puede calcular:\n";
        cout << "1. Aceleracion\n";
        cout << "2. Fuerza de friccion\n";
        cout << "3. Coeficiente de friccion\n";
        cout << "Seleccione lo que desea calcular: ";
        cin >> calcular;

        cout << "Ingrese la direccion del movimiento (izquierda/derecha): ";
        cin >> direccion;

        switch (calcular) {
            case 1:
                cout << "Ingrese la fuerza neta (N): ";
                cin >> fuerza;
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                aceleracion = fuerza / masa;
                cout << "La aceleracion es: " << aceleracion << " m/s^2\n";
                break;
            case 2:
                cout << "Ingrese el coeficiente de friccion: ";
                cin >> coef_friccion;
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                friccion = coef_friccion * masa * gravedad;
                cout << "La fuerza de friccion es: " << friccion << " N\n";
                break;
            case 3:
                cout << "Ingrese la fuerza de friccion (N): ";
                cin >> friccion;
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                coef_friccion = friccion / (masa * gravedad);
                cout << "El coeficiente de friccion es: " << coef_friccion << "\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } else {
        cout << "Estado no valido.\n";
    }
}

// Problemas en plano inclinado
void planoInclinado() {
    int calcular;
    double angulo, masa, peso, normal, fuerza_equilibrio, friccion, coef_friccion, gravedad = 9.81;

    cout << "\nPLANO INCLINADO\n";
    cout << "Puede calcular:\n";
    cout << "1. Fuerza para mantener el equilibrio\n";
    cout << "2. Peso en X\n";
    cout << "3. Peso en Y\n";
    cout << "Seleccione lo que desea calcular: ";
    cin >> calcular;

    switch (calcular) {
        case 1:
            cout << "Ingrese la masa (kg): ";
            cin >> masa;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;
            angulo = angulo * M_PI / 180;  // Convertir a radianes
            fuerza_equilibrio = masa * gravedad * sin(angulo);
            cout << "La fuerza para mantener el equilibrio es: " << fuerza_equilibrio << " N\n";
            break;
        case 2:
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;
            angulo = angulo * M_PI / 180;  // Convertir a radianes
            double pesoX;
            pesoX = peso * sin(angulo);
            cout << "El peso en X es: " << pesoX << " N\n";
            break;
        case 3:
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;
            angulo = angulo * M_PI / 180;  // Convertir a radianes
            double pesoY;
            pesoY = peso * cos(angulo);
            cout << "El peso en Y es: " << pesoY << " N\n";
            break;
        default:
            cout << "Opcion invalida.\n";
    }
}

// Convertidor de unidades
void menuConvertidor() {
    int opcion;
    do {
        cout << "\nCONVERTIDOR DE UNIDADES\n";
        cout << "1. Conversion de fuerza\n";
        cout << "2. Conversion de aceleracion\n";
        cout << "3. Conversion de masa\n";
        cout << "4. Conversion de angulos\n";
        cout << "5. Volver al menu principal\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                conversionFuerza();
                break;
            case 2:
                conversionAceleracion();
                break;
            case 3:
                conversionMasa();
                break;
            case 4:
                conversionAngulos();
                break;
            case 5:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 5);
}

// Conversion de fuerza
void conversionFuerza() {
    double newtons, dinas;
    cout << "\nCONVERSION DE FUERZA\n";
    cout << "Ingrese la fuerza en Newtons: ";
    cin >> newtons;
    dinas = newtons * 1e5;
    cout << newtons << " N son " << dinas << " dinas\n";
}

// Conversion de aceleracion
void conversionAceleracion() {
    double ms2, gal;
    cout << "\nCONVERSION DE ACELERACION\n";
    cout << "Ingrese la aceleracion en m/s^2: ";
    cin >> ms2;
    gal = ms2 * 100;
    cout << ms2 << " m/s^2 son " << gal << " Gal\n";
}

// Conversion de masa
void conversionMasa() {
    double gramos, kilogramos;
    cout << "\nCONVERSION DE MASA\n";
    cout << "Ingrese la masa en gramos: ";
    cin >> gramos;
    kilogramos = gramos / 1000;
    cout << gramos << " g son " << kilogramos << " kg\n";
}

// Conversion de angulos
void conversionAngulos() {
    double grados, radianes;
    cout << "\nCONVERSION DE ANGULOS\n";
    cout << "Ingrese el angulo en grados: ";
    cin >> grados;
    radianes = grados * M_PI / 180;
    cout << grados << " grados son " << radianes << " radianes\n";
}
