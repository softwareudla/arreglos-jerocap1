#include <stdio.h>
#include <string.h>

int main() {
    int i, j;
    float calificaciones[5][3];
    char nombres[5][50];
    char asignaturas[3][50];
    float suma_estudiante, suma_asignatura;
    float promedio_estudiante[5];
    float promedio_asignatura[3];
    float max_estudiante[5], min_estudiante[5];
    float max_asignatura[3], min_asignatura[3];
    int aprobados[3] = {0, 0, 0};
    int reprobados[3] = {0, 0, 0};

    printf("Ingrese los nombres de los 5 estudiantes:\n");
    for (i = 0; i < 5; i++) {
        printf("Estudiante %d: ", i + 1);
        fgets(nombres[i], sizeof(nombres[i]), stdin);
        size_t len = strlen(nombres[i]);
        if (len > 0 && nombres[i][len - 1] == '\n') {
            nombres[i][len - 1] = '\0';
        }
    }

    printf("\nIngrese los nombres de las 3 asignaturas:\n");
    for (j = 0; j < 3; j++) {
        printf("Asignatura %d: ", j + 1);
        fgets(asignaturas[j], sizeof(asignaturas[j]), stdin);
        size_t len = strlen(asignaturas[j]);
        if (len > 0 && asignaturas[j][len - 1] == '\n') {
            asignaturas[j][len - 1] = '\0';
        }
    }

    for (i = 0; i < 5; i++) {
        printf("\nNotas para %s:\n", nombres[i]);
        for (j = 0; j < 3; j++) {
            int valido = 0;
            while (!valido) {
                printf("  Ingrese calificación para %s (0-10): ", asignaturas[j]);
                int resultado = scanf("%f", &calificaciones[i][j]);
                if (resultado != 1) {
                    printf("  Error: Debe ingresar un número válido.\n");
                    while (getchar() != '\n');
                    valido = 0;
                } else if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("  Calificación fuera de rango. Debe estar entre 0 y 10.\n");
                    valido = 0;
                } else {
                    valido = 1;
                }
            }
        }
        while (getchar() != '\n');
    }

    for (i = 0; i < 5; i++) {
        suma_estudiante = 0;
        max_estudiante[i] = calificaciones[i][0];
        min_estudiante[i] = calificaciones[i][0];
        for (j = 0; j < 3; j++) {
            suma_estudiante += calificaciones[i][j];
            if (calificaciones[i][j] > max_estudiante[i]) {
                max_estudiante[i] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < min_estudiante[i]) {
                min_estudiante[i] = calificaciones[i][j];
            }
        }
        promedio_estudiante[i] = suma_estudiante / 3.0;
    }

    for (j = 0; j < 3; j++) {
        suma_asignatura = 0;
        max_asignatura[j] = calificaciones[0][j];
        min_asignatura[j] = calificaciones[0][j];
        for (i = 0; i < 5; i++) {
            suma_asignatura += calificaciones[i][j];
            if (calificaciones[i][j] > max_asignatura[j]) {
                max_asignatura[j] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < min_asignatura[j]) {
                min_asignatura[j] = calificaciones[i][j];
            }
            if (calificaciones[i][j] >= 6.0) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
        promedio_asignatura[j] = suma_asignatura / 5.0;
    }

    printf("\n--- Resultados por estudiante ---\n");
    for (i = 0; i < 5; i++) {
        printf("%s - Promedio: %.2f, Max: %.2f, Min: %.2f\n", 
               nombres[i], promedio_estudiante[i], max_estudiante[i], min_estudiante[i]);
    }

    printf("\n--- Resultados por asignatura ---\n");
    for (j = 0; j < 3; j++) {
        printf("%s - Promedio: %.2f, Max: %.2f, Min: %.2f\n", 
               asignaturas[j], promedio_asignatura[j], max_asignatura[j], min_asignatura[j]);
        printf("  Aprobados: %d, Reprobados: %d\n", aprobados[j], reprobados[j]);
    }

    return 0;
}
