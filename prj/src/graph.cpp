#include "Graphs/graph.hh"


/*!
 * \file
 * \brief Ciala metod klasy Graph
 */

void Graph::insert(int v1, int v2){
  tab[v1].push(v2);
  if(v1!=v2)
    tab[v2].push(v1);
}

void Graph::print(){
  for(int i=0; i<vCount; i++){
    std::cout<<i<<" | ";
    for(unsigned int j=0; j<tab[i].size();j++)
      std::cout<<(tab[i])[j] << " ";
    std::cout<<std::endl;
  }
}

void Graph::BFS(int source){
  int *distance = new int [vCount];
  char *color = new char [vCount];
  int *previous = new int [vCount];
  for(int i=0; i<vCount; i++){
    color[i]='w';
    distance[i]= -1;
    previous[i]= -1;
  }
  color[source]='g';
  distance[source]=0;
  previous[source]=-2;
  Queue<int> Q;
  Q.push(source);
  while(Q.size()>0){
    for(unsigned int i=0; i<tab[Q[0]].size(); i++){
      if(color[tab[Q[0]][i]]=='w'){
	color[tab[Q[0]][i]]='g';
	distance[tab[Q[0]][i]]=distance[Q[0]]+1;
	previous[tab[Q[0]][i]] = Q[0];
	Q.push(tab[Q[0]][i]);
      }
    }
    color[Q[0]]='b';
    Q.pop();
  }
  delete distance;
  delete color;
  delete previous;
}


void Graph::BFS(int source, int finish){
  int *distance = new int [vCount];
  char *color = new char [vCount];
  int *previous = new int [vCount];
  for(int i=0; i<vCount; i++){
    color[i]='w';
    distance[i]= -1;
    previous[i]= -1;
  }
  color[source]='g';
  distance[source]=0;
  previous[source]=-2;
  Queue<int> Q;
  Q.push(source);
  while(Q.size()>0){
    for(unsigned int i=0; i<tab[Q[0]].size(); i++){
      if(color[tab[Q[0]][i]]=='w'){
	color[tab[Q[0]][i]]='g';
	distance[tab[Q[0]][i]]=distance[Q[0]]+1;
	previous[tab[Q[0]][i]] = Q[0];
	Q.push(tab[Q[0]][i]);
      }
      if(tab[Q[0]][i]==finish){
	std::cout<<"Znaleziona sciezka: " << std::endl;
	int a = tab[Q[0]][i];
	Stack<int> path;
	path.push(a);
	while(previous[a]!=source){
	  a = previous[a];
	  path.push(a);
	}
	path.push(previous[a]);
	path.display();
	for(unsigned int j=0; j<Q.size(); j++)
	  Q.pop();
      }
    }
    color[Q[0]]='b';
    Q.pop();
  }
  delete distance;
  delete color;
  delete previous;
}

void Graph::DFS(){
  int time = 0;
  int *d = new int [vCount];
  int *f = new int [vCount];
  char *color = new char [vCount];
  int *previous = new int [vCount];
  for(int i=0; i<vCount; i++){
    color[i]='w';
    previous[i]= -1;
  }
  for(int i=0; i<vCount; i++)
    if(color[i]=='w')
      DFS_visit(i, time, color, previous, d, f);
}

void Graph::DFS_visit(int u, int time, char *color, int *previous, int *d, int *f){
  color[u] = 'g';
  time++;
  d[u]=time;
  for(unsigned int i=0; i<tab[u].size(); i++)
    while(color[tab[u][i]]=='w'){
      previous[tab[u][i]] = u;
      DFS_visit(tab[u][i], time, color, previous, d ,f);
    }
  color[u] = 'b';
  f[u] = time;
}
