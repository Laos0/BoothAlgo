#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <iomanip>

using namespace std;

/*
- user inpuit two decimal
- Add 0 at the end of product
- Depending on the last two digit of the product
	- 00: no operation
	- 01: Prod' = Prod' + Multiplicand
	- 10: Prod' = Prod' - Multuplicand
	- 11: no operation
- Stops iterating when it reaches the end of 8th steps cause there is 8-bit
- output binary

*/
int binToDec(vector<int> v1, vector<int> v2) {
	string product = "";
	int finalProduct = 0;
	int rem = 0;
	int temp = 0;
	int base = 1;
	int dec = 0;
	for (int i = 0; i < v1.size(); i++) {
		product += to_string(v1[i]);
	}
	for (int i = 0; i < v2.size() - 1; i++) {
		product += to_string(v2[i]);
	}

	finalProduct = stoi(product);
	temp = finalProduct;
	while (temp) {
		int lastDigit = temp % 10;
		temp = temp / 10;
		dec += lastDigit * base;
		base = base * 2;
	}

	return dec;
}
string displayFinalProduct(vector<int>v1, vector<int>v2) {
	string currentProduct;
	string vec1 = "";
	string vec2 = "";

	for (int i = 0; i < v1.size(); i++) {
		vec1 += to_string(v1[i]);
	}
	for (int i = 0; i < v2.size() - 1; i++) {
		vec2 += to_string(v2[i]);
	}
	currentProduct = vec1 + " " + vec2;
	return currentProduct;
}
string displayCurrentProduct(vector<int>v1, vector<int>v2) {
	string currentProduct;
	string vec1 = "";
	string vec2 = "";

	for (int i = 0; i < v1.size(); i++) {
		vec1 += to_string(v1[i]);
	}
	for (int i = 0; i < v2.size(); i++) {
		vec2 += to_string(v2[i]);
	}
	currentProduct = vec1 + " " + vec2;
	return currentProduct;
}
string decToBin(int n) {// Convert decimal to binary
	int num = n;
	bitset<8> bin(num);
	return bin.to_string();
}

vector<int> convertBinaryToNegative(vector<int> v) {
	vector<int> negativeVec = v;
	int carry = 1;
	for (int i = 0; i < negativeVec.size(); i++) {
		if (negativeVec[i] == 0) {
			negativeVec[i] = 1;
		}
		else if (negativeVec[i] == 1) {
			negativeVec[i] = 0;
		}
	}
	// After changing all the 1's to 0, and 0's to 1 in the vector v, set negativeVec = v, then add 1 to it
	// implement negativeVec + 1
	for (int i = 0; i < negativeVec.size(); i++) {
		negativeVec[negativeVec.size() - 1 - i] = negativeVec[negativeVec.size() - 1 - i] + carry;
		if (negativeVec[negativeVec.size() - 1 - i] == 3) {
			negativeVec[negativeVec.size() - 1 - i] = 1;
			carry = 1;
		}
		else if (negativeVec[negativeVec.size() - 1 - i] == 2) {
			negativeVec[negativeVec.size() - 1 - i] = 0;
			carry = 1;
		}
		else if (negativeVec[negativeVec.size() - 1 - i] == 1) {
			negativeVec[negativeVec.size() - 1 - i] = 1;
			carry = 0;
		}
		else if (negativeVec[negativeVec.size() - 1 - i] == 0) {
			negativeVec[negativeVec.size() - 1 - i] = 0;
			carry = 0;
		}
	}
	return negativeVec;
}

// splitting a string of numbers apart, and converting each one of them into an int then pushed into a vector
vector<int> convertStringToVec(string cand, vector<int> multiplicand) {
	vector<int> tempMultiplicand = multiplicand;
	for (int i = 0; i < cand.size(); i++) {
		string tempNum;
		tempNum = cand.at(i);
		int num = stoi(tempNum);
		tempMultiplicand.push_back(num);
	}
	return tempMultiplicand;
}

void displayVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
}

