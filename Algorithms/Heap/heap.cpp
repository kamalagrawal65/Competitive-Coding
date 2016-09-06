#include<iostream>
using namespace std;
class minheap{
	public:
		int capacity;
		int size;
		int *harr;
		minheap(int c){
			capacity=c;
			size=0;
			harr=new int[c];
		}
		int parent(int p){
			return (p-1)/2;
		}
		int left(int p){
			return 2*p+1;
		}
		int right(int p){
			return 2*p+2;
		}
		void swap(int &a,int &b){
			int temp=a;
			a=b;
			b=temp;
		}
		void insert(int k){
			if(size>capacity)
				return;
			size++;
			int i=size-1;
			harr[i]=k;
			while(i>0 && harr[i]<harr[parent(i)]){
				swap(harr[i],harr[parent(i)]);
				i=parent(i);
			}
		}
		void display(){
			for(int i=0;i<size;i++){
				cout<<harr[i]<<" ";
			}
		}
		void heapify(int i){
			int smallest=i;
			if(left(i)<size && harr[left(i)]<harr[parent(i)])
				smallest=left(i);
			if(right(i)<size && harr[right(i)]<harr[smallest])
				smallest=right(i);
			if(smallest!=i){
				swap(harr[i],harr[smallest]);
				heapify(smallest);
			}
		}
};
int main(){
	minheap m(10);
	m.insert(10);
	m.insert(2);
	m.insert(1);
	m.display();
}
