#include <iostream>
#include <vector>
#include <algorithm>

void printArr(std::vector<int>& arr)
{
    std::cout << "printing Arr:\n";
    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int findMed(std::vector<int> arr)
{
    std::sort(arr.begin(), arr.end());
    if(arr.size() == 0) return 0;

    if(arr.size() % 2 == 0)
    {
        return arr[(arr.size() - 1) / 2];
    }
    else
    {
        int res = (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2;
        return res;
    }

}

std::vector<int> windSum(std::vector<int>& arr, size_t windSize)
{
    std::vector<int> output;

    printArr(arr);

    for(size_t i = 0; i < arr.size() - windSize + 1; i++)
    {
        size_t j = 0;
        size_t tmpSum = 0;
        for (size_t j = 0; j < windSize; j++)
        {
            tmpSum += arr[i+j];
        }
        output.push_back(tmpSum);
    }
    return output;
}

std::vector<int> medArr(std::vector<int>& arr, size_t windSize)
{
    if(windSize > arr.size()) return {};
    std::vector<int> ret;
    #if 1
    std::vector<int> tmp(windSize, 0);
    for(size_t i = 0; i < arr.size() - windSize + 1; i++)
    {
        int med = 0;
        for (size_t j = 0; j < windSize; j++)
        {
            tmp[j] = arr[i+j];
            med = findMed(tmp);   
        }
        ret.push_back(med);
    }
    #else
    std::vector<int> tmp;
    int count = 0;
    while(count < windSize)
    {
        tmp.push_back(arr[count]);
	count++;
    }
    for(size_t i = 0; i < arr.size() - windSize + 1; i++)
    {
        int med = findMed(tmp);
        tmp.pop_front();
	tmp.push_back(arr[i+windSize]);
    }
    #endif
    return ret;
}

int main()
{
    std::vector<int> inputArr = {343, 1, 4, 334, 87, 223, 111};
    //std::cout << "Med = " << findMed(inputArr) << std::endl;

    std::vector<int> medVec = medArr(inputArr, 3);
    std::cout << "medVec = ";
    printArr(medVec);
}
