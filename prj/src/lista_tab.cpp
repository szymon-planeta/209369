//lista_tab.cpp
#include "lista_tab.hh"
#include <cmath>

/*!\file 
 * \brief Zawiera definicje metod klasy Lista
 */
// ZWIEKSZA SIE O 1
/*void Lista_tab::push(int x){
  if(rozmiar==0){
    tab = new int [1];
    rozmiar=1;
    iterator=0;
    tab[iterator]=x;
  }
  else{
    if(iterator<rozmiar-1){
      tab[++iterator]=x;
    }
    else if(iterator>=rozmiar-1){
      int *tmp = new int[rozmiar+1];
      for(int i=0;i<=iterator;i++)
	tmp[i] = tab[i];
      delete [] tab;
      tab = tmp;
      tab[++iterator]=x;
      rozmiar++;
    }
  }
  }*/
//TABLICA POWIEKSZANA DWUKROTNIE
void zamien(int *wsk, int i, int j){
  int tmp;
  tmp=wsk[i];
  wsk[i]=wsk[j];
  wsk[j]=tmp;
}

void Lista_tab::push(int x){
  if(rozmiar==0){
    tab = new int [1];
    rozmiar=1;
    iterator=0;
    tab[iterator]=x;
  }
  else{
    if(iterator<rozmiar-1){
      tab[++iterator]=x;
    }
    else if(iterator>=rozmiar-1){
      int *tmp = new int[2*rozmiar];
      for(int i=0;i<=iterator;i++)
	tmp[i] = tab[i];
      delete [] tab;
      tab = tmp;
      tab[++iterator]=x;
      rozmiar*=2;
    }
  }
}


void Lista_tab::pop(){
  if(rozmiar == 0){
    cerr<<"Lista jest pusta!"<<endl;
  }
  iterator--;
  if(iterator<0.25*(rozmiar-1)){
    int *tmp = new int[iterator+1];
    for(int i=0;i<=iterator;i++){
      tmp[i]=tab[i];
    }  
    delete [] tab;
    tab = tmp;
    rozmiar = iterator+1;
  }
}


int Lista_tab::size(){
  return iterator+1;
}

bool Lista_tab::wykonaj_program(char* nazwa_pliku, int ilosc_danych){
  int tmp;
  plik_we.open(nazwa_pliku);
  if(plik_we.good()==false){
    cerr<<"Blad odczytu pliku!"<<endl;
    return false;
  }
  plik_we >> rozmiar_tab;  //pozbyc sie pierwszej liczby z pliku z danymi
  for(int i=0;i<ilosc_danych;i++){
    plik_we >> tmp;
    push(tmp);
  }
  plik_we.close();
  return true;
}

void Lista_tab::wyczysc_dane(int ile){
  delete [] tab;
  rozmiar = 0;
  iterator = 0;
  tab = NULL;
}

void Lista_tab::mergesort(int beg, int end){
  int tmp[end+1];
  int mid = (beg+end+1)/2; int i1, i2,i;
  if(mid-beg>1)
    mergesort(beg,mid-1);
  if(end-mid>0)
    mergesort(mid,end);
  i1=beg; i2=mid;
  for(i=beg; i<=end; i++)
    tmp[i]=((i1==mid)||((i2<=end)&&(tab[i1] > tab[i2]))) ? tab[i2++] : tab[i1++];
  for(i=beg; i<=end; i++) tab[i]=tmp[i];
}

void Lista_tab::heapsort(){

  if(size()>1){

    int root, swap, child, val, start,end;

    //heapify
    start=(size()-2)/2;
    while(start>=0){
      //siftdown
      root = start; end = size()-1;
      while(((root*2)+1)<=end){
	child = (root*2)+1; //left child
	swap = root;      //remembers child
	if(tab[swap]<tab[child])
	  swap = child;
	if(((child+1)<=end) && (tab[swap]<tab[child+1]))
	  swap = child+1;
	if(swap==root) break;
	else{
	  val=tab[root];
	  tab[root]=tab[swap];
	  tab[swap]=val;
	  root=swap;
	}
      }
      start--;
    }
    //
    end=size()-1;
    while(end>0){
      val=tab[end];
      tab[end]=tab[0];
      tab[0]=val;
      end--;
      //siftdown
      root = 0; 
      while(root*2+1<=end){
	child = root*2+1; //left child
	swap = root;      //remembers child

	if(tab[swap]<tab[child])
	  swap = child;
	if(child+1<=end && tab[swap]<tab[child+1])
	  swap = child+1;
	if(swap==root) break;
	else{
	  val=tab[root];
	  tab[root]=tab[swap];
	  tab[swap]=val;
	  root=swap;
	}
      }
    }
  }
}

