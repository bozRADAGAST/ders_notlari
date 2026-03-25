#include <iostream>
using namespace std;

class Node {
	public:
		int deger;
		Node* next;

		Node(int deger) {
			this->deger = deger;
			next = NULL;
		}
};
class LinkedList {
	private:
		Node* head;
		Node* tail;
		int count;

	public:
		LinkedList(int deger) {
			Node* node = new Node(deger);
			head = node;
			tail = node;
			count = 1;
			// destructor: linked list listesi silinirken tüm düğümleri siler
			~LinkedList() {
				Node* tmp = head;
				while(head) {
					head = head->next;
					delete tmp;
					tmp = head;

					void printHead() {
						if(head != NULL)
							cout << "Head: " << head->deger << endl;
					}
					void printTail() {
						if(tail != NULL)
							cout << "Head: " << tail->deger << endl;
					}
					void getCount() {
						cout << "List Count: " << count << endl;
					}
					// liste sonuna düğüm ekleme
					void appendList(int deger) {
						Node* node = new Node(deger);
						if(count==0) {
							head=node;
							tail=node;
						} else {
							tail->next = node;
							tail = node;
						}
						count++;
					}
					//
					void printList() {
						Node* tmp = head;
						while(tmp!=NULL) {
							cout << tmp->deger << " -> ";
							tmp = tmp->next;
						}
						cout << "NULL" << endl;
					}
				void deleteLastNode(){
					if(count==0)
					return;
					Node* temp1 = head;
					Node* temp2 = head;
					while(temp1->next){
						temp2 = temp1;
						temp1 = temp1->next;
					}
					tail = temp2;
					tail->next = NULL;
					count--;
					if(count==0){
						head = NULL;
						tail = NULL;
					}
					delete temp1;
					
				}
				// listenin basina dugum ekleme
				void addFirst(){
					Node* newNode = new Node(deger);
					if(count == 0){
						head = newNode;
						tail = newNode;
					}else{
						newNode->next = head;
						head = newNode;
					}
					count++;
				}
				// listenin basindaki dugumu silme
				void deleteFirst(){
					if(count == 0)
					return;
					
					Node* temp = head;
					if(count == 1){
						head == NULL;
						tail == NULL;
					}
					else{
						head = head->next;
					}
					delete temp;
					count--;
				}
				
				Node* getNode(int index){
					if(index < 0 || index >= count)
					return NULL;
						
					Node* temp = head;
					for(int i = 0; i < index; i++){
						temp = temp->next;
					}
					return temp;
					
				}
				
				bool setValue(int index, int yeniDeger){
					Node* temp = getNode(index);
					if(temp == NULL)
					return false;
					temp->deger = yeniDeger;
					return true;

				}
				// belirtilen indexe yeni düğüm ekleme
				bool insertNode(int index, int deger){
					if(index < 0 || index > count)
					return false;
					if(index == 0){
						addFirst(deger);
						return true;
					}
					if(index == count){
						appendList(deger);
						return true;
					}
					Node* yeniNode = new Node(deger);
					Node* temp = getNode(index - 1);
					yeniNode->next = temp->next;
					temp->next = yeniNode;
					count ++;
					return true;
				}
				// belirtilen indexteki düğümü silme
				void deleteNode(int index){
					if(index<0 || index >= count)
					return;
						if(index==count){
							deleteFirst;
						}else if(index == count -1){
							deleteLastNode();
						}else{
							Node* del = getNode(index - 1);
							Node* temp = del->next;
							del->next=temp->next;
							delete temp;
							count--;
						}
						
				}

				}
				int main(){
					LinkedList* list = new LinkedList(10);
					list->appendList(20);
					list->appendList(30);
					list->addFirst(5);
					
					cout << "Liste elemanları (ilk eklemeler): ";
					list->printList();
					////////////////////////////////
					list->deleteLastNode();
					cout << "Liste elemanları (son dugum silindi): ";
					list->printList();
					////////////////////////////////
					list->insertNode(1,15);
					cout << "Liste elemanları (1. indexe 15 degeri eklendi): ";
					list->printList();
					////////////////////////////////
					list->setValue(2,25);
					cout << "Liste elemanları (2. indexteki deger 25 olarak degistirildi.): ";
					list->printList();
					////////////////////////////////
					list->deleteNode(1);
					cout << "Liste elemanları (1. indexteki dugum silindi): ";
					list->printList();
					
					delete list;
					return 0;
				}
			}
		}
};

/* LinkedList yapısı C dilinde ise bu sekildedir;
struct Node{
	int data;
	struct Node* next;
};
struct Node* head = NULL;
void insertToHead(int a){
	struct Node* t = (struct Node*) malloc(sizeof(struct Node));
	t->data = a;
	t->next = head;
	head = t;

}
void deleteFromHead(){
	if(head != NULL){
		struct Node *t = head;
		head = head->next;
		free(t);
	}
}
void printList(){
	struct Node *t = head;
	while(t != NULL){
		printf("%d\n", t->data);
		t = t->next;
	}
}
int main(int argc, char** argv) {
	int i,j;
	for(i=1;i<=20;i++){
		insertToHead(i);
	}
	for(i=1;i<=20;i++){
		insertToHead(i);
	}
	printList();
}*/
/*
// faktöriyel hesaplama fonksiyonu
int factorial(int n){
	if( n<=1)
	return 1;
	return n * factorial(n-1);
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop
int fibonacci(int n){
	if(n==1||n==2)
		return 1;
	return fibonacci(n-1)+fibonacci(n-2);

}
int main(int argc, char** argv) {
	int num;
	cout << "Bir sayi girin: ";
	cin >> num;
	cout << num << "! = " << factorial(num) << endl;
	/*int n;
	printf("Kacinci fibonacci sayisini hesaplamak istersin?");
	scanf("%d",&n);
	printf("%d. Fibonacci sayisi: %d\n" , n ,fibonacci(n));
	return 0;
}*/
