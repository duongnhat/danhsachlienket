#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class node
{
	public:
    int data;
    node *tam;
    node *next;
    
    node *head= NULL;
	node *tail= NULL;
	node *bienLuu= NULL;
	node *link=NULL;
	
	void insert(int data)
	{
		node *link= new node;
	    
	    link->data = data;
	    link->next = head;
	    head = link;
	}
	
	void print()
	{
	    node *out = head;
	    while(out != NULL){
	        cout << out->data<<"  ";
	        out = out->next;
	    }
	}
	int dem()
	{
	    int soLuong=0;
	    class node *a=head;
	    for(a=head;a!=NULL;a=a->next){
	        soLuong++;
	    }
	    return soLuong;
	}
	int nhap(){
	    int data;
	    cout << "nhap gia tri: " << endl;
	    cin >> data;
	    return data;
	}
	
	void daoNguoc(){
	    int bien;
	    class node *dao = head;
	    bien=dem();
	    for(int i=1; i<=bien; i++){
	    	bienLuu=dao->next;
	        dao->next=tail;
	        tail=dao;
	        dao=bienLuu;
	    }
	    head=tail;
	}
	
	void sapXep2() {
		node *a = head;
		node *b = head;
		node *truoc = NULL;
		node *sau = head;
		node *temp = head;
		
		cout << endl;
		while (a->next != NULL) {
			b = a->next;
			sau = a;
			while (b != NULL) {
				cout << "so sanh " << a->data << " va " << b->data << endl;
				
				if (a->data > b->data) {
					if (truoc == NULL) {
						head = b;
					} else {
						truoc->next = b;
					}
					sau->next = a;
					temp = a->next;
					a->next = b->next;
					b->next = temp;
					
					// dao a va b
					temp = a;
					a = b;
					b = temp;
				}
				
				sau = b;
				b = b->next;
			}
			truoc = a;
			a = a->next;	
		}
		tail = a;
	}	
	void xapXep(){
		node *a = head;
		node *b = head;
		node *luu = head;
		node *luutail = head;
		node *truoc = head;
		node *sau = head;
		node *luub = b;
		node *luuhead = head;
		node *temp = head;
		node *luuab =head;
		int sl=dem();
		int sl2=sl;
		for(int i=1; i<=sl-1; i++){
			b=b->next; cout<<"contro"<<b->next;
			for(int j=1; j<=sl2-1; j++){
				
			cout<<" "<<a->data<<""<<b->data;
				if(a->data>b->data){
					
					if(i==1){ cout<<"vao";
						head=b;
						truoc=b;
						sau=b;
						luu=b;
						luuhead=b;
					}
					else{
						truoc->next=b;
						
					}
					luub=b;
					luutail=a;
					if(i>1){
						truoc->next=b;
					}
					sau->next=a;
					temp=b->next;
					a->next=b->next;
					
					luuab=a;
					a=b;
					b=luuab;
					sau=a;
					
				}else{
					luutail=b;
					b=b->next;
					luu=head;
				}
				sau=sau->next;
				
				b=temp->next;
			}
			if(i>2){
				truoc=truoc->next;
			}
			luu=luuhead;
			a=luuhead->next;
			b=a;
			luuhead=a;
			sl2--;
		}
		luutail->next=NULL;
	}
	
	void timKiem(int giaTri)
	{
		node *tk = head;
		int viTri=1, i=0;
		while(tk!=NULL){
			if(tk->data==giaTri){
				cout<<"tim thay "<<giaTri<<" o vi tri thu: "<<viTri<<endl;
				i=1;
			}
			viTri++;
			tk=tk->next;
		}
		if(i==0){
			cout<<"khong tim thay"<<endl;
		}
	}
};



int main(int argc, char** argv) {
	node node1;
	node *conTro;
	conTro=&node1;
    int so=0, data, giaTri;
    cout << "so gia tri muon nhap: " << endl;
    cin >> so;
    for(int i=1; i<=so; i++){
        data = conTro->nhap();
        conTro->insert(data);
    }
    node1.print();
	conTro->daoNguoc();
	cout<<endl<<"sau dao nguoc: ";
	conTro->print();
    //conTro->xapXep();
    conTro->sapXep2();
	cout<<endl<<"sau xap xep: ";
    conTro->print();
    cout<<endl<<"nhap gia tri can tim: "<<endl;
    cin>>giaTri;
    node1.timKiem(giaTri);
    return 0;
}