void displayInstruction() {
	cout << fixed << setprecision(20);
	cout << left << setw(25) << "Iteration";
	cout << right << setw(25) << "Step";
	cout << right << setw(25) << "Multiplicand";
	cout << right << setw(25) << "Product";
	cout << "\n" << endl;
}

vector<int> returnFirstMCand(vector<int> firstMcand) {
	vector<int> tempV = firstMcand;
	for (int i = 0; i < tempV.size(); i++) {
		tempV[i] = 0;
	}

	return tempV;
}


// Make sure to pass in another vector so you can display the fixed multiplicand and use mCand for the changing Multiplicand

vector<int> addTwoBinary(vector<int> changingMcand, vector<int> fixedMcand) {
	vector<int> finalVec = changingMcand;
	int carry = 0;

	for (int i = 0; i < changingMcand.size(); i++) {
		//  finalVec[7] = product[last index] + multiplicand[last index] + carry;
		finalVec[finalVec.size() - 1 - i] = changingMcand[changingMcand.size() - 1 - i] + fixedMcand[fixedMcand.size() - 1 - i] + carry;
		if (finalVec[finalVec.size() - 1 - i] == 3) {
			finalVec[finalVec.size() - 1 - i] = 1;
			carry = 1;
		}
		else if (finalVec[finalVec.size() - 1 - i] == 2) {
			finalVec[finalVec.size() - 1 - i] = 0;
			carry = 1;
		}
		else if (finalVec[finalVec.size() - 1 - i] == 1) {
			finalVec[finalVec.size() - 1 - i] = 1;
			carry = 0;
		}
		else if (finalVec[finalVec.size() - 1 - i] == 0) {
			finalVec[finalVec.size() - 1 - i] = 0;
			carry = 0;
		}
	}
	return finalVec;
}

// ***************** WHY IS THE TWO SHOWING UP ***********************************
// passing in (changingMcand, multiplicand)
vector<int> subTwoBinary(vector<int> changingMcand, vector<int> fixedMcand) {
	vector<int> finalVec = changingMcand;
	vector<int> negVec = convertBinaryToNegative(fixedMcand);

	int carry = 0;
	for (int i = 0; i < changingMcand.size(); i++) {
		finalVec[finalVec.size() - 1 - i] = changingMcand[changingMcand.size() - 1 - i] + negVec[negVec.size() - 1 - i] + carry;
		if (finalVec[finalVec.size() - 1 - i] == 3) {
			finalVec[finalVec.size() - 1 - i] = 1;
			carry = 1;
		}
		else if (finalVec[finalVec.size() - 1 - i] == 2) {
			finalVec[finalVec.size() - 1 - i] = 0;
			carry = 1;
		}
		else if (finalVec[finalVec.size() - 1 - i] == 1) {
			finalVec[finalVec.size() - 1 - i] = 1;
			carry = 0;
		}
		else if (finalVec[finalVec.size() - 1 - i] == 0) {
			finalVec[finalVec.size() - 1 - i] = 0;
			carry = 0;
		}
	}
	return finalVec;
}


vector<int> mCandARS(vector<int> changingMcand) {
	vector<int> shiftRightMcand = changingMcand;
	for (int i = 1; i < shiftRightMcand.size(); i++) {
		shiftRightMcand[i] = changingMcand[i - 1];
	}
	return shiftRightMcand;
}

vector<int> mPlierARS(vector<int> changingMcand, vector<int> mPlier) {

	// mPlier[0] = changingMcand[last Index]
	// 0001 00001 -- starting
	// 0000 10000 -- 
	vector<int> shiftRightMplier = mPlier;
	shiftRightMplier[0] = changingMcand[changingMcand.size() - 1];
	for (int i = 1; i < mPlier.size(); i++) {
		shiftRightMplier[i] = mPlier[i - 1];
	}
	return shiftRightMplier;
}

