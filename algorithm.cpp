#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <string>
using namespace std;

// CONSTANTE GRAVEDAD
const double GRAVEDAD = 9.80665;

// VARIABLES GLOBALES
int Opcion, Ecuacion;
double Valor, Resultado, Mayor_Cero;

// PROCEDIMIENTOS MENÚS
void menuPrincipal();
void menuPlanoHorizontal();
void menuCuerpoEnReposoPlanoHorizontal();
void menuCuerpoEnMovimientoPlanoHorizontal();
void planoHorizontal();
void planoInclinado();
void menuConvertidor();

// FUNCIONES PARA CÁLCULOS - PLANO HORIZONTAL
// Cuerpo en REPOSO
double calcularPeso(double masa);
void calcularYMostrarPeso();
double calcularMasaCuerpoEnReposoPH(double peso);
void calcularYMostrarMasaCuerpoEnReposoPH();
void calcularYMostrarFuerzaNormalCuerpoEnReposoPH();
// Cuerpo en MOVIMIENTO
void calcularYMostrarFuerzaCuerpoEnMovimientoPH();
void calcularYMostrarFuerzaNormalCuerpoEnMovimientoPH();
double calcularMasaCuerpoEnMovimientoEcuacion1PH(double fuerza, double aceleracion, double coeficienteFriccion);
void calcularYMostrarMasaCuerpoEnMovimientoEcuacion1PH();
void calcularYMostrarMasaCuerpoEnMovimientoEcuacion2PH();
void calcularYMostrarAceleracionCuerpoEnMovimientoPH();
void calcularYMostrarFuerzaRozamientoCuerpoEnMovimientoEcuacion1PH();
void calcularYMostrarFuerzaRozamientoCuerpoEnMovimientoEcuacion2PH();
void calcularYMostrarCoeficienteFriccionCuerpoEnMovimientoEcuacion1PH();
void calcularYMostrarCoeficienteFriccionCuerpoEnMovimientoEcuacion2PH();


// PROCEDIMIENTOS CONVERSIONES DE UNIDADES
void conversionFuerza();
void conversionAceleracion();
void conversionMasa();
void conversionAngulos();
void ingresoDatosConversion();

// PROCEDIMIENTOS LIMPIAR PANTALLA Y ESPERA DE ENTRADA
void limpiarPantalla();
void presionarEnterParaContinuar();

// FUNCIONES VALIDAR ENTRADA PARA CÁLCULOS Y OPCIONES
double leerNumero();
int leerOpcion();
bool validarMayorCero(double dato, string nombreDato);


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

// PROCEDIMIENTO "PRESIONE ENTER PARA CONTINUAR"
void presionarEnterParaContinuar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(); // IGNORA CUALQUIER ENTRADA PREVIA
    cin.get();    // ESPERA QUE EL USUARIO PRESIONE ENTER
    limpiarPantalla();
}

// FUNCIÓN PARA LEER UN DATO VÁLIDO
double leerNumero() {
    double numero;
    
    // BUCLE HASTA QUE SE INGRESE UN NÚMERO VÁLIDO
    while (true) {
        cin >> numero;
        
        // SI HAY ERROR DE ENTRADA, SE LIMPIA LA PANTALLA Y SE DESCARTA LA ENTRADA INCORRECTA
        if (cin.fail()) {
            cin.clear(); // LIMPIA EL ESTADO DE ERROR
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // IGNORA ENTRADAS PREVIAS
            cout << "\nError, debe ingresar un dato valido.\n";
            cout << "Intente de nuevo: ";
        } else {
            break; // SI LA ENTRADA ES CORRECTA, SALE DEL BUCLE
        }
    }
    
    return numero;
}

// FUNCIÓN PARA LEER UNA OPCIÓN ENTERA VÁLIDA
int leerOpcion() {
    
    // BUCLE HASTA QUE SE INGRESE UNA OPCIÓN VÁLIDA
    while (true) {
        cin >> Opcion;
        
        // SI HAY ERROR DE ENTRADA, SE LIMPIA LA PANTALLA Y SE DESCARTA LA ENTRADA INCORRECTA
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // IGNORA ENTRADAS PREVIAS

            cout << "\nError, debe ingresar un numero entero valido.\n";
            cout << "Intente de nuevofsfsf: ";
        } else {
            break; // SI LA ENTRADA ES CORRECTA, SALE DEL BUCLE
        }
    }
    
    return Opcion;
}

// VALORES MAYORES A CERO
bool validarMayorCero(double dato, string nombreDato){
    if (dato > 0){
        return true; // DATO VÁLIDO
    } else {
        limpiarPantalla();
        cout << "Error: " << nombreDato << " debe ser mayor a 0\n\n";
        return false; // DATO NO VÁLIDO
    }
}

// FUNCIONES PARA CÁLCULOS DE UN CUERPO EN REPOSO EN EL PLANO HORIZONTAL //
// Calcular el PESO de un cuerpo
double calcularPeso(double masa) {
    return masa * GRAVEDAD;
}

// Calcular y mostrar el PESO - PLANO HORIZONTAL
void calcularYMostrarPeso() {
    double masa;
    do {
        cout << "CALCULANDO EL PESO\n\n";
        cout << "Ingrese la masa (kg): ";
        masa = leerNumero();
    } while (!validarMayorCero(masa, "masa"));

    double peso = calcularPeso(masa);

    cout << "\nDatos ingresados:\n";
    cout << "Masa: " << masa << " kg\n";
    cout << "\nRESULTADO\n";
    cout << "El peso es: " << peso << " N\n";
    presionarEnterParaContinuar();
}

// Calcular la MASA de un cuerpo en REPOSO - PLANO HORIZONTAL
double calcularMasaCuerpoEnReposoPH(double peso) {
    return peso / GRAVEDAD;
}

// Calcular y mostrar la MASA de un cuerpo en REPOSO - PLANO HORIZONTAL
void calcularYMostrarMasaCuerpoEnReposoPH() {
    double peso;
    do {
        cout << "CALCULANDO LA MASA\n\n";
        cout << "Ingrese el peso (N): ";
        peso = leerNumero();
    } while (!validarMayorCero(peso, "peso"));

    double masa = calcularMasaCuerpoEnReposoPH(peso);

    cout << "\nDatos ingresados:\n";
    cout << "Peso: " << peso << " N\n";
    cout << "\nRESULTADO\n";
    cout << "La masa es: " << masa << " kg\n";
    presionarEnterParaContinuar();
}

// Calcular y mostrar la FUERZA NORMAL de un cuerpo en REPOSO - PLANO HORIZONTAL
void calcularYMostrarFuerzaNormalCuerpoEnReposoPH() {
    double masa;
    do {
        cout << "CALCULANDO LA FUERZA NORMAL\n\n";
        cout << "Ingrese la masa (kg): ";
        masa = leerNumero();

        if (validarMayorCero(masa, "masa")) {
            double fuerzaNormal = masa * GRAVEDAD;

            cout << "\nDatos ingresados:\n";
            cout << "Masa: " << masa << " kg\n";
            cout << "\nRESULTADO\n";
            cout << "La fuerza normal es: " << fuerzaNormal << " N\n";
            presionarEnterParaContinuar();
            break;
        }
    } while (true);
}

