#include <iostream>
#include <cmath>

using namespace std;

// Validar que el número ingresado sea positivo
double leerNumeroPositivo(string mensaje) {
    double numero;
    do {
        cout << mensaje;
        cin >> numero;
        if (numero <= 0) {
            cout << "El valor debe ser mayor a 0. Intente nuevamente.\n";
        }
    } while (numero <= 0);
    return numero;
}

// Validar que el número sea no negativo
double leerNumeroNoNegativo(string mensaje) {
    double numero;
    do {
        cout << mensaje;
        cin >> numero;
        if (numero < 0) {
            cout << "El valor no puede ser negativo. Intente nuevamente.\n";
        }
    } while (numero < 0);
    return numero;
}

// Menú de cálculos en plano horizontal
void planoHorizontal() {
    char estado;
    cout << "\n¿El cuerpo está en reposo (R) o en movimiento (M)? ";
    cin >> estado;
    estado = toupper(estado);

    if (estado != 'R' && estado != 'M') {
        cout << "Estado inválido. Debe ser 'R' o 'M'.\n";
        return;
    }

    cout << "\n¿Qué desea calcular?\n";
    cout << "1. Masa\n2. Fuerza neta\n3. Peso\n4. Aceleración\n";
    cout << "5. Fuerza de fricción\n6. Fuerza normal\n7. Coeficiente de fricción\nOpción: ";
    int opcion;
    cin >> opcion;

    double masa, fuerza, peso, aceleracion, fuerzaFriccion, fuerzaNormal, coefFriccion;

    switch (opcion) {
        case 1: // Calcular masa
            fuerza = leerNumeroPositivo("Ingrese la fuerza neta aplicada (N): ");
            aceleracion = leerNumeroPositivo("Ingrese la aceleración (m/s²): ");
            masa = fuerza / aceleracion;
            cout << "\nDatos ingresados:\n";
            cout << "Fuerza: " << fuerza << " N\nAceleración: " << aceleracion << " m/s²\n";
            cout << "Resultado:\nMasa: " << masa << " kg\n";
            break;
        case 2: // Calcular fuerza neta
            masa = leerNumeroPositivo("Ingrese la masa del cuerpo (kg): ");
            aceleracion = leerNumeroPositivo("Ingrese la aceleración (m/s²): ");
            fuerza = masa * aceleracion;
            cout << "\nDatos ingresados:\n";
            cout << "Masa: " << masa << " kg\nAceleración: " << aceleracion << " m/s²\n";
            cout << "Resultado:\nFuerza neta: " << fuerza << " N\n";
            break;
        case 3: // Calcular peso
            masa = leerNumeroPositivo("Ingrese la masa del cuerpo (kg): ");
            peso = masa * 9.8; // Gravedad = 9.8 m/s²
            cout << "\nDatos ingresados:\n";
            cout << "Masa: " << masa << " kg\n";
            cout << "Resultado:\nPeso: " << peso << " N\n";
            break;
        case 4: // Calcular aceleración
            fuerza = leerNumeroPositivo("Ingrese la fuerza neta aplicada (N): ");
            masa = leerNumeroPositivo("Ingrese la masa del cuerpo (kg): ");
            aceleracion = fuerza / masa;
            cout << "\nDatos ingresados:\n";
            cout << "Fuerza: " << fuerza << " N\nMasa: " << masa << " kg\n";
            cout << "Resultado:\nAceleración: " << aceleracion << " m/s²\n";
            break;
        case 5: // Calcular fuerza de fricción
            coefFriccion = leerNumeroPositivo("Ingrese el coeficiente de fricción: ");
            fuerzaNormal = leerNumeroPositivo("Ingrese la fuerza normal (N): ");
            fuerzaFriccion = coefFriccion * fuerzaNormal;
            cout << "\nDatos ingresados:\n";
            cout << "Coeficiente de fricción: " << coefFriccion << "\nFuerza normal: " << fuerzaNormal << " N\n";
            cout << "Resultado:\nFuerza de fricción: " << fuerzaFriccion << " N\n";
            break;
        case 6: // Calcular fuerza normal
            masa = leerNumeroPositivo("Ingrese la masa del cuerpo (kg): ");
            fuerzaNormal = masa * 9.8; // En plano horizontal, normal = peso
            cout << "\nDatos ingresados:\n";
            cout << "Masa: " << masa << " kg\n";
            cout << "Resultado:\nFuerza normal: " << fuerzaNormal << " N\n";
            break;
        case 7: // Calcular coeficiente de fricción
            fuerzaFriccion = leerNumeroPositivo("Ingrese la fuerza de fricción (N): ");
            fuerzaNormal = leerNumeroPositivo("Ingrese la fuerza normal (N): ");
            coefFriccion = fuerzaFriccion / fuerzaNormal;
            cout << "\nDatos ingresados:\n";
            cout << "Fuerza de fricción: " << fuerzaFriccion << " N\nFuerza normal: " << fuerzaNormal << " N\n";
            cout << "Resultado:\nCoeficiente de fricción: " << coefFriccion << "\n";
            break;
        default:
            cout << "Opción no válida.\n";
    }
}

