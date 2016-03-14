#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 2

double matrix[N][M];

void init_matrix() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            matrix[i][j] = rand() % 20;
}

void read_file(FILE *fp) {
    for (int i = 0; i < N; i++)
        fscanf(fp, "%lf %lf\n", &matrix[i][0], &matrix[i][1]);
}

void write_in_file(FILE *fp) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            fprintf(fp, "%lf ", matrix[i][j]);
        fprintf(fp, "\n");
    }
}

void print_matrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%lf ", matrix[i][j]);
        printf("\n");
    }
}

int main(void) {
    FILE *fp_read, *fp_write;

    fp_read = fopen("test.pixel", "r");
    fp_write = fopen("test.pixel", "w");

    init_matrix();
    write_in_file(fp_write);

    read_file(fp_read);
    print_matrix();
}
