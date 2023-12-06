#include <iostream>
#include <pthread.h>
using namespace std;
struct ThreadData {
    int* array;
    int start;
    int end;
    int sum;
};

void* sumArray(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    int partialSum = 0;

    for (int i = data->start; i <= data->end; i++) {
        partialSum += data->array[i];
    }

    data->sum = partialSum;
    pthread_exit(nullptr);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }

    int numThreads;
    cout << "Enter the number of threads: ";
    cin >> numThreads;

    pthread_t* threads = new pthread_t[numThreads];
    ThreadData* threadData = new ThreadData[numThreads];

    int elementsPerThread = n / numThreads;
    int remainingElements = n % numThreads;

    int start = 0;
    for (int i = 0; i < numThreads; i++) {
        int end = start + elementsPerThread - 1;
        if (i < remainingElements) {
            end++;
        }

        threadData[i].array = array;
        threadData[i].start = start;
        threadData[i].end = end;

        pthread_create(&threads[i], nullptr, sumArray, &threadData[i]);

        start = end + 1;
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], nullptr);
    }

    int finalSum = 0;
    for (int i = 0; i < numThreads; i++) {
        finalSum += threadData[i].sum;
    }

    cout << "The sum of the array is: " << finalSum << endl;

    delete[] array;
    delete[] threads;
    delete[] threadData;

    return 0;
}

