#include <conio.h>
#include <iostream>

using namespace std;

class Sorting{
    friend istream& operator>>(istream&, Sorting&);
    friend ostream& operator<<(ostream&, const Sorting&);
public:
    Sorting();
    int pencarianbiner(int);
    void cetakbaris(int,int,int);
    void selection_sort();
    void cari_data();
    void selection_sort(int&, int&);
private:
    void minimum(int, int, int&);
    void tukar(int&, int&);
    int data[100], n;
};

    Sorting::Sorting(){
        n=10;
    }

void Sorting::selection_sort(){
    int t;
    for(int i=0; i<n; i++){
        minimum(i,n,t);
        tukar(data[i], data[t]);
    }
}

void Sorting::minimum(int dari, int n,int& tempat){
    int min=data[dari];
    tempat=dari;
    for(int i=dari+1; i<n; i++){
        if(data[i]<min){
            min=data[i];
            tempat=i;
        }
    }
}

void Sorting::tukar(int&a, int&b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void Sorting::cari_data(){
    int posisi=0, qq;
    cout <<"cari data : "; cin >> qq;
    for(int i=0; i<n; i++){
        if(data[i]==qq) {
            posisi = i+1;
        }
    }
    if(pencarianbiner(qq)==-1){
        cout <<"tdk ada"<<endl;
    }
    else cout << "ada, posisi di : "<< posisi << endl;

}

int Sorting::pencarianbiner(int qq){
    int midle, low=0, high=n;
    while(low<=high){
        midle=(low+high)/2;
        cetakbaris(low,midle,high);
        if(qq==data[midle]){
            return midle;
        }else if(qq< data[midle]){
            high = midle-1;
        }else low=midle+1;
    }
    return -1;
}

void Sorting::cetakbaris(int low,int midle,int high){
    cout<<"low "<<low<<"\nmidle "<<midle<<"\nhigh "<<high<<endl;
}


istream& operator>>(istream& in, Sorting& A){
    cout << "Masukkan jumlah data : ";cin >> A.n;
    for(int i=0; i<A.n;i++){
        cout <<"Data["<<i<<"] : ";
        in >> A.data[i];
    }
    return in;
}
ostream& operator<<(ostream& out, const Sorting& A){
    for(int i=0; i<A.n;i++){
        out<<A.data[i]<<" ";
    }
    return out;
}

int main(){
    Sorting X;
    cin >> X;
    cout <<"Data sebelum Sorting :\n";
    cout <<X<<endl;
    X.selection_sort();
    cout <<"Data sesudah Sorting :\n";
    cout <<X<<endl<<endl;
    X.cari_data();
    getch();
    return 0;
}