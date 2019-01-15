#include <QString>
#include <QDebug.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <QTextCodec>
using namespace std;


#include "GGlobalFunctions.h"
#include "NCharString.h"
#include "NChainLink.hpp"
#include "NCharStringLink.hpp"
#include "NNews.h"
#include "NDictionary.hpp"
#include "NFindFiles.h"
#include "NReversedWordList.hpp"


#include "ui_mainwindow.h"
#include "ui_loadingwindow.h"
#include "ui_articledisplay.h"
#include "ui_articleselection.h"

#include "maincontrol.h"

MainControl::MainControl()
{
    m_MainWindow = new MainWindow();
    m_LoadingWindow = new LoadingWindow();
    m_ArticleSelection = new ArticleSelection();
    m_ArticleDisplay = new ArticleDisplay();
    m_ConnectSignalSlots();
    m_Initialize();
    m_MainWindow->show();
}

void MainControl::m_ConnectSignalSlots()
{
    connect(this, SIGNAL(m_ChangeProgress(int)), m_LoadingWindow, SLOT(m_ChangeValue(int)));
    connect(this, SIGNAL(m_Loaded()), m_MainWindow, SLOT(show()));
    connect(this, SIGNAL(m_Loaded()), m_LoadingWindow, SLOT(close()));
    connect(m_MainWindow->ui->ExitButton, SIGNAL(clicked()), m_MainWindow, SLOT(close()));
    connect(m_MainWindow->ui->SearchButton, SIGNAL(clicked()),this,SLOT(m_ManageSearch()));
    connect(m_MainWindow->ui->SearchButton, SIGNAL(clicked()),m_MainWindow, SLOT(close()));
    connect(m_MainWindow->ui->SearchButton, SIGNAL(clicked()),m_ArticleSelection, SLOT(show()));
    
    connect(this, SIGNAL(m_ChangeRecommendation(int,int,int,int,int)),
            m_ArticleSelection, SLOT(m_ManageRecommendDisplay(int, int, int, int, int)));
    connect(this, SIGNAL(m_ChangeRecommendation(int,int,int,int,int)),
            m_ArticleDisplay, SLOT(m_ManageRecommendDisplay(int, int, int, int, int)));

    connect(m_ArticleSelection, SIGNAL(m_OpenNewArticle(int)),this, SLOT(m_ManageDisplay(int)));
    connect(m_ArticleDisplay, SIGNAL(m_OpenNewArticle(int)),this, SLOT(m_ManageDisplay(int)));

    connect(this, SIGNAL(m_Display(int)), m_ArticleDisplay, SLOT(show()));
    connect(this,SIGNAL(m_Display(int)), m_ArticleDisplay,SLOT(m_ManageArticleDisplay(int)));
    connect(this, SIGNAL(m_Display(int)),m_ArticleSelection, SLOT(close()));

    connect(m_ArticleSelection->ui->QuitButton, SIGNAL(clicked()),m_ArticleSelection,SLOT(close()));
    connect(m_ArticleSelection->ui->QuitButton, SIGNAL(clicked()),m_ArticleDisplay,SLOT(close()));
    connect(m_ArticleSelection->ui->QuitButton, SIGNAL(clicked()),m_MainWindow,SLOT(show()));
    connect(m_ArticleDisplay->ui->QuitButton, SIGNAL(clicked()),m_ArticleSelection,SLOT(close()));
    connect(m_ArticleDisplay->ui->QuitButton, SIGNAL(clicked()),m_ArticleDisplay,SLOT(close()));
    connect(m_ArticleDisplay->ui->QuitButton, SIGNAL(clicked()),m_MainWindow,SLOT(show()));

    connect(m_ArticleDisplay->ui->Button_1, SIGNAL(clicked()),m_ArticleDisplay,SLOT(m_ManageButtonClick1()));
    connect(m_ArticleDisplay->ui->Button_2, SIGNAL(clicked()),m_ArticleDisplay,SLOT(m_ManageButtonClick2()));
    connect(m_ArticleDisplay->ui->Button_3, SIGNAL(clicked()),m_ArticleDisplay,SLOT(m_ManageButtonClick3()));
    connect(m_ArticleDisplay->ui->Button_4, SIGNAL(clicked()),m_ArticleDisplay,SLOT(m_ManageButtonClick4()));
    connect(m_ArticleDisplay->ui->Button_5, SIGNAL(clicked()),m_ArticleDisplay,SLOT(m_ManageButtonClick5()));
    connect(m_ArticleSelection->ui->Button_1, SIGNAL(clicked()),m_ArticleSelection,SLOT(m_ManageButtonClick1()));
    connect(m_ArticleSelection->ui->Button_2, SIGNAL(clicked()),m_ArticleSelection,SLOT(m_ManageButtonClick2()));
    connect(m_ArticleSelection->ui->Button_3, SIGNAL(clicked()),m_ArticleSelection,SLOT(m_ManageButtonClick3()));
    connect(m_ArticleSelection->ui->Button_4, SIGNAL(clicked()),m_ArticleSelection,SLOT(m_ManageButtonClick4()));
    connect(m_ArticleSelection->ui->Button_5, SIGNAL(clicked()),m_ArticleSelection,SLOT(m_ManageButtonClick5()));
}

