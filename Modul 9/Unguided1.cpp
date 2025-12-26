#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <string> 
using namespace std; 

int main() 
{ 
    int Haifan_2311102091; 
    cout << "Silahkan masukkan jumlah simpul : "; 
    cin >> Haifan_2311102091; 
    vector<string> simpul(Haifan_2311102091); 
    vector<vector<int>> busur(Haifan_2311102091, 
    vector<int>(Haifan_2311102091, 0)); 
    
    cout << "Silahkan masukkan nama simpul " << endl; 
    
    for (int i = 0; i < Haifan_2311102091; i++) { 
        cout << "Simpul " << (i + 1) << ": "; 
        cin >> simpul[i]; 
        } 
        cout << "Silahkan masukkan bobot antar simpul" << endl; 
    
    for (int i = 0; i < Haifan_2311102091; i++) { 
        
        for (int j = 0; j < Haifan_2311102091; j++) 
        { 
            cout << simpul[i] << " --> " << simpul[j] << " = "; 
            cin >> busur[i][j];
             }
        } 
             cout << endl; 
             cout << setw(7) << " "; 
             for (int i = 0; i < Haifan_2311102091; i++) {

                cout << setw(8) << simpul[i]; 
            } 
                cout << endl; 
                
                for (int i = 0; i < Haifan_2311102091; i++) 
                { 
                    cout << setw(7) << simpul[i]; 
                    
                    for (int j = 0; j < Haifan_2311102091; j++) 
                    
                {
                    cout << setw(8) << busur[i][j];
                } 
                cout << endl; 
            } 
        }