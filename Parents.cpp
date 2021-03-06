#include "singlecircular.h"


using namespace std;
string judul,pengarang,tahun,penerbit,h,j,k,l;
int ID,g;
void CreateList(List_p &LP){
    first(LP) = NULL;
};
address_p alokasi(int ID, string judul, string pengarang, string tahun, string penerbit){
    address_p P;
    P = new elmlist_p;
    info(P).ID = ID;
    info(P).judul = judul;
    info(P).pengarang = pengarang;
    info(P).tahun = tahun;
    info(P).penerbit = penerbit;
    next(P) = NULL;
        return P;
};
void dealokasi(address_p &P){
    delete P;
};
void insertFirst(List_p &LP, address_p P){
        if (first(LP) == NULL){
            first(LP) = P;
            next(P) = first(LP);
        }
        else{
             address_p Q = first(LP);
        while(next(Q) != first(LP)){
            Q = next(Q);
        };
        next(Q) = P;
        next(P) = first(LP);
            first(LP) = P;
        }
};
void insertLast(List_p &LP, address_p P){
    if (first(LP) == NULL){
        first(LP) = P;
        next(P) = first(LP);
    }
    else{
        address_p Q = first(LP);
        while(next(Q) != first(LP)){
            Q = next(Q);
        };
        next(Q) = P;
        next(P) = first(LP);
    }
};
address_p findElm(List_p LP, int x){
    address_p Q = first(LP);
    if (first(LP) == NULL){
        Q = NULL;
    }
    else{
        while (info(Q).ID != x && next(Q) != first(LP)){
            Q = next(Q);
        }
    }
    return Q;
};
void deleteFirst(List_p &LP, address_p &P){
    if (first(LP) == NULL){

    }
    else if(next(first(LP)) == first(LP)){
        P = first(LP);
        next(P) = NULL;
        first(LP) = NULL;
        dealokasi(P);
    }
    else{
        address_p Q = first(LP);
        P = first(LP);
        while(next(Q) != first(LP)){
            Q = next(Q);
        }
        next(Q) = next(P);
        first(LP) = next(P);
        next(P) = NULL;
        dealokasi(P);
    }
};
void deleteID(List_p &LP, int x){
    address_p P;
    if (first(LP) != NULL){
    P = findElm(LP,x);
    if (info(P).ID == x){
        address_p Q;
        Q = first(LP);
        while(next(Q) != P){
            Q = next(Q);
        }
        deleteAfter(LP,Q,P);
        cout<<"Data telah dihapus\n";
    }
    else{
        cout<<"ID tidak ditemukan";
    }
    }
    else{
        cout<<"Data kosong";
    }
}
void deleteAfter(List_p &LP, address_p &Prec, address_p &P){
    P = first(LP);
    if(next(P) == first(LP)){
        deleteFirst(LP,P);
    }
    else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
        dealokasi(P);
    }

};
void deleteLast(List_p &LP, address_p &P){
    address_p Q;
    if (first(LP) == NULL){

    }
    else if(next(first(LP)) == first(LP)){
        P = first(LP);
        next(P) = NULL;
        first(LP) = NULL;
        dealokasi(P);
    }
    else{
        P = first(LP);
        Q = first(LP);
        while(next(Q) != first(LP)){
            Q = next(Q);
        }
        while(next(next(P)) != first(LP)){
            P = next(P);
        }
        next(P) = first(LP);
        next(Q) = NULL;
        dealokasi(Q);
    }
};
void printInfo(List_p LP){
    int i;
    i = 1;
    if (first(LP) == NULL){
        cout<<"data kosong";
    }
    else{
    address_p Q;
    Q = first(LP);
    while(next(Q) != first(LP)){
        cout<<"List Artikel ke-"<<i<<"\n";
        cout<<"----------"<<endl;
            cout<<"Nomor Seri   :"<<info(Q).ID<<endl;
            cout<<"Judul        :"<<info(Q).judul<<endl;
            cout<<"Pengarang    :"<<info(Q).pengarang<<endl;
            cout<<"Tahun        :"<<info(Q).tahun<<endl;
            cout<<"Penerbit     :"<<info(Q).penerbit<<endl;
        Q = next(Q);
        i = i+1;
    }cout<<"List Artikel ke-"<<i<<endl;
    cout<<"----------"<<endl;
            cout<<"Nomor Seri   :"<<info(Q).ID<<endl;
            cout<<"Judul        :"<<info(Q).judul<<endl;
            cout<<"Pengarang    :"<<info(Q).pengarang<<endl;
            cout<<"Tahun        :"<<info(Q).tahun<<endl;
            cout<<"Penerbit     :"<<info(Q).penerbit<<endl;
    }
};
void insertAfter(List_p &LP, int Prec, address_p P){
    address_p Q;
    Q = first(LP);
    while(info(Q).ID != Prec){
        Q = next(Q);
    };
    next(P) = next(Q);
    next(Q) = P;
 };

 void insertAscending(List_p &LP, int ID, string nama,string alamat, string nohp, string gender){
    address_p P,Q;
    int prec;
    g = ID;
    h = nama;
    j = alamat;
    k = nohp;
    l = gender;
    P = alokasi(g,h,j,k,l);
    if(first(LP) == NULL || info(first(LP)).ID > g){
        insertFirst(LP, alokasi(g,h,j,k,l));
    }
    else{
        Q = first(LP);
        while(next(Q) != first(LP) && info(next(Q)).ID < g){
            Q = next(Q);
        }
        prec = info(Q).ID;
        insertAfter(LP, prec, alokasi(g,h,j,k,l));
    }
};
