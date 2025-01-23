#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Prototipos
/* void menuPrincipal();
void planoHorizontal();
void planoInclinado();
void menuConvertidor();
void conversionFuerza();
void conversionAceleracion();
void conversionMasa();
void conversionAngulos(); */

void limpiarPantalla() {
    #ifdef _WIN32  // Si estamos en Windows
        system("cls");
    #else  // Si estamos en Linux/macOS
        system("clear");
    #endif
}

// PROBLEMAS EN PLANO HORIZONTALL
void planoHorizontal() {
    limpiarPantalla();
    int Estado, Calcular, ecuacion;
    double masa, fuerza, peso, aceleracion, friccion, normal, coef_friccion, gravedad = 9.81;
    string direccion;

    // MENÚ PLANO HORIZONTALL
    cout << "\n====== PLANO HORIZONTAL ======\n";
    cout << "1. En reposo\n";
    cout << "2. En movimiento\n";
    cout << "Seleccione el estado del cuerpo: ";
    cin >> Estado;

    // CUERPO EN REPOSO
    if (Estado == 1) {
        limpiarPantalla();
        cout << "\nPLANO HORIZONTAL: CUERPO EN REPOSO\n";
        cout << "\nPuede calcular:\n";
        cout << "1. Peso\n";
        cout << "2. Masa\n";
        cout << "3. Fuerza normal\n";
        cout << "Seleccione lo que desea calcular: ";
        cin >> Calcular;

        switch (Calcular) {
            // CÁLCULO DEL PESO
            case 1:
                limpiarPantalla();
                cout << "CALCULANDO EL PESO\n\n";
                cout << "Ingrese la masa (kg): ";
                cin >> masa;

                peso = masa * gravedad;

                cout << "\nDatos ingresados:\n";
                cout << "Masa: " << masa << " kg\n";
                cout << "\nRESULTADO\n";
                cout << "El peso es: " << peso << " N\n";
                break;
            // CÁLCULO DE LA MASA
            case 2:
                limpiarPantalla();
                cout << "CALCULANDO LA MASA\n\n";
                cout << "Ingrese el peso (N): ";
                cin >> peso;

                masa = peso / gravedad;

                cout << "\nDatos ingresados:\n";
                cout << "Peso: " << peso << " N\n";
                cout << "\nRESULTADO\n";
                cout << "La masa es: " << masa << " kg\n";
                break;
            // CÁLCULO DE LA FUERZA NORMAL
            case 3:
                limpiarPantalla();
                cout << "CALCULANDO LA FUERZA NORMAL\n\n";
                cout << "Ingrese la masa (kg): ";
                cin >> masa;

                normal = masa * gravedad;

                cout << "\nDatos ingresados:\n";
                cout << "Masa: " << masa << " kg\n";
                cout << "\nRESULTADO\n";
                cout << "La fuerza normal es: " << normal << " N\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } 
    // CUERPO EN MOVIMIENTO
    else if (Estado == 2) {
        cout << "\nPLANO HORIZONTAL: CUERPO EN MOVIMIENTO\n";
        cout << "\nPuede calcular:\n";
        cout << "1. Fuerza\n";
        cout << "2. Fuerza Normal\n";
        cout << "3. Masa\n";
        cout << "4. Aceleracion\n";
        cout << "5. Peso\n";
        cout << "6. Fuerza de Friccion\n";
        cout << "7. Coeficiente de friccion\n";
        cout << "\nSeleccione lo que desea calcular: ";
        cin >> Calcular;

        /* cout << "Ingrese la direccion del movimiento (izquierda/derecha): ";
        cin >> direccion; */

        switch (Calcular) {
            // CÁLCULO DE LA FUERZA
            case 1:
                limpiarPantalla();
                cout << "CALCULANDO LA FUERZA\n\n";
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                cout << "Ingrese la aceleracion (m/s^2): ";
                cin >> aceleracion;
                cout << "Ingrese coeficiente de friccion: ";
                cin >> coef_friccion;

                fuerza = masa * (aceleracion + coef_friccion * gravedad);

                cout << "\nDatos ingresados:\n";
                cout << "Masa: " << masa << " kg\n";
                cout << "Aceleracion: " << aceleracion << " m/s^2\n";
                cout << "Coeficiente de friccion: " << coef_friccion << endl;

                cout << "\nRESULTADO\n";
                cout << "La fuerza es: " << fuerza << " N\n";
                break;
            // CÁLCULO DE LA FUERZA NORMAL
            case 2:
                limpiarPantalla();
                cout << "CALCULANDO LA FUERZA NORMAL\n\n";
                cout << "Ingrese la masa (kg): ";
                cin >> masa;

                normal = masa * gravedad;

                cout << "\nDatos ingresados:\n";
                cout << "Masa: " << masa << " kg\n";

                cout << "\nRESULTADO\n";
                cout << "La fuerza normal es: " << normal << " N\n";
                break;
            // CÁLCULO DE LA MASA
            case 3:
                limpiarPantalla();
                cout << "CALCULANDO LA MASA\n\n";
                cout << "Seleccione la ecuacion a utilizar segun los datos que disponga\n";
                cout << "          F\n";
                cout << "1. m = --------\n";
                cout << "        a + ug\n\n";
                cout << "           W\n";
                cout << "2. m = --------\n";
                cout << "           g\n\n";
                cout << "Donde:\n";
                cout << "m: masa (kg)\n";
                cout << "F: fuerza (N)\n";
                cout << "W: Peso (N)\n";
                cout << "a: aceleracion (m/s^2)\n";
                cout << "u: coeficiente de friccion\n";
                cout << "g: gravedad (m/s^2)\n\n";
                cout << "Seleccione la ecuacion: ";
                cin >> ecuacion;

                if (ecuacion == 1){
                    limpiarPantalla();
                    cout << "CALCULANDO LA MASA\n\n";
                    cout << "Ingrese la fuerza (N): ";
                    cin >> fuerza;
                    cout << "Ingrese la aceleracion (m/s^2): ";
                    cin >> aceleracion;
                    cout << "Ingrese el coeficiente de friccion: ";
                    cin >> coef_friccion;

                    masa = fuerza / (aceleracion + coef_friccion * gravedad);

                    cout << "\nDatos ingresados:\n";
                    cout << "Fuerza: " << fuerza << " N\n";
                    cout << "Aceleracion: " << aceleracion << " m/s^2\n";
                    cout << "Coeficiente de friccion: " << coef_friccion << endl;

                    cout << "\nRESULTADO\n";
                    cout << "La masa es: " << masa << " kg\n";
                } else if (ecuacion == 2){
                    limpiarPantalla();
                    cout << "CALCULANDO LA MASA\n\n";
                    cout << "Ingrese el peso (N): ";
                    cin >> peso;

                    masa = peso / gravedad;

                    cout << "\nDatos ingresados:\n";
                    cout << "Peso: " << peso << " N\n";

                    cout << "\nRESULTADO\n";
                    cout << "La masa es: " << masa << " kg\n";
                } else {
                    cout << "\nOpcion no valida\n";
                }
                break;
            // CÁLCULO DE LA ACELERACIÓN
            case 4:
                limpiarPantalla();
                cout << "CALCULANDO LA ACELERACION\n\n";
                cout << "Ingrese la fuerza (N): ";
                cin >> fuerza;
                cout << "Ingrese el coeficiente de friccion: ";
                cin >> coef_friccion;
                cout << "Ingrese la masa (kg): ";
                cin >> masa;

                aceleracion = (fuerza - coef_friccion * masa * gravedad) / masa;

                cout << "\nDatos ingresados:\n";
                cout << "Fuerza: " << fuerza << " N\n";
                cout << "Coeficiente de friccion: " << coef_friccion << endl;
                cout << "Masa: " << masa << " kg\n";

                cout << "\nRESULTADO\n";
                cout << "La aceleracion es: " << aceleracion << " m/s^2\n";
                break;
            // CÁLCULO DEL PESO
            case 5:
                limpiarPantalla();
                cout << "CALCULANDO EL PESO\n\n";
                cout << "Ingrese la masa: ";
                cin >> masa;

                peso = masa * gravedad;

                cout << "\nDatos ingresados:\n";
                cout << "Masa: " << masa << " kg\n";

                cout << "\nRESULTADO\n";
                cout << "El peso es: " << peso << " N\n";
                break;
            // CÁLCULO DE LA FUERZA DE FRICCIÓN
            case 6:
                limpiarPantalla();
                cout << "CALCULANDO LA FUERZA DE FRICCION\n\n";
                cout << "Seleccione la ecuacion a utilizar segun los datos que disponga\n";
                cout << "1. Fr = uN\n";
                cout << "2. Fr = F - ma\n\n";
                cout << "Donde:\n";
                cout << "Fr: fuerza de rozamiento (N)\n";
                cout << "u: coeficiente de friccion\n";
                cout << "N: fuerza normal (N)\n";
                cout << "F: fuerza (N)\n";
                cout << "m: masa (kg)\n";
                cout << "a: aceleracion (m/s^2)\n\n";
                cout << "Seleccione la ecuacion: ";
                cin >> ecuacion;

                if (ecuacion == 1){
                    limpiarPantalla();
                    cout << "CALCULANDO LA FUERZA DE FRICCION\n\n";
                    cout << "Ingrese el coeficiente de friccion: ";
                    cin >> coef_friccion;
                    cout << "Ingrese la fuerza normal (N): ";
                    cin >> normal;

                    friccion = coef_friccion * normal;

                    cout << "\nDatos ingresados:\n";
                    cout << "Coeficiente de friccion: " << coef_friccion << endl;
                    cout << "Fuerza normal: " << normal << " N\n";

                    cout << "\nRESULTADO\n";
                    cout << "La fuerza de friccion es: " << friccion << " N\n";
                } else if (ecuacion == 2){
                    limpiarPantalla();
                    cout << "CALCULANDO LA FUERZA DE FRICCION\n\n";
                    cout << "Ingrese la fuerza (N): ";
                    cin >> fuerza;
                    cout << "Ingrese la masa (kg): ";
                    cin >> masa;
                    cout << "Ingrese la aceleracion (m/s^2): ";
                    cin >> aceleracion;

                    friccion = fuerza - masa * aceleracion;

                    cout << "\nDatos ingresados:\n";
                    cout << "Fuerza: " << fuerza << " N\n";
                    cout << "Masa: " << masa << " kg\n";
                    cout << "Aceleracion: " << aceleracion << " m/s^2\n";

                    cout << "\nRESULTADO\n";
                    cout << "La fuerza de friccion es: " << friccion << " N\n";
                } else {
                    cout << "Opcion no valida\n";
                }
                break;
            // CÁLCULO DEL COEFICIENTE DE FRICCIÓN
            case 7:
                limpiarPantalla();
                cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
                cout << "Seleccione la ecuacion a utilizar segun los datos que disponga\n";
                cout << "          Fr\n";
                cout << "1. u = --------\n";
                cout << "          N\n\n";
                cout << "        F - ma\n";
                cout << "2. u = --------\n";
                cout << "          mg\n\n";
                cout << "Donde: \n";
                cout << "u: coeficiente de friccion\n";
                cout << "Fr: fuerza de rozamiento (N)\n";
                cout << "N: fuerza normal (N)\n";
                cout << "F: fuerza (N)\n";
                cout << "m: masa (kg)\n";
                cout << "a: aceleracion (m/s^2)\n";
                cout << "g: gravedad (m/s^2)\n\n";
                cout << "Seleccione la ecuacion: ";
                cin >> ecuacion;

                if(ecuacion == 1){
                    limpiarPantalla();
                    cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
                    cout << "Ingrese la fuerza de rozamiento (N): ";
                    cin >> friccion;
                    cout << "Ingrese la fuerza normal (N): ";
                    cin >> normal;

                    coef_friccion = friccion / normal;

                    cout << "\nDatos ingresados:\n";
                    cout << "Fuerza de rozamiento: " << friccion << " N\n";
                    cout << "Fuerza normal: " << normal << " N\n";

                    cout << "\nRESULTADO\n";
                    cout << "El coeficiente de friccion es: " << coef_friccion << endl;
                } else if(ecuacion == 2){
                    limpiarPantalla();
                    cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
                    cout << "Ingrese la fuerza (N): ";
                    cin >> fuerza;
                    cout << "Ingrese la masa (kg): ";
                    cin >> masa;
                    cout << "Ingrese la aceleracion (m/s^2): ";
                    cin >> aceleracion;

                    coef_friccion = (fuerza - masa * aceleracion) / (masa * gravedad);

                    cout << "\nDatos ingresados:\n";
                    cout << "Fuerza: " << fuerza << " N\n";
                    cout << "Masa: " << masa << " kg\n";
                    cout << "Aceleracion: " << aceleracion << " m/s^2\n";

                    cout << "\nRESULTADO\n";
                    cout << "El coeficiente de friccion es: " << coef_friccion << endl;
                } else {
                    cout << "Opcion no valida\n";
                }
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
    limpiarPantalla();
    int calcular;
    double angulo, masa, peso, pesoX, pesoY, normal, fuerza_equilibrio, friccion, coef_friccion, aceleracion, gravedad = 9.81;
    string direccion;

    cout << "\n======== PLANO INCLINADO ========\n";
    //cout << "Ingrese la direccion del movimiento (izquierda/derecha): ";
    //cin >> direccion;

    //Plano inclinado verificado (variables a calcular)
    cout << "\nPuede calcular:\n";
    cout << "1. Fuerza Normal\n";
    cout << "2. Masa\n";
    cout << "3. Aceleracion\n";
    cout << "4. Peso\n";
    cout << "5. Peso en X\n";
    cout << "6. Peso en Y\n";
    cout << "7. Fuerza de rozamiento\n";
    cout << "8. Coeficiente de friccion\n";
    cout << "\nSeleccione lo que desea calcular: ";
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

// Convertidor de unidades
void menuConvertidor() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n| CONVERTIDOR DE UNIDADES |\n";
        cout << "\n1. Fuerza\n";
        cout << "2. Aceleracion\n";
        cout << "3. Masa\n";
        cout << "4. Angulos\n";
        cout << "5. Volver al menu principal\n";
        cout << "\nIngrese una opcion: ";
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

// MENÚ PRINCIPAL
void menuPrincipal() {
    int opcion;
    do {
        cout << "\nSEGUNDA LEY DE NEWTON: LEY FUNDAMENTAL DE LA DINAMICA\n";
        cout << "\n================== MENU PRINCIPAL ===================\n";
        cout << "1. Plano horizontal\n";
        cout << "2. Plano inclinado\n";
        cout << "3. Convertidor de unidades\n";
        cout << "4. Salir\n";
        cout << "\nIngrese una opcion: ";
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


// FUNCIÓN PRINCIPALL
int main() {
    limpiarPantalla();
    menuPrincipal();
    return 0;
}