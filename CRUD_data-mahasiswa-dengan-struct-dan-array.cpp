#include <iostream>
#include <string>
#include <iomanip> // menggunakan librart untuk mengambil fungsi setw
using namespace std;

const int maks = 20; // deklarasi variabel global max

// Struktur untuk menyimpan nilai mahasiswa
struct Nilai
{
    float absen;
    float tugas;
    float uts;
    float uas;
    float nilaiakhir;
    char nilaihuruf;
};

// Struktur untuk menyimpan data mahasiswa
struct mahasiswa
{
    string nama;
    string npm;
    Nilai nilai; // Struktur nilai yang dimiliki mahasiswa
};

// Fungsi untuk menghitung nilai akhir dan nilai huruf
void hitungnilai(mahasiswa &mhs)
{
    // menghitung nilai akhir mahasiswa
    mhs.nilai.nilaiakhir = (0.1 * mhs.nilai.absen) + (0.2 * mhs.nilai.tugas) + (0.3 * mhs.nilai.uts) + (0.4 * mhs.nilai.uas);

    // Menentukan nilai huruf berdasarkan nilai akhir
    if (mhs.nilai.nilaiakhir > 80)
    {
        mhs.nilai.nilaihuruf = 'A';
    }
    else if (mhs.nilai.nilaiakhir > 70)
    {
        mhs.nilai.nilaihuruf = 'B';
    }
    else if (mhs.nilai.nilaiakhir > 60)
    {
        mhs.nilai.nilaihuruf = 'C';
    }
    else
    {
        mhs.nilai.nilaihuruf = 'D';
    }
}

// Fungsi untuk menampilkan data mahasiswa
void tampildata(mahasiswa mhs[], int count)
{
    cout << "====================================================================\n";
    cout << "|       NPM       |         Nama        |    Nilai    | Huruf Mutu |\n";
    cout << "====================================================================\n";

    for (int i = 0; i < count; i++)
    {
        cout << "| " << setw(16) << left << mhs[i].npm // menggunakan fungsi setw mengatur lebar tampilan output
             << "| " << setw(20) << left << mhs[i].nama
             << "| " << setw(12) << left << mhs[i].nilai.nilaiakhir
             << "| " << setw(10) << left << mhs[i].nilai.nilaihuruf << " |\n";
    }

    cout << "====================================================================\n";
}

// Fungsi untuk mencari mahasiswa berdasarkan NPM
int carimahasiswa(mahasiswa mhs[], int count, const string &npm)
{
    for (int i = 0; i < count; i++)
    {
        if (mhs[i].npm == npm)
        {
            return i; // Mengembalikan indeks mahasiswa
        }
    }
    return -1; // Jika tidak ditemukan
}

