#include<iostream>
#include<fstream>
#include<climits>

using namespace std;

class Queue {
    int *A;
    int s, front, rear;

public:
    Queue(int size = 100) {
        s = size;
        A = new int[s];
        front = rear = -1;
    }

    ~Queue() {
        delete[] A;
    }

    bool isFull() {
        return rear == s - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enQueue(int key) {
        if (isFull()) return;
        if (isEmpty()) front = 0;
        A[++rear] = key;
    }

    int deQueue() {
        if (isEmpty()) return INT_MIN;
        int e = A[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return e;
    }
};

class Stack {
    int *A, s, top;

public:
    Stack(int size = 100) {
        s = size;
        A = new int[s];
        top = -1;
    }

    ~Stack() {
        delete[] A;
    }

    bool isFull() {
        return top == s - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int key) {
        if (!isFull()) A[++top] = key;
    }

    void pop() {
        if (!isEmpty()) top--;
    }

    int peek() {
        return isEmpty() ? INT_MIN : A[top];
    }
};

class Graph {
    int **A, v;

public:
    Graph(string filename) {
        fstream file;
		file.open(filename, ios::in);
		file >> v;
        A = new int*[v];
        for (int i = 0; i < v; i++) {
            A[i] = new int[v];
            for (int j = 0; j < v; j++) {
				file >> A[i][j];
            }
        }
	    file.close();
    }

    ~Graph() {
        for (int i = 0; i < v; i++) delete[] A[i];
        delete[] A;
    }

    void Display() {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
    }

    void BFS(int sv = 0) {
        Queue Q(v);
        int *visited = new int[v]{};
        Q.enQueue(sv);
        visited[sv] = 1;
        cout << "\nBFS Traversal: ";

        while (!Q.isEmpty()) {
            int x = Q.deQueue();
            cout << x << " ";
            for (int j = 0; j < v; j++) {
                if (A[x][j] && !visited[j]) {
                    Q.enQueue(j);
                    visited[j] = 1;
                }
            }
        }
        delete[] visited;
    }

    void DFS(int sv = 0) {
        Stack st(v);
        int *visited = new int[v]{};
        st.push(sv);
        visited[sv] = 1;
        cout << "\nDFS Traversal: ";
        cout << sv << " ";

        while (!st.isEmpty()) {
            int x = st.peek();
            bool found = false;
            for (int j = 0; j < v; j++) {
                if (A[x][j] && !visited[j]) {
                    cout << j << " ";
                    st.push(j);
                    visited[j] = 1;
                    found = true;
                    break;
                }
            }
            if (!found) st.pop();
        }
        delete[] visited;
    }
};

int main() {
    Graph G("maze.txt");
    G.Display();
    G.DFS();
    G.BFS();
    return 0;
}