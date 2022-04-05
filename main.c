#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct list{
    char todo[200];
    char deadline[100];
    struct list *next;
} *dataTodo, *head, *tail;

int jumlah = 0;

void menampilkanTodoList (){
    printf("_______________________________________\n");
    printf("TODO LIST ANDA :\n");
    int num = 0;
    dataTodo = head;
    while(dataTodo != NULL){
        num ++;
        printf("List ke-%i\n", num);
        printf("List : %s\n", dataTodo->todo);
        printf("Deadline : %s\n", dataTodo->deadline);
        printf("\n");
        dataTodo = dataTodo->next;
    }
}

void menambahTodolist(char varTodoList[], char deadline[]){
    dataTodo = (struct list*) malloc(sizeof (struct list));
    strcpy(dataTodo->todo, varTodoList);
    strcpy(dataTodo->deadline, deadline);
    if(head == NULL){
        head = tail = dataTodo;
    } else {
        tail->next = dataTodo;
        tail = dataTodo;
    }
    jumlah++;
    tail->next = NULL;
}

bool menghapusTodoList (int nomorData){
    struct list *temp = head;
    struct list *previous = head;
    if(nomorData>jumlah){
        return false;
    } else{
        if(head==NULL){
            return false;
        }else if(nomorData == 1){
            head = head ->next;
            free(temp);
            return true;
        }else if (nomorData == jumlah){
            while(temp->next!=tail){
                temp=temp->next;
            }
            free(tail);
            tail=temp;
            tail->next=NULL;
            return true;
        } else{
            for (int i = 0; i < nomorData-1; i++) {
                temp = temp->next;
            }
            for (int i = 0; i < nomorData-2; i++) {
                previous = previous->next;
            }
            previous->next = previous ->next->next;
            free(temp);
            return true;

        }
    }
}
void tampilanMenambah (){
    printf("_______________________________________\n");
    printf("TAMBAH LIST\n");
    printf("Input y untuk lanjut atau x jika batal) :");
    char tambahanTodo[200];
    char deadlineTodo[100];
    char status;
    scanf("%c", &status);
    getchar();
    if (status == 'x' || status == 'X'){
        return;
    }else if (status == 'y' || status == 'Y') {
        printf("Masukkan List :");
        gets(tambahanTodo);
        printf("Masukkan Deadline :");
        gets(deadlineTodo);
        menambahTodolist(tambahanTodo, deadlineTodo);
    } else{
        printf("Masukkan Input Yang Benar !\n");
    }
}
void tampilanMenghapus (){
    printf("_______________________________________\n");
    printf("HAPUS LIST\n");
    int angka;
    printf("Input y untuk lanjut atau x jika batal) :");
    char status;
    scanf("%c", &status);
    getchar();
    if(status == 'x' || status == 'X'){
        return;
    } else if (status == 'y' || status == 'Y'){
        printf("Masukkan nomor list yang ingin dihapus :");
        scanf("%i", &angka);
        bool sukses = menghapusTodoList(angka);
        if(sukses == false){
            printf("Maaf permintaan anda gagal\n");
        } else{
            jumlah--;
        }
    } else{
        printf("Masukkan Input Yang Benar !\n");
    }
}

void tampilanUtama (){
    printf("APLIKASI TO DO LIST\nALGORITMA DAN PEMROGRAMAN\n");
    while (true){
        fflush(stdin);
        menampilkanTodoList();
        printf("MENU\n1.\tTambah List\n2.\tHapus List\nx.\tKeluar\n");
        printf("Pilihan Anda :");
        char menu;
        scanf("%c", &menu);
        getchar();
        switch (menu){
            case  '1' :
                tampilanMenambah();
                break;
            case '2' :
                tampilanMenghapus();
                break;
            case 'x' :
                return;
            default:
                printf("Mohon Pilih Sesuai Menu !!\n");
                break;
        }
    }
}

int main() {
    tampilanUtama();
    return 0;
}