// FUNCIONES PARA CÁLCULOS DE UN CUERPO EN MOVIMIENTO EN EL PLANO HORIZONTAL //
// Calcular y mostrar la FUERZA de un cuerpo en MOVIMIENTO - PLANO HORIZONTAL
void calcularYMostrarFuerzaCuerpoEnMovimientoPH() {
    double masa, aceleracion, coeficienteFriccion;

    // SOLICITAR Y VALIDAR LA MASA
    do {
        cout << "CALCULANDO LA FUERZA\n\n";
        cout << "Ingrese la masa (kg): ";
        masa = leerNumero();
    } while (!validarMayorCero(masa, "masa"));

    // SOLICITAR Y VALIDAR LA ACELERACIÓN
    do {
        cout << "Ingrese la aceleracion (m/s^2): ";
        aceleracion = leerNumero();
    } while (!validarMayorCero(aceleracion, "aceleracion"));

    // SOLICITAR Y VALIDAR EL COEFICIENTE DE FRICCIÓN
    do {
        cout << "Ingrese el coeficiente de friccion, entre [0 y 1]: ";
        coeficienteFriccion = leerNumero();
        if (coeficienteFriccion <= 0 || coeficienteFriccion > 1) {
            limpiarPantalla();
            cout << "El coeficiente de friccion debe estar entre 0 y 1\n\n";
        }
    } while (coeficienteFriccion <= 0 || coeficienteFriccion > 1);

    // CALCULAR LA FUERZA
    double fuerza = masa * (aceleracion + coeficienteFriccion * GRAVEDAD);

    // MOSTRAR RESULTADOS
    cout << "\nDatos ingresados:\n";
    cout << "Masa: " << masa << " kg\n";
    cout << "Aceleracion: " << aceleracion << " m/s^2\n";
    cout << "Coeficiente de friccion: " << coeficienteFriccion << endl;

    cout << "\nRESULTADO\n";
    cout << "La fuerza es: " << fuerza << " N\n";
    presionarEnterParaContinuar();
}

// Calcular y mostrar la FUERZA NORMAL de un cuerpo en MOVIMIENTO - PLANO HORIZONTAL
void calcularYMostrarFuerzaNormalCuerpoEnMovimientoPH() {
    double masa;
    do {
        cout << "CALCULANDO LA FUERZA NORMAL\n\n";
        cout << "Ingrese la masa (kg): ";
        masa = leerNumero();

        if (validarMayorCero(masa, "masa")) {
            double fuerzaNormal = masa * GRAVEDAD;

            cout << "\nDatos ingresados:\n";
            cout << "Masa: " << masa << " kg\n";
            cout << "\nRESULTADO\n";
            cout << "La fuerza normal es: " << fuerzaNormal << " N\n";
            presionarEnterParaContinuar();
            break;
        }
    } while (true);
}

// Calcular la MASA usando la ECUACIÓN 1 de un cuerpo en MOVIMIENTO - PLANO HORIZONTAL
double calcularMasaCuerpoEnMovimientoEcuacion1PH(double fuerza, double aceleracion, double coeficienteFriccion) {
    return fuerza / (aceleracion + coeficienteFriccion * GRAVEDAD);
}

// Calcular y mostrar la MASA de un cuerpo en MOVIMIENTO usando la ECUACIÓN 1 - PLANO HORIZONTAL
void calcularYMostrarMasaCuerpoEnMovimientoEcuacion1PH() {
    double fuerza, aceleracion, coeficienteFriccion;

    // SOLICITAR Y VALIDAR LA FUERZA
    do {
        cout << "CALCULANDO LA MASA\n\n";
        cout << "Ecuación seleccionada:\n\n";
        cout << "          F\n";
        cout << "1. m = --------\n";
        cout << "        a + ug\n\n";
        cout << "Ingrese la fuerza (N): ";
        fuerza = leerNumero();
    } while (!validarMayorCero(fuerza, "fuerza"));

    // SOLICITAR Y VALIDAR LA ACELERACIÓN
    do {
        cout << "Ingrese la aceleracion (m/s^2): ";
        aceleracion = leerNumero();
    } while (!validarMayorCero(aceleracion, "aceleracion"));

    // SOLICITAR Y VALIDAR EL COEFICIENTE DE FRICCIÓN
    do {
        cout << "Ingrese el coeficiente de friccion, entre [0 y 1]: ";
        coeficienteFriccion = leerNumero();
        if (coeficienteFriccion <= 0 || coeficienteFriccion > 1) {
            limpiarPantalla();
            cout << "El coeficiente de friccion debe estar entre 0 y 1\n\n";
        }
    } while (coeficienteFriccion <= 0 || coeficienteFriccion > 1);

    // CALCULAR LA MASA
    double masa = calcularMasaCuerpoEnMovimientoEcuacion1PH(fuerza, aceleracion, coeficienteFriccion);

    // MOSTRAR RESULTADOS
    cout << "\nDatos ingresados:\n";
    cout << "Fuerza: " << fuerza << " N\n";
    cout << "Aceleracion: " << aceleracion << " m/s^2\n";
    cout << "Coeficiente de friccion: " << coeficienteFriccion << endl;

    cout << "\nRESULTADO\n";
    cout << "La masa es: " << masa << " kg\n";
    presionarEnterParaContinuar();
}

// Calcular la MASA usando la ECUACIÓN del cuerpo en REPOSO
void calcularYMostrarMasaCuerpoEnMovimientoEcuacion2PH() {
    double peso;

    // SOLICITAR Y VALIDAR EL PESO
    do {
        cout << "CALCULANDO LA MASA\n\n";
        cout << "           W\n";
        cout << "2. m = --------\n";
        cout << "           g\n\n";
        cout << "Ingrese el peso (N): ";
        peso = leerNumero();
    } while (!validarMayorCero(peso, "peso"));

    // CALCULAR LA MASA
    double masa = calcularMasaCuerpoEnReposoPH(peso);

    // MOSTRAR RESULTADOS
    cout << "\nDatos ingresados:\n";
    cout << "Peso: " << peso << " N\n";

    cout << "\nRESULTADO\n";
    cout << "La masa es: " << masa << " kg\n";
    presionarEnterParaContinuar();
}

// Calcular y mostrar la ACELERACIÓN de un cuerpo en MOVIMIENTO - PLANO HORIZONTAL
void calcularYMostrarAceleracionCuerpoEnMovimientoPH() {
    double fuerza, coeficienteFriccion, masa;

    // SOLICITAR Y VALIDAR FUERZA
    do {
        cout << "CALCULANDO LA ACELERACION\n\n";
        cout << "Ingrese la fuerza (N): ";
        fuerza = leerNumero();
    } while (!validarMayorCero(fuerza, "fuerza"));

    // SOLICITAR Y VALIDAR EL COEFICIENTE DE FRICCIÓN
    do {
        cout << "Ingrese el coeficiente de friccion, entre [0 y 1]: ";
        coeficienteFriccion = leerNumero();
        if (coeficienteFriccion <= 0 || coeficienteFriccion > 1) {
            limpiarPantalla();
            cout << "El coeficiente de friccion debe estar entre 0 y 1\n\n";
        }
    } while (coeficienteFriccion <= 0 || coeficienteFriccion > 1);

    // SOLICITAR Y VALIDAR MASA
    do {
        cout << "Ingrese la masa (kg): ";
        masa = leerNumero();
    } while (!validarMayorCero(masa, "masa"));

    // CALCULAR LA ACELERACIÓN
    double aceleracion = (fuerza - coeficienteFriccion * masa * GRAVEDAD) / masa;

    // MOSTRAR RESULTADOS
    cout << "\nDatos ingresados:\n";
    cout << "Fuerza: " << fuerza << " N\n";
    cout << "Coeficiente de friccion: " << coeficienteFriccion << endl;
    cout << "Masa: " << masa << " kg\n";

    cout << "\nRESULTADO\n";
    cout << "La aceleracion es: " << aceleracion << " m/s^2\n";
    presionarEnterParaContinuar();
}

