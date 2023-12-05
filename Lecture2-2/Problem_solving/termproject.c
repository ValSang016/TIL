#define _CRT_SECURE_NO_WARNINGS
// 필요한 헤더 파일 포함
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 등록 정보를 저장하는 구조체 정의
struct Registraion {
    int tag;
    char date_registered[11];
    char fee_paid[4];
    char name[20];
    int age;
    char organization[50];
    char job[20];
} registraion[30];

// P2 시작부분
// 연결 리스트의 노드를 나타내는 구조체 정의
struct Node {
    struct Registraion data;
    struct Node* next;
};

// 연결 리스트에 노드를 삽입하는 함수
void insertNode(struct Node** head, struct Registraion data) {
    // 새 노드 동적 할당
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("메모리 할당 실패");
        exit(EXIT_FAILURE);
    }

    // 데이터 삽입
    newNode->data = data;
    newNode->next = NULL;

    // 연결 리스트의 처음에 삽입
    if (*head == NULL || data.age < (*head)->data.age) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        // 중간이나 끝에 삽입
        struct Node* current = *head;
        while (current->next != NULL && data.age > current->next->data.age) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// 연결 리스트의 메모리를 해제하는 함수
void freeList(struct Node* head) {
    // 연결 리스트의 메모리 해제
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}
//P2 마무리부분



// 나이에 따라 등록 정보를 정렬하는 함수
void sortByAge(struct Registraion registraion[], int size) {
    int i, j, minIndex;
    struct Registraion temp;

    for (i = 0; i < size - 1; ++i) {
        minIndex = i;
        for (j = i + 1; j < size; ++j) {
            // 현재 인덱스의 나이가 최소값보다 작으면 최소값을 현재 인덱스로 업데이트
            if (registraion[j].age < registraion[minIndex].age) {
                minIndex = j;
            }
        }

        // 최소값을 현재 인덱스와 교환
        if (minIndex != i) {
            temp = registraion[i];
            registraion[i] = registraion[minIndex];
            registraion[minIndex] = temp;
        }
    }
}

//P1
// 정렬된 등록 정보를 파일에 쓰는 함수
void writeToFile(struct Registraion registraion[], int size) {
    FILE* outputFile = fopen("P1.txt", "w");
    if (!outputFile) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < size; ++i) {
        fprintf(outputFile, "%d/%s/%s/%s/%d/%s/%s\n",
            registraion[i].tag, registraion[i].date_registered, registraion[i].fee_paid,
            registraion[i].name, registraion[i].age, registraion[i].organization,
            registraion[i].job);
    }

    fclose(outputFile);
}

// P3-1 (array)
// 등록료를 납부한 모든 사람을 검색하고, 해당되는 사람들의 모든 정보를 출력하는 함수
void searchFeePaid(struct Registraion registraion[], int size) {
    printf("(P3-1)Fee-Paid People:\n");
    for (int i = 0; i < size; ++i) {
        if (strcmp(registraion[i].fee_paid, "yes") == 0) {
            printf("Tag: %d, Date Registered: %s, Fee Paid: %s, Name: %s, Age: %d, Organization: %s, Job: %s\n",
            registraion[i].tag, registraion[i].date_registered, registraion[i].fee_paid,
            registraion[i].name, registraion[i].age, registraion[i].organization,
            registraion[i].job);
        }
    }
    printf("\n");

}

// P4-1 (array)
// 가천대학교에서 온 모든 사람을 검색하고, 해당되는 사람들의 모든 정보를 출력하는 함수
void searchGachonUniversity(struct Registraion registraion[], int size) {
    printf("(P4-1)People from Gachon University:\n");
    for (int i = 0; i < size; ++i) {
        if (strcmp(registraion[i].organization, "Gachon University") == 0) {
            printf("Tag: %d, Date Registered: %s, Fee Paid: %s, Name: %s, Age: %d, Organization: %s, Job: %s\n",
            registraion[i].tag, registraion[i].date_registered, registraion[i].fee_paid,
            registraion[i].name, registraion[i].age, registraion[i].organization,
            registraion[i].job);
        }
    }
    printf("\n");
}


// main 함수
int main()
{
    FILE* myFile;
    myFile = NULL;

    // 등록 정보 파일 열기
    myFile = fopen("registraion_data.txt", "r");
    int size = 30;

    if (myFile == NULL) {
        printf("registraion_data.txt Could Not Be Opened.");
        return 1;
    }

    // 파일에서 등록 정보 읽기
    for (int i = 0; i < size; ++i) {
        fscanf(myFile, "%d/%10[^/]/%3[^/]/%19[^/]/%d/%49[^/]/%19s\n",
            &registraion[i].tag,
            registraion[i].date_registered,
            registraion[i].fee_paid,
            registraion[i].name,
            &registraion[i].age,
            registraion[i].organization,
            registraion[i].job);
    }

    fclose(myFile); // 파일 닫기

    // 나이에 따라 등록 정보 정렬
    sortByAge(registraion, size);
    // 정렬된 정보를 파일에 쓰기
    writeToFile(registraion, size);

    // 연결 리스트의 머리를 나타내는 포인터
    struct Node* linkedList = NULL;

    // 정렬된 데이터를 사용하여 연결 리스트에 삽입
    for (int i = 0; i < size; ++i) {
        insertNode(&linkedList, registraion[i]);
    }

    // P3-1(array)
    // 등록료를 납부한 사람을 검색하고 출력
      searchFeePaid(registraion, size);

    // P4-1
    // 가천대학교에서 온 사람을 검색하고 출력
    searchGachonUniversity(registraion, size);


    // 연결 리스트의 메모리 해제
    freeList(linkedList);

    return 0;
}