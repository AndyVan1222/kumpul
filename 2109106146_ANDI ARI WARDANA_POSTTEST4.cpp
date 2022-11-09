#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
using namespace std;

struct game
{
	string namaGame;
	string namaDev;
	int tahunRilis;
	float rating;
	string platform;
	
};

struct node
{
	game dataGame;
	node *next;
};

int panjangList = 0;


void menu()
{
	cout << "|===============================|" << endl;
	cout << "|\t\tMENU\t\t|" << endl;
	cout << "|===============================|" << endl;
	cout << "| 1.)TAMBAH GAME" << endl;
	cout << "| 2.)TAMPILKAN GAME" << endl;
	cout << "| 3.)UPDATE GAME" << endl;
	cout << "| 4.)HAPUS" << endl;
	cout << "| 5.)URUTKAN" << endl;
	cout << "| 6.)CARI" << endl;
	cout << "| 7.)EXIT" << endl;
	cout << "|===============================|" << endl;
}

void menuTambah()
{
	cout << "|===============================|" << endl;
	cout << "|\t\tTAMBAH\t\t|" << endl;
	cout << "|===============================|" << endl;
	cout << "| 1.)TAMBAH AWAL" << endl;
	cout << "| 2.)TAMBAH TENGAH" << endl;
	cout << "| 3.)TAMBAH AKHIR" << endl;
	cout << "| 4.)KEMBALI" << endl;
	cout << "|===============================|" << endl;
}

void menuHapus()
{
	cout << "|===============================|" << endl;
	cout << "|\t\tHAPUS\t\t|" << endl;
	cout << "|===============================|" << endl;
	cout << "| 1.)HAPUS DATA AWAL" << endl;
	cout << "| 2.)HAPUS DATA TENGAH" << endl;
	cout << "| 3.)HAPUS DATA AKHIR" << endl;
	cout << "| 4.)KEMBALI" << endl;
	cout << "|===============================|" << endl;
}

void menuSorting()
{
	cout << "|===============================================|" << endl;
	cout << "|\t\t\tMENU\t\t\t|" << endl;
	cout << "|===============================================|" << endl;
	cout << "| 1.)URUTKAN BERDASARKAN TANGGAL RILIS" << endl;
	cout << "|-----------------------------------------------|" << endl;
	cout << "| 2.)URUTKAN BERDASARKAN RATING" << endl;
	cout << "|-----------------------------------------------|" << endl;
	cout << "| 3.)KEMBALI" << endl;
	cout << "|===============================================|" << endl;
}


node *masukanData()
{
	node *nodeBaru = new node;
		cout << "NAMA GAME \t\t: ";getline(cin >> ws, nodeBaru->dataGame.namaGame);
		cout << "DEVELOPER \t\t: ";getline(cin >> ws, nodeBaru->dataGame.namaDev);
		cout << "TAHUN RILIS \t\t: ";cin >> nodeBaru->dataGame.tahunRilis;
		cout << "RATING \t\t\t: ";cin >> nodeBaru->dataGame.rating;
		cout << "PLATFORM \t\t: ";getline(cin >> ws, nodeBaru->dataGame.platform);
	
	return nodeBaru;
}

int lenght(node *head)
{
	int jumlah = 0;
	while(head != NULL)
	{
		jumlah ++;
		head = head->next;
	}
	return jumlah;
}

void tambahAwal(node **head)
{
	node *nodeBaru = masukanData();
	nodeBaru->next = *head;
	*head = nodeBaru;
	cout << "Data Berhasil Dimasukan Di Awal" << endl;
}

void tambahTengah(node **head)
{
	node *cur;
	node *nodeBaru = masukanData();
	int pilihData;
	cout << "Masukan Data Pada Nomor : "; cin >> pilihData;
	if(pilihData > 1 && pilihData < lenght(*head)+1)
	{
		cur = *head;
		int posisi = 1;
		while(posisi < pilihData-1)
		{
			cur = cur->next;
			posisi++;
		}
		
		nodeBaru->next = cur->next;
		cur->next = nodeBaru;
		cout << "Data BERHASIL ditambahkan di tengah" << endl;
	}
	
	else
	{
		cout << "ERROR : Data HARUS DILETAKAN di tengah" << endl;
	}
	
}

