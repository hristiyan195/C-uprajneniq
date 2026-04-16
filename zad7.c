#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void task1() {
    int n, m;
    printf("\nZadacha 1\nVuvedete broi redove i koloni: ");
    scanf("%d %d", &n, &m);
    int mat[100][100];
    
    printf("Vuvedete elementite na masiva:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    bool valid = true;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(mat[i][j] < mat[i][j-1]) valid = false;
        }
    }
    for(int j = 0; j < m; j++) {
        for(int i = 1; i < n; i++) {
            if(mat[i][j] > mat[i-1][j]) valid = false;
        }
    }

    if(valid) printf("Rezultat: Yes (1)\n");
    else printf("Rezultat: No (0)\n");
}

void task2() {
    int n, m;
    printf("\nZadacha 2\nVuvedete broi redove i koloni: ");
    scanf("%d %d", &n, &m);
    int mat[100][100];
    
    printf("Vuvedete elementite na masiva:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int maxSum = -1000000;
    int bestVal = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int di = -1; di <= 1; di++) {
                for(int dj = -1; dj <= 1; dj++) {
                    if(di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        sum += mat[ni][nj];
                    }
                }
            }
            if(sum > maxSum) {
                maxSum = sum;
                bestVal = mat[i][j];
            }
        }
    }
    printf("Chisloto s nai-golqm sbor na okolnite e: %d\n", bestVal);
}

void task3() {
    int n, m;
    printf("\nZadacha 3\nVuvedete broi redove i koloni: ");
    scanf("%d %d", &n, &m);
    int mat[100][100];
    int maxVal = -1000000, minVal = 1000000;
    int maxRow = 0, minRow = 0;

    printf("Vuvedete elementite na masiva:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
            if(mat[i][j] > maxVal) { maxVal = mat[i][j]; maxRow = i; }
            if(mat[i][j] < minVal) { minVal = mat[i][j]; minRow = i; }
        }
    }

    for(int j = 0; j < m; j++) {
        int temp = mat[maxRow][j];
        mat[maxRow][j] = mat[minRow][j];
        mat[minRow][j] = temp;
    }

    printf("Masivut sled razmianata:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void task4() {
    int n, m;
    printf("\nZadacha 4\nVuvedete broi hora (N) i broi priyatelstva (M): ");
    scanf("%d %d", &n, &m);
    
    int *degrees = (int*)calloc(100001, sizeof(int));
    
    printf("Vuvedete %d dvoiki priyateli:\n", m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        degrees[u]++;
        degrees[v]++;
    }
    
    int q;
    printf("Vuvedete nomer na chovek, za kogoto tursite broi priyateli: ");
    scanf("%d", &q);
    printf("Chovek %d ima %d priyateli.\n", q, degrees[q]);
    
    free(degrees);
}

void task5() {
    printf("\nZadacha 5\n(Vuvedete komanda 0 0 za krai na zadachata)\n");
    int arr[100000];
    int size = 0;
    int cmd, x;
    
    while(true) {
        printf("Vuvedete komanda (1:dobavi, 2:iztrii, 3:nameri N-to nai-malko, 0:izhod): ");
        scanf("%d", &cmd);
        if (cmd == 0) break;
        
        scanf("%d", &x);
        
        if(cmd == 1) {
            arr[size++] = x;
        } else if(cmd == 2) {
            int newSize = 0;
            for(int i = 0; i < size; i++) {
                if(arr[i] != x) arr[newSize++] = arr[i];
            }
            size = newSize;
        } else if(cmd == 3) {
            int temp[100000];
            for(int i = 0; i < size; i++) temp[i] = arr[i];
            qsort(temp, size, sizeof(int), cmp);
            if(x > 0 && x <= size) printf("-> %d-toto nai-malko chislo e %d\n", x, temp[x-1]);
            else printf("-> Nyama tolkova elementi!\n");
        }
    }
}

void task6() {
    int n;
    printf("\nZadacha 6\nVuvedete broi elementi: ");
    scanf("%d", &n);
    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));
    int size1 = 0, size2 = 0;

    printf("Vuvedete chislata:\n");
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if(isPrime(val)) {
            arr2[size2++] = val;
        } else {
            arr1[size1++] = val;
        }
    }

    printf("Masiv 1 (neprosti): ");
    for(int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    printf("\nMasiv 2 (prosti): ");
    for(int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    printf("\n");

    free(arr1);
    free(arr2);
}

void task7() {
    int n, m;
    printf("\nZadacha 7\nVuvedete razmer N i M (pone 3x3): ");
    scanf("%d %d", &n, &m);
    int mat[100][100];
    
    printf("Vuvedete matricata:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int maxSum = -1000000;
    int bestI = 0, bestJ = 0;

    for(int i = 0; i <= n - 3; i++) {
        for(int j = 0; j <= m - 3; j++) {
            int sum = 0;
            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    sum += mat[i+r][j+c];
                }
            }
            if(sum > maxSum) {
                maxSum = sum;
                bestI = i;
                bestJ = j;
            }
        }
    }

    printf("Podmatricata s maksimalna suma e:\n");
    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            printf("%d ", mat[bestI+r][bestJ+c]);
        }
        printf("\n");
    }
}

void task8() {
    printf("\nZadacha 8\n");
    int *arr = (int*)malloc(1000 * sizeof(int));
    int size = 10;
    
    printf("Vuvedete 10 nachalni chisla:\n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    int num, pos;
    printf("Vuvejdai 'chislo poziciya' (vuvedi 0 za krai):\n");
    while(scanf("%d", &num) == 1 && num != 0) {
        scanf("%d", &pos);
        for(int i = size; i > pos; i--) {
            arr[i] = arr[i-1];
        }
        arr[pos] = num;
        size++;
    }

    printf("Krainiyat masiv e:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Zadacha 1 (Sortirani redove/koloni)\n");
        printf("2. Zadacha 2 (Nai-golqm sbor na okolni)\n");
        printf("3. Zadacha 3 (Razmqna na min i max red)\n");
        printf("4. Zadacha 4 (Priyatelstva)\n");
        printf("5. Zadacha 5 (Softuer s komandi)\n");
        printf("6. Zadacha 6 (Masiv s prosti chisla)\n");
        printf("7. Zadacha 7 (Podmatrica 3x3)\n");
        printf("8. Zadacha 8 (Vmukvane v masiv)\n");
        printf("0. IZHOD\n");
        printf("Izberete zadacha (0-8): ");
        
        if(scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            choice = -1;
        }

        switch(choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 0: printf("Krai na programata.\n"); break;
            default: printf("Nevaliden izbor.\n");
        }
    } while(choice != 0);

    return 0;
}