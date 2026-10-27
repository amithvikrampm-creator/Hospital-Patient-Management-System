
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Patient queue[MAX];
int front = -1, rear = -1;

// Add a patient to the queue
void addPatient() {
    if (rear == MAX - 1) {
        printf("\nQueue is full!\n");
        return;
    }

    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", p.name);

    printf("Enter Patient Age: ");
    scanf("%d", &p.age);

    printf("Enter Disease: ");
    scanf(" %49[^\n]", p.disease);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = p;

    printf("\nPatient added successfully!\n");
}

// Serve the next patient
void treatPatient() {
    if (front == -1 || front > rear) {
        printf("\nNo patients waiting!\n");
        return;
    }

    printf("\nTreating Patient:\n");
    printf("ID      : %d\n", queue[front].id);
    printf("Name    : %s\n", queue[front].name);
    printf("Age     : %d\n", queue[front].age);
    printf("Disease : %s\n", queue[front].disease);

    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

// Display all waiting patients
void displayPatients() {
    int i;

    if (front == -1) {
        printf("\nNo patients in the queue!\n");
        return;
    }

    printf("\n--- Waiting Patients ---\n");

    for (i = front; i <= rear; i++) {
        printf("\nPatient ID : %d\n", queue[i].id);
        printf("Name       : %s\n", queue[i].name);
        printf("Age        : %d\n", queue[i].age);
        printf("Disease    : %s\n", queue[i].disease);
    }
}
int main() {
    int choice;

    while (1) {
        printf("\n===== HOSPITAL PATIENT MANAGEMENT =====\n");
        printf("1. Add Patient\n");
        printf("2. Treat Patient\n");
        printf("3. Display Waiting Patients\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                treatPatient();
                break;

            case 3:
                displayPatients();
                break;

            case 4:
                printf("\nExiting the system...\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
