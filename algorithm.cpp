#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// PROCEDIMIENTOS MENÚS
void menuPrincipal();
void planoHorizontal();
void planoInclinado();
void menuConvertidor();

// PROCEDIMIENTOS CONVERSIONES DE UNIDADES
void conversionFuerza();
void conversionAceleracion();
void conversionMasa();
void conversionAngulos();

// PROCEDIMIENTO LIMPIAR PANTALLA Y ESPERA DE ENTRADA
void limpiarPantalla();
void presionarEnterParaContinuar();

// FUNCIÓN PRINCIPAL
int main() {
    limpiarPantalla();
    menuPrincipal();
    return 0;
}

// LIMPIAR PANTALLA
void limpiarPantalla() {
    #ifdef _WIN32  // PARA WINDOWS
        system("cls");
    #else  // PARA LINUX
        system("clear");
    #endif
}

// PROCEDIMIENTO ESPERA DE ENTRADA
void presionarEnterParaContinuar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(); // IGNORA CUALQUIER ENTRADA PREVIA
    cin.get();    // ESPERA QUE EL USUARIO PRESIONE ENTER
}

// MENÚ PRINCIPAL DEL PROGRAMA
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
        limpiarPantalla();
        cout << "\nPLANO HORIZONTAL: CUERPO EN MOVIMIENTO\n";
        cout << "\nPuede calcular:\n";
        cout << "1. Fuerza\n";
        cout << "2. Fuerza Normal\n";
        cout << "3. Masa\n";
        cout << "4. Aceleracion\n";
        cout << "5. Peso\n";
        cout << "6. Fuerza de rozamiento\n";
        cout << "7. Coeficiente de friccion\n";
        cout << "\nSeleccione lo que desea calcular: ";
        cin >> Calcular;

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
                cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
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
                    cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
                    cout << "Ingrese el coeficiente de friccion: ";
                    cin >> coef_friccion;
                    cout << "Ingrese la fuerza normal (N): ";
                    cin >> normal;

                    friccion = coef_friccion * normal;

                    cout << "\nDatos ingresados:\n";
                    cout << "Coeficiente de friccion: " << coef_friccion << endl;
                    cout << "Fuerza normal: " << normal << " N\n";

                    cout << "\nRESULTADO\n";
                    cout << "La fuerza de rozamiento es: " << friccion << " N\n";
                } else if (ecuacion == 2){
                    limpiarPantalla();
                    cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
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
                    cout << "La fuerza de rozamiento es: " << friccion << " N\n";
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

// PROBLEMAS EN PLANO INCLINADO
void planoInclinado() {
    limpiarPantalla();
    int calcular = 0, ecuacion = 0;
    double angulo = 0, masa = 0, peso = 0, pesoX = 0, pesoY = 0, normal = 0, fuerza_equilibrio = 0, friccion = 0, coef_friccion = 0, aceleracion = 0, gravedad = 9.81;
    string direccion;

    cout << "\n======== PLANO INCLINADO ========\n";
    //cout << "Ingrese la direccion del movimiento (izquierda/derecha): ";
    //cin >> direccion;

    cout << "\nPuede calcular:\n";
    cout << "1. Fuerza normal\n";
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
        // CÁLCULO DE LA FUERZA NORMAL
        case 1:
            limpiarPantalla();
            cout << "CALCULANDO LA FUERZA NORMAL\n\n";
            cout << "Ingrese la masa (kg): ";
            cin >> masa;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;
            angulo *= M_PI / 180;  // CONVERTIR A RADIANES
            
            normal = masa * gravedad * cos(angulo);
            
            cout << "\nDatos ingresados:\n";
            cout << "Masa: " << masa << " kg\n";
            cout << "Angulo: " << angulo << " rad\n";

            cout << "\nRESULTADO\n";
            cout << "La fuerza normal es: " << normal << " N\n";
            break;
        // CÁLCULO DE LA MASA
        case 2:
            limpiarPantalla();
            cout << "CALCULANDO LA MASA\n\n";
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            
            masa = peso / gravedad;

            cout << "\nDatos ingresados:\n";
            cout << "Peso: " << peso << " N\n\n";

            cout << "\nRESULTADO\n";
            cout << "La masa es: " << masa << " kg\n";
            break;
        // CÁLCULO DE LA ACELERACIÓN
        case 3:
            limpiarPantalla();
            cout << "CALCULANDO LA ACELERACION\n\n";
            cout << "Ingrese el coeficiente de friccion: ";
            cin >> coef_friccion;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;

            angulo *= M_PI / 180; // CONVERTIR A RADIANES
            aceleracion = gravedad * (sin(angulo) - coef_friccion * cos(angulo));

            cout << "\nDatos ingresados:\n";
            cout << "Coeficiente de friccion: " << coef_friccion << endl;
            cout << "Angulo: " << angulo << " rad\n";

            cout << "\nRESULTADO\n";
            cout << "La acelaracion es: " << aceleracion << " m/s^2\n";
            break;
        // CÁLCULO DEL PESO
        case 4:
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
        // CÁLCULO DEL PESO EN X
        case 5:
            limpiarPantalla();
            cout << "CALCULANDO EL PESO EN X\n\n";
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;

            angulo *= M_PI / 180;  // CONVERTIR A RADIANES
            pesoX = peso * sin(angulo);

            cout << "\nDatos ingresados:\n";
            cout << "Peso: " << peso << " N\n";
            cout << "Angulo: " << angulo << " rad\n";

            cout << "\nRESULTADO\n";
            cout << "El peso en X es: " << pesoX << " N\n";
            break;
        // CÁLCULO DEL PESO EN Y
        case 6:
            limpiarPantalla();
            cout << "CALCULANDO EL PESO EN X\n\n";
            cout << "Ingrese el peso (N): ";
            cin >> peso;
            cout << "Ingrese el angulo de inclinacion (grados): ";
            cin >> angulo;

            angulo *= M_PI / 180;  // CONVERTIR A RADIANES
            pesoY = peso * cos(angulo);

            cout << "\nDatos ingresados:\n";
            cout << "Peso: " << peso << " N\n";
            cout << "Angulo: " << angulo << " rad\n";

            cout << "\nRESULTADO\n";
            cout << "El peso en Y es: " << pesoY << " N\n";
            break;
        // CÁLCULO DE LA FUERZA DE FRICCIÓN
        case 7:
            limpiarPantalla();
            cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
            cout << "Seleccione la ecuacion a utilizar segun los datos que disponga\n";
            cout << "1. Fr = uN\n";
            cout << "2. Fr = m(gsin(x) - a)\n\n";
            cout << "Donde: \n";
            cout << "Fr: fuerza de rozamiento (N)\n";
            cout << "u: coeficiente de friccion\n";
            cout << "N: fuerza normal (N)\n";
            cout << "m: masa (kg)\n";
            cout << "g: gravedad (m/s^2)\n";
            cout << "x: angulo (grados)\n";
            cout << "a: aceleracion (m/s^2)\n\n";
            cout << "Seleccione la ecuacion: ";
            cin >> ecuacion;

            if(ecuacion == 1){
                limpiarPantalla();
                cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
                cout << "Ingrese el coeficiente de friccion: ";
                cin >> coef_friccion;
                cout << "Ingrese la fuerza normal (N): ";
                cin >> normal;

                friccion = coef_friccion * normal;

                cout << "\nDatos ingresados:\n";
                cout << "Coeficiente de friccion: " << coef_friccion << endl;
                cout << "Fuerza normal: " << normal << " N\n";

                cout << "\nRESULTADO\n";
                cout << "La fuerza de rozamiento es: " << friccion << " N\n";
            } else if(ecuacion == 2){
                limpiarPantalla();
                cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
                cout << "Ingrese la masa (kg): ";
                cin >> masa;
                cout << "Ingrese el angulo de inclinacion (grados): ";
                cin >> angulo;
                cout << "Ingrese la aceleracion (m/s^2): ";
                cin >> aceleracion;

                angulo *= M_PI / 180;  // CONVERTIR A RADIANES
                friccion = masa * ((gravedad * sin(angulo)) - aceleracion);

                cout << "\nDatos ingresados:\n";
                cout << "Masa: " << masa << " kg\n";
                cout << "Angulo: " << angulo << " rad\n";
                cout << "Aceleracion: " << aceleracion << " m/s^2\n";

                cout << "\nRESULTADO\n";
                cout << "La fuerza de rozamiento es: " << friccion << " N\n";
            } else {
                cout << "Opcion no valida\n";
            }

            break;
        // CÁLCULO DEL COEFICIENTE DE FRICCIÓN
        case 8:
            limpiarPantalla();
            cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
            cout << "Seleccione la ecuacion a utilizar segun los datos que disponga\n";
            cout << "          Fr\n";
            cout << "1. u = --------\n";
            cout << "          N\n\n";
            cout << "        gsin(x) - a\n";
            cout << "2. u = -------------\n";
            cout << "          gcos(x)\n\n";
            cout << "Donde: \n";
            cout << "u: coeficiente de friccion\n";
            cout << "Fr: fuerza de rozamiento (N)\n";
            cout << "N: fuerza normal (N)\n";
            cout << "g: gravedad (m/s^2)\n";
            cout << "x: angulo\n";
            cout << "a: aceleracion (m/s^2)\n\n";
            cout << "Seleccione la ecuacion: ";
            cin >> ecuacion;
            if (ecuacion == 1){
                limpiarPantalla();
                cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
                cout << "Ecuacion seleccionada:\n";
                cout << "          Fr\n";
                cout << "1. u = --------\n";
                cout << "          N\n\n";
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
            } else if (ecuacion == 2){
                limpiarPantalla();
                cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
                cout << "Ecuacion seleccionada:\n";
                cout << "        gsin(x) - a\n";
                cout << "2. u = -------------\n";
                cout << "          gcos(x)\n\n";
                cout << "Ingrese el angulo de inclinacion (grados): ";
                cin >> angulo;
                cout << "Ingrese la aceleracion (m/s^2): ";
                cin >> aceleracion;

                angulo *= M_PI / 180;  // CONVERTIR A RADIANES
                coef_friccion = (gravedad * sin(angulo) - aceleracion) / (gravedad * cos(angulo));

                cout << "\nDatos ingresados:\n";
                cout << "Angulo: " << angulo << " rad\n";
                cout << "Aceleracion: " << aceleracion << " m/s^2\n";

                cout << "\nRESULTADO\n";
                cout << "El coeficiente de friccion es: " << coef_friccion << endl;
            }
            
            break;
        case 9:
            break;
        default:
            cout << "Opcion invalida.\n";
    }
}

