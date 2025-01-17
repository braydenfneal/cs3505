/**
 * Brayden Neal
 * A1: 1D Cellular Automata
 * 
 * This program demonstrates how a cellular automata worlks using rulesets
 * 0-250. Visualization uses #'s and spaces.
 * 
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/**
 * The function should make sure every element in the array is assigned a value.
 * Converting the rule numnber into a binary number, and using those digits for 
 * values.
*/
void convertRuleSetNumberToRuleSetArray(int ruleNum, int ruleArr[8]){
int counter = 0;

while(counter <= 7){
    //is Even
    if (ruleNum % 2 == 0 && ruleNum != 0){
        ruleArr[counter] = 0;
        counter++;
        ruleNum = ruleNum/2;
    }
    //is Odd
    else if (ruleNum % 2 != 0){
        ruleArr[counter] = 1;
        ruleNum--;
        counter++;   
        ruleNum = ruleNum/2;
    }
    //is Zero
    else{
        ruleArr[counter] = 0;
        counter++;
    }
}
}

/**
 * The function should print a space for every 0 in the array and a '#' for every 1, 
 * then add a single end line after outputting all the elements of the array.
 * Example: For a generation array = [1,0,1,1] and a call displayGeneration(array, 4)
 * it would output "# ##"
*/
void displayGeneration(int arr[], int length){

for (size_t i = 0; i < length; i++)
{
    if (*(arr + i) == 0){
        cout << " ";
    }
    else{
        cout << "#";
    }
}
    cout << endl;
}

/**
 * This helper function is really converting a 3 digit binary number to an integer.
*/
int convertNeighborhoodToIndex(int left, int current, int right){
    int binNumber = (left * 4) + (current * 2) + (right * 1);

    return binNumber;
}

/**
 * This function should use the current generation array and the rule set array to compute 
 * and set the values in the next generation array.
*/
void computeNextGeneration(int currentGen[], int nextGen[], int length, int ruleSet[]){
    //Copy the first and last integers into the next Generation
    nextGen[0] = currentGen[0];
    nextGen[length - 1] = currentGen[length - 1];
    //Copy the rest
    for (size_t i = 1; i < length - 1; i++)
    {
        int index = convertNeighborhoodToIndex(currentGen[i - 1], currentGen[i], currentGen[i + 1]);
        nextGen[i] = ruleSet[index];
    }
}

/**
 * Many of the tasks will be delegated to the functions below by calling them. 
 * The main function can have some code of its own - for example, code to get 
 * user input and to loop over the different generations of the CA.
*/
int main(){
    int ruleNum = 0;
    int ruleSetArr[8] = {};
    int currentGenArr[64] = {};
    int nextGenArr[64] = {};
    //1. Asks user for an acceptable set number
    cout << "Please input a rule set number from 0 to 255: " << endl;
    cin >> ruleNum;
    //Check to see if the number is within bounds.
    if (ruleNum < 0 || ruleNum > 255){
        cout << "I'm sorry, the number you chose is outside of the range allowed."<<endl;
        return 0;
    }

    //2. Rule set number converts to binary and stored in the rule set array
    convertRuleSetNumberToRuleSetArray(ruleNum, ruleSetArr);

    //3.A starting generation of all 0's and one 1 at index 32 is created and displayed
    for (size_t i = 0; i < 64; i++)
    {
        currentGenArr[i] = 0;
    }
    currentGenArr[32] = 1;
    displayGeneration(currentGenArr, 64);
    
    //4. 49 new generations should be computed and displayed using the rule set array to compute 
    //   each new generation. This makes a total of 50 rows of output.
    for (size_t i = 0; i < 49; i++)
    {
        computeNextGeneration(currentGenArr, nextGenArr, 64, ruleSetArr);
        displayGeneration(nextGenArr, 64);
        
        //Create new current generation
        for (size_t i = 0; i < 64; i++)
        {
            currentGenArr[i] = nextGenArr[i];
        }
    }
}