void tambahAkhir(node **head)
{
	node *nodeBaru = masukanData();
	nodeBaru->next = NULL;
	node *temp = *head;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->next = nodeBaru;
	cout << "Data ditambahkah di AKHIR" << endl;
}



void display(node **head)
{
	panjangList = 0;
	if(head == NULL)
	{
		cout << "data TIDAK ada!" << endl;
		return;
	}
	
	node *temp = *head;
	cout << "|=======================================================|" << endl;
	cout << "|\t\t\tDAFTAR GAME\t\t\t|" << endl;
	cout << "|=======================================================|" << endl;
	while(temp != NULL)
	{
		cout << "| NAMA GAME \t\t: " << temp->dataGame.namaGame << endl;
		cout << "| DEVELOPER \t\t: " << temp->dataGame.namaDev << endl;
		cout << "| TAHUN RILIS \t\t: " << temp->dataGame.tahunRilis << endl;
		cout << "| RATING \t\t: " << temp->dataGame.rating << endl;
		cout << "| PLATFORM \t\t: " << temp->dataGame.platform << endl;
		cout << "|=======================================================|" << endl;
		temp = temp->next;
		panjangList++;
	}
	
}

void update(node **head)
{
	int pilihData;
	string updateNama;
	string updateDev;
	string updatePlatform;
	int updateTahun;
	float updateRating;
	
	node *temp = *head;
	display(head);
	cout << "Pilih Data yang ingin di ubah : "; cin >> pilihData;
	if(pilihData > 0 && pilihData <= lenght(*head))
	{
		for(int i = 1; i < pilihData; i++)
		{
			temp = temp->next;
		}
		
		cout << "|=======================================================|" << endl;
		cout << "|\t\t\tUPDATE GAME\t\t\t|" << endl;
		cout << "|=======================================================|" << endl;
		
		cout << "NAMA GAME \t\t: ";getline(cin >> ws, updateNama);temp->dataGame.namaGame = updateNama;
		cout << "DEVELOPER \t\t: ";getline(cin >> ws, updateDev);temp->dataGame.namaDev = updateDev;
		cout << "TAHUN RILIS \t\t: ";cin >> updateTahun;temp->dataGame.tahunRilis = updateTahun;
		cout << "RATING \t\t\t: ";cin >> updateRating;temp->dataGame.rating = updateRating;
		cout << "PLATFORM \t\t: ";getline(cin >> ws, updatePlatform);temp->dataGame.platform = updatePlatform;
		
		cout << "DATA berhasil Di UPDATE" << endl;
	}
	
}

void hapusAwal(node **head)
{
	*head = (*head)->next;
	cout << "DATA berhasil di HAPUS" << endl;
}

void hapusTengah(node **head)
{
	node *cur, *before, *hapus;
	if(lenght(*head) < 3)
	{
		cout << "BUTUH 3 DATA UNTUK MENGHAPUS DATA TENGAH" << endl;
	}
	
	int pilihData;
	display(head);
	cout << "pilih DATA yan ingin DIHAPUS : "; cin >> pilihData;
	
	if(pilihData < 1 || pilihData > lenght(*head))
	{
		cout << "ERROR : data tidak ditemukan" << endl;
	}
	else if(pilihData == 1 || pilihData == lenght(*head))
	{
		cout << "ERROR : data tidak ditemukan di tengah data" << endl;
	}
	
	else
	{
		int data = 1;
		cur = *head;
		
		while(data <= pilihData)
		{
			if(data == pilihData-1)
			{
				before = cur;
			}
			
			if(data == pilihData)
			{
				hapus = cur; 
			}
			cur = cur->next;
			data++;
		}
		
		before->next = cur;
		delete hapus;
		cout << "Data Berhasil Dihapus" << endl;
		cout << endl;
		
	}
}