int main()
{
    mahasiswa mhs[maks]; // Array untuk menyimpan data mahasiswa
    int pilihan;         // Variabel untuk menyimpan pilihan menu
    int count = 0;       // Jumlah mahasiswa yang sudah dimasukkan
    bool lanjut = true;  // Variabel untuk mengontrol perulangan menu
    char t;              // Variabel untuk konfirmasi lanjut/tidak
    string npm;          // Variabel untuk menyimpan input NPM

    do
    {
        cout << "===========================================================\n"
                "|                  Welcome To Main Menu                   |\n"
                "|                  --------------------                   |\n"
                "|                                                         |\n"
                "| 1. Tambah Data Mahasiswa                                |\n"
                "| 2. Lihat Data Mahasiswa                                 |\n"
                "| 3. Edit Data Mahasiswa                                  |\n"
                "| 4. Hapus Data Mahasiswa                                 |\n"
                "| 5. Keluar                                               |\n"
                "===========================================================\n"
                "\n | Masukkan Nomor Pilihan (1-5) : ";
        cin >> pilihan;
        cin.ignore();  // Menghapus newline yang tersisa di buffer
        system("cls"); // membersihkan layar

        switch (pilihan)
        {
        case 1:
            cout << "Masukan data diri\n";
            cout << "-----------------\n";

            cout << "NPM  : ";
            cin >> mhs[count].npm;

            cout << "Nama : ";
            cin.ignore();
            getline(cin, mhs[count].nama); // membaca spasi

            cout << "\nMasukan data nilai\n";
            cout << "------------------\n";

            cout << "Nilai Absen : ";
            cin >> mhs[count].nilai.absen;

            cout << "Nilai Tugas : ";
            cin >> mhs[count].nilai.tugas;

            cout << "Nilai UTS   : ";
            cin >> mhs[count].nilai.uts;

            cout << "Nilai UAS   : ";
            cin >> mhs[count].nilai.uas;

            if (mhs[count].nilai.absen > 100 || mhs[count].nilai.tugas > 100 || mhs[count].nilai.uts > 100 || mhs[count].nilai.uas > 100)
            {
                cout << "Nilai tidak boleh lebih dari 100!\n";
                cout << "\nKlik 'ENTER' untuk kembali";
                cin.ignore();
                lanjut = cin.get();
                system("cls");
            }
            else
            {

                // Hitung nilai akhir dan nilai huruf
                hitungnilai(mhs[count]);
                count++; // menambah jumlah data

                cout << "\nData telah tersimpan!";

                cout << "\nKlik 'ENTER' untuk kembali";
                lanjut = cin.get();
                cin.ignore();
                system("cls");
            }
            break;

        case 2:
            if (count > 0)
            {
                cout << "Tampilan data mahasiswa\n";
                cout << "-----------------------\n";
                tampildata(mhs, count); // menampilkan fungsi tampildata untuk menampilkan data mahasiswa
            }
            else
            {
                cout << "Tidak ada data mahasiswa yang dapat ditampilkan.\n";
            }
            cout << "\nKlik 'ENTER' untuk kembali";
            lanjut = cin.get();
            cin.ignore();
            system("cls");
            break;

        case 3:
            cout << "Edit Data Mahasiswa\n";
            cout << "-------------------\n";

            if (count > 0)
            {
                tampildata(mhs, count);

                cout << "Ingin edit data? (y/n): ";
                cin >> t;
                lanjut = (t != 'y' || t != 'Y');

                if (t == 'y' || t == 'Y')
                {
                    cout << "Masukkan NPM mahasiswa : ";
                    cin >> npm;

                    int indexEdit;
                    indexEdit = carimahasiswa(mhs, count, npm); // mencari berdasarkan npm mahasiswa

                    if (indexEdit != -1)
                    {
                        cout << "\nMasukkan Nama : ";
                        cin.ignore();
                        getline(cin, mhs[indexEdit].nama);

                        cout << "Nilai Absen   : ";
                        cin >> mhs[indexEdit].nilai.absen;

                        cout << "Nilai Tugas   : ";
                        cin >> mhs[indexEdit].nilai.tugas;

                        cout << "Nilai UTS     : ";
                        cin >> mhs[indexEdit].nilai.uts;

                        cout << "Nilai UAS     : ";
                        cin >> mhs[indexEdit].nilai.uas;

                        if (mhs[indexEdit].nilai.absen > 100 || mhs[indexEdit].nilai.tugas > 100 || mhs[indexEdit].nilai.uts > 100 || mhs[indexEdit].nilai.uas > 100)
                        {
                            cout << "Nilai tidak boleh lebih dari 100!\n";
                            cout << "\nKlik 'ENTER' untuk kembali";
                            cin.ignore();
                            lanjut = cin.get();
                            system("cls");
                        }
                        else
                        {

                            // Hitung ulang nilai akhir dan nilai huruf
                            hitungnilai(mhs[indexEdit]);
                            cout << "\nData mahasiswa berhasil diperbarui!";
                            cout << "\nKlik 'ENTER' untuk kembali";
                            cin.ignore();
                            lanjut = cin.get();
                            system("cls");
                        }
                    }
                    else
                    {
                        cout << "Mahasiswa dengan NPM " << npm << " tidak ditemukan." << endl;
                        cout << "\nKlik 'ENTER' untuk kembali";
                        lanjut = cin.get();
                        cin.ignore();
                        system("cls");
                    }
                }
                else
                {
                    cout << "\nKlik 'ENTER' untuk kembali";
                    lanjut = cin.get();
                    cin.ignore();
                    system("cls");
                }
            }
            else
            {
                cout << "Tidak ada data yang dapat diedit!\n";
                cout << "\nKlik 'ENTER' untuk kembali";
                lanjut = cin.get();
                cin.ignore();
                system("cls");
            }

            break;

        case 4:
            cout << "Hapus Data Mahasiswa\n";
            cout << "--------------------\n";

            if (count > 0)
            {
                tampildata(mhs, count);

                cout << "Ingin hapus data? (y/n): ";
                cin >> t;
                lanjut = (t != 'y' || t != 'Y'); // jika ketik tidak sama dengan y maka akan kembali ke menu utama

                if (t == 'y' || t == 'Y')
                {
                    cout << "\nMasukkan NPM mahasiswa : ";
                    cin >> npm;

                    int indexhapus;
                    indexhapus = carimahasiswa(mhs, count, npm); // menghapus data menggunakan npm mahasiswa

                    if (indexhapus != -1)
                    {
                        for (int i = indexhapus; i < count - 1; i++)
                        {
                            mhs[i] = mhs[i + 1];
                        }
                        count--; // mengurasi jumlah data
                        cout << "\nData mahasiswa dengan NPM " << npm << " berhasil dihapus!\n";
                    }
                    else
                    {
                        cout << "\nMahasiswa dengan NPM " << npm << " tidak ditemukan!\n";
                    }
                }
            }
            else
            {
                cout << "Tidak ada data yang dapat dihapus!\n";
            }

            cout << "\nKlik 'ENTER' untuk kembali";
            lanjut = cin.get();
            cin.ignore();
            system("cls");
            break;

        case 5:
            lanjut = false; // program selesai
            break;

        default:
            cout << "\nPilihan yang Anda pilih tidak tersedia, Kembali ke menu utama? (y/n): ";
            cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;
        }
    } while (lanjut);

    cout << "Program telah selesai";
    return 0;
}
