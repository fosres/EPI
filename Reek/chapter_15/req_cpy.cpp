#if 0

Copyright 2018-INFINITY Tanveer Salim

#endif


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846264338327950288419716939937510;

void grayscale(int**pix,int SIZE, double max, double min, int ncol, int nrow, double xscal, double yscal,string fname);

void binary_grayscale(short**pix,int SIZE, double max, double min, int ncol,int nrow,double xscal, double yscal,string
fname);

int * rescale(int**pix, double S[], int SIZE, int ncol, int nrow, double xscal,double yscal);

short * rescale_for_binary(short**pix, double S[], int SIZE, int ncol, int nrow, double xscal,double yscal);

void convert_to_PGM(int*pix,int ncol, int nrow, int SIZE,string fname);

void convert_to_grayscale_PGM(int*pix,int ncol, int nrow, int SIZE,string fname);


void convert_to_binary_grayscale_PGM(short*pix,int ncol, int nrow, int SIZE,string fname);

void convert_to_binary_PGM(short*pix,int ncol, int nrow,int SIZE,string fname);

void convert_to_binary_grayscale_PGM(short*pix,int ncol, int nrow,int SIZE,string fname);

void dot_product_of_pixel(int**pix,double S[],int ncol,int c, int nrow, int r, double xscal,double yscal);


void short_dot_product_of_pixel(short**pix,double S[],int ncol,int c, int nrow, int r, double xscal,double yscal);

void extract_subregion(int ** dest, int * src, int ulr, int ulc, int lrr, int lrc, int ncol);

void extract_short_subregion(short ** dest, short * src, int ulr, int ulc, int lrr, int lrc, int ncol);

int min(int arr[], int SIZE);

void eleven_min(int arr[], int nrow, int * r_min, int ncol, int * c_min);

int max(int arr[], int SIZE);

void eleven_max(int arr[], int nrow, int * r_max, int ncol, int * c_max);

short short_min(short arr[], int SIZE);

void eleven_short_min(short arr[], int nrow, int * r_min, int ncol, int * c_min);

short short_max(short arr[], int SIZE);

void eleven_short_max(short arr[],int nrow, int * r_max, int ncol, int * c_max);

void read_EGM(string fname,char header[],int*nc, int*nr, double*min, double*max, double*x_scale,double*y_scale,int**pix);

void write_PGM(string fname, int *nc, int * nr, int * mv, int *pix);

void read_binary_EGM(string fname,char egm_type[8],int hdr_info[6],int*ncol,int*nrow,double*min,double*max,double*x_scal,double*y_scal,short**pix_arr);


