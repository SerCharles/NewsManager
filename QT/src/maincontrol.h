/*
 filename: maincontrol.h
 function: the main control of the entire program
 version: 2.0
 date:12/16/2018
*/

#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>



#include "GGlobalFunctions.h"
#include "NCharString.h"
#include "NChainLink.hpp"
#include "NCharStringLink.hpp"
#include "NReversedWordList.hpp"
#include "NNews.h"
#include "NDictionary.hpp"
#include "NFindFiles.h"
#include "mainwindow.h"
#include "loadingwindow.h"
#include "articleselection.h"
#include "articledisplay.h"

class MainControl:public QObject
{
    Q_OBJECT

public:
    MainWindow* m_MainWindow;
    LoadingWindow* m_LoadingWindow;
    ArticleSelection* m_ArticleSelection;
    ArticleDisplay* m_ArticleDisplay;
    //todo: other windows

    const double m_cMinimumRelevance{0};  //used in recommending
    const double m_cMinimumSame{0.99};    //used in judging whether the two titles are the same
    const int m_cFileNum{780};              //the number of files
    const int m_cMatrixSize{800};

    int m_RecommendList[800][6]{0};
    NDictionary* m_TheDictionary{NULL};
    NReversedWordList* m_TheList{NULL};



public:
    MainControl();

    //used in connecting signals and slots
    void m_ConnectSignalSlots();

    //used in initializing the files
    void m_Initialize();

signals:

    //change the progress bar of the loading window
    void m_ChangeProgress(int new_int);

    //close the loading process, and open the main menu
    void m_Loaded();


    //show a list of news
    void m_Display(int num);
    
    //show recommendation
    void m_ChangeRecommendation(int num_1, int num_2, int num_3, int num_4, int num_5);
public slots:
    
    //search for articles by input words
    void m_ManageSearch();
    
    //display an article
    void m_ManageDisplay(int num);
};

#endif // MAINCONTROL_H
