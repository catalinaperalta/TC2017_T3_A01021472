//
//  main.cpp
//  TC2017_T3_A01021472
//
//  Created by iCaty on 10/5/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define N 4

std::vector<int> camionero(int tank, std::vector<int> ruta);
void divisionParrafos(std::string parrafo);
void subseqMax(std::vector<int> X, std::vector<int> Y);
void parejasEstables(int M[N][N], int H[N][N]);

int main(int argc, const char * argv[])
{
//-------------------------------------CAMIONERO CON PRISA---------------------------------------------
    std::vector<int> ruta;
    
    int gasolineras[6] = {100, 250, 120, 200, 300, 95};
    
    for (int i = 0; i<6; i++)
    {
        ruta.push_back(gasolineras[i]);
    }
    
    
    std::vector<int> paradas = camionero(400, ruta);
    for (auto i : paradas)
        std::cout<<"Se hará una parada en la "<<i<<" gasolinera."<<std::endl;

//-------------------------------------DIVISION DE PARRAFOS------------------------------------------------------
    
    divisionParrafos("the quick brown fox has over the lazy og");
    
//-------------------------------------SUBSEQUENCIA COMUN MAXIMA---------------------------------------------
    std::vector<int> S;
    std::vector<int> P;
    int t[10] = {2,4,5,3,6,7,0,2,1,3};
    int t1[8] = {4,5,6,7,0,2,1,1};
    
    for (int i = 0; i<10; i++)
    {
        S.push_back(t[i]);
    }
    
    for (int i = 0; i<8; i++)
    {
        P.push_back(t1[i]);
    }
    
    subseqMax(S, P);
    
//-------------------------------------PAREJAS ESTABLES---------------------------------------------
    int M[N][N];
    int H[N][N];
//    srand((int) time(NULL));
    
    int HzeroPref[N] = {2,1,0,3};
    int HonePref[N] = {1,3,0,2};
    int HtwoPref[N] = {2,0,3,1};
    int HthreePref[N] = {0, 1, 2, 3};
    
    int MzeroPref[N] = {0,2,1,3};
    int MonePref[N] = {2,3,1,0};
    int MtwoPref[N] = {1,2,3,0};
    int MthreePref[N] = {3,1,0,2};
//    int MzeroPref[N] = {1,3,2,0};
//    int MonePref[N] = {2,0,3,1};
//    int MtwoPref[N] = {1,2,3,0};
//    int MthreePref[N] = {0,1,3,2};
//    
//    int HzeroPref[N] = {0,1,2,3};
//    int HonePref[N] = {2,1,0,3};
//    int HtwoPref[N] = {0,2,1,3};
//    int HthreePref[N] = {1,3,0,2};
    
    for (int i = 0; i<N; i++)
    {
        M[0][i] = MzeroPref[i];
        M[1][i] = MonePref[i];
        M[2][i] = MtwoPref[i];
        M[3][i] = MthreePref[i];
        
        H[0][i] = HzeroPref[i];
        H[1][i] = HonePref[i];
        H[2][i] = HtwoPref[i];
        H[3][i] = HthreePref[i];
    }
    
    parejasEstables(M, H);
    
    return 0;
}

std::vector<int> camionero(int tank, std::vector<int> ruta)
{
    std::vector<int> paradas;
    int distPorRecorrer = 0;
    
    for(int i = 0; i<ruta.size(); i++)
    {
        distPorRecorrer = distPorRecorrer + ruta[i];
        if (distPorRecorrer > tank)
        {
            distPorRecorrer = 0;
            paradas.push_back(i);
        }
    }
    
    return paradas;
}

