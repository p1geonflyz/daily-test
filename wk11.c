#include <stdio.h>

//ȸ�����԰� �α����� �ϴ� ���α׷��� �ۼ�

//1. ȸ������ (�Է�)

//2. �α��� (���̵�� �н����尡 ��ġ�ϴ��� ���θ� �Ǵ�)

struct member {

    char id[10];

    char password[20];

    char name[20];

    int phone;

};

void member_login(struct member* m, int count);

void member_join(struct member* m);



main()

{

    struct member m[100];

    int select, member_count = 0;

    while (1) {  //1:ȸ������, 2:�α���, 3:���� �������ּ��� -> 

        printf("1:ȸ������, 2:�α���, 3:���� �������ּ��� -> ");

        scanf_s("%d", &select);

        if (select == 1) {

            member_join(&m[member_count]);

            member_count += 1;

        }

        else if (select == 2)

            member_login(&m, member_count);

        else

            break;

    }

    for (int i = 0; i < member_count; i++) {

        printf("%s %s %s %d\n", m[i].id, m[i].password, m[i].name, m[i].phone);

    }

}



void member_join(struct member* m) {

    printf("ȸ�� ���̵� �Է��ϼ��� : ");

    scanf_s("%s", m->id, 10);

    printf("ȸ�� �н����带 �Է��ϼ��� : ");

    scanf_s("%s", m->password, 20);

    printf("ȸ�� �̸��� �Է��ϼ��� : ");

    scanf_s("%s", m->name, 20);

    printf("ȸ�� ��ȭ��ȣ�� �Է��ϼ��� : ");

    scanf_s("%d", &m->phone);

}

void member_login(struct member* m, int count) {  //���̵�� �н����带 �Է¹޾Ƽ�, ���� ȸ������Ʈ���� ������ �ִ��� ���θ� �Ǵ�.

    char tempId[10], tempPassword[20];

    printf("�α����� �մϴ�. ");

    printf("���̵� �Է��ϼ��� : ");

    scanf_s("%s", tempId, 10);

    printf("�н����带 �Է��ϼ��� : ");

    scanf_s("%s", tempPassword, 20);

    for (int i = 0; i < count; i++) {

        if (!strcmp(tempId, m[i].id)) {

            if (!strcmp(tempPassword, m[i].password))

                printf("����\n");

        }

    }

}