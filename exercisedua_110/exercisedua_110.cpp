#include <iostream>
#include <vector>
using namespace std;

class Buku {
public:
	string judulBuku;
	Pengarang* pengarang;

	Buku(string judul, Pengarang* pengarang) : judulBuku(judul), pengarang(pengarang) {

	}
	
};

class Penerbit {
public:
	string namaPenerbit;

	Penerbit(string nama) : namaPenerbit(nama) {

	}
};
class Pengarang {

public:
	string namaPengarang;

	Penerbit* penerbit;
	vector<Buku*> daftarBuku;

	Pengarang(string nama, Penerbit* penerbit) : namaPengarang(nama), penerbit(penerbit) {

	}

	void tambahBuku(Buku* buku) {
		daftarBuku.push_back(buku);
	}
};

int main() {
	
	//objek
	Penerbit penerbit1("Game Press");
	Penerbit penerbit2("Intan Pariwara");

	Pengarang pengarang1("Joko", &penerbit1);
	Pengarang pengarang2("Lia", &penerbit1);
	Pengarang pengarang3("Giga", &penerbit1);
	Pengarang pengarang4("Asroni", &penerbit2);
	Pengarang pengarang5("Giga", &penerbit2);

	Buku buku1("Fisika", &pengarang1);
	Buku buku2("Algoritma", &pengarang1);
	Buku buku3("Basisdata", &pengarang2);
	Buku buku4("Dasar Pemrograman", &pengarang4);
	Buku buku5("Matematika", &pengarang3);
	Buku buku6("Multimedia 1", &pengarang3);

	// untuk menambahkan buku ke daftar buku pengarang
	pengarang1.tambahBuku(&buku1);
	pengarang1.tambahBuku(&buku2);
	pengarang2.tambahBuku(&buku3);
	pengarang4.tambahBuku(&buku4);
	pengarang3.tambahBuku(&buku5);
	pengarang3.tambahBuku(&buku6);

	cout << "Daftar pengarang pada penerbit \"" << penerbit1.namaPenerbit << "\":\n";
	for (Pengarang* pengarang : { &pengarang1, &pengarang2, &pengarang3 }) {
		if (pengarang->penerbit == &penerbit1) {
			cout << pengarang->namaPengarang << endl;
		}
	}
	cout << endl;
	
	cout << "Daftar pengarang pada penerbit \"" << penerbit2.namaPenerbit << "\":\n";
	for (Pengarang* pengarang : { &pengarang4, &pengarang5 }) {
		if (pengarang->penerbit == &penerbit2) {
			cout << pengarang->namaPengarang << endl;
		}
	}
	cout << endl;

	cout << "Daftar buku yang dikarang \"" << pengarang4.namaPengarang << "\":\n";
	for (Buku* buku : pengarang4.daftarBuku) {
		cout << buku->judulBuku << endl;
	}
	cout << endl;

	cout << "Daftar buku yang dikarang \"" << pengarang3.namaPengarang << "\":\n";
	for (Buku* buku : pengarang3.daftarBuku) {
		cout << buku->judulBuku << endl;
	}
	cout << endl;

	return 0;
}