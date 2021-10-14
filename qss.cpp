#include <iostream>
#include <sstream>
#include <cstdlib>
// create an array of length size of random numbers
// returns a pointer to the array

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


// function to rearrange array (find the partition point)
int partition(int *array, int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int *array, int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}



// seed: seeds the random number generator
int * randNumArray( const int size, const int seed ) {
	srand( seed );
	int * array = new int[ size ];
	for( int i = 0; i < size; i ++ ) {
		array[i] = std::rand() % 1000000;
	}
	return array;
}
int main( int argc, char** argv ) {
	int * array; // the poitner to the array of rands
	int size, seed; // values for the size of the array
	// and the seed for generating
	// random numbers
	// check the command line args
	if( argc < 3 ){
	std::cerr << "usage: "<< argv[0] << " [amount of random nums to generate] [seed value for rand]"
	<< std::endl;
		exit( -1 );
	}
	// convert cstrings to ints
		{
			std::stringstream ss1( argv[1] );
			ss1 >> size;
		}
	{
	std::stringstream ss1( argv[2] );
	ss1 >> seed;
	}
	// get the random numbers
	array = randNumArray( size, seed );
	// **************************
	// **************************
	// **************************
	//
	quickSort(arr, 0, size - 1);
	//
	// **************************
	// **************************
	// **************************

	// delete the heap memory
	delete [] array;
}






