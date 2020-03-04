//Rifa Safeer Shah
//CECS 282 LAB 3 PROBLEM 1

#include <iostream>
#include <iomanip>
using namespace std;

void sort(double array[], int size) {
	for (int i = 0; i < size - 1; i++){
		for (int j = 0; j < size - i - 1; ++j){
			if (array[j] > array[j+1]){
				int value = array[j]; //set value to first element
				array[j] = array[j+1]; //set it to next element
				array[j+1] = value; //set it to value
			}
		}
	}
	
	cout << "The test scores in ascending order, and their average, are: " << endl;
	cout << " " << endl;
	cout << "Score" << endl;
	cout << "-----" << endl;
	cout << " " << endl;
}

double average(double array[], int numScores) {
	double sum = 0;
	for(int k = 0 ; k < numScores ; k ++) {
		sum = sum + array[k];
	}
	return sum / numScores;
}

int main() {
	double scores[5];
	int size;
	
	cout << "How many test scores will you enter? ";
	cin >> size;
	for (int i = 0; i < 5; i++){
		int num;
		cout << "Enter test score " << i + 1 << ": " << fixed << setprecision(2);
		cin >> num;
		scores[i] = num;
	}
	sort(scores, 5);
	for (int m = 0; m < 5; m++){
		
		cout << fixed << setprecision(2) << scores[m] << endl;
	}
	cout << " " << endl;
	printf("Average score: %.2f" , average(scores, size)); //print out average
	return 0;
}