// MENÚ CONVERTIDOR DE UNIDADES
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

// PROCEDIMIENTO CONVERSIÓN DE FUERZA
void conversionFuerza() {
    int opcion;
    double valor, resultado;

    limpiarPantalla();
    cout << "CONVERSIONES DE FUERZA\n\n";
    cout << "1. Newtons (N)         > Dinas\n";
    cout << "2. Dinas               > Newtons (N)\n";
    cout << "3. Newtons (N)         > Libras-fuerza (lbf)\n";
    cout << "4. Libras-fuerza (lbf) > Newtons (N)\n";
    cout << "5. Newtons (N)         > Kilopondios (kp)\n";
    cout << "6. Kilopondios (kp)    > Newtons (N)\n";
    cout << "7. Kilopondios (kp)    > Libras-fuerza (lbf)\n";
    cout << "8. Libras-fuerza (lbf) > Kilopondios (kp)\n";
    cout << "\nIngrese una opcion: ";
    cin >> opcion;

    cout << "\nIngrese el valor a convertir: ";
    cin >> valor;

    switch (opcion){
        // NEWTONS A DINAS
        case 1:
            resultado = valor * 1e5; // 1 N = 100000 Dinas
            cout << valor << " N = " << resultado << " Dinas\n";
            break;
        // DINAS A NEWTONS
        case 2:
            resultado = valor / 1e5;
            cout << valor << " Dinas = " << resultado << " N\n";
            break;
        // NEWTONS A LIBRAS-FUERZA
        case 3:
            resultado = valor / 4.44822; // 1 lbf = 4.44822 N
            cout << valor << " N = " << resultado << " lbf\n";
            break;
        // LIBRAS-FUERZA A NEWTONS
        case 4:
            resultado = valor * 4.44822;
            cout << valor << " lbf = " << resultado << " N\n";
            break;
        // NEWTONS A KILOPONDIOS
        case 5:
            resultado = valor / 9.80665; // 1 kp = 9.80665 N
            cout << valor << " N = " << resultado << " kp\n";
            break;
        // KILOPONDIOS A NEWTONS
        case 6:
            resultado = valor * 9.80665;
            cout << valor << " kp = " << resultado << " N\n";
            break;
        // KILOPONDIOS A LIBRAS-FUERZA
        case 7:
            resultado = valor * 2.20462; // 1 kp = 2.20462 lbf
            cout << valor << " kp = " << resultado << " lbf\n";
            break;
        // LIBRAS-FUERZA A KILOPONDIOS
        case 8:
            resultado = valor / 2.20462;
            cout << valor << " lbf = " << resultado << " kp\n";
            break;
        default:
            break;
    }
    presionarEnterParaContinuar();
}

