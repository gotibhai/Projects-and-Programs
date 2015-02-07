
#include<iostream.h>
#include<conio.h>
using namespace std;
 
int main()
{
    int mat[3][3], trans_mat[3][3];
 
     cout<<"INITIALIZE THE MATRIX : "<<endl;
    /* Initializing Mat1 and Mat2 */
    for (int i = 0; i < 3; i++)
    { 
        for (int j = 0; j < 3; j++)
        {
            cin >> mat[i][j];	
        }
    }
   cout<<endl;
   cout<<"CURRENT ARRAY : "<<endl<<endl;
    for (int i = 0; i < 3; i++)
    { 
        for (int j = 0; j < 3; j++)
        {
            cout<< mat[i][j]<< "\t";
        }
        cout<<endl;
    }
 
    /* Transposing elements of the matrix */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            trans_mat[j][i] = mat[i][j];	
        }
    }
 
    cout << "TRANSPOSE : " <<endl<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << trans_mat[i][j] << "\t";	
        }
        cout << endl;
    }
    getch();
}
