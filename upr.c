#include <stdio.h>
int areaofsquare(short side) {
    return side * side;
}

int areaofrectangle(short side1, short side2) {
    return side1 * side2; 
}

float areaoftriangle(short strana, short visochina) {
    return (strana * visochina) / 2.0; 
}

float areaofcircle(float radius) {
    return radius * radius * 3.1415926;
}


void smqnanachisla(short *chislo1, short *chislo2) {
    short temp;
    temp = *chislo1;
    *chislo1 = *chislo2;
    *chislo2 = temp;
}

int chisla(short chislo) {
    if (chislo % 2 == 0) {
        return 1;
    } else {
        return 2;
    }
}


void decimal_to_binary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int binary_array[32];
    int index = 0;

    while (num > 0) {
        binary_array[index] = num % 2;
        num = num / 2;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary_array[i]);
    }
}
void task1() {
    int type_of_body;
    float areaofbody;
    
    printf("\nVuvedete kod na figura (1-Kvadrat, 2-Pravoougulnik, 3-Triugulnik, 4-Krug): ");
    scanf("%d", &type_of_body); 
    
    switch(type_of_body) {
        case 1: { 
            int sideofsquare;
            printf("Vuvedete strana: ");
            scanf("%d", &sideofsquare); 
            areaofbody = areaofsquare(sideofsquare);
            printf("Strana: %d\nLice: %.2f\n", sideofsquare, areaofbody); 
            break;
        }
        case 2: { 
            int sideofrectangle1, sideofrectangle2;
            printf("Vuvedete dve strani: ");
            scanf("%d %d", &sideofrectangle1, &sideofrectangle2); 
            areaofbody = areaofrectangle(sideofrectangle1, sideofrectangle2);
            printf("Strani: %d, %d\nLice: %.2f\n", sideofrectangle1, sideofrectangle2, areaofbody); 
            break;
        }
        case 3: { 
            int strana, visochina;
            printf("Vuvedete strana i visochina: ");
            scanf("%d %d", &strana, &visochina);
            areaofbody = areaoftriangle(strana, visochina);
            printf("Strana: %d, Visochina: %d\nLice: %.2f\n", strana, visochina, areaofbody); 
            break;
        }
        case 4: { 
            float radius;
            printf("Vuvedete radius: ");
            scanf("%f", &radius);
            areaofbody = areaofcircle(radius);
            printf("Radius: %.2f\nLice: %.2f\n", radius, areaofbody);
            break;
        }
        default:
            printf("Greshen kod!\n");
    }
}

void task2() {
    short num1, num2;
    printf("\nVuvedete dve chisla (razdeleni s interval): ");
    scanf("%hd %hd", &num1, &num2);
    printf("PREDI razmqnata:\nParvo chislo: %hd\nVtoro chislo: %hd\n", num1, num2);
    
    smqnanachisla(&num1, &num2);
    
    printf("\nSLED razmqnata:\nParvo chislo: %hd\nVtoro chislo: %hd\n", num1, num2);
}

void task3() {
    short chislo1;
    printf("\nVuvedete chislo za proverka (chetno/nechetno): ");
    scanf("%hd", &chislo1);
    
    if (chisla(chislo1) == 1) {
        printf("Chisloto e chetno\n");
    } else {
        printf("Chisloto e nechetno\n");
    }
}

void task4() {
    int number;
    printf("\nVuvedete polojitelno desetichno chislo: ");
    scanf("%d", &number);

    printf("Dvoichnoto predstavqne na %d e: ", number);
    decimal_to_binary(number);
    printf("\n");
}




int main() {
    int choice;
    
    do {
        printf("1. Lice na geometrichni figuri\n");
        printf("2. Razmqna na dve chisla\n");
        printf("3. Proverka za chetno ili nechetno chislo\n");
        printf("4. Prevrushtane ot desetichno v dvoichno chislo\n");
        printf("0. IZHOD\n");
        printf("Izberete zadacha: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        switch(choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            default: printf("\nNevaliden izbor! Molq opitaite otnovo.\n");
        }
        
    } while (choice != 0);
    
    return 0;
}