#include <iostream>
using namespace std;

void inputData(int term, int coeff[], int degree[]){
    for (int i = 0; i < term; i++) {
        cout << "Enter degree and coefficient for term " << i + 1 << ": "<<endl;
        cin >> coeff[i] >> degree[i];
    }
}

void printData(int term, int coeff[], int degree[]){
    for(int i = 0; i < term; i++){
        cout<<coeff[i]<<"x^"<<degree[i];
        if(i != term - 1)   cout<<" + ";
    }
    cout << endl;
}

void add(int terma, int coeffa[], int degreea[],
         int termb, int coeffb[], int degreeb[], 
         int termc, int coeffc[], int degreec[],
         int &resultTerms, int resultCoeff[], int resultDegree[]) {
    
    int i = 0, j = 0, k = 0; // indices for A, B, and C
    resultTerms = 0; // count of terms in result
    
    while (i < terma || j < termb || k < termc) {
        int degreeA = (i < terma) ? degreea[i] : -1; // degree of current term in A or -1 if no more terms
        int degreeB = (j < termb) ? degreeb[j] : -1; // degree of current term in B or -1 if no more terms
        int degreeC = (k < termc) ? degreec[k] : -1; // degree of current term in C or -1 if no more terms
        
        if (degreeA == degreeB && degreeB == degreeC) {
            // All degrees are the same; add coefficients
            resultDegree[resultTerms] = degreeA;
            resultCoeff[resultTerms] = coeffa[i] + coeffb[j] + coeffc[k];
            i++; j++; k++;
        } else if (degreeA <= degreeB && degreeA <= degreeC && degreeA != -1) {
            // Degree of A is smallest (or tied and A is available)
            resultDegree[resultTerms] = degreeA;
            resultCoeff[resultTerms] = coeffa[i] + (degreeA == degreeB ? coeffb[j++] : 0) + (degreeA == degreeC ? coeffc[k++] : 0);
            i++;
        } else if (degreeB <= degreeA && degreeB <= degreeC && degreeB != -1) {
            // Degree of B is smallest (or tied and B is available)
            resultDegree[resultTerms] = degreeB;
            resultCoeff[resultTerms] = coeffb[j] + (degreeB == degreeA ? coeffa[i++] : 0) + (degreeB == degreeC ? coeffc[k++] : 0);
            j++;
        } else {
            // Degree of C is smallest (or tied and C is available)
            resultDegree[resultTerms] = degreeC;
            resultCoeff[resultTerms] = coeffc[k] + (degreeC == degreeA ? coeffa[i++] : 0) + (degreeC == degreeB ? coeffb[j++] : 0);
            k++;
        }
        
        // Only add non-zero terms to the result
        if (resultCoeff[resultTerms] != 0) {
            resultTerms++; // Increment result term count
        }
    }
    
}

int main() {
    
    int terma;

    cout<<"Enter the number of term in the polynomial A: ";
    if (!(cin>>terma) || terma <= 0){
        cout<<"Error!!! Term should be a number greater than zero";
        return 1;
    }

    int coeffa[terma], degreea[terma];

    inputData(terma, coeffa, degreea);
    printData(terma, coeffa, degreea);
    

    int termb;

    cout<<"Enter the number of term in the polynomial B: ";
    if (!(cin>>termb) || termb <= 0){
        cout<<"Error!!! Term should be a number greater than zero";
        return 1;
    }

    int coeffb[termb], degreeb[termb];

    inputData(termb, coeffb, degreeb);
    printData(termb, coeffb, degreeb);
    

    int termc;

    cout<<"Enter the number of term in the polynomial C: ";
    if (!(cin>>termc) || termc <= 0){
        cout<<"Error!!! Term should be a number greater than zero";
        return 1;
    }

    int coeffc[termc], degreec[termc];

    inputData(termc, coeffc, degreec);
    printData(termc, coeffc, degreec);

    int resultTerms = 0;
    int resultCoeff[terma + termb + termc]; // Result coefficient array
    int resultDegree[terma + termb + termc]; // Result degree array

    add(terma, coeffa, degreea, termb, coeffb, degreeb, termc, coeffc, degreec, resultTerms, resultCoeff, resultDegree);
    
    printData(resultTerms, resultCoeff, resultDegree);
    
    return 0;
}