void MainControl::m_Initialize()
{
    char dictionary_name[100] = "WordList/WordList.txt";
    m_TheDictionary = new NDictionary(dictionary_name);
    m_TheList = new NReversedWordList(m_TheDictionary);
    /*
    //find all files;
    NCharStringLink* all_files_input = g_FindAllFilesInput();
    if (all_files_input == NULL)
    {
        cout << "No Valid Files!";
        return ;
    }


    //handle all news

    NChainNode<NCharString>* present = all_files_input->m_Head;
    while (present != NULL)
    {
        if (present != all_files_input->m_Head)
        {
            NNews* the_news = new NNews(present->m_Data);
            the_news->m_Dictionary = m_TheDictionary;
            if (the_news->m_Content != NULL)
            {
                the_news->m_DivideWord();
                the_news->m_OutPut();
                delete(the_news);
            }
        }
        present = present->m_Next;
    }
    */
    //find all out and info files
    NCharStringLink* all_files_output = g_FindAllFilesOutput();
    if (all_files_output == NULL)
    {
        cout << "No Valid Files!";
        return ;
    }
    NCharStringLink* all_files_word = g_FindAllFilesWord();
    if (all_files_word == NULL)
    {
        cout << "No Valid Files!";
        return ;
    }
    qDebug()<<"Begin to launch files";
    NChainNode<NCharString>* present_out = all_files_output->m_Head;
    NChainNode<NCharString>* present_word = all_files_word->m_Head;
    int progress = 0;
    while (present_out != NULL)
    {
        if (present_out != all_files_output->m_Head)
        {
             m_TheList->m_AddOneFile(present_out->m_Data, present_word->m_Data);
             progress ++;
             qDebug()<<"Launched "<<progress<<" files";
        }
        present_out = present_out->m_Next;
        present_word = present_word->m_Next;

    }
    //m_TheList->m_HandleWordSearch(m_TheDictionary);

    ifstream file_recommend("auxiliary.txt");
    for(int i = 0; i <= m_cFileNum; i ++)
    {
        file_recommend>>m_RecommendList[i][1]>>m_RecommendList[i][2]>>m_RecommendList[i][3]>>m_RecommendList[i][4]>>m_RecommendList[i][5];
    }





}




void MainControl::m_ManageSearch()
{
    QString str_utf = m_MainWindow->ui->textEdit->toPlainText();
    QByteArray useful = str_utf.toLocal8Bit().data();
    char str[1000] = {0};
    for(int i = 0; i < useful.length(); i ++)
    {
        str[i] = useful[i];
    }    
    NCharString* new_string = new NCharString(str, strlen(str));
    int num[6] = {0,-1,-1,-1,-1,-1};
        NFileLink* file_list = m_TheList->m_HandleWordSearchQT(m_TheDictionary,new_string);
        if(file_list != NULL)
        {
            NChainNode<NFileNode>* current = file_list->m_FileList.m_Head->m_Next;
            for(int i = 1; i <= 5; i ++)
            {
                if(current == NULL)
                {
                    break;
                }
                num[i]=current->m_Data->m_Code;
                current = current->m_Next;
            }
            delete(file_list);
        }
        delete(new_string);
    emit m_ChangeRecommendation(num[1], num[2], num[3], num[4], num[5]);

}


void MainControl::m_ManageDisplay(int num)
{
    emit m_Display(num);
    emit m_ChangeRecommendation(m_RecommendList[num][1], m_RecommendList[num][2], m_RecommendList[num][3], m_RecommendList[num][4], m_RecommendList[num][5]);
}