//displayBooth(current Iteration, changingMcand, currentMplier, the never changing Mcand )
void displayBooth(int iter, vector<int> mCand, vector<int> mPlier, vector<int> fixedMcand, bool isShift, vector<int> shiftMcand, vector<int> shiftMplier) {
	cout << "======================================================================================================================" << endl;

	int iteration = iter;
	//bool isARS = false;
	//bool isShift = false; // if there 01 or 10 then there is a ARS  then true
	string shift = "";
	string product = ""; // This string has two vectors' elements printed out(the changing multiplicand and the multiplier
	string theMcand = ""; // This string should be the multiplicand from the very start and should not change.  The first number they enter. 
	string operation = "";  // This string will change depending on the last two bit/digits of the multiplier
	vector<int> currentMultiplicand; // this vector is the current multiplicand, that means it will change time to time
	vector<int> theZerosMcand; // This vector contains all 0's in its element, and will only be used once through the 0 iteration or initalization

	// These two variables will be concat into one string which will produce the product
	string curMcand = "";
	string curMplier = "";

	theZerosMcand = returnFirstMCand(mCand);
	// Displaying the fixed multiplicand which is always the same throughout all iterations
	for (int i = 0; i < fixedMcand.size(); i++) {
		theMcand += to_string(fixedMcand[i]);
	}

	if (iteration == 0) {
		for (int i = 0; i < theZerosMcand.size(); i++) {
			curMcand += to_string(theZerosMcand[i]);
		}
		for (int i = 0; i < mPlier.size(); i++) {
			curMplier += to_string(mPlier[i]);
		}
		product = curMcand + " " + curMplier;
	}
	else {
		for (int i = 0; i < mCand.size(); i++) {
			curMcand += to_string(mCand[i]);
		}
		for (int i = 0; i < mPlier.size(); i++) {
			curMplier += to_string(mPlier[i]);
		}
		product = curMcand + " " + curMplier;
	}


	// This is section is for the oeprations 

	if (iteration == 0) {
		operation = "Initalization";
	}
	else if (mPlier[mPlier.size() - 2] == 0 && mPlier[mPlier.size() - 1] == 0) {
		operation = "No Operation";
	}
	else if (mPlier[mPlier.size() - 2] == 1 && mPlier[mPlier.size() - 1] == 0) {
		operation = "Prod' = Prod' - Mcand";
		//isShift = true;
		//isARS = true;
	}
	else if (mPlier[mPlier.size() - 2] == 0 && mPlier[mPlier.size() - 1] == 1) {
		operation = "Prod' = Prod' + Mcand";
		//isShift = true;
	}
	else if (mPlier[mPlier.size() - 2] == 1 && mPlier[mPlier.size() - 1] == 1) {
		operation = "No Operation";
	}
	else {
		operation = "ERROR";
	}

	if (isShift) {
		shift = "ARS >> 1";
		//isARS = true;
	}
	else {
		shift = "";
	}

	cout << fixed << setprecision(20);
	cout << left << setw(25) << iteration;
	cout << right << setw(25) << operation; // add << shift; later
	cout << right << setw(25) << theMcand;
	cout << right << setw(25) << product;

	cout << endl;
	if (isShift) {
		string shiftMultiplicand = "";
		string shiftMultiplier = "";
		for (int i = 0; i < shiftMcand.size(); i++) {
			shiftMultiplicand += to_string(shiftMcand[i]);
		}
		for (int i = 0; i < shiftMplier.size(); i++) {
			shiftMultiplier += to_string(shiftMplier[i]);
		}
		product = shiftMultiplicand + " " + shiftMultiplier;
		cout << left << setw(25) << iteration;
		cout << right << setw(25) << shift;
		cout << right << setw(25) << theMcand;
		cout << right << setw(25) << product;
	}

	cout << endl;
	//isShift = false;
	//isARS = false;
}