void divisionParrafos(std::string parrafo)
{
    int L = 20;
    int b = 1;
    int rb;
    int total = 0;
    std::vector<int> badnessPerLine;
    int totalBadness = 0;
    
    std::vector<std::string> words;
    std::vector<std::vector<std::string>> lineas;
    
//-----------------------------------------OBTENER STRING DE PALABRAS---------------------------------------
    std::string word;
    std::stringstream par(parrafo);
    
    while (std::getline(par, word, ' '))
    {
        words.push_back(word);
    }

//------------------------------------AGRUPAR PALABRAS EN LINEAS---------------------------------------------
    std::vector<std::string> temp;
    
    for (int i = 0; i<words.size(); i++)
    {
        if (total > L)
        {
            for (auto i : temp)
                std::cout<<i<<" ";
            std::cout<<std::endl;
        }
        else
        {
            total += words[i].length();
        }
    }
    
    
//-------------------------PREVIOUS WAY------------------------------PREVIOUS WAY--------------------
//    
//    for (int i = 0; i<words.size(); i++)
//    {
//        if (total > L-temp.size() || (i == words.size()-1 && L-temp.size() > words[i].length()))
//        {
//            lineas.push_back(temp);
//            if (i == words.size()-1)
//            {
//                badnessPerLine.push_back(0);
//            }
//            badnessPerLine.push_back((L-total)/(i-(i-temp.size())));
//            temp.clear();
//            total = 0;
//            if (i == words.size()-1)
//            {
//                temp.push_back(words[i]);
//                lineas.push_back(temp);
//            }
//            else
//            {
//                i = i-1;
//            }
//            
//            
//        }
//        else if (total <= L)
//        {
//            total += words[i].length();
//            temp.push_back(words[i]);
//        }
//    }
//    
////----------------------------FIXFIXFIXFIXFIXFIXFIX--------------------------------------------------
//    for (auto i : badnessPerLine)
//    {
//        std::cout<<"BPL:"<<i<<std::endl;
//        totalBadness = totalBadness + i;
//    }
//    std::cout<<totalBadness<<std::endl;
//    for(auto i : lineas)
//    {
//        for (auto j : i)
//        {
//            std::cout<<j;
//        }
//        std::cout<<std::endl;
//    }
    
}

void subseqMax(std::vector<int> X, std::vector<int> Y)
{
//------------------------------------SUBSEQUENCIA MÁXIMA COMÚN CONTIGUA------------------------------------
    std::vector<int> longestSoFar;
    std::vector<int> subsequence;
    int k = 0;
    int m = 0;
    for (int i = 0; i<X.size(); i++)
    {
        k=i;
        
        for (int j = 0; j<Y.size(); j++)
        {
            m = j;
            
            while(X[k] == Y[m])
            {
                subsequence.push_back(X[k]);
                k++;
                m++;
            }
            
            if (longestSoFar.size() < subsequence.size())
            {
                longestSoFar = subsequence;
            }
        }
        
        subsequence.clear();
    }
    
    for (auto i : longestSoFar)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
//------------------------------SUBSEQUENCIA MÁXIMA COMÚN NO CONTIGUA------------------------------------
    int count[X.size()][Y.size()];
    
    for (int i = X.size()-1; i>=0; i--)
    {
        for (int j = X.size()-1; j>=0; j--)
        {
            if (i == X.size()-1 || j == Y.size()-1)
            {
                count[i][j] = 0;
            }
            
            
        }
    }
    
}

void parejasEstables(int M[N][N], int H[N][N])
{
    bool stable = false;
    int Mmatched[N];
    bool Hmatched[N];
    std::fill_n(Mmatched, N, -1);
    std::fill_n(Hmatched, N, false);
    
    int i = 0;
    int j = 0;
    
    while (!stable)
    {
            if (Hmatched[i] == false)
            {
                int w = H[i][j];
            
                if (Mmatched[w] == -1)
                {
                    Mmatched[w] = i;
                    Hmatched[i] = true;
                    i++;
                    j = 0;
                }
                else
                {
                    int h1 = Mmatched[w];
                    //Check if m prefers h (i) over h1
                    for (int k = 0; k<N; k++)
                    {
                        if (M[w][k] == i)
                        {
                            Mmatched[w] = i;
                            Hmatched[i] = true;
                            Hmatched[h1] = false;
                            i++;
                            j = 0;
                            break;
                        }
                        
                        if (M[w][k] == h1)
                        {
                            j++;
                            break;
                        }
                    }
                }
            }
            else
                break;
        
        for (int j = 0; j<N; j++)
        {
            if (Hmatched[j] == true)
                stable = true;
            else
            {
                stable = false;
                i = j;
                break;
            }
        }
    }
    
    std::cout<<"M H"<<std::endl;
    for (int i = 0; i<N; i++)
    {
        std::cout<<i<<" "<<Mmatched[i]<<std::endl;
    }
}