void Lista_tab::quicksort(int left, int right){
  int i=(right+left)/2;
  int j=0;
 
  if(tab[right]<tab[left])
    zamien(tab,left,right);
  if(tab[i] < tab[left])
    zamien(tab,i,left);
  if(tab[right]<tab[i])
    zamien(tab,right,i);
  int piwot=tab[i];
  i=left; j = right;
  do{
    while(tab[i]<piwot) i++;
    while(tab[j]>piwot) j--;
    if(i<=j){
      zamien(tab,i,j);
      i++; j--;
    }
  }while(i<=j);
  
  if(j>left)
    quicksort(left,j);
  if(i<right)
    quicksort(i,right);
}



int quicky(int *wsk, int left, int right){
  int i, j; 
  i = (left+right)/2;
  if(wsk[right]<wsk[left])
    zamien(wsk,left,right);
  if(wsk[i] < wsk[left])
    zamien(wsk,i,left);
  if(wsk[right]<wsk[i])
    zamien(wsk,right,i);

  for (i=left, j=right-2; ; )
    {
      for ( ; wsk[i]<wsk[right-1]; ++i);
      for ( ; j>=left && wsk[j]>wsk[right-1]; --j);
      if (i<j)
	zamien(wsk,i++,j--);
      else break;
    }
  zamien(wsk,i,right-1);
  return i;
}

void heapsort(int *wsk, int rozmiar){
  if(rozmiar>1){

    int root, swap, child, val, start,end;

    //heapify
    start=(rozmiar-2)/2;
    while(start>=0){
      //siftdown
      root = start; end = rozmiar-1;
      while(((root*2)+1)<=end){
	child = (root*2)+1; //left child
	swap = root;      //remembers child
	if(wsk[swap]<wsk[child])
	  swap = child;
	if(((child+1)<=end) && (wsk[swap]<wsk[child+1]))
	  swap = child+1;
	if(swap==root) break;
	else{
	  val=wsk[root];
	  wsk[root]=wsk[swap];
	  wsk[swap]=val;
	  root=swap;
	}
      }
      start--;
    }
    //
    end=rozmiar-1;
    while(end>0){
      val=wsk[end];
      wsk[end]=wsk[0];
      wsk[0]=val;
      end--;
      //siftdown
      root = 0; 
      while(root*2+1<=end){
	child = root*2+1; //left child
	swap = root;      //remembers child

	if(wsk[swap]<wsk[child])
	  swap = child;
	if(child+1<=end && wsk[swap]<wsk[child+1])
	  swap = child+1;
	if(swap==root) break;
	else{
	  val=wsk[root];
	  wsk[root]=wsk[swap];
	  wsk[swap]=val;
	  root=swap;
	}
      }
    }
  }
}

void introsort(int *wsk, int dlugosc, int M){
  int i;
  if(M<=0){
    heapsort(wsk, dlugosc);
    return;
  }
  i=quicky(wsk,0,dlugosc-1);
  if(i>9)
    introsort(wsk,i,M-1);
  if(dlugosc-1-i>9)
    introsort(wsk+i+1,dlugosc-1-i,M-1);
}

void Lista_tab::hybridsort(){
  introsort(tab,size(),(int)floor(2*log(size())/M_LN2));
  insertsort();
}

void Lista_tab::insertsort(){
  int i,j; int temp;
  for(i=1; i<size(); ++i){
    temp=tab[i];
    for(j=i; j>0 && temp<tab[j-1]; --j)
      tab[j] = tab[j-1];
    tab[j]=temp;
  }
}