// Calcular la FUERZA DE ROZAMIENTO usando la ECUACIÓN 1 (Fr = uN) - PLANO HORIZONTAL
void calcularYMostrarFuerzaRozamientoCuerpoEnMovimientoEcuacion1PH() {
    double coeficienteFriccion, fuerzaNormal;

    // SOLICITAR Y VALIDAR EL COEFICIENTE DE FRICCIÓN
    do {
        cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
        cout << "Ecuacion seleccionada:\n";
        cout << "1. Fr = uN\n\n";
        cout << "Ingrese el coeficiente de friccion, entre [0 y 1]: ";
        coeficienteFriccion = leerNumero();
        if (coeficienteFriccion <= 0 || coeficienteFriccion > 1) {
            limpiarPantalla();
            cout << "El coeficiente de friccion debe estar entre 0 y 1\n\n";
        }
    } while (coeficienteFriccion <= 0 || coeficienteFriccion > 1);

    // SOLICITAR Y VALIDAR LA FUERZA NORMAL
    do {
        cout << "Ingrese la fuerza normal (N): ";
        fuerzaNormal = leerNumero();
    } while (!validarMayorCero(fuerzaNormal, "fuerza normal"));

    // CALCULAR LA FUERZA DE ROZAMIENTO
    double fuerzaRozamiento = coeficienteFriccion * fuerzaNormal;

    // MOSTRAR RESULTADOS
    cout << "\nDatos ingresados:\n";
    cout << "Coeficiente de friccion: " << coeficienteFriccion << endl;
    cout << "Fuerza normal: " << fuerzaNormal << " N\n";

    cout << "\nRESULTADO\n";
    cout << "La fuerza de rozamiento es: " << fuerzaRozamiento << " N\n";
    presionarEnterParaContinuar();
}

// Calcular la FUERZA DE ROZAMIENTO usando la ECUACIÓN 2 (Fr = F - ma) - PLANO HORIZONTAL
void calcularYMostrarFuerzaRozamientoCuerpoEnMovimientoEcuacion2PH() {
    double fuerza, masa, aceleracion;

    // SOLICITAR Y VALIDAR LA FUERZA
    do {
        cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
        cout << "Ecuacion seleccionada:\n";
        cout << "2. Fr = F - ma\n";
        cout << "Ingrese la fuerza (N): ";
        fuerza = leerNumero();
    } while (!validarMayorCero(fuerza, "fuerza"));

    // SOLICITAR Y VALIDAR LA MASA
    do {
        cout << "Ingrese la masa (kg): ";
        masa = leerNumero();
    } while (!validarMayorCero(masa, "masa"));

    // SOLICITAR Y VALIDAR LA ACELERACIÓN
    do {
        cout << "Ingrese la aceleracion (m/s^2): ";
        aceleracion = leerNumero();
    } while (!validarMayorCero(aceleracion, "aceleracion"));

    // CALCULAR LA FUERZA DE ROZAMIENTO
    double fuerzaRozamiento = fuerza - masa * aceleracion;

    // MOSTRAR RESULTADOS
    cout << "\nDatos ingresados:\n";
    cout << "Fuerza: " << fuerza << " N\n";
    cout << "Masa: " << masa << " kg\n";
    cout << "Aceleracion: " << aceleracion << " m/s^2\n";

    cout << "\nRESULTADO\n";
    cout << "La fuerza de rozamiento es: " << fuerzaRozamiento << " N\n";
    presionarEnterParaContinuar();
}

// Función para calcular COEFICIENTE DE FRICCIÓN usando la ECUACIÓN 1 (u = Fr / N)
void calcularYMostrarCoeficienteFriccionCuerpoEnMovimientoEcuacion1PH() {
    double fuerzaRozamiento, fuerzaNormal;

    // Solicitar y validar la fuerza de rozamiento
    do {
        cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
        cout << "Ingrese la fuerza de rozamiento (N): ";
        fuerzaRozamiento = leerNumero();
    } while (!validarMayorCero(fuerzaRozamiento, "fuerza de rozamiento"));

    // Solicitar y validar la fuerza normal
    do {
        cout << "Ingrese la fuerza normal (N): ";
        fuerzaNormal = leerNumero();
    } while (!validarMayorCero(fuerzaNormal, "fuerza normal"));

    // Calcular el coeficiente de fricción
    double coeficienteFriccion = fuerzaRozamiento / fuerzaNormal;

    // Mostrar resultados
    cout << "\nDatos ingresados:\n";
    cout << "Fuerza de rozamiento: " << fuerzaRozamiento << " N\n";
    cout << "Fuerza normal: " << fuerzaNormal << " N\n";

    cout << "\nRESULTADO\n";
    cout << "El coeficiente de friccion es: " << coeficienteFriccion << endl;
    presionarEnterParaContinuar();
}

// Función para calcular el COEFICIENTE DE FRICCIÓN usando la ECUACIÓN 2 (u = (F - ma) / (mg))
void calcularYMostrarCoeficienteFriccionCuerpoEnMovimientoEcuacion2PH() {
    double fuerza, masa, aceleracion;

    // Solicitar y validar la fuerza
    do {
        cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
        cout << "Ingrese la fuerza (N): ";
        fuerza = leerNumero();
    } while (!validarMayorCero(fuerza, "fuerza"));

    // Solicitar y validar la masa
    do {
        cout << "Ingrese la masa (kg): ";
        masa = leerNumero();
    } while (!validarMayorCero(masa, "masa"));

    // Solicitar y validar la aceleración
    do {
        cout << "Ingrese la aceleracion (m/s^2): ";
        aceleracion = leerNumero();
    } while (!validarMayorCero(aceleracion, "aceleracion"));

    // Calcular el coeficiente de fricción
    double coeficienteFriccion = (fuerza - masa * aceleracion) / (masa * GRAVEDAD);

    // Mostrar resultados
    cout << "\nDatos ingresados:\n";
    cout << "Fuerza: " << fuerza << " N\n";
    cout << "Masa: " << masa << " kg\n";
    cout << "Aceleracion: " << aceleracion << " m/s^2\n";

    cout << "\nRESULTADO\n";
    cout << "El coeficiente de friccion es: " << coeficienteFriccion << endl;
    presionarEnterParaContinuar();
}

