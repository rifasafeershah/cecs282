//Rifa Safeer Shah
//CECS 282 LAB 3 PROBLEM 2

#include <iostream>
#include <iomanip>
using namespace std;

void sort(double* score, int size);
double average(double*score, int numScores);

void sort(double* score, int size){
	int i;
	int j;
	double value;
	for (i = 0; i < size; i++){
		for (j = i + 1; j < size; j++){
			if (score[i] > score[j]){
				value = score[i];
				score[i] = score[j];
				score[j] = value;
			}
		}
	}
	
	cout << "The test scores in ascending order, and their average, are: " << endl;
	cout << " " << endl;
	cout << "Score" << endl;
	cout << "-----" << endl;
	cout << " " << endl;
	
	for (i = 0; i < size; i++){
		printf("%.2f\n", score[i]);
	}
}

double average(double* score, int numScores){
	int k;
	double sum = 0;
	double average;
	for (k = 0; k < numScores; k++){
		sum = sum + score[k];
	}
	average = sum / numScores;
	return average;
}

int main(){
	double* score,number;
	int size;
	
	cout << "How many test scores will you enter? ";
	cin >> size;
	score = new double[size];
	for (int l = 0; l < size; l++){
		cout << "Enter test score " << l + 1 << ": " << fixed << setprecision(2);
		cin>>number;
		score[l] = number;
	}
	sort(score, size); //calls the sort function
	cout << " " << endl;
	printf("Average score: %.2f" ,average(score, size)); //print out average
	return 0;
}