int main() {
	// -------------------------------------------   GLOBAL VARIABLES  -----------------------------------------------------
	vector<int> multiplicand;
	vector<int> multiplier;
	vector<int> changingMcand;
	vector<int> displayMcand;

	int mCand;
	int mPlier;
	int iteration = 0;
	int isAddSub = false;
	bool isBothInputsNegative = false;
	string currentProduct = "";

	// These two variable is only used once to convert each char in teh string into an int and then pushed into a vector<int>
	string cand;
	string plier;
	// -------------------------------------------------------------------- END OF GLOBAL VARIABLES --------------------------------------------------
		// User decimal input 
	cout << "Please enter a multiplicand." << endl;
	cin >> mCand;
	cout << "Please enter a multiplier." << endl;
	cin >> mPlier;

	// flag if the two inputs are negative
	if (mCand < 0 && mPlier < 0) {
		isBothInputsNegative = true;
	}
	// converting user mCand and mPlier to string binary
	cand = decToBin(mCand);
	plier = decToBin(mPlier);

	// ---------------------------------------------------------- Converting Both mCand and mPlier string into a vector<int> ---------------------------------------
	multiplicand = convertStringToVec(cand, multiplicand);
	multiplier = convertStringToVec(plier, multiplier);
	// ---------------------------------------------------------- end of converting mCand and mPlier string into a vector<int> -------------------------------------

	// -------------------------------------------- TESTING TO SEE VISUALIZATIONS ------------------------------------------------------------------
	cout << mCand << " in binary is: ";
	displayVector(multiplicand);
	cout << endl << endl;
	cout << mPlier << " in binary is: ";
	displayVector(multiplier);
	cout << endl << endl;
	cout << "The current product is: " << displayCurrentProduct(multiplicand, multiplier);


	// add extra 0 to the mPlier vector or the right half of the product
	cout << endl << endl;
	cout << "Adding an extra zero at the end of the multiplier which is in the right side of product..." << endl;
	multiplier.push_back(0);
	for (int j = 0; j < multiplier.size(); j++) {
		cout << multiplier[j];
	}

	cout << endl << endl;
	// --------------------------------------------- END OF TESTING FOR VISUALIZATIONS ------------------------------------------------------------

	// ----------------------------------- DISPLAYING BOOTH ALGORITHM ----------------------------------------------------------------

	// Default setting
	displayInstruction();
	changingMcand = multiplicand;
	displayMcand = multiplicand;

	vector<int> shiftMcand = multiplicand;
	vector<int> shiftMplier = multiplier;

	// At iteration 0
	displayBooth(iteration, changingMcand, multiplier, displayMcand, isAddSub, shiftMcand, shiftMplier);
	changingMcand = returnFirstMCand(multiplicand);
	iteration++;
	// At iteration 1:
	while (iteration < 9) {
		if (multiplier[multiplier.size() - 2] == 0 && multiplier[multiplier.size() - 1] == 0) {
			//throw invalid_argument("dont hit");
			isAddSub = true;
		}
		else if (multiplier[multiplier.size() - 2] == 0 && multiplier[multiplier.size() - 1] == 1) {
			changingMcand = addTwoBinary(changingMcand, multiplicand);
			isAddSub = true;
		}
		else if (multiplier[multiplier.size() - 2] == 1 && multiplier[multiplier.size() - 1] == 0) {
			changingMcand = subTwoBinary(changingMcand, multiplicand);
			isAddSub = true;
		}
		else if (multiplier[multiplier.size() - 2] == 1 && multiplier[multiplier.size() - 1] == 1) {
			//throw invalid_argument("dont hit");
			isAddSub = true;
		}
		else {
			throw invalid_argument("dont hit");
		}
		if (isAddSub) {
			shiftMcand = mCandARS(changingMcand);
			shiftMplier = mPlierARS(changingMcand, multiplier);
		}
		displayBooth(iteration, changingMcand, multiplier, displayMcand, isAddSub, shiftMcand, shiftMplier);
		changingMcand = shiftMcand;
		multiplier = shiftMplier;
		isAddSub = false;
		iteration++;
	}

	int finalP = mCand * mPlier;
	cout << endl << endl;
	cout << "The product is: " << displayCurrentProduct(changingMcand, multiplier) << endl;
	cout << "Take out the last bit at the end of the product." << endl;
	cout << "Final product is: " << displayFinalProduct(changingMcand, multiplier) << endl;
	cout << "Converting the final product to decimal is: " << finalP << endl;
	//cout << "Converting the final product to decimal is: " << binToDec(changingMcand, multiplier);

	system("pause");
	return 0;

}
