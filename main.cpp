#include "funky hack/funky hack/DataProcessor.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>




using namespace std;

int main()
{
	DataProcessor process;
	process.initialize("input.txt");
	process.update();
	cout << "here";
	
	process.printGarbo();
}