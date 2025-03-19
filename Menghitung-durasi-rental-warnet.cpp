#include<iostream>
#include<cmath> //menambah library cmath untuk mengambil fungsi abs
using namespace std;

// struktur untuk menyimpan nilai warnet
struct warnet{ //deklarasi structure
    int jam;
    int menit;
    int detik;
};

int hitungdurasi(const warnet &mulai, const warnet &selesai){
    int waktumulai = mulai.jam * 3600 + mulai.menit * 60 + mulai.detik; //menghitung waktu mulai dengan mengkonversi semua ke satuan detik
    int waktuselsai = selesai.jam * 3600 + selesai.menit * 60 + selesai.detik; //menghitung waktu selesai dengan mengkonversi semua ke satuan detik

    return waktuselsai - waktumulai; //menghitung hasil konversi dalam detik
};

int biaya(int durasi){
    const int waktuper30detik = 130; // biaya per 30 detik
    int totalbiaya = (durasi/30) * waktuper30detik; //menghitung durasi per 30 detik * 130

    return totalbiaya;
};

int main(){
    const int maxrental = 3; // Jumlah maksimal rental yang diperbolehkan
    warnet mulai[maxrental], selesai[maxrental]; // Deklarasi array struct untuk menyimpan waktu mulai dan selesai
    int totalbiaya[maxrental]; // Array untuk menyimpan total biaya masing-masing rental
    int durasi[maxrental]; // Array untuk menyimpan durasi masing-masing rental
    int jumlahrental; // Variabel untuk menyimpan jumlah rental yang akan dimasukkan
    int totaljam[maxrental]; // Array untuk menyimpan total jam bermain
    int totalmenit[maxrental]; // Array untuk menyimpan total menit bermain
    int totaldetik[maxrental]; // Array untuk menyimpan total detik bermain


    cout << "Selamat datang dalam program rental warnet!!!\n";
    cout << "=============================================\n";
    cout << "Masukan jumlah rental (Max " << maxrental << " ): "; //input jumlah rental tidak boleh lebih dari 3
    cin >> jumlahrental;
    cout << endl;

    if(jumlahrental > 3){ // jika input lebih dari 3 maka akan menampilkan kata dibawah
        cout << "Jumlah max rental tidak boleh lebih dari(" << maxrental <<")";
        return 1; // jika jumlah lebih dari 3 maka program akan selesai
    };

    //looping untuk input
    for(int i = 0; i < jumlahrental; i++){
        cout << "Rental ke-" << i+1 << endl;
        cout << "Masukkan pukul mulai(jam menit detik) \n"; //input jam mulai
        cout << "jam : ";
        cin >> mulai[i].jam;
        cout << "menit : ";
        cin >> mulai[i].menit;
        cout << "detik : ";
        cin >> mulai[i].detik;

        cout << "\nMasukkan pukul selsai(jam menit detik) \n"; // input jam selesai
        cout << "jam : ";
        cin >> selesai[i].jam;
        cout << "menit : ";
        cin >> selesai[i].menit;
        cout << "detik : ";
        cin >> selesai[i].detik;

        durasi[i] = hitungdurasi(mulai[i], selesai[i]); //menghitung total durasi

        // jika input jam lebih dari 23, menit lebih dari 59 dan detik lebih dari 59 maka waktu tidak valid
        if(mulai[i].jam > 23 || selesai[i].jam > 23 || mulai[i].menit > 59 || selesai[i].menit > 59 || mulai[i].detik > 59 || selesai[i].detik > 59){
        cout << "Waktu yang dimasukan tidak valid!";
        return 0;
        };

        //input waktu selsai tidak boleh kurang dari waktu mulai
        if (durasi[i] < 0){
        cout << "Waktu selsai tidak boleh kurang dari waktu mulai";
        return 1;
        };

        totalbiaya[i] = biaya(durasi[i]); //menghitung total biaya
        // menghitung total waktu bermain
        totaljam[i] = abs(selesai[i].jam - mulai[i].jam); //menggunakan fungsi abs agar hasil tetap bernilai positif
        totalmenit[i] = abs(selesai[i].menit - mulai[i].menit);
        totaldetik[i] = abs(selesai[i].detik - mulai[i].detik);

        cout << "====================================\n";
    }
    system("cls"); //fungsi untuk membersihkan layar

    cout << "Detail rental\n";
    cout << "-------------\n";

    //looping untuk output
    for(int i = 0; i < jumlahrental; i++){
        cout << "Rental ke-" << i+1 << endl;
        cout << "-------------\n";
        cout << "Waktu mulai : " << mulai[i].jam << ":" << mulai[i].menit << ":" <<  mulai[i].detik << endl; //tampilan waktu mulai bermain
        cout << "Waktu selsai : " << selesai[i].jam << ":" << selesai[i].menit << ":" <<  selesai[i].detik << endl; //tampilan waktu selsai bermain
        cout << "Total waktu bermain : " << totaljam[i] << " Jam " << totalmenit[i] << " Menit " << totaldetik[i] << " Detik " <<endl; // tampilan durasi bermain
        cout << "Total waktu durasi(detik) : " << durasi[i] << endl; // tampilan total durasi dalam satuan detik
        cout << "Total biaya rental : " << totalbiaya[i] << endl << endl; //tampilan total biaya
    };

return 0;
}