// PROCEDIMIENTO CONVERSIÓN DE ACELERACIÓN
void conversionAceleracion() {
    int opcion;
    double valor, resultado;

    limpiarPantalla();
    cout << "CONVERSIONES DE ACELERACION\n\n";
    cout << "1. m/s^2   > ft/s^2\n";
    cout << "2. ft/s^2  > m/s^2\n";
    cout << "3. m/s^2   > cm/s^2\n";
    cout << "4. cm/s^2  > m/s^2\n";
    cout << "5. m/s^2   > km/h^2\n";
    cout << "6. km/h^2 -> m/s^2\n";
    cout << "\nIngrese una opcion: ";
    cin >> opcion;

    cout << "\nIngrese el valor a convertir: ";
    cin >> valor;

    switch (opcion) {
        // m/s^2 a ft/s^2
        case 1:
            resultado = valor * 3.28084;
            cout << valor << " m/s^2 = " << resultado << " ft/s^2\n";
            break;
        // ft/s^2 a m/s^2
        case 2: 
            resultado = valor / 3.28084;
            cout << valor << " ft/s^2 = " << resultado << " m/s^2\n";
            break;
        // m/s^2 a cm/s^2
        case 3: 
            resultado = valor * 100;
            cout << valor << " m/s^2 = " << resultado << " cm/s^2\n";
            break;
        // cm/s^2 a m/s^2
        case 4: 
            resultado = valor / 100;
            cout << valor << " cm/s^2 = " << resultado << " m/s^2\n";
            break;
        // m/s^2 a km/h^2
        case 5:
            resultado = valor * 12960; // 1 m/s^2 = 12960 km/h^2
            cout << valor << " m/s^2 = " << resultado << " km/h^2\n";
            break;
        // km/h^2 a m/s^2
        case 6:
            resultado = valor / 12960;
            cout << valor << " km/h^2 = " << resultado << " m/s^2\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
    }
    presionarEnterParaContinuar();
}

