#include<iostream>
#include<vector>
#include<climits>     
using namespace std;

// this method returns a minimum distance for the 
// vertex which is not included in Tset.
int minimumDist(vector<int>dist, vector<bool>visited) 
{
	int min=INT_MAX,index;
              
	for(int i=0;i<visited.size();i++) 
	{
		if(visited[i]==false && dist[i]<=min)      
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(vector<vector<int>>graph,int src) 
{
	vector<int>dist(graph.size(),INT_MAX); // integer array to calculate minimum distance for each node.                            
	vector<bool>visited(graph.size(),false);// boolean array to mark visted/unvisted for each node.
	// set the nodes with infinity distance
	// except for the initial node and mark
	// them unvisited.  
	dist[src] = 0;   // Source vertex distance is set to zero.             
	
	for(int i = 0; i<graph.size(); i++)                           
	{
		int m=minimumDist(dist,visited); // vertex not yet included.
		visited[m]=true;// m with minimum distance included in Tset.
		for(int i = 0; i<graph.size(); i++)                  
		{
			// Updating the minimum distance for the particular node.
			if(!visited[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
				dist[i]=dist[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i = 0; i<graph.size(); i++)                      
	{ //Printing
		char str=65+i; // Ascii values for pritning A,B,C..
		cout<<str<<"\t\t\t"<<dist[i]<<endl;
	}
}

int main()
{
	vector<vector<int>> graph={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
	Dijkstra(graph,0);
	return 0;	                        
}