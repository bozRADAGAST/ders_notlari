#include <stdio.h>
#include <iostream>
using namespace std;

class Node{
	public:
		int deger;
		Node* next;
		Node(int deger){
			this->deger = deger;
			next = NULL;
		}
};

class Stack{
	private:
		Node* top;
		int count;
	public:
		Stack(int deger){
			Node* node = new Node(deger);
			top = node;
			count = 1;
		}

		~Stack(){
			Node* tmp = top;
			while(top != NULL){
				top = top->next;
				delete tmp;
				tmp = top;
			}
		}

		void printAll(){
			Node* tmp = top;
			while(tmp != NULL){
				cout << tmp->deger << endl;
				tmp = tmp->next;
			}
		}

		void printTop(){
			if(top != NULL){
				cout << "Top deger:" << top->deger << endl; 
			}else{
				cout << "Stack bos!" << endl;
			}
		} // printTop stack'ın en üstündeki değeri yazar.
		//   eğer stack boşsa stack boş hatası verir.

		int getCount(){
			return count;
		}

		void push(int deger){
			Node* node = new Node(deger);
			node->next = top;
			top = node;
			count++;
		}// push o(1) zamanda gerçekleşir. eğer tüm listeyi dolaşsaydım o(n) zamanda gerçekleşirdi.

		int pop(){
			if(top == NULL){
				cout << "Bos stackte pop islemi yapilmaya calisiliyor!!!" << endl;
				exit(1);
			}
			if(count == 0){
				return -1;
			}
			Node* tmp = top;
			int deger = top->deger;
			top = top->next;
			delete tmp;
			count--;
			return deger;
		}

		bool isEmpty(){
			return count == 0;
		}
};

// ~ tilda işaretidir. destruct fonksiyonunda kullanılır.
// destructor nesnedeki elemanları tek tek silerek yok eder.
// destructor yazılmazsa memory leak oluşur.

int main(){
	Stack* stack = new Stack(10);
	stack->push(20);
	stack->push(25);
	stack->push(30);
	stack->push(45);
	stack->push(55);
	stack->printAll();
	stack->printTop();
	stack->pop();
	stack->pop();
	stack->pop();
	stack->pop();
	stack->push(10);
	cout << "Stacktaki node sayisi: " << stack->getCount() << endl;
	stack->printAll();
	stack->printTop();
	delete stack;
	return 0;
	
}

/*
int main(){
	int n = 10; // A 1 kere çalışır
	for(int i = 1; i<n; i++){ // B 9 kere çalışır
		for(int j = 1; j<n;j++){ // C 81 kere çalışır(diğer for'un içinde olduğu için 9x9 olur)
			printf("%d ",i*j); // D 81 kere çalışır aynı mantık
			
		}
		printf("\n"); // E 1 kere
	}
	return 0;
}*/
// A+ 9B + 81C + 81D + 9E = M = 2N2 + 2N +1 = O(N2)
// 2li döngü olursa cevap o(n2) n kare 3lü olursa o(n3) n kök yani.
