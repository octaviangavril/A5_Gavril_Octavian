#pragma once
class Sort

{

    int* vector;
    int numar_elemente;
public:


    Sort(int numar_elemente, int min_element, int max_element);

    Sort(int* vector, int numar_elemente);

    Sort(int count, ...);

    Sort(char* c);

    Sort();

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent ,int low,int high);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};

