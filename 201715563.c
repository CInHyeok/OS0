#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid; //ID
    int arrival_time; //도착시간
    int code_bytes; //코드길이(바이트)
} process; //프로세스 구조체

typedef struct{
    unsigned char operation; //operation
    unsigned char length;   //length
} code; //코드 구조체 

int main(int argc, char* argv[]){
    process p_data; //프로세스 구조체 변수 선언
    code c_data; // 코드 구조체 변수 선언
 
    while(fread(&p_data,sizeof(process),1,stdin) == 1){ //프로세스 구조체 크기만큼 읽어들임
        fprintf(stdout,"%d %d %d \n",p_data.pid,p_data.arrival_time,p_data.code_bytes); //프로세스 정보 출력
        for(int j=0;j<p_data.code_bytes/2;j++){ // operation 과 lenghth가 코드 구조체안에 있기 때문에 프로세스 코드길이의 절반만큼 반복
            fread(&c_data,sizeof(code),1,stdin); //코드 구조체 크기만큼 읽어들임
            fprintf(stdout,"%d %d \n",c_data.operation,c_data.length); // 코드 정보 출력
        }
    }
}