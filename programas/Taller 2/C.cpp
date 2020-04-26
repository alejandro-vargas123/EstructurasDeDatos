//Alejandro Vargas Bernal

#include <iostream>

using namespace std;

int left(int x) { return 2 * x + 1; }
int right(int x) { return 2 * x + 2; }
int parent(int x) { return (x - 1) / 2; }

struct PQ {
	int n;
	int heap[5010];
};

void min_heapify(PQ &pq, int id) {
	int l = left(id);
	int r = right(id);
	int smallest = id;
	if (l < pq.n && pq.heap[l] < pq.heap[smallest])
		smallest = l;
	if (r < pq.n && pq.heap[r] < pq.heap[smallest])
		smallest = r;
	if (smallest != id) {
		int tmp = pq.heap[id];
		pq.heap[id] = pq.heap[smallest];
		pq.heap[smallest] = tmp;
		min_heapify(pq, smallest);
	}
}

void build(PQ &pq) {
	for (int i = pq.n - 1; i >= 0; i--)
		min_heapify(pq, i);
}

int top(PQ &pq) {
	return pq.heap[0];
}

void pop(PQ &pq) {
	if (pq.n == 0) return;
	int smallest = pq.heap[0];
	pq.heap[0] = pq.heap[pq.n - 1];
	pq.n--;
	min_heapify(pq, 0);
}

void push(PQ &pq, int key) {
	pq.n++;
	pq.heap[pq.n - 1] = key;
	int i = pq.n - 1;
	while (i > 0 && pq.heap[parent(i)] > pq.heap[i]) {
		int tmp = pq.heap[parent(i)];
		pq.heap[parent(i)] = pq.heap[i];
		pq.heap[i] = tmp;
		i = parent(i);
	}
}

int main() {
	int n;
	//cin>>n;
	while (cin >> n && n > 0) {
		PQ pq;
		pq.n = n;
		for (int i = 0; i < n; i++)
			cin >> pq.heap[i];
		build(pq);
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			int a = top(pq); pop(pq);
			int b = top(pq); pop(pq);
			sum += a + b;
			push(pq, a + b);
		}
		cout << sum << endl;
	}
	return 0;
}
