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
    double angulo, masa, peso, pesoX, pesoY, normal, fuerza_equilibrio, friccion, coef_friccion, aceleracion, gravedad = 9.81;
    string direccion;

    cout << "\nPLANO INCLINADO\n";
    cout << "Ingrese la direccion del movimiento (izquierda/derecha): ";
    cin >> direccion;

    cout << "\nPuede calcular:\n";
    cout << "1. Fuerza para mantener en equilibrio\n";
    cout << "2. Aceleracion\n";
    cout << "3. Masa\n";
    cout << "4. Peso\n";
    cout << "5. Peso en X\n";
    cout << "6. Peso en Y\n";
    cout << "7. Fuerza normal\n";
    cout << "8. Fuerza de rozamiento\n";
    cout << "9. Coeficiente de friccion\n";
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
            cout << "Ingrese la fuerza neta (N): ";
            cin >> fuerza_equilibrio;
            cout << "Ingrese la masa (kg): ";
            cin >> masa;
            aceleracion = fuerza_equilibrio / masa;
            cout << "La aceleracion es: " << aceleracion << " m/s^2\n";
            break;
        case 3:
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            masa = peso / gravedad;
            cout << "La masa es: " << masa << " kg\n";
            break;
        case 4:
            cout << "Ingrese la masa (kg): ";
            cin >> masa;
            peso = masa * gravedad;
            cout << "El peso es: " << peso << " N\n";
            break;
        case 5:
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;
            angulo = angulo * M_PI / 180;  // Convertir a radianes
            pesoX = peso * sin(angulo);
            cout << "El peso en X es: " << pesoX << " N\n";
            break;
        case 6:
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;
            angulo = angulo * M_PI / 180;  // Convertir a radianes
            pesoY = peso * cos(angulo);
            cout << "El peso en Y es: " << pesoY << " N\n";
            break;
        case 7:
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;
            angulo = angulo * M_PI / 180;  // Convertir a radianes
            normal = peso * cos(angulo);
            cout << "La fuerza normal es: " << normal << " N\n";
            break;
        case 8:
            cout << "Ingrese el coeficiente de friccion: ";
            cin >> coef_friccion;
            cout << "Ingrese la normal (N): ";
            cin >> normal;
            friccion = coef_friccion * normal;
            cout << "La fuerza de rozamiento es: " << friccion << " N\n";
            break;
        case 9:
            cout << "Ingrese la fuerza de rozamiento (N): ";
            cin >> friccion;
            cout << "Ingrese la normal (N): ";
            cin >> normal;
            coef_friccion = friccion / normal;
            cout << "El coeficiente de friccion es: " << coef_friccion << "\n";
            break;
        default:
            cout << "Opcion invalida.\n";
    }
}

// Convertidor de unidades
void menuConvertidor() {
    int opcion;
    do {
        cout << "\n========== CONVERTIDOR DE UNIDADES ==========\n";
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
                cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 5);
}

void conversionFuerza() {
    cout << "Proximamente conversiones de fuerza...\n";
}

void conversionAceleracion() {
    cout << "Proximamente conversiones de aceleracion...\n";
}

void conversionMasa() {
    cout << "Proximamente conversiones de masa...\n";
}

void conversionAngulos() {
    cout << "Proximamente conversiones de angulos...\n";
}