#if 0

    Formula to convert (row#,col#) of pixel into index of array:

    index i == ncol*(r)+c, c == col#, r == row# 

    r range: 0-(nrow-1)

    c range: 0-(ncol-1)

    To convert DEM pixel to PGM pixel, you actually need FOUR distinct DEM pixels!!!

    Target Pix: ncol*(r)+c

    Adjacent (To Target) Pix: ncol(r)+c+1

    Below Target Pix: ncol*(r+1)+c

    4th Pix: ncol*(r+1)+c+1

    A --> (xscal,0,Adjacent-Target)

    B --> (0,yscal,Below-Target)

    A_norm = <A>/||A||

    B_norm = <B>/||B||

    N = <A_norm> x <B_norm> (cross product) // This is the normalized surface vector

    A x B = (AyBz - ByAz,
             AzBx - BzAx,
             AxBy - BxAy
            )

    N = (
         An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

    The above is the programming formula for the normalized

    surface vector.

    NOTE: This formula will not work for the last row. There is no row

    below it!

    For last row (EXCEPT THE VERY LAST PIXEL IN FILE, DO THIS:

    Target Pixel: ncol*r+c      Adjacent: ncol*(r)+c+1

    Below: ncol*(r-1)+c         4th Pix: ncol*(r-1)+c+1

    For VERY LAST PIXEL, do this:

    Target Pixel: ncol*r+c      Adjacent: ncol*(r)+c-1

    Below: ncol*(r-1)+c         4th Pix: ncol*(r-1)+c-1

    
    Now that you have the Normal vector(array), perform the DOT product of 
    the sun vector(array) S and the normal vector (array) N:

    double dot_product = N dot S = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];

    double brightness = 0.9*dot_product+0.1;

    pix_arr[i] = (int or short)(255*brightness);

#endif


void convert_to_grayscale_PGM(int*pix,int ncol, int nrow, int SIZE,string fname)
{
    
    ofstream ofs;

    fname += "_grayscale_ascii.pgm";

    cout << endl;

    cout << "The grayscale ASCII image file produced by the program is " << fname << endl;
    
    cout << endl;

    ofs.open(fname.c_str());

    if (!ofs)
    { cerr << "Error! Can't open file for writing." << endl; exit(1); }

    ofs << "P2" << endl;

    ofs << endl;

    ofs << ncol << " " << nrow << endl;

    ofs << 255 << endl;


#if 0
    index i == ncol*(r)+c, c == col#, r == row# 
#endif

    for ( int r = 0; r < nrow; r++)
    {
        for ( int c = 0; c < ncol; c++)
        {
            ofs << pix[ncol*(r)+c] << " ";
        }

            ofs << endl;

    }

    ofs.close();
}


void convert_to_PGM(int*pix,int ncol, int nrow, int SIZE,string fname)
{
    
    ofstream ofs;

    fname += "_ascii.pgm";

    cout << endl;

    cout << "The illuminated image file produced by the program is " << fname << endl;

    ofs.open(fname.c_str());

    if (!ofs)
    { cerr << "Error! Can't open file for writing." << endl; exit(1); }

    ofs << "P2" << endl;

    ofs << endl;

    ofs << ncol << " " << nrow << endl;

    ofs << 255 << endl;


#if 0
    index i == ncol*(r)+c, c == col#, r == row# 
#endif

    for ( int r = 0; r < nrow; r++)
    {
        for ( int c = 0; c < ncol; c++)
        {
            ofs << pix[ncol*(r)+c] << " ";
        }

            ofs << endl;

    }

    ofs.close();
}



void convert_to_binary_PGM(short*pix,int ncol,int nrow,int SIZE,string fname)
{
    
    ofstream ofs;

    fname += "_binary.pgm";
    
    cout << endl;

    cout << "The illuminated binary image file produced by the program is " << fname << endl;

    ofs.open(fname.c_str(),ios::binary);

    if (!ofs)
    { cerr << "Error! Can't open file for writing!" << endl; exit(1); }

    ofs << "P5" << " " << ncol << " " << nrow << " " << 255 << " " << endl;

#if 0
    index i == ncol*(r)+c, c == col#, r == row# 
#endif
    

    unsigned char * temp = new unsigned char[SIZE];

    for ( int i = 0; i < SIZE; i++)
    {
       temp[i] = (unsigned char)pix[i]; 

    }
    
    ofs.write(reinterpret_cast<char *>(temp),SIZE*sizeof(unsigned char));

    delete[] temp;

    ofs.close();
}


void convert_to_binary_grayscale_PGM(short*pix,int ncol, int nrow,int SIZE,string fname)
{
    
    ofstream ofs;

    fname += "_grayscale_binary.pgm";
    
    cout << endl;

    cout << "The grayscale binary image file produced by the program is " << fname << endl;

    ofs.open(fname.c_str(),ios::binary);

    if (!ofs)
    { cerr << "Error! Can't open file for writing!" << endl; exit(1); }

    ofs << "P5" << " " << ncol << " " << nrow << " " << 255 << " " << endl;

#if 0
    index i == ncol*(r)+c, c == col#, r == row# 
#endif
    

    unsigned char * temp = new unsigned char[SIZE];

    for ( int i = 0; i < SIZE; i++)
    {
       temp[i] = (unsigned char)pix[i]; 

    }
    
    ofs.write(reinterpret_cast<char *>(temp),SIZE*sizeof(unsigned char));

    delete[] temp;

    ofs.close();
}


void short_dot_product_of_pixel(short**pix,double S[],int ncol,int c, int nrow, int r, double xscal,double yscal)
{

#if 0
    index i == ncol*(r)+c, c == col#, r == row# 


    To convert DEM (*pix)el to PGM (*pix)el, you actually need FOUR distinct DEM (*pix)els!!!

    Target Pix: ncol*(r)+c

    Adjacent (To Target) Pix: ncol(r)+c+1

    Below Target Pix: ncol*(r+1)+c

    4th Pix: ncol*(r+1)+c+1

    A --> (xscal,0,Adjacent-Target)

    B --> (0,yscal,Below-Target)

    A_norm = <A>/||A||

    B_norm = <B>/||B||

    N = <A_norm> x <B_norm> (cross product) // This is the normalized surface vector

    A x B = (AyBz - ByAz,
             AzBx - BzAx,
             AxBy - BxAy
            )

    N = (An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

    The above is the programming formula for the normalized

    surface vector.

    NOTE: This formula will not work for the last row. There is no row

    below it!
#endif    
    
    cout << endl;

    cout << "Statistics for pixel at: Column " << c << " Row " << r << ":" << endl;
    short target_pix = (*pix)[ncol*(r)+c];

    cout << "Target Pixel is: " << (*pix)[ncol*(r)+c] << endl;

#if 0

    Below Target Pix: ncol*(r+1)+c

#endif


    short below_pix = (*pix)[ncol*(r+1)+c];

    cout << "Below Pixel is: " << (*pix)[ncol*(r+1)+c] << endl;

#if 0

    Adjacent (To Target) Pix: ncol(r)+c+1

#endif

    short adjacent_pix = (*pix)[ncol*(r)+c+1]; 

    cout << "Adjacent Pixel is: " << (*pix)[ncol*(r)+c+1] << endl;

#if 0
    4th Pix: ncol*(r+1)+c+1
#endif

    short fourth_pix = (*pix)[ncol*(r+1)+c+1];

    cout << "Fourth Pixel is: " << (*pix)[ncol*(r+1)+c+1]<< endl;

#if 0

    A --> (xscal,0,Adjacent-Target)

#endif


    double A[3] = {xscal,0,adjacent_pix - target_pix};

    cout << "A is: " << "(" << A[0] << "," << A[1] << "," << A[2] << ")" << endl;

    double A_mag = sqrt(pow(A[0],2)+pow(A[1],2)+pow(A[2],2));

#if 0

    B --> (0,yscal,Below-Target)
#endif

    double B[3] = {0,yscal,below_pix-target_pix};

    cout << "B is: " << "(" << B[0] << "," << B[1] << "," << B[2] << ")" << endl;

    double B_mag = sqrt(pow(B[0],2)+pow(B[1],2)+pow(B[2],2));

    double A_norm[3] = {A[0]/A_mag,A[1]/A_mag,A[2]/A_mag};

    cout << "A_norm is: " << "(" << A_norm[0] << "," << A_norm[1] << "," << A_norm[2] << ")" << endl;

    double B_norm[3] = {B[0]/B_mag,B[1]/B_mag,B[2]/B_mag};

    cout << "B_norm is: " << "(" << B_norm[0] << "," << B_norm[1] << "," << B_norm[2] << ")" << endl;

#if 0

    N = <A_norm> x <B_norm> (cross product) // This is the normalized surface vector

    A x B = (AyBz - ByAz,
             AzBx - BzAx,
             AxBy - BxAy
            )

    N = (An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

    The above is the programming formula for the normalized

    surface vector.


#endif


    double N[3] = {A_norm[1]*B_norm[2] - B_norm[1]*A_norm[2],A_norm[2]*B_norm[0] - B_norm[2]*A_norm[0],A_norm[0]*B_norm[1] - B_norm[0]*A_norm[1]};

    cout << "N is: " << "(" << N[0] << "," << N[1] << "," << N[2] << ")" << endl;
    
    cout << "Sun normal vector is: " << endl;

    cout << "(" << S[0] << "," << S[1] << "," << S[2] << ")" << endl;

    double dot_product = S[0]*N[0] + S[1]*N[1] + S[2]*N[2];

    cout << "Dot product of surface normal vector and sun vector is: " << endl;

    cout << dot_product << endl;

    double brightness = 0.9*dot_product+0.1;

    cout << "Brightness is: " << brightness << endl;

    short sample_pixel = (short)(brightness*255);

    cout << "PGM pixel is: " << sample_pixel << endl;

}


void dot_product_of_pixel(int**pix,double S[],int ncol, int c, int nrow, int r, double xscal, double yscal)
{

#if 0
    index i == ncol*(r)+c, c == col#, r == row# 


    To convert DEM (*pix)el to PGM (*pix)el, you actually need FOUR distinct DEM (*pix)els!!!

    Target Pix: ncol*(r)+c

    Adjacent (To Target) Pix: ncol(r)+c+1

    Below Target Pix: ncol*(r+1)+c

    4th Pix: ncol*(r+1)+c+1

    A --> (xscal,0,Adjacent-Target)

    B --> (0,yscal,Below-Target)

    A_norm = <A>/||A||

    B_norm = <B>/||B||

    N = <A_norm> x <B_norm> (cross product) // This is the normalized surface vector

    A x B = (AyBz - ByAz,
             AzBx - BzAx,
             AxBy - BxAy
            )

    N = (An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

    The above is the programming formula for the normalized

    surface vector.

    NOTE: This formula will not work for the last row. There is no row

    below it!
#endif    
    

    cout << "Statistics for pixel at: Column " << c << " Row " << r << ":" << endl;
    int target_pix = (*pix)[ncol*(r)+c];

    cout << "Target Pixel is: " << (*pix)[ncol*(r)+c] << endl;

#if 0

    Below Target Pix: ncol*(r+1)+c

#endif


    int below_pix = (*pix)[ncol*(r+1)+c];

    cout << "Below Pixel is: " << (*pix)[ncol*(r+1)+c] << endl;

#if 0

    Adjacent (To Target) Pix: ncol(r)+c+1

#endif

    int adjacent_pix = (*pix)[ncol*(r)+c+1]; 

    cout << "Adjacent Pixel is: " << (*pix)[ncol*(r)+c+1] << endl;

#if 0
    4th Pix: ncol*(r+1)+c+1
#endif

    int fourth_pix = (*pix)[ncol*(r+1)+c+1];

    cout << "Fourth Pixel is: " << (*pix)[ncol*(r+1)+c+1]<< endl;

#if 0

    A --> (xscal,0,Adjacent-Target)

#endif


    double A[3] = {xscal,0,adjacent_pix - target_pix};

    cout << "A is: " << "(" << A[0] << "," << A[1] << "," << A[2] << ")" << endl;

    double A_mag = sqrt(pow(A[0],2)+pow(A[1],2)+pow(A[2],2));

#if 0

    B --> (0,yscal,Below-Target)
#endif

    double B[3] = {0,yscal,below_pix-target_pix};

    cout << "B is: " << "(" << B[0] << "," << B[1] << "," << B[2] << ")" << endl;

    double B_mag = sqrt(pow(B[0],2)+pow(B[1],2)+pow(B[2],2));

    double A_norm[3] = {A[0]/A_mag,A[1]/A_mag,A[2]/A_mag};

    cout << "A_norm is: " << "(" << A_norm[0] << "," << A_norm[1] << "," << A_norm[2] << ")" << endl;

    double B_norm[3] = {B[0]/B_mag,B[1]/B_mag,B[2]/B_mag};

    cout << "B_norm is: " << "(" << B_norm[0] << "," << B_norm[1] << "," << B_norm[2] << ")" << endl;

#if 0

    N = <A_norm> x <B_norm> (cross product) // This is the normalized surface vector

    A x B = (AyBz - ByAz,
             AzBx - BzAx,
             AxBy - BxAy
            )

    N = (An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

    The above is the programming formula for the normalized

    surface vector.


#endif


    double N[3] = {A_norm[1]*B_norm[2] - B_norm[1]*A_norm[2],A_norm[2]*B_norm[0] - B_norm[2]*A_norm[0],A_norm[0]*B_norm[1] - B_norm[0]*A_norm[1]};

    cout << "N is: " << "(" << N[0] << "," << N[1] << "," << N[2] << ")" << endl;
    
    cout << "Sun normal vector is: " << endl;

    cout << "(" << S[0] << "," << S[1] << "," << S[2] << ")" << endl;

    double dot_product = S[0]*N[0] + S[1]*N[1] + S[2]*N[2];

    cout << "Dot product of surface normal vector and sun vector is: " << endl;

    cout << dot_product << endl;

    double brightness = 0.9*dot_product+0.1;

    cout << "Brightness is: " << brightness << endl;

    int sample_pixel = (int)(brightness*255);

    cout << "PGM pixel is: " << sample_pixel << endl;

}


void grayscale(int**pix,int SIZE, double max, double minimum, int ncol, int nrow, double xscal, double yscal,string fname)
{
    fname = fname + "_grayscale.pgm";
   
   const int MIN = min((*pix),SIZE);

   double raw_gray_value = 0;

   for ( int i = 0; i < SIZE; i++ )
   {
        (*pix)[i] = (*pix)[i] - MIN;
   }

   for ( int i = 0; i < SIZE; i++ )
   {

       raw_gray_value = ( (*pix)[i] * (255.) )/(max - minimum);
        
        (*pix)[i] = (int)(raw_gray_value);

   }

    convert_to_grayscale_PGM((*pix),ncol,nrow,SIZE,fname);
    

}


void binary_grayscale(short**pix,int SIZE, double max, double min, int ncol,int nrow,double xscal, double yscal,string fname)
{
    fname = fname + "_grayscale.pgm";
   
   const short MIN = short_min((*pix),SIZE);

   double raw_gray_value = 0;

   for ( int i = 0; i < SIZE; i++ )
   {
        (*pix)[i] = (*pix)[i] - MIN;
   }

   for ( int i = 0; i < SIZE; i++ )
   {

       raw_gray_value = ( (*pix)[i] * (255.) )/(max - min);
        
        (*pix)[i] = (short)(raw_gray_value);

   }

    convert_to_binary_grayscale_PGM((*pix),ncol,nrow,SIZE,fname);
    

}




int * rescale(int**pix, double S[], int SIZE, int ncol, int nrow, double xscal,double yscal)
{
   const int MIN = min((*pix),SIZE);

   for ( int i = 0; i < SIZE; i++ )
   {
        (*pix)[i] = (*pix)[i] - MIN;
   }

   ofstream ofs;

   ofs.open("pixel_values_after_min_sub.txt");

   for ( int i = 0; i < SIZE; i++ )
   {
        ofs << (*pix)[i] << endl;
   }

   ofs.close();

    int target_pix = 0;

    int below_pix = 0;

    int adjacent_pix = 0;

    int fourth_pix = 0;
   
    double A[3];

    double A_mag = 0;

    double B[3];

    double B_mag = 0;

    double A_norm[3];

    double B_norm[3];

    double N[3];

    double dot_product = 0;

    double brightness = 0;

//Remember that the below double loop does not work for last row (obviously)

//That's why the conditional is nrow-1

    for ( int r = 0; r < nrow-1; r++) 
    {
        for ( int c = 0; c < ncol; c++)
        {
                        
            target_pix = (*pix)[ncol*r+c];

            below_pix = (*pix)[ncol*(r+1)+c];

            adjacent_pix = (*pix)[ncol*r+c+1];

            fourth_pix = (*pix)[ncol*(r+1)+c+1];
#if 0
    A --> (xscal,0,Adjacent-Target)

    B --> (0,yscal,Below-Target)

    A_norm = <A>/||A||

    B_norm = <B>/||B||

#endif
           A[0] = xscal;

           A[1] = 0;

           A[2] = adjacent_pix-target_pix;

           A_mag = sqrt(pow(A[0],2)+pow(A[1],2)+pow(A[2],2));

            B[0] = 0;

            B[1] = yscal;

            B[2] = below_pix-target_pix;

            B_mag = sqrt(pow(B[0],2)+pow(B[1],2)+pow(B[2],2));

            A_norm[0] = A[0]/A_mag;

            A_norm[1] = A[1]/A_mag;

            A_norm[2] = A[2]/A_mag;
//                
            B_norm[0] = B[0]/B_mag;

            B_norm[1] = B[1]/B_mag;

            B_norm[2] = B[2]/B_mag;

#if 0

    N = (
         An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

#endif

           N[0] =  A_norm[1]*B_norm[2] - B_norm[1]*A_norm[2];

           N[1] =  A_norm[2]*B_norm[0] - B_norm[2]*A_norm[0];

           N[2] = A_norm[0]*B_norm[1] - B_norm[0]*A_norm[1];

#if 0

    Now that you have the Normal vector(array), perform the DOT product of 
    the sun vector(array) S and the normal vector (array) N:

    double dot_product = N dot S = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];

    double brightness = 0.9*dot_product+0.1;

    (*pix)[i] = (int or short)(255*brightness);

#endif

    dot_product = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];
    
    brightness = 0.9*dot_product+0.1;

#if 0
    index i == ncol*(r)+c, c == col#, r == row# 
#endif

    (*pix)[ncol*(r)+c] = (int)(255*brightness);
        
        
        }
    }

// The below double for loop processes DEM (*pix)els in the last row 


#if 0
    For last row:

    Target Pixel: ncol*r+c      Adjacent: ncol*(r)+c+1

    Below: ncol*(r-1)+c         4th Pix: ncol*(r-1)+c+1
#endif

    for ( int r = nrow-1; r < nrow; r++) 
    {
        for ( int c = 0; c < ncol-1; c++)
        {

            target_pix = (*pix)[ncol*r+c];

            below_pix = (*pix)[ncol*(r-1)+c];

            adjacent_pix = (*pix)[ncol*r+c+1];

            fourth_pix = (*pix)[ncol*(r-1)+c+1];
#if 0
    A --> (xscal,0,Adjacent-Target)

    B --> (0,yscal,Below-Target)

    A_norm = <A>/||A||

    B_norm = <B>/||B||

#endif
           A[0] = xscal;

           A[1] = 0;

           A[2] = adjacent_pix-target_pix;

            A_mag = sqrt(pow(A[0],2)+pow(A[1],2)+pow(A[2],2));
            
            B[0] = 0;

            B[1] = yscal;

            B[2] = below_pix-target_pix;

            B_mag = sqrt(pow(B[0],2)+pow(B[1],2)+pow(B[2],2));

            A_norm[0] = A[0]/A_mag;

            A_norm[1] = A[1]/A_mag;

            A_norm[2] = A[2]/A_mag;

            B_norm[0] = B[0]/B_mag;

            B_norm[1] = B[1]/B_mag;

            B_norm[2] = B[2]/B_mag;

#if 0

    N = (
         An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

#endif
            
            N[0] = A_norm[1]*B_norm[2] - B_norm[1]*A_norm[2];

            N[1] = A_norm[2]*B_norm[0] - B_norm[2]*A_norm[0];

            N[2] = A_norm[0]*B_norm[1] - B_norm[0]*A_norm[1];
            

#if 0

    Now that you have the Normal vector(array), perform the DOT product of 
    the sun vector(array) S and the normal vector (array) N:

    double dot_product = N dot S = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];

    double brightness = 0.9*dot_product+0.1;

    (*pix)[i] = (int or short)(255*brightness);
#endif


    dot_product = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];
    
    brightness = 0.9*dot_product+0.1;

#if 0
    index i == ncol*(r)+c, c == col#, r == row# 
#endif

    (*pix)[ncol*(r)+c] = (int)(255*brightness);

    }

}

    return &(*pix)[0];

}

short * rescale_for_binary(short**pix,double S[], int SIZE, int ncol, int nrow, double xscal, double yscal) 
{
    
   const short MIN = short_min((*pix),SIZE);

   for ( int i = 0; i < SIZE; i++ )
   {
        (*pix)[i] = (*pix)[i] - MIN;
   }

   ofstream ofs;

   ofs.open("pixel_values_after_min_sub.txt",ios::binary);

   ofs.write(reinterpret_cast<char *>(*pix),SIZE*sizeof(short));

#if 0
   for ( int i = 0; i < SIZE; i++ )
   {
        ofs << (*pix)[i] << endl;
   }
#endif
   
   
   ofs.close();

    short target_pix = 0;

    short below_pix = 0;

    short adjacent_pix = 0;

    short fourth_pix = 0;
   
    double A[3];

    double A_mag = 0;

    double B[3];

    double B_mag = 0;

    double A_norm[3];

    double B_norm[3];

    double N[3];

    double dot_product = 0;

    double brightness = 0;

//Remember that the below double loop does not work for last row (obviously)

//That's why the conditional is nrow-1

    for ( int r = 0; r < nrow-1; r++) 
    {
        for ( int c = 0; c < ncol; c++)
        {
                        
            target_pix = (*pix)[ncol*r+c];

            below_pix = (*pix)[ncol*(r+1)+c];

            adjacent_pix = (*pix)[ncol*r+c+1];

            fourth_pix = (*pix)[ncol*(r+1)+c+1];
#if 0
    A --> (xscal,0,Adjacent-Target)

    B --> (0,yscal,Below-Target)

    A_norm = <A>/||A||

    B_norm = <B>/||B||

#endif
           A[0] = xscal;

           A[1] = 0;

           A[2] = adjacent_pix-target_pix;

           A_mag = sqrt(pow(A[0],2)+pow(A[1],2)+pow(A[2],2));

            B[0] = 0;

            B[1] = yscal;

            B[2] = below_pix-target_pix;

            B_mag = sqrt(pow(B[0],2)+pow(B[1],2)+pow(B[2],2));

            A_norm[0] = A[0]/A_mag;

            A_norm[1] = A[1]/A_mag;

            A_norm[2] = A[2]/A_mag;
//                
            B_norm[0] = B[0]/B_mag;

            B_norm[1] = B[1]/B_mag;

            B_norm[2] = B[2]/B_mag;

#if 0

    N = (
         An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

#endif

           N[0] =  A_norm[1]*B_norm[2] - B_norm[1]*A_norm[2];

           N[1] =  A_norm[2]*B_norm[0] - B_norm[2]*A_norm[0];

           N[2] = A_norm[0]*B_norm[1] - B_norm[0]*A_norm[1];

#if 0

    Now that you have the Normal vector(array), perform the DOT product of 
    the sun vector(array) S and the normal vector (array) N:

    double dot_product = N dot S = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];

    double brightness = 0.9*dot_product+0.1;

    (*pix)[i] = (int or short)(255*brightness);

#endif

    dot_product = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];
    
    brightness = 0.9*dot_product+0.1;

#if 0
    index i == ncol*(r)+c, c == col#, r == row# 
#endif

    (*pix)[ncol*(r)+c] = (short)(255*brightness);
        
        
        }
    }

// The below double for loop processes DEM (*pix)els in the last row 


#if 0
    For last row: 

    Target Pixel: ncol*r+c      Adjacent: ncol*(r)+c+1

    Below: ncol*(r-1)+c         4th Pix: ncol*(r-1)+c+1
#endif

    for ( int r = nrow-1; r < nrow; r++) 
    {
        for ( int c = 0; c < ncol-1; c++)
        {

            target_pix = (*pix)[ncol*r+c];

            below_pix = (*pix)[ncol*(r-1)+c];

            adjacent_pix = (*pix)[ncol*r+c+1];

            fourth_pix = (*pix)[ncol*(r-1)+c+1];
#if 0
    A --> (xscal,0,Adjacent-Target)

    B --> (0,yscal,Below-Target)

    A_norm = <A>/||A||

    B_norm = <B>/||B||

#endif
           A[0] = xscal;

           A[1] = 0;

           A[2] = adjacent_pix-target_pix;

            A_mag = sqrt(pow(A[0],2)+pow(A[1],2)+pow(A[2],2));
            
            B[0] = 0;

            B[1] = yscal;

            B[2] = below_pix-target_pix;

            B_mag = sqrt(pow(B[0],2)+pow(B[1],2)+pow(B[2],2));

            A_norm[0] = A[0]/A_mag;

            A_norm[1] = A[1]/A_mag;

            A_norm[2] = A[2]/A_mag;

            B_norm[0] = B[0]/B_mag;

            B_norm[1] = B[1]/B_mag;

            B_norm[2] = B[2]/B_mag;

#if 0

    N = (
         An[1]*Bn[2] - Bn[1]*An[2],
         An[2]*Bn[0] - Bn[2]*An[0],
         An[0]*Bn[1] - Bn[0]*An[1]
        )

#endif
            
            N[0] = A_norm[1]*B_norm[2] - B_norm[1]*A_norm[2];

            N[1] = A_norm[2]*B_norm[0] - B_norm[2]*A_norm[0];

            N[2] = A_norm[0]*B_norm[1] - B_norm[0]*A_norm[1];
            

#if 0

    Now that you have the Normal vector(array), perform the DOT product of 
    the sun vector(array) S and the normal vector (array) N:

    double dot_product = N dot S = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];

    double brightness = 0.9*dot_product+0.1;

    (*pix)[i] = (int or short)(255*brightness);
#endif


    dot_product = N[0]*S[0] + N[1]*S[1] + N[2]*S[2];
    
    brightness = 0.9*dot_product+0.1;

#if 0
    index i == ncol*(r)+c, c == col#, r == row# 
#endif

    (*pix)[ncol*(r)+c] = (short)(255*brightness);

    }

}

    return &(*pix)[0];

}

#if 0


    index i == ncol*(r)+c, c == col#, r == row# 

    r range: 0-(nrow-1)

    c range: 0-(ncol-1)

    ulr == upper lower row

    ulc == upper lower column

    lrr == lower right row

    lrc == lower right column


#endif


void extract_subregion(int ** dest, int * src, int ulr, int ulc, int lrr, int lrc, int ncol)
{

   int SUB_SIZE = (ncol*lrr+lrc)-(ncol*ulr+ulc)+1;

   *dest = new int[SUB_SIZE];

   for ( int i = ncol*ulr+ulc; i <= ncol*lrr+lrc; i++)
   {
        
        (*dest)[i-(ncol*ulr+ulc)] = src[i];

   }

}


void extract_short_subregion(short ** dest, short * src, int ulr, int ulc, int lrr, int lrc, int ncol)

{

   int SUB_SIZE = (ncol*lrr+lrc)-(ncol*ulr+ulc)+1;

   *dest = new short[SUB_SIZE];

   for ( int i = ncol*ulr+ulc; i <= ncol*lrr+lrc; i++)
   {
        
        (*dest)[i-(ncol*ulr+ulc)] = src[i];

   }

}


int min(int arr[], int SIZE)
{
    int min = arr[0]; 
   
   for (int i = 0; i < SIZE; i++)
   {
        if ( arr[i] < min )
        { min = arr[i]; }

   }

   return min;

}


void eleven_min(int arr[], int nrow, int * r_min, int ncol, int * c_min)
{
    int min = arr[0]; 
   
   for (int r = 0; r < nrow; r++)
   {
       for ( int c = 0; c < ncol ; c++ )
       {
        
        if ( arr[ncol*r+c] < min )
        { min = arr[ncol*r+c]; *r_min = r; *c_min = c;}


        }
   }

    cout << endl;

   cout << "11-by-11 array centered around min" << endl;

   cout << endl;

   for (int r = *r_min - 6; r < *r_min + 5; r++ )
   {
        for (int c = *c_min - 6; c < *c_min + 5; c++ )
        {
           cout << arr[ncol*r+c] << " "; 

        }

        cout << endl;


   }

        cout << endl;


}

short short_min(short arr[], int SIZE)
{
    short min = arr[0]; 
   
   for (int i = 0; i < SIZE; i++)
   {
        if ( arr[i] < min )
        { min = arr[i]; }

   }

   return min;

}


void eleven_short_min(short arr[], int nrow, int * r_min, int ncol, int * c_min)
{
    short min = arr[0]; 
   
   for (int r = 0; r < nrow; r++)
   {
       for ( int c = 0; c < ncol; c++ )
       {
        
        if ( arr[ncol*r+c] < min )
        { min = arr[ncol*r+c]; *r_min = r; *c_min = c;}


        }
   }

    cout << endl;

   cout << "11-by-11 array centered around min" << endl;

   cout << endl;

   for (int r = *r_min - 6; r < *r_min + 5; r++ )
   {
        for (int c = *c_min - 6; c < *c_min + 5; c++ )
        {
           cout << arr[ncol*r+c] << " "; 

        }

        cout << endl;

   }

        cout << endl;

}

int max(int arr[], int SIZE)
{
    int max = arr[0]; 
   
   for (int i = 0; i < SIZE; i++)
   {
        if ( arr[i] > max )
        { max = arr[i]; }

   }

  return max;

}


void eleven_max(int arr[], int nrow, int * r_max, int ncol, int * c_max)
{
    int max = arr[0]; 
   
   for (int r = 0; r < nrow; r++)
   {
       for (int c = 0; c < ncol; c++ )
       {
        
        if ( arr[ncol*r+c] > max )
        { max = arr[ncol*r+c]; *r_max = r; *c_max = c;}
        
        }

   }

   cout << endl;

   cout << "11-by-11 array centered around max" << endl;

   cout << endl;

   for (int r = *r_max - 6; r < *r_max + 5; r++ )
   {
        for (int c = *c_max - 6; c < *c_max + 5; c++ )
        {
           cout << arr[ncol*r+c] << " "; 

        }

        cout << endl;

   }
        cout << endl;

}

short short_max(short arr[], int SIZE)
{
    short max = arr[0]; 
   
   for (int i = 0; i < SIZE; i++)
   {
        if ( arr[i] > max )
        { max = arr[i]; }

   }

  return max;

}


void eleven_short_max(short arr[],int nrow, int * r_max, int ncol, int * c_max)
{
    short max = arr[0]; 
   
   for (int r = 0; r < nrow; r++ )
   {
       for (int c = 0; c < ncol; c++ )
       {
        
        if ( arr[ncol*r+c] > max )
        { max = arr[ncol*r+c]; *r_max = r; *c_max = c;}


        }
   }


   cout << "11-by-11 array centered around max" << endl;

   cout << endl;

   for (int r = *r_max - 6; r < *r_max + 5; r++ )
   {
        for (int c = *c_max - 6; c < *c_max + 5; c++ )
        {
           cout << arr[ncol*r+c] << " "; 

        }

        cout << endl;

   }
        
        cout << endl;

}

void read_EGM(string fname,char header[],int*nc,int*nr,double*min,double*max,double*x_scale, double*y_scale,int**pix)
{
   ifstream ifs;

   ifs.open(fname.c_str(),ifstream::in);

   if (!ifs)
   { cerr << "Error! Can't open file for reading" << endl; exit(1); }

   ifs >> header;

    ifs >> *nc;

    ifs >> *nr;

    ifs >> *min;

    ifs >> *max;

    ifs >> *x_scale;

    ifs >> *y_scale;

    int SIZE = (*nc)*(*nr);

    *pix = new int[SIZE];

    int pixel = 0;

    for ( int i = 0; i < SIZE; i++)
    {
        ifs >> pixel;

        (*pix)[i] = pixel; 
    }
    
    ifs.close();
    
}

void read_binary_EGM(string fname,char egm_type[],int hdr_info[],int*ncol,int*nrow,double*min,double*max,double*x_scal,double*y_scal, short ** pix)
{

   ifstream ifs;

   ifs.open(fname.c_str(),ios::binary);

   if (!ifs)
   { cerr << "Error! Can't open file." << endl; exit(1); }

    ifs.read(egm_type,8);

    ifs.read(reinterpret_cast<char *>(hdr_info),6*sizeof(int));

    *ncol = (int)hdr_info[0];

    *nrow = (int)hdr_info[1];

    *min = (double)hdr_info[2];

    *max = (double)hdr_info[3];
    
    *x_scal = (double)hdr_info[4];

    *y_scal = (double)hdr_info[5];
    
    int SIZE = (*ncol)*(*nrow);

    *pix = new short[SIZE];

    ifs.read(reinterpret_cast<char *>(*pix),SIZE*sizeof(short));

    

    ifs.close();

}

int main(void)
{
    
    int IS_ASCII = 0;

    string fname = "";

    cout << "Enter EGM filename: ";

    cin >> fname;

    char hdr[3];

    char egm_type[8]; 
    
    int hdr_info[6];

    int ncol = 0; 
    
    int nrow = 0; 
    
    double minimum = 0; 
    
    double maximum = 0; 
    
    double x_scal = 0; 
    
    double y_scal = 0; 
    
    int * pix_arr = NULL;

    short * short_pix_arr = NULL;

    int r = 0; //used for designing 11-by-11 array

    int c = 0; //used for designing 11-by-11 array

    ifstream ifs;

    ifs.open(fname.c_str());

    ifs >> hdr;

    if ( strstr(hdr,"E1") == NULL )
    { 
        read_binary_EGM(fname, egm_type, hdr_info, &ncol, &nrow, &minimum, &maximum, &x_scal, &y_scal,&short_pix_arr);

        cout << endl;  
        
        cout << "Max elevation is " << short_max(short_pix_arr,ncol*nrow) << endl;

        cout << "Min elevation is " << short_min(short_pix_arr,ncol*nrow) << endl;


        eleven_short_min(short_pix_arr,nrow,&r,ncol,&c);

        cout << endl;

        eleven_short_max(short_pix_arr,nrow,&r,ncol,&c);
        

    }

    else
    {
        read_EGM(fname,hdr,&ncol,&nrow,&minimum,&maximum,&x_scal,&y_scal,&pix_arr);

        IS_ASCII = 1;

        cout << "Max elevation is " << max(pix_arr,ncol*nrow) << endl;

        cout << "Min elevation is " << min(pix_arr,ncol*nrow) << endl;

        cout << endl;

        eleven_min(pix_arr,nrow,&r,ncol,&c);


        eleven_max(pix_arr,nrow,&r,ncol,&c);

        
    }
    
    cout << "Header type is " << hdr << endl;

    cout << "Number of columns: " << ncol << endl;

    cout << "Number of rows: " << nrow << endl;

    cout << "Minimum pixel value before scaling: " << minimum << endl;

    cout << "Maximum pixel value before scaling: " << maximum << endl;
    
    cout << "x-scaling value: " << x_scal << endl;

    cout << "y-scaling value: " << y_scal << endl;

ofstream ofs;

#if 0
if (IS_ASCII)
{

  cout << endl;

  cout << "A text file displaying all egm values before rescaling can be found in" << endl;

  cout << "ascii_dem_values.txt" << endl;

  cout << endl;
   
   ofs.open("ascii_dem_values.txt"); 
    
    for ( int r = 0; r < nrow ; r++)
    {
       for (int c = 0; c < ncol; c++)
       {
        
        ofs << pix_arr[ncol*r+c] << " ";

       }

       ofs << endl;
    }

    ofs.close();
}

#endif

#if 0
else
{
   
  cout << endl;

  cout << "A text file displaying all egm values before rescaling can be found in" << endl;

  cout << "binary_dem_values.txt" << endl;

  cout << endl;
   
   
   
   ofs.open("binary_dem_values.txt",ios::binary); 


    for ( int i = 0; i < ((ncol)*(nrow)) ; i++)
    {
        ofs << short_pix_arr[i] << endl;
    }
    
    ofs.close();
}

#endif
    
    double azimuth = 0;

    double elevation = 0;

    cout << "Enter azimuth (Please make it between 180 - 360 degrees): " ;

    cin >> azimuth;

    cout << "Enter elevation angle (Please make it between 0 - 90 degrees): ";

    cin >> elevation;

    azimuth = (azimuth*pi/180);

    elevation = (elevation*pi/180);

    double S[3] = {cos(elevation)*cos(azimuth),cos(elevation)*sin(azimuth),sin(elevation)}; // Normalized sun vector

    

    int * sub = NULL;

    short * short_sub = NULL;

    int * grayscale_pix_arr = NULL;

    short * short_grayscale_pix_arr = NULL;


   if (IS_ASCII)
   {
    
    grayscale_pix_arr = new int[ncol*nrow];

    for ( int i = 0; i < (ncol*nrow) ; i++ )
    {
        grayscale_pix_arr[i] = pix_arr[i];

    }
        grayscale(&grayscale_pix_arr,ncol*nrow,maximum,minimum,ncol,nrow,x_scal,y_scal,fname);


        delete[] grayscale_pix_arr;

        dot_product_of_pixel(&pix_arr,S,ncol, 18,nrow,0,x_scal,y_scal);
        
        rescale(&pix_arr,S,ncol*nrow,ncol,nrow,x_scal,y_scal);

        cout << endl;


#if 0
        cout << "A text file with all the pixel values after rescaling is found in" << endl;

        cout << "pix_arr_values.txt" << endl;

        cout << endl;

        ofs.open("pix_arr_values.txt");

        for (int i = 0; i < ncol*nrow; i++)
        {
            ofs << pix_arr[i] << endl;     

        }

        ofs.close();
#endif

   cout << endl;
    
    cout << "A text file displaying contents of an array for the subregion for" << endl;

    cout << "pixels between Row 0, Column 18 and Row 1, Column 19" << endl;

    cout << "is found in Subregion_Pix_Array_File.txt" << endl;

   extract_subregion(&sub,pix_arr,0,18,1,19,ncol);

    ofs.open("Subregion_Pix_Array_File.txt");

   int SUB_SIZE = (ncol*1+19)-(ncol*0+18)+1;
    
    for ( int i = 0; i < SUB_SIZE ; i++)
    {
        ofs << sub[i] << endl;

    }

    ofs.close(); 

    cout << endl;

    cout << "Subregion EGM size is " << SUB_SIZE << endl;

    cout << "Subregion min elevation is " << min(sub,SUB_SIZE) << endl;

    cout << "Subregion max elevation is " << max(sub,SUB_SIZE) << endl;

    cout << "Subregion xscaling is " << x_scal << endl;

    cout << "Subregion yscaling is " << y_scal << endl;


   delete[] sub;


   }


   else //its a binary EGM
   {
    
    short_grayscale_pix_arr = new short[ncol*nrow];

    for ( int i = 0; i < (ncol*nrow) ; i++ )
    {
        short_grayscale_pix_arr[i] = short_pix_arr[i];

    }
        binary_grayscale(&short_grayscale_pix_arr,ncol*nrow,maximum,minimum,ncol,nrow,x_scal,  y_scal,fname);
   

        delete[] short_grayscale_pix_arr;

        short_dot_product_of_pixel(&short_pix_arr,S,ncol, 18,nrow,0,x_scal,y_scal);
        
        rescale_for_binary(&short_pix_arr,S,ncol*nrow,ncol,nrow,x_scal,y_scal);
        
        cout << endl;

#if 0
        cout << "A text file with all the pixel values after rescaling is found in" << endl;

        cout << "pix_arr_values.txt" << endl;

        cout << endl;

        ofs.open("pix_arr_values.txt");

        for (int i = 0; i < ncol*nrow; i++)
        {
            ofs << short_pix_arr[i] << endl;     

        }
        
        ofs.close();
#endif
    
    cout << endl;

    cout << "A text file displaying contents of an array for the subregion for" << endl;

    cout << "pixels between Row 0, Column 18 and Row 1, Column 19" << endl;

    cout << "is found in Subregion_Pix_Array_File.txt" << endl;



   extract_short_subregion(&short_sub,short_pix_arr,0,18,1,19,ncol);

    ofs.open("Subregion_Pix_Array_File.txt",ios::binary);

   int SUB_SIZE = (ncol*1+19)-(ncol*0+18)+1;
    
    for ( int i = 0; i < SUB_SIZE ; i++)
    {
        ofs << short_sub[i] << endl;

    }

    ofs.close(); 

    cout << endl;

    cout << "Subregion EGM size is " << SUB_SIZE << endl;

    cout << "Subregion min elevation is " << short_min(short_sub,SUB_SIZE) << endl;

    cout << "Subregion max elevation is " << short_max(short_sub,SUB_SIZE) << endl;

    cout << "Subregion xscaling is " << x_scal << endl;

    cout << "Subregion yscaling is " << y_scal << endl;


   delete[] short_sub;


   }

   if (IS_ASCII)
   {
        
        convert_to_PGM(pix_arr,ncol,nrow,ncol*nrow,fname);

   }

   else
   {
        
        convert_to_binary_PGM(short_pix_arr,ncol,nrow,ncol*nrow,fname);

   }
    
   
   delete[] pix_arr; 

   delete[] short_pix_arr;
   

return 0;

}
   H‹Mè°  H‰EðHƒ}ð
