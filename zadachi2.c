#include <stdio.h>
float lice_kvadrat(float a) { return a * a; }
float obikolka_kvadrat(float a) { return 4 * a; }

float lice_prav(float a, float b) { return a * b; }
float obikolka_prav(float a, float b) { return 2 * (a + b); }

float lice_tri(float a, float h) { return (a * h) / 2.0; } 
float obikolka_tri(float a, float b, float c) { return a + b + c; }

float lice_krug(float r) { return 3.14159 * r * r; }
float obikolka_krug(float r) { return 2 * 3.14159 * r; }

float lice_trapec(float a, float b, float h) { return ((a + b) * h) / 2.0; }
float obikolka_trapec(float a, float b, float c, float d) { return a + b + c + d; }

void task1() {
    int izbor;
    printf("\n1-Kvadrat, 2-Pravougulnik, 3-Triugulnik, 4-Krug, 5-Trapec: ");
    scanf("%d", &izbor);

    if (izbor == 1) {
        float a; printf("Strana: "); scanf("%f", &a);
        printf("Lice: %.2f, Obikolka: %.2f\n", lice_kvadrat(a), obikolka_kvadrat(a));
    } else if (izbor == 2) {
        float a, b; printf("Dve strani: "); scanf("%f %f", &a, &b);
        printf("Lice: %.2f, Obikolka: %.2f\n", lice_prav(a,b), obikolka_prav(a,b));
    } else if (izbor == 3) {
        float a, b, c, h; 
        printf("Osnova i visochina (za lice): "); scanf("%f %f", &a, &h);
        printf("Drugite dve strani (za obikolka): "); scanf("%f %f", &b, &c);
        printf("Lice: %.2f, Obikolka: %.2f\n", lice_tri(a,h), obikolka_tri(a,b,c));
    } else if (izbor == 4) {
        float r; printf("Radius: "); scanf("%f", &r);
        printf("Lice: %.2f, Obikolka: %.2f\n", lice_krug(r), obikolka_krug(r));
    } else if (izbor == 5) {
        float a, b, c, d, h; 
        printf("Dve osnovi i visochina: "); scanf("%f %f %f", &a, &b, &h);
        printf("Dve bedra: "); scanf("%f %f", &c, &d);
        printf("Lice: %.2f, Obikolka: %.2f\n", lice_trapec(a,b,h), obikolka_trapec(a,b,c,d));
    }
}
void task2() {
    int n, sum = 0, count = 0;
    printf("\nBroy chisla: "); scanf("%d", &n);
    int arr[100];
    
    printf("Vuvedi %d chisla: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] % 2 == 0) count++;
    }

    int max = arr[0], min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    printf("Suma: %d\nMax: %d\nMin: %d\nChetni: %d\n", sum, max, min, count);
    
    printf("Oburnat: ");
    for(int i = n - 1; i >= 0; i--) printf("%d ", arr[i]);
    printf("\n");
}
void task3() {
    int n, prosto = 1, sum = 0, br = 0, rev = 0;
    printf("\nVuvedi chislo: "); scanf("%d", &n);
    if (n < 2) prosto = 0;
    for (int i = 2; i < n; i++) if (n % i == 0) prosto = 0;
    
    if (prosto == 1) printf("Prosto e.\n"); else printf("Ne e prosto.\n");
    int temp = n;
    while (temp > 0) {
        sum += temp % 10;
        rev = rev * 10 + (temp % 10);
        br++;
        temp /= 10;
    }
    printf("Suma cifri: %d\nBroy cifri: %d\nOburnato: %d\n", sum, br, rev);
}
void task4() {
    int izbor;
    float a, b;
    printf("\n1-Subirane, 2-Izvajdane, 3-Umnojenie, 4-Delenie, 5-Stepenuvane, 6-NOD: ");
    scanf("%d", &izbor);
    printf("Vuvedi 2 chisla: "); scanf("%f %f", &a, &b);

    if (izbor == 1) printf("Rezultat: %.2f\n", a + b);
    else if (izbor == 2) printf("Rezultat: %.2f\n", a - b);
    else if (izbor == 3) printf("Rezultat: %.2f\n", a * b);
    else if (izbor == 4 && b != 0) printf("Rezultat: %.2f\n", a / b);
    else if (izbor == 5) {
        float rezultat = 1;
        for(int i = 0; i < (int)b; i++) rezultat *= a;
        printf("Rezultat: %.2f\n", rezultat);
    }
    else if (izbor == 6) {
        int x = (int)a, y = (int)b;
        while (y != 0) { int t = y; y = x % y; x = t; }
        printf("Rezultat (NOD): %d\n", x);
    }
}
void task5() {
    char s[100];
    printf("\nVuvedi tekst: ");
    scanf(" %[^\n]", s); 
    int len = 0, glavni = 0, malki = 0, cifri = 0, palindrom = 1;
    while(s[len] != '\0') {
        if(s[len] >= 'A' && s[len] <= 'Z') glavni++;
        if(s[len] >= 'a' && s[len] <= 'z') malki++;
        if(s[len] >= '0' && s[len] <= '9') cifri++;
        len++;
    }

   
    for(int i = 0; i < len / 2; i++) {
        if(s[i] != s[len - 1 - i]) palindrom = 0;
    }

    printf("Duljina: %d\nGlavni: %d\nMalki: %d\nCifri: %d\n", len, glavni, malki, cifri);
    if(palindrom == 1) printf("Nizut e palindrom.\n"); 
    else printf("Nizut NE E palindrom.\n");
}
int main() {
    int ch;
    do {
        printf("\n--- MENU ---\n1. Geometriya\n2. Masiv\n3. Chislo\n4. Kalkulator\n5. Tekst\n0. Izhod\nIzbor: ");
        scanf("%d", &ch);
        
        if(ch == 1) task1();
        else if(ch == 2) task2();
        else if(ch == 3) task3();
        else if(ch == 4) task4();
        else if(ch == 5) task5();
        
    } while (ch != 0);
    return 0;
}