void hapusAkhir(node **head)
{
	if((*head)==NULL)
	{
		cout << "DATA KOSONG" << endl;
		return;
	}
	
	if((*head)->next == NULL)
	{
		*head = NULL;
	}
	
	node *temp = *head;
	
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	
	cout << "DATA BERHASIL DIHAPUS" << endl;
}

//Sorting
/* function prototypes */
node *SortedMerge(node *a, node *b);
node *SortedMergeRating(node *a, node *b);
node *SortedMergeDesc(node *a, node *b);
node *SortedMergeRatingDesc(node *a, node *b);
void FrontBackSplit(node *source, node **frontRef, node **backRef);
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(node **headRef){
	node *head = *headRef;
	node *a;
	node *b;
/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)){
	  return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);
	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);
	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
node *SortedMerge(node *a, node *b){
	node *result = NULL;
	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	/* Pick either a or b, and recur */
	if (a->dataGame.tahunRilis <= b->dataGame.tahunRilis){
		
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

// Desc

void MergeSortDesc(node **headRef){
	node *head = *headRef;
	node *a;
	node *b;
/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)){
	  return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);
	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);
	/* answer = merge the two sorted lists together */
	*headRef = SortedMergeDesc(a, b);
}
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
node *SortedMergeDesc(node *a, node *b){
	node *result = NULL;
	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	/* Pick either a or b, and recur */
	if (a->dataGame.tahunRilis >= b->dataGame.tahunRilis){
		
		result = a;
		result->next = SortedMergeDesc(a->next, b);
	}
	else{
		result = b;
		result->next = SortedMergeDesc(a, b->next);
	}
	return (result);
}

//rating

