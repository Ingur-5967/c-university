#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int findMaxElement(const int* arr, int size) {
    int maximum = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > maximum)
            maximum = arr[i];
    }
    return maximum;
}

void task1(const int* arrA, const int* arrB, int size) {

    int maximumA = findMaxElement(arrA, size);
    int maximumB = findMaxElement(arrB, size);

    cout << "Maximum A: " << maximumA << endl;
    cout << "Maximum B: " << maximumB << endl;

    for (int i = 0; i < size; i++) {
        cout << "A (Del/Source): " << static_cast<double>(arrA[i]) / maximumA << " " << arrA[i] << endl;
        cout << "B (Del/Source): " << static_cast<double>(arrB[i]) / maximumB << " " << arrB[i] << endl;
    }

    cout << endl;
}

void task2(set<int> setA, set<int> setB) {

    set_intersection(setB.begin(), setB.end(), setA.begin(), setA.end(), inserter(setB, setB.begin()));

    for (const int& e : setB) {
        if(e < 0) 
            cout<< "Set B: " << e << endl;
    }

    cout << endl;
}

int main()
{
    int N;

    cout << "Input size (N): ";
    cin >> N;

    int* A = new int[N];
    int* B = new int[N];

    cout << "Input [" << N << "] elements for massive A:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    cout << "Input [" << N << "] elements for massive B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    task1(A, B, N);

    set<int> setA;
    set<int> setB;

    int elementA;
    cout << "Input [" << N << "] elements for set A:" << std::endl;
    for (int i = 0; i < N; i++) {
        cin >> elementA;
        setA.insert(elementA);
    }

    int elementB;
    cout << "Input [" << N << "] elements for set B:" << std::endl;
    for (int i = 0; i < N; i++) {
        cin >> elementB;
        setB.insert(elementB);
    }

    task2(setA, setB);
}
