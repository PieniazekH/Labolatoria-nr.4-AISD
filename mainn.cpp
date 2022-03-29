#include <iostream>

using namespace std;
int size=0;

void change(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}

void heapify(int tab[], int size, int i){
    if(size==1)
    {
        printf("tablica ma tylko jeden element");

    }
    else
    {
        int najwiekszy = i;
        int lewe=(2*i)+1;
        int prawe=(2*i)+2;
        if (lewe < size && tab[lewe] > tab[najwiekszy]){
            najwiekszy = lewe;
        }
        if(prawe<size && tab[prawe] > tab[najwiekszy]){
            najwiekszy=prawe;
        }
        if (najwiekszy!=i){
            change(&tab[i], &tab[najwiekszy]);
            heapify(tab,size,najwiekszy);
        }


    }
}
void insert(int tab[], int newValue)
{
    if(size==0)
    {
        tab[0]=newValue;
        size+=1;
    }
    else
    {
        tab[size]=newValue;
       size+=1;
       for(int i=(size/2) - 1; i>=0; i--)
       {
           heapify(tab,size,i);
       }

    }

}

int main()
{
    int tab[10];

    insert(tab,23);
    insert(tab,17);
    insert(tab,12);
    insert(tab,13);
    insert(tab,6);
    insert(tab,9);
    insert(tab,10);
    insert(tab,7);
    insert(tab,11);
    insert(tab,4);




    for(int i=0; i<size ;i++){
             cout << tab[i] << " ";

    }

    return 0;
}
