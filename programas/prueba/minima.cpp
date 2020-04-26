// C++ program to us priority_queue to implement min heap 
#include <bits/stdc++.h> 
using namespace std; 

// Driver code 
int main () 
{ 
	// Creates a min heap 
	priority_queue <int, vector<int>, greater<int> > pq; 
	int a;
	cin>>a;
	int b=0;
	while(b<a){
		int c;
		cin>>c;
		pq.push(c);
		b++;
	}
	/*pq.push(5); 
	pq.push(1); 
	pq.push(10); 
	pq.push(30); 
	pq.push(20); */

	// One by one extract items from min heap 
	while (pq.empty() == false) 
	{ 
		cout << pq.top() << " "; 
		pq.pop(); 
	} 

	return 0; 
}