void MergeSortRating(node **headRef){
	node *head = *headRef;
	node *a;
	node *b;
/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)){
	  return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);
	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);
	/* answer = merge the two sorted lists together */
	*headRef = SortedMergeRating(a, b);
}
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
node *SortedMergeRating(node *a, node *b){
	node *result = NULL;
	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	/* Pick either a or b, and recur */
	if (a->dataGame.rating <= b->dataGame.rating){
		
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

// Desc

void MergeSortRatingDesc(node **headRef){
	node *head = *headRef;
	node *a;
	node *b;
/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)){
	  return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);
	/* Recursively sort the sublists */
	MergeSortRating(&a);
	MergeSortRating(&b);
	/* answer = merge the two sorted lists together */
	*headRef = SortedMergeRatingDesc(a, b);
}
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
node *SortedMergeRatingDesc(node *a, node *b){
	node *result = NULL;
	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	/* Pick either a or b, and recur */
	if (a->dataGame.rating >= b->dataGame.rating){
		
		result = a;
		result->next = SortedMergeRatingDesc(a->next, b);
	}
	else{
		result = b;
		result->next = SortedMergeRatingDesc(a, b->next);
	}
	return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
void FrontBackSplit(node *source,node **frontRef, node **backRef){
	node *fast;
	node *slow;
	slow = source;
	fast = source->next;
	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL){
		fast = fast->next;
		if (fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
/* Function to print nodes in a given linked list */



int jumpSearch(struct node *node, int cari, int jumlah){
    int step = sqrt(jumlah);
    int prev;
    // int i = min(step, n);
    // Inisiasi head untuk traversal dari awal
    node *head = node;
    // Traversal node ke-i
    for (int trv = 0; head->next != NULL && trv < min(step, jumlah)-1; trv++){
        head = head->next;
    } 
    // while (arr[min(step, n)-1] < x)
    while (head->dataGame.tahunRilis < cari) {
        prev = step;
        step += sqrt(jumlah);
        if (prev >= jumlah) return -1;
 
        // Traversal ke node index step-1/n-1
        for (int trv = 0; head->next != NULL && trv < min(step, n)-1; trv++){
            head = head->next;
        } 
    }
    // Inisiasi head2 untuk traversal dari awal lagi
    node *head2 = node;
    // Traversal ke node index prev
    for (int trv = 0; head2->next != NULL && trv < prev; trv++){
        head2 = head2->next;
    } 
 
    // trv = Index sekarang
    while (head2->dataGame.tahunRilis < x) {
        prev++;
        if (prev == min(step, n)) return -1;
        
        // Setelah prev++, pindah ke node prev selanjutnya
        for (int trv = 0; head2->next != NULL && trv < prev; trv++){
            head2 = head2->next;
        }
    }
    // Jika data sama maka kembalikan nilai prev.
    if (head2->dataGame.tahunRilis == x) return prev;
    return -1;
}
	

int main()
{
	node *head = NULL;
	string pilihMenu, subMenu;
	bool loop = true;
	while(loop == true)
	{
		menu :
			menu();
		cout << "PILIH MENU : ";cin >> pilihMenu;
		
		if(pilihMenu == "1")
		{
			system("CLS");
			menuTambah();
			cout << "PILIH MENU : ";cin >> subMenu;
			if(subMenu == "1")
			{
				tambahAwal(&head);
			}
			
			else if(subMenu == "2")
			{
				if(lenght(head)>=2)
				{
					tambahTengah(&head);
				}
				
				else
				{
					cout << "ERROR : data harus labih dari satu" << endl;
				}
			}
			
			else if(subMenu == "3")
			{
				tambahAkhir(&head);
			}
			
			else if(subMenu == "4")
			{
				system("CLS");
				goto menu;
			}
			
		}
		
		else if(pilihMenu == "2")
		{
			system("CLS");
			display(&head);
		}
		
		else if(pilihMenu == "3")
		{
			update(&head);
		}
		
		else if(pilihMenu == "4")
		{
			menuHapus();
			cout << "PILIH MENU : ";cin >> subMenu;
			if(subMenu == "1")
			{
				hapusAwal(&head);
			}
			
			else if(subMenu == "2")
			{
				if(lenght(head) >= 2)
				{
					hapusTengah(&head);
				}
				else
				{
					cout << "ERROR : data harus lebih dari satu" << endl;
				}
			}
			
			else if(subMenu == "3")
			{
				hapusAkhir(&head);
			}
			
			else if(subMenu == "4")
			{
				system("CLS");
				goto menu;
			}
		}
		
		else if(pilihMenu == "5")
		{
			string pilih, pilih2;
			menuSrt:
				menuSorting();
				cout << "PILIH MENU : "; cin >> pilih;
				
				if(pilih == "1")
				{
					cout << "a.)Ascending|b.)Descending|c.)Kembali : "; cin >> pilih2;
					if(pilih2 == "a")
					{
						MergeSort(&head);
						display(&head);
						goto menuSrt;
					}
					
					else if(pilih2 == "b")
					{
						MergeSortDesc(&head);
						display(&head);
						goto menuSrt;
					}
					
					else if(pilih2 == "c")
					{
						goto menuSrt;
					}
				}
				
				if(pilih == "2")
				{
					cout << "a.)Ascending|b.)Descending|c.)Kembali : "; cin >> pilih2;
					if(pilih2 == "a")
					{
						MergeSortRating(&head);
						display(&head);
						goto menuSrt;
					}
					
					else if(pilih2 == "b")
					{
						MergeSortRatingDesc(&head);
						display(&head);
						goto menuSrt;
					}
					
					else if(pilih2 == "c")
					{
						goto menuSrt;
					}
					
					else
					{
						cout << "inputan TIDAK JELAS!" << endl;
						goto menuSrt;
					}
				}
				
				else if(pilih == "3")
				{
					goto menu;
				}
				
				else
				{
					cout << "inputan TIDAK JELAS!" << endl;
					goto menuSrt;
				}

		}
		
		else if(pilihMenu == "6")
		{
			int cari;
			int jumlah = panjangList;
			cout << "Masukan Tahun Rilis Game : "; cin >> cari;
			int idx = jumpSearch(&head, cari, jumlah);
			
			if(idx >= 0)
			{
				cout << "Angka ketemu pada index : " << idx;
			}
			else
			{
				cout << cari << " Tidak ada dalam list" << endl;
			}
			
			
			
		}
		
		else if(pilihMenu == "7")
		{
			cout << "Terimakasih SUDAH MAMPIR:)" << endl;
			loop = false;
		}
		
		else
		{
			cout << "inputan tidak jelas" << endl;
		}
	}
	
}