// MENÚS //
// MENÚ PRINCIPAL DEL PROGRAMA
void menuPrincipal() {
    do {
        cout << "\nSEGUNDA LEY DE NEWTON: LEY FUNDAMENTAL DE LA DINAMICA\n";
        cout << "\n================== MENU PRINCIPAL ===================\n";
        cout << "1. Plano horizontal\n";
        cout << "2. Plano inclinado\n";
        cout << "3. Convertidor de unidades\n";
        cout << "4. Salir\n";
        cout << "\nIngrese una opcion: ";
        Opcion = leerOpcion();

        switch (Opcion) {
            case 1: // MUESTRA EL MENÚ DEL PLANO HORIZONTAL
                menuPlanoHorizontal();
                break;
            case 2: // MUESTRA EL MENÚ DEL PLANO INCLINADO
                planoInclinado();
                break;
            case 3: // MUESTRA EL MENÚ DE CONVERSIONES
                menuConvertidor();
                break;
            case 4: // SALIR DEL PROGRAMA
                cout << "Saliendo del programa...\n";
                break;
            default: // MENSAJE DE ERROR POR DEFECTO
                limpiarPantalla();
                cout << "Error: inserte una opcion del 1 al 4\n";
        }
    } while (Opcion != 4);
}

// MENÚ PLANO HORIZONTAL
void menuPlanoHorizontal() {
    limpiarPantalla();
    int opcion;
    do {
        cout << "\n====== PLANO HORIZONTAL ======\n";
        cout << "1. EN REPOSO\n";
        cout << "2. EN MOVIMIENTO\n";
        cout << "3. Volver\n";
        cout << "4. Salir\n";
        cout << "\nSeleccione el estado del cuerpo: ";
        opcion = leerOpcion();

        switch (opcion) {
            case 1: // MUESTRA EL MENÚ DEL CUERPO EN REPOSO - PLANO HORIZONTAL
                limpiarPantalla();
                menuCuerpoEnReposoPlanoHorizontal();
                break;
            case 2: // MUESTRA EL MENÚ DEL CUERPO EN MOVIMIENTO - PLANO HORIZONTAL
                limpiarPantalla();
                menuCuerpoEnMovimientoPlanoHorizontal();
                break;
            case 3: // VOLVER AL MENÚ PRINCIPAL
                limpiarPantalla();
                break;
            case 4: // SALIR DEL PROGRAMA
                cout << "Saliendo del programa...\n";
                exit(0);
            default: // MENSAJE DE ERROR POR DEFECTO
                limpiarPantalla();
                cout << "Error: inserte una opcion del 1 al 4\n";
                break;
        }
    } while (opcion != 3);
}

// Menú para el CUERPO EN REPOSO
void menuCuerpoEnReposoPlanoHorizontal() {
    int opcion;
    do {
        cout << "\nPLANO HORIZONTAL: CUERPO EN REPOSO\n";
        cout << "\nPuede calcular:\n";
        cout << "1. Peso\n";
        cout << "2. Masa\n";
        cout << "3. Fuerza normal\n";
        cout << "4. Volver\n";
        cout << "5. Salir\n";
        cout << "\nSeleccione lo que desea calcular: ";
        opcion = leerOpcion();

        switch (opcion) {
            case 1: // CALCULA Y MUESTRA EL PESO DE UN CUERPO EN REPOSO - PLANO HORIZONTAL
                limpiarPantalla();
                calcularYMostrarPeso();
                break;
            case 2: // CALCULA Y MUESTRA LA MASA DE UN CUERPO EN REPOSO - PLANO HORIZONTAL
                limpiarPantalla();
                calcularYMostrarMasaCuerpoEnReposoPH();
                break;
            case 3: // CALCULA Y MUESTRA LA FUERZA NORMAL DE UN CUERPO EN REPOSO - PLANO HORIZONTAL
                limpiarPantalla();
                calcularYMostrarFuerzaNormalCuerpoEnReposoPH();
                break;
            case 4: // VOLVER AL MENÚ ANTERIOR
                limpiarPantalla();
                break;
            case 5: // SALIR DEL PROGRAMA
                cout << "Saliendo del programa...\n";
                exit(0);
            default: // MENSAJE DE ERROR POR DEFECTO
                limpiarPantalla();
                cout << "Error: inserte una opcion del 1 al 5\n";
                break;
        }
    } while (opcion != 4);
}

// Menú para el CUERPO EN MOVIMIENTO
void menuCuerpoEnMovimientoPlanoHorizontal() {
    int opcion;
    do {
        cout << "\nPLANO HORIZONTAL: CUERPO EN MOVIMIENTO\n";
        cout << "\nPuede calcular:\n";
        cout << "1. Fuerza\n";
        cout << "2. Fuerza Normal\n";
        cout << "3. Masa\n";
        cout << "4. Aceleracion\n";
        cout << "5. Peso\n";
        cout << "6. Fuerza de rozamiento\n";
        cout << "7. Coeficiente de friccion\n";
        cout << "8. Volver\n";
        cout << "9. Salir\n";
        cout << "\nSeleccione lo que desea calcular: ";
        opcion = leerOpcion();

        switch (opcion) {
            case 1: // CALCULA Y MUESTRA LA FUERZA DE UN CUERPO EN MOVIMIENTO - PLANO HORIZONTAL
                limpiarPantalla();
                calcularYMostrarFuerzaCuerpoEnMovimientoPH();
                break;
            case 2: // CALCULA Y MUESTRA LA FUERZA NORMAL DE UN CUERPO EN MOVIMIENTO - PLANO HORIZONTAL
                limpiarPantalla();
                calcularYMostrarFuerzaNormalCuerpoEnMovimientoPH();
                break;
            case 3: // CALCULA Y MUESTRA LA MASA DE UN CUERPO EN MOVIMIENTO - PLANO HORIZONTAL
                limpiarPantalla();
                do {
                    cout << "CALCULANDO LA MASA\n\n";
                    cout << "Seleccione la ecuacion a utilizar segun los datos que disponga\n";
                    cout << "          F\n";
                    cout << "1. m = --------\n";
                    cout << "        a + ug\n\n";
                    cout << "           W\n";
                    cout << "2. m = --------\n";
                    cout << "           g\n";
                    cout << "3. Volver\n";
                    cout << "4. Salir\n\n";
                    cout << "Donde:\n";
                    cout << "m: masa (kg)\n";
                    cout << "F: fuerza (N)\n";
                    cout << "W: Peso (N)\n";
                    cout << "a: aceleracion (m/s^2)\n";
                    cout << "u: coeficiente de friccion\n";
                    cout << "g: gravedad (m/s^2)\n\n";
                    cout << "Seleccione la ecuacion: ";
                    Ecuacion = leerOpcion();

                    switch (Ecuacion){
                        // SE CALCULA LA MASA CON LA ECUACIÓN 1
                        case 1:
                            limpiarPantalla();
                            calcularYMostrarMasaCuerpoEnMovimientoEcuacion1PH();
                            break;
                        // SE CALCULA LA MASA CON LA ECUACIÓN 2
                        case 2:
                            limpiarPantalla();
                            calcularYMostrarMasaCuerpoEnMovimientoEcuacion2PH();
                            break;
                        // VOLVER AL MENÚ PRINCIPAL
                        case 3:
                            limpiarPantalla();
                            break;
                        // SALIR DEL PROGRAMA
                        case 4:
                            cout << "Saliendo del programa...\n";
                            exit(0);
                            break;
                        default:
                            limpiarPantalla();
                            cout << "Error: inserte una opcion del 1 al 4\n";
                            break;
                    }
                } while (Ecuacion != 3);
                break;
            case 4: // CALCULA Y MUESTRA LA ACELERACIÓN DE UN CUERPO EN MOVIMIENTO - PLANO HORIZONTAL
                limpiarPantalla();
                calcularYMostrarAceleracionCuerpoEnMovimientoPH();
                break;
            case 5: // CALCULA Y MUESTRA EL PESO DE UN CUERPO EN MOVIMIENTO - PLANO HORIZONTAL
                limpiarPantalla();
                calcularYMostrarPeso();
                break;
            case 6: // CALCULA Y MUESTRA LA FUERZA DE ROZAMIENTO DE UN CUERPO EN MOVIMIENTO - PLANO HORIZONTAL
                limpiarPantalla();
                do {
                    cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
                    cout << "Seleccione la ecuacion a utilizar segun los datos que disponga\n";
                    cout << "1. Fr = uN\n";
                    cout << "2. Fr = F - ma\n";
                    cout << "3. Volver\n";
                    cout << "4. Salir\n\n";
                    cout << "Donde:\n";
                    cout << "Fr: fuerza de rozamiento (N)\n";
                    cout << "u: coeficiente de friccion\n";
                    cout << "N: fuerza normal (N)\n";
                    cout << "F: fuerza (N)\n";
                    cout << "m: masa (kg)\n";
                    cout << "a: aceleracion (m/s^2)\n\n";
                    cout << "Seleccione la ecuacion: ";
                    Ecuacion = leerOpcion();

                    switch (Ecuacion) {
                        case 1: // SE CALCULA LA FUERZA DE ROZAMIENTO CON LA ECUACIÓN 1
                            limpiarPantalla();
                            calcularYMostrarFuerzaRozamientoCuerpoEnMovimientoEcuacion1PH();
                            break;
                        case 2: // SE CALCULA LA FUERZA DE ROZAMIENTO CON LA ECUACIÓN 2
                            limpiarPantalla();
                            calcularYMostrarFuerzaRozamientoCuerpoEnMovimientoEcuacion2PH();
                            break;
                        case 3: // VOLVER AL MENÚ ANTERIOR
                            limpiarPantalla();
                            break;
                        case 4: // SALIR DEL PROGRAMA
                            cout << "Saliendo del programa...\n";
                            exit(0);
                            break;
                        default: // MENSAJE DE ERROR POR DEFECTO
                            limpiarPantalla();
                            cout << "Error: inserte una opcion del 1 al 4\n";
                            break;
                    }
                } while (Ecuacion != 3);
                break;
            case 7: // CALCULA Y MUESTRA EL COEFICIENTE DE FRICCIÓN DE UN CUERPO EN MOVIMIENTO - PLANO HORIZONTAL
                limpiarPantalla();
                do {
                    limpiarPantalla();
                    cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
                    cout << "Seleccione la ecuacion a utilizar segun los datos que disponga\n";
                    cout << "          Fr\n";
                    cout << "1. u = --------\n";
                    cout << "          N\n\n";
                    cout << "        F - ma\n";
                    cout << "2. u = --------\n";
                    cout << "          mg\n\n";
                    cout << "3. Volver\n";
                    cout << "4. Salir\n\n";
                    cout << "Donde: \n";
                    cout << "u: coeficiente de friccion\n";
                    cout << "Fr: fuerza de rozamiento (N)\n";
                    cout << "N: fuerza normal (N)\n";
                    cout << "F: fuerza (N)\n";
                    cout << "m: masa (kg)\n";
                    cout << "a: aceleracion (m/s^2)\n";
                    cout << "g: gravedad (m/s^2)\n\n";
                    cout << "Seleccione la ecuacion: ";
                    Ecuacion = leerOpcion();

                    switch (Ecuacion) {
                        case 1: // SE CALCULA EL COEFICIENTE DE FRICCIÓN CON LA ECUACIÓN 1
                            limpiarPantalla();
                            calcularYMostrarCoeficienteFriccionCuerpoEnMovimientoEcuacion1PH();
                            break;
                        case 2: // SE CALCULA EL COEFICIENTE DE FRICCIÓN CON LA ECUACIÓN 2
                            limpiarPantalla();
                            calcularYMostrarCoeficienteFriccionCuerpoEnMovimientoEcuacion2PH();
                            break;
                        case 3: // VOLVER AL MENÚ ANTERIOR
                            limpiarPantalla();
                            break;
                        case 4: // SALIR DEL PROGRAMA
                            cout << "Saliendo del programa...\n";
                            exit(0);
                            break;
                        default: // MENSAJE DE ERROR POR DEFECTO
                            limpiarPantalla();
                            cout << "Error: inserte una opcion del 1 al 4\n";
                            break;
                    }
                } while (Ecuacion != 3);
                break;
            case 8: // VOLVER AL MENÚ ANTERIOR
                limpiarPantalla();
                break;
            case 9: // SALIR DEL PROGRAMA
                cout << "Saliendo del programa...\n";
                exit(0);
            default: // MENSAJE DE ERROR POR DEFECTO
                limpiarPantalla();
                cout << "Error: inserte una opcion del 1 al 9\n";
                break;
        }
    } while (opcion != 8);
}
















// PROBLEMAS EN PLANO INCLINADO
void planoInclinado() {
    limpiarPantalla();
    double Angulo = 0, Masa = 0, Peso = 0, PesoX = 0, PesoY = 0, Fuerza_Normal = 0, Fuerza_Rozamiento = 0, Coef_Friccion = 0, Aceleracion = 0;

    do {
        cout << "\n======== PLANO INCLINADO ========\n";
        cout << "\nPuede calcular:\n";
        cout << "1. Fuerza normal\n";
        cout << "2. Masa\n";
        cout << "3. Aceleracion\n";
        cout << "4. Peso\n";
        cout << "5. Peso en X\n";
        cout << "6. Peso en Y\n";
        cout << "7. Fuerza de rozamiento\n";
        cout << "8. Coeficiente de friccion\n";
        cout << "9. Volver\n";
        cout << "10. Salir\n";
        cout << "\nSeleccione lo que desea calcular: ";
        Opcion = leerOpcion();

        switch (Opcion) {
            // CÁLCULO DE LA FUERZA NORMAL
            case 1:
                limpiarPantalla();
                cout << "CALCULANDO LA FUERZA NORMAL\n\n";
                cout << "Ingrese la masa (kg): ";
                cin >> Masa;
                cout << "Ingrese el angulo de inclinacion (grados): ";
                cin >> Angulo;
                Angulo *= M_PI / 180;  // CONVERTIR A RADIANES
                
                Fuerza_Normal = Masa * GRAVEDAD * cos(Angulo);
                
                cout << "\nDatos ingresados:\n";
                cout << "Masa: " << Masa << " kg\n";
                cout << "Angulo: " << Angulo << " rad\n";

                cout << "\nRESULTADO\n";
                cout << "La fuerza normal es: " << Fuerza_Normal << " N\n";
                presionarEnterParaContinuar();
                break;
            // CÁLCULO DE LA MASA
            case 2:
                limpiarPantalla();
                cout << "CALCULANDO LA MASA\n\n";
                cout << "Ingrese el peso (N): ";
                cin >> Peso;
                
                Masa = Peso / GRAVEDAD;

                cout << "\nDatos ingresados:\n";
                cout << "Peso: " << Peso << " N\n\n";

                cout << "RESULTADO\n";
                cout << "La masa es: " << Masa << " kg\n";
                presionarEnterParaContinuar();
                break;
            // CÁLCULO DE LA ACELERACIÓN
            case 3:
                limpiarPantalla();
                cout << "CALCULANDO LA ACELERACION\n\n";
                cout << "Ingrese el coeficiente de friccion: ";
                cin >> Coef_Friccion;
                cout << "Ingrese el angulo de inclinacion (grados): ";
                cin >> Angulo;

                Angulo *= M_PI / 180; // CONVERTIR A RADIANES
                Aceleracion = GRAVEDAD * (sin(Angulo) - Coef_Friccion * cos(Angulo));

                cout << "\nDatos ingresados:\n";
                cout << "Coeficiente de friccion: " << Coef_Friccion << endl;
                cout << "Angulo: " << Angulo << " rad\n";

                cout << "\nRESULTADO\n";
                cout << "La acelaracion es: " << Aceleracion << " m/s^2\n";
                presionarEnterParaContinuar();
                break;
            // CÁLCULO DEL PESO
            case 4:
                limpiarPantalla();
                cout << "CALCULANDO EL PESO\n\n";
                cout << "Ingrese la masa (kg): ";
                cin >> Masa;
                
                Peso = Masa * GRAVEDAD;

                cout << "\nDatos ingresados:\n";
                cout << "Masa: " << Masa << " kg\n";

                cout << "\nRESULTADO\n";
                cout << "El peso es: " << Peso << " N\n";
                presionarEnterParaContinuar();
                break;
            // CÁLCULO DEL PESO EN X
            case 5:
                limpiarPantalla();
                cout << "CALCULANDO EL PESO EN X\n\n";
                cout << "Ingrese el peso (N): ";
                cin >> Peso;
                cout << "Ingrese el angulo de inclinacion (grados): ";
                cin >> Angulo;

                Angulo *= M_PI / 180;  // CONVERTIR A RADIANES
                PesoX = Peso * sin(Angulo);

                cout << "\nDatos ingresados:\n";
                cout << "Peso: " << Peso << " N\n";
                cout << "Angulo: " << Angulo << " rad\n";

                cout << "\nRESULTADO\n";
                cout << "El peso en X es: " << PesoX << " N\n";
                presionarEnterParaContinuar();
                break;
            // CÁLCULO DEL PESO EN Y
            case 6:
                limpiarPantalla();
                cout << "CALCULANDO EL PESO EN X\n\n";
                cout << "Ingrese el peso (N): ";
                cin >> Peso;
                cout << "Ingrese el angulo de inclinacion (grados): ";
                cin >> Angulo;

                Angulo *= M_PI / 180;  // CONVERTIR A RADIANES
                PesoY = Peso * cos(Angulo);

                cout << "\nDatos ingresados:\n";
                cout << "Peso: " << Peso << " N\n";
                cout << "Angulo: " << Angulo << " rad\n";

                cout << "\nRESULTADO\n";
                cout << "El peso en Y es: " << PesoY << " N\n";
                presionarEnterParaContinuar();
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
                cin >> Ecuacion;

                if(Ecuacion == 1){
                    limpiarPantalla();
                    cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
                    cout << "Ingrese el coeficiente de friccion: ";
                    cin >> Coef_Friccion;
                    cout << "Ingrese la fuerza normal (N): ";
                    cin >> Fuerza_Normal;

                    Fuerza_Rozamiento = Coef_Friccion * Fuerza_Normal;

                    cout << "\nDatos ingresados:\n";
                    cout << "Coeficiente de friccion: " << Coef_Friccion << endl;
                    cout << "Fuerza normal: " << Fuerza_Normal << " N\n";

                    cout << "\nRESULTADO\n";
                    cout << "La fuerza de rozamiento es: " << Fuerza_Rozamiento << " N\n";
                    presionarEnterParaContinuar();
                } else if(Ecuacion == 2){
                    limpiarPantalla();
                    cout << "CALCULANDO LA FUERZA DE ROZAMIENTO\n\n";
                    cout << "Ingrese la masa (kg): ";
                    cin >> Masa;
                    cout << "Ingrese el angulo de inclinacion (grados): ";
                    cin >> Angulo;
                    cout << "Ingrese la aceleracion (m/s^2): ";
                    cin >> Aceleracion;

                    Angulo *= M_PI / 180;  // CONVERTIR A RADIANES
                    Fuerza_Rozamiento = Masa * ((GRAVEDAD * sin(Angulo)) - Aceleracion);

                    cout << "\nDatos ingresados:\n";
                    cout << "Masa: " << Masa << " kg\n";
                    cout << "Angulo: " << Angulo << " rad\n";
                    cout << "Aceleracion: " << Aceleracion << " m/s^2\n";

                    cout << "\nRESULTADO\n";
                    cout << "La fuerza de rozamiento es: " << Fuerza_Rozamiento << " N\n";
                    presionarEnterParaContinuar();
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
                cin >> Ecuacion;
                if (Ecuacion == 1){
                    limpiarPantalla();
                    cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
                    cout << "Ecuacion seleccionada:\n";
                    cout << "          Fr\n";
                    cout << "1. u = --------\n";
                    cout << "          N\n\n";
                    cout << "Ingrese la fuerza de rozamiento (N): ";
                    cin >> Fuerza_Rozamiento;
                    cout << "Ingrese la fuerza normal (N): ";
                    cin >> Fuerza_Normal;

                    Coef_Friccion = Fuerza_Rozamiento / Fuerza_Normal;

                    cout << "\nDatos ingresados:\n";
                    cout << "Fuerza de rozamiento: " << Fuerza_Rozamiento << " N\n";
                    cout << "Fuerza normal: " << Fuerza_Normal << " N\n";

                    cout << "\nRESULTADO\n";
                    cout << "El coeficiente de friccion es: " << Coef_Friccion << endl;
                    presionarEnterParaContinuar();
                } else if (Ecuacion == 2){
                    limpiarPantalla();
                    cout << "CALCULANDO EL COEFICIENTE DE FRICCION\n\n";
                    cout << "Ecuacion seleccionada:\n";
                    cout << "        gsin(x) - a\n";
                    cout << "2. u = -------------\n";
                    cout << "          gcos(x)\n\n";
                    cout << "Ingrese el angulo de inclinacion (grados): ";
                    cin >> Angulo;
                    cout << "Ingrese la aceleracion (m/s^2): ";
                    cin >> Aceleracion;

                    Angulo *= M_PI / 180;  // CONVERTIR A RADIANES
                    Coef_Friccion = (GRAVEDAD * sin(Angulo) - Aceleracion) / (GRAVEDAD * cos(Angulo));

                    cout << "\nDatos ingresados:\n";
                    cout << "Angulo: " << Angulo << " rad\n";
                    cout << "Aceleracion: " << Aceleracion << " m/s^2\n";

                    cout << "\nRESULTADO\n";
                    cout << "El coeficiente de friccion es: " << Coef_Friccion << endl;
                    presionarEnterParaContinuar();
                }
                break;
            // VOLVER AL MENÚ ANTERIOR
            case 9:
                limpiarPantalla();
                break;
            // SALIR DEL PROGRAMA
            case 10:
                cout << "Saliendo del programa...\n";
                exit(0);
                break;
            default:
                limpiarPantalla();
                cout << "Error, inserte una opcion del 1 al 10\n";
                break;
        }
    } while (Opcion != 9);
}

// MENÚ CONVERTIDOR DE UNIDADES
void menuConvertidor() {
    limpiarPantalla();
    do {
        cout << "\n| CONVERTIDOR DE UNIDADES |\n";
        cout << "\n1. Fuerza\n";
        cout << "2. Aceleracion\n";
        cout << "3. Masa\n";
        cout << "4. Angulos\n";
        cout << "5. Volver\n";
        cout << "6. Salir\n";
        cout << "\nIngrese una opcion: ";
        Opcion = leerOpcion();

        switch (Opcion) {
            // CONVERSIÓN DE FUERZA
            case 1:
                conversionFuerza();
                break;
            // CONVERSIÓN DE ACELERACIÓN
            case 2:
                conversionAceleracion();
                break;
            // CONVERSIÓN DE MASA
            case 3:
                conversionMasa();
                break;
            // CONVERSIÓN DE ÁNGULOS
            case 4:
                conversionAngulos();
                break;
            // VOLVER AL MENÚ PRINCIPAL
            case 5:
                limpiarPantalla();
                break;
            // SALIR DEL PROGRAMA
            case 6:
                cout << "Saliendo del programa...\n";
                exit(0);
                break;
            default:
                limpiarPantalla();
                cout << "Error, inserte una opcion del 1 al 6\n";
                break;
        }
    } while (Opcion != 5);
}

// INGRESO DE DATOS EN CONVERSIONES
void ingresoDatosConversion() {
    cout << "\nIngrese el valor a convertir: ";
    cin >> Valor;
}

// PROCEDIMIENTO CONVERSIÓN DE FUERZA
void conversionFuerza() {
    limpiarPantalla();
    
    do {
        cout << "\nCONVERSIONES DE FUERZA\n\n";
        cout << " 1. Newtons        (N)   > Dinas\n";
        cout << " 2. Dinas                > Newtons       (N)\n";
        cout << " 3. Newtons        (N)   > Libras-fuerza (lbf)\n";
        cout << " 4. Libras-fuerza  (lbf) > Newtons       (N)\n";
        cout << " 5. Newtons        (N)   > Kilopondios   (kp)\n";
        cout << " 6. Kilopondios    (kp)  > Newtons       (N)\n";
        cout << " 7. Kilopondios    (kp)  > Libras-fuerza (lbf)\n";
        cout << " 8. Libras-fuerza  (lbf) > Kilopondios   (kp)\n";
        cout << " 9. Volver\n";
        cout << "10. Salir\n";
        cout << "\nIngrese una opcion: ";
        Opcion = leerOpcion();

        switch (Opcion){
            // NEWTONS A DINAS
            case 1:
                ingresoDatosConversion();
                Resultado = Valor * 1e5; // 1 N = 100000 Dinas
                cout << Valor << " N = " << Resultado << " Dinas\n";
                presionarEnterParaContinuar();
                break;
            // DINAS A NEWTONS
            case 2:
                ingresoDatosConversion();
                Resultado = Valor / 1e5;
                cout << Valor << " Dinas = " << Resultado << " N\n";
                presionarEnterParaContinuar();
                break;
            // NEWTONS A LIBRAS-FUERZA
            case 3:
                ingresoDatosConversion();
                Resultado = Valor / 4.44822; // 1 lbf = 4.44822 N
                cout << Valor << " N = " << Resultado << " lbf\n";
                presionarEnterParaContinuar();
                break;
            // LIBRAS-FUERZA A NEWTONS
            case 4:
                ingresoDatosConversion();
                Resultado = Valor * 4.44822;
                cout << Valor << " lbf = " << Resultado << " N\n";
                presionarEnterParaContinuar();
                break;
            // NEWTONS A KILOPONDIOS
            case 5:
                ingresoDatosConversion();
                Resultado = Valor / 9.80665; // 1 kp = 9.80665 N
                cout << Valor << " N = " << Resultado << " kp\n";
                presionarEnterParaContinuar();
                break;
            // KILOPONDIOS A NEWTONS
            case 6:
                ingresoDatosConversion();
                Resultado = Valor * 9.80665;
                cout << Valor << " kp = " << Resultado << " N\n";
                presionarEnterParaContinuar();
                break;
            // KILOPONDIOS A LIBRAS-FUERZA
            case 7:
                ingresoDatosConversion();
                Resultado = Valor * 2.20462; // 1 kp = 2.20462 lbf
                cout << Valor << " kp = " << Resultado << " lbf\n";
                presionarEnterParaContinuar();
                break;
            // LIBRAS-FUERZA A KILOPONDIOS
            case 8:
                ingresoDatosConversion();
                Resultado = Valor / 2.20462;
                cout << Valor << " lbf = " << Resultado << " kp\n";
                presionarEnterParaContinuar();
                break;
            // VOLVER AL MENÚ ANTERIOR
            case 9:
                limpiarPantalla();
                break;
            // SALIR DEL PROGRAMA
            case 10:
                cout << "Saliendo del programa...\n";
                exit(0);
                break;
            default:
                limpiarPantalla();
                cout << "Error, inserte una opcion del 1 al 10\n";
                break;
        }
    } while (Opcion != 9);
}

// PROCEDIMIENTO CONVERSIÓN DE ACELERACIÓN
void conversionAceleracion() {
    limpiarPantalla();

    do {
        cout << "\nCONVERSIONES DE ACELERACION\n\n";
        cout << "1. m/s^2   > ft/s^2\n";
        cout << "2. ft/s^2  > m/s^2\n";
        cout << "3. m/s^2   > cm/s^2\n";
        cout << "4. cm/s^2  > m/s^2\n";
        cout << "5. m/s^2   > km/h^2\n";
        cout << "6. km/h^2  > m/s^2\n";
        cout << "7. Volver\n";
        cout << "8. Salir\n";
        cout << "\nIngrese una opcion: ";
        Opcion = leerOpcion();

        switch (Opcion) {
            // m/s^2 a ft/s^2
            case 1:
                ingresoDatosConversion();
                Resultado = Valor * 3.28084;
                cout << Valor << " m/s^2 = " << Resultado << " ft/s^2\n";
                presionarEnterParaContinuar();
                break;
            // ft/s^2 a m/s^2
            case 2:
                ingresoDatosConversion();
                Resultado = Valor / 3.28084;
                cout << Valor << " ft/s^2 = " << Resultado << " m/s^2\n";
                presionarEnterParaContinuar();
                break;
            // m/s^2 a cm/s^2
            case 3:
                ingresoDatosConversion();
                Resultado = Valor * 100;
                cout << Valor << " m/s^2 = " << Resultado << " cm/s^2\n";
                presionarEnterParaContinuar();
                break;
            // cm/s^2 a m/s^2
            case 4:
                ingresoDatosConversion();
                Resultado = Valor / 100;
                cout << Valor << " cm/s^2 = " << Resultado << " m/s^2\n";
                presionarEnterParaContinuar();
                break;
            // m/s^2 a km/h^2
            case 5:
                ingresoDatosConversion();
                Resultado = Valor * 12960; // 1 m/s^2 = 12960 km/h^2
                cout << Valor << " m/s^2 = " << Resultado << " km/h^2\n";
                presionarEnterParaContinuar();
                break;
            // km/h^2 a m/s^2
            case 6:
                ingresoDatosConversion();
                Resultado = Valor / 12960;
                cout << Valor << " km/h^2 = " << Resultado << " m/s^2\n";
                presionarEnterParaContinuar();
                break;
            // VOLVER AL MENÚ ANTERIOR
            case 7:
                limpiarPantalla();
                break;
            // SALIR DEL PROGRAMA
            case 8:
                cout << "Saliendo del programa...\n";
                exit(0);
                break;
            default:
                limpiarPantalla();
                cout << "Error, inserte una opcion del 1 al 8\n";
                break;
        }
    } while (Opcion != 7);
    
}

// PROCEDIMIENTO CONVERSIÓN DE MASA
void conversionMasa() {
    limpiarPantalla();

    do {
        cout << "\nCONVERSIONES DE MASA\n\n";
        cout << " 1. Kilogramos (kg)  > Gramos     (g)\n";
        cout << " 2. Gramos     (g)   > Kilogramos (kg)\n";
        cout << " 3. Kilogramos (kg)  > Slugs\n";
        cout << " 4. Slugs            > Kilogramos (kg)\n";
        cout << " 5. Kilogramos (kg)  > Libras     (lb)\n";
        cout << " 6. Libras     (lb)  > Kilogramos (kg)\n";
        cout << " 7. Kilogramos (kg)  > Onzas      (oz)\n";
        cout << " 8. Onzas      (oz)  > Kilogramos (kg)\n";
        cout << " 9. Kilogramos (kg)  > Toneladas  (t)\n";
        cout << "10. Toneladas  (t)   > Kilogramos (kg)\n";
        cout << "11. Volver\n";
        cout << "12. Salir\n";
        cout << "\nIngrese una opcion: ";
        Opcion = leerOpcion();

        switch (Opcion) {
            // KILOGRAMOS A GRAMOS
            case 1:
                ingresoDatosConversion();
                Resultado = Valor * 1000; // 1 kg = 1000 g
                cout << Valor << " kg = " << Resultado << " g\n";
                presionarEnterParaContinuar();
                break;
            // GRAMOS A KILOGRAMOS
            case 2:
                ingresoDatosConversion();
                Resultado = Valor / 1000;
                cout << Valor << " g = " << Resultado << " kg\n";
                presionarEnterParaContinuar();
                break;
            // KILOGRAMOS A SLUGS
            case 3:
                ingresoDatosConversion();
                Resultado = Valor / 14.5939; // 1 slug = 14.5939 kg
                cout << Valor << " kg = " << Resultado << " slugs\n";
                presionarEnterParaContinuar();
                break;
            // SLUGS A KILOGRAMOS
            case 4:
                ingresoDatosConversion();
                Resultado = Valor * 14.5939;
                cout << Valor << " slugs = " << Resultado << " kg\n";
                presionarEnterParaContinuar();
                break;
            // KILOGRAMOS A LIBRAS
            case 5:
                ingresoDatosConversion();
                Resultado = Valor * 2.20462; // 1 kg = 2.20462 lb
                cout << Valor << " kg = " << Resultado << " lb\n";
                presionarEnterParaContinuar();
                break;
            // LIBRAS A KILOGRAMOS
            case 6:
                ingresoDatosConversion();
                Resultado = Valor / 2.20462;
                cout << Valor << " lb = " << Resultado << " kg\n";
                presionarEnterParaContinuar();
                break;
            // KILOGRAMOS A ONZAS
            case 7:
                ingresoDatosConversion();
                Resultado = Valor * 35.274; // 1 kg = 35.274 oz
                cout << Valor << " kg = " << Resultado << " oz\n";
                presionarEnterParaContinuar();
                break;
            // ONZAS A KILOGRAMOS
            case 8:
                ingresoDatosConversion();
                Resultado = Valor / 35.274;
                cout << Valor << " oz = " << Resultado << " kg\n";
                presionarEnterParaContinuar();
                break;
            // KILOGRAMOS A TONELADAS
            case 9:
                ingresoDatosConversion();
                Resultado = Valor / 1000; // 1 tonelada = 1000 kg
                cout << Valor << " kg = " << Resultado << " t\n";
                presionarEnterParaContinuar();
                break;
            // TONELADAS A KILOGRAMOS
            case 10:
                ingresoDatosConversion();
                Resultado = Valor * 1000;
                cout << Valor << " t = " << Resultado << " kg\n";
                presionarEnterParaContinuar();
                break;
            // VOLVER AL MENÚ ANTERIOR
            case 11:
                limpiarPantalla();
                break;
            // SALIR DEL PROGRAMA
            case 12:
                cout << "Saliendo del programa...\n";
                exit(0);
                break;
            default:
                limpiarPantalla();
                cout << "Error, inserte una opcion del 1 al 12\n";
                break;
        }
    } while (Opcion != 11);
}

// PROCEDIMIENTO CONVERSIÓN DE ÁNGULOS
void conversionAngulos() {
    limpiarPantalla();

    do {
        cout << "\nCONVERSIONES DE ANGULOS\n\n";
        cout << "1. Grados   (°)    > Radianes (rad)\n";
        cout << "2. Radianes (rad)  > Grados   (°)\n";
        cout << "3. Volver\n";
        cout << "4. Salir\n";
        cout << "\nIngrese una opcion: ";
        Opcion = leerOpcion();

        switch (Opcion) {
            // GRADOS A RADIANES
            case 1:
                ingresoDatosConversion();
                Resultado = Valor * (M_PI / 180); // 1° = pi/180 rad
                cout << Valor << "° = " << Resultado << " rad\n";
                presionarEnterParaContinuar();
                break;
            // RADIANES A GRADOS
            case 2:
                ingresoDatosConversion();
                Resultado = Valor * (180 / M_PI); // 1 rad = 180/pi °
                cout << Valor << " rad = " << Resultado << "°\n";
                presionarEnterParaContinuar();
                break;
            // VOLVER AL MENÚ ANTERIOR
            case 3:
                limpiarPantalla();
                break;
            // SALIR DEL PROGRAMA
            case 4:
                cout << "Saliendo del programa...\n";
                exit(0);
                break;
            default:
                limpiarPantalla();
                cout << "Error, inserte una opcion del 1 al 4\n";
                break;
        }
    } while (Opcion != 3);
}