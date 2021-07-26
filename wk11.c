#include <stdio.h>

//회원가입과 로그인을 하는 프로그램
//1. 회원가입 (입력)
//2. 로그인 (아이디와 패스워드가 일치하는지 여부를 판단)
//3. 그 외 

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

    while (1) {  //1:회원가입, 2:로그인, 3:종료 선택해주세요 -> 

        printf("1:회원가입, 2:로그인, 3:종료 선택해주세요 -> ");

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

    printf("회원 아이디를 입력하세요 : ");

    scanf_s("%s", m->id, 10);

    printf("회원 패스워드를 입력하세요 : ");

    scanf_s("%s", m->password, 20);

    printf("회원 이름을 입력하세요 : ");

    scanf_s("%s", m->name, 20);

    printf("회원 전화번호를 입력하세요 : ");

    scanf_s("%d", &m->phone);

}

void member_login(struct member* m, int count) {  //아이디와 패스워드를 입력받아서, 기존 회원리스트에서 같은게 있는지 여부를 판단.

    char tempId[10], tempPassword[20];

    printf("로그인을 합니다. ");

    printf("아이디를 입력하세요 : ");

    scanf_s("%s", tempId, 10);

    printf("패스워드를 입력하세요 : ");

    scanf_s("%s", tempPassword, 20);

    for (int i = 0; i < count; i++) {

        if (!strcmp(tempId, m[i].id)) {

            if (!strcmp(tempPassword, m[i].password))

                printf("같음\n");
        }
    }
}
//다른 기능 추가 시, 종료를 뒤로 보낼 수 있음