// Menú de cálculos en plano inclinado
void planoInclinado() {
    cout << "\n¿Qué desea calcular?\n";
    cout << "1. Fuerza para mantener en equilibrio\n2. Aceleración\n3. Peso\n";
    cout << "4. Peso en X\n5. Peso en Y\n6. Fuerza normal\n";
    cout << "7. Fuerza de rozamiento\n8. Coeficiente de fricción\nOpción: ";
    int opcion;
    cin >> opcion;

    double masa, peso, angulo, fuerzaNormal, fuerzaFriccion, coefFriccion, aceleracion, fuerzaEquilibrio;

    switch (opcion) {
        case 1: // Calcular fuerza para mantener en equilibrio
            masa = leerNumeroPositivo("Ingrese la masa del cuerpo (kg): ");
            angulo = leerNumeroPositivo("Ingrese el ángulo de inclinación (°): ");
            angulo = angulo * M_PI / 180.0; // Convertir a radianes
            fuerzaEquilibrio = masa * 9.8 * sin(angulo);
            cout << "\nDatos ingresados:\n";
            cout << "Masa: " << masa << " kg\nÁngulo: " << angulo * 180.0 / M_PI << " °\n";
            cout << "Resultado:\nFuerza para mantener en equilibrio: " << fuerzaEquilibrio << " N\n";
            break;
        case 2: // Calcular aceleración
            masa = leerNumeroPositivo("Ingrese la masa del cuerpo (kg): ");
            angulo = leerNumeroPositivo("Ingrese el ángulo de inclinación (°): ");
            coefFriccion = leerNumeroNoNegativo("Ingrese el coeficiente de fricción: ");
            angulo = angulo * M_PI / 180.0; // Convertir a radianes
            aceleracion = 9.8 * (sin(angulo) - coefFriccion * cos(angulo));
            if (aceleracion < 0) aceleracion = 0; // No hay movimiento si fricción > componente x
            cout << "\nDatos ingresados:\n";
            cout << "Masa: " << masa << " kg\nÁngulo: " << angulo * 180.0 / M_PI << " °\nCoeficiente de fricción: " << coefFriccion << "\n";
            cout << "Resultado:\nAceleración: " << aceleracion << " m/s²\n";
            break;
        // Otros cálculos del plano inclinado se añadirían aquí siguiendo esta estructura
        default:
            cout << "Opción no válida.\n";
    }
}

// Menú principal
void menuPrincipal() {
    int opcion;
    do {
        cout << "\nMenú principal:\n";
        cout << "1. Cálculos en plano horizontal\n2. Cálculos en plano inclinado\n3. Salir\nOpción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: planoHorizontal(); break;
            case 2: planoInclinado(); break;
            case 3: cout << "Saliendo del programa.\n"; break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 3);
}

// Función principal
int main() {
    menuPrincipal();
    return 0;
}