// PROCEDIMIENTO CONVERSIÓN DE MASA
void conversionMasa() {
    int opcion;
    double valor, resultado;

    limpiarPantalla();
    cout << "CONVERSIONES DE MASA\n\n";
    cout << "1. Kilogramos (kg)   > Gramos (g)\n";
    cout << "2. Gramos (g)        > Kilogramos (kg)\n";
    cout << "3. Kilogramos (kg)   > Slugs\n";
    cout << "4. Slugs             > Kilogramos (kg)\n";
    cout << "5. Kilogramos (kg)   > Libras (lb)\n";
    cout << "6. Libras (lb)       > Kilogramos (kg)\n";
    cout << "7. Kilogramos (kg)   > Onzas (oz)\n";
    cout << "8. Onzas (oz)        > Kilogramos (kg)\n";
    cout << "9. Kilogramos (kg)   > Toneladas (t)\n";
    cout << "10. Toneladas (t)    > Kilogramos (kg)\n";
    cout << "\nIngrese una opcion: ";
    cin >> opcion;

    cout << "\nIngrese el valor a convertir: ";
    cin >> valor;

    switch (opcion) {
        // KILOGRAMOS A GRAMOS
        case 1:
            resultado = valor * 1000; // 1 kg = 1000 g
            cout << valor << " kg = " << resultado << " g\n";
            break;
        // GRAMOS A KILOGRAMOS
        case 2:
            resultado = valor / 1000;
            cout << valor << " g = " << resultado << " kg\n";
            break;
        // KILOGRAMOS A SLUGS
        case 3:
            resultado = valor / 14.5939; // 1 slug = 14.5939 kg
            cout << valor << " kg = " << resultado << " slugs\n";
            break;
        // SLUGS A KILOGRAMOS
        case 4:
            resultado = valor * 14.5939;
            cout << valor << " slugs = " << resultado << " kg\n";
            break;
        // KILOGRAMOS A LIBRAS
        case 5:
            resultado = valor * 2.20462; // 1 kg = 2.20462 lb
            cout << valor << " kg = " << resultado << " lb\n";
            break;
        // LIBRAS A KILOGRAMOS
        case 6:
            resultado = valor / 2.20462;
            cout << valor << " lb = " << resultado << " kg\n";
            break;
        // KILOGRAMOS A ONZAS
        case 7:
            resultado = valor * 35.274; // 1 kg = 35.274 oz
            cout << valor << " kg = " << resultado << " oz\n";
            break;
        // ONZAS A KILOGRAMOS
        case 8:
            resultado = valor / 35.274;
            cout << valor << " oz = " << resultado << " kg\n";
            break;
        // KILOGRAMOS A TONELADAS
        case 9:
            resultado = valor / 1000; // 1 tonelada = 1000 kg
            cout << valor << " kg = " << resultado << " t\n";
            break;
        // TONELADAS A KILOGRAMOS
        case 10:
            resultado = valor * 1000;
            cout << valor << " t = " << resultado << " kg\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
    }
    presionarEnterParaContinuar();
}

// PROCEDIMIENTO CONVERSIÓN DE ÁNGULOS
void conversionAngulos() {
    int opcion;
    double valor, resultado;

    limpiarPantalla();
    cout << "CONVERSIONES DE ANGULOS\n\n";
    cout << "1. Grados (°)      > Radianes (rad)\n";
    cout << "2. Radianes (rad)  > Grados (°)\n";
    cout << "\nIngrese una opcion: ";
    cin >> opcion;

    cout << "\nIngrese el valor a convertir: ";
    cin >> valor;

    switch (opcion) {
        // GRADOS A RADIANES
        case 1:
            resultado = valor * (M_PI / 180); // 1° = pi/180 rad
            cout << valor << "° = " << resultado << " rad\n";
            break;
        // RADIANES A GRADOS
        case 2:
            resultado = valor * (180 / M_PI); // 1 rad = 180/pi °
            cout << valor << " rad = " << resultado << "°\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
    }
    presionarEnterParaContinuar();
}