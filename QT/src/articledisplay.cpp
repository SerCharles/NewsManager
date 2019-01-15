/*
 filename: ArticleDisplay.cpp
 function: manage article display
 version: 2.0
 date:12/17/2018
*/

#include <QDebug>
#include <QFile>
#include "articledisplay.h"
#include "ui_articledisplay.h"
#include "GGlobalFunctions.h"
#include <fstream>
#include <QString>
#include <QTextCodec>
using namespace std;


ArticleDisplay::ArticleDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ArticleDisplay)
{
    ui->setupUi(this);
}

ArticleDisplay::~ArticleDisplay()
{
    delete ui;
}

void ArticleDisplay::m_ManageArticleDisplay(int num)
{
    char filename[20] = {0};
    NCharString* filename_1 = g_GetFileName(num);
    for(int j = 0; j < filename_1->m_Length; j ++)
    {
        filename[j] = filename_1->m_String[j];
    }
    ifstream file(filename);
    if(file.is_open())
    {
        //qDebug()<<"open";
    }
    ui->ArticleShow->clear();

    while(file)
    {
        char c[30000] = {0};
        file.getline(c,30000);
        QTextCodec* codec = QTextCodec::codecForName("GBK");
        QString show_string = codec->toUnicode(c);
        ui->ArticleShow->append(show_string);
    }
    delete(filename_1);



}



void ArticleDisplay::m_ManageRecommendDisplay(int num_1, int num_2, int num_3, int num_4, int num_5)
{
    m_Recommend[1] = num_1;
    m_Recommend[2] = num_2;
    m_Recommend[3] = num_3;
    m_Recommend[4] = num_4;
    m_Recommend[5] = num_5;
    int num_all[6] = {0, num_1, num_2, num_3, num_4, num_5};
    for(int i = 1; i <= 5; i ++)
    {
        if(num_all[i] != -1)
        {
            char cc[100]="与您搜索的关键词最相关的几篇文章如下";
            QTextCodec* codec_0 = QTextCodec::codecForName("GBK");
            QString text = codec_0->toUnicode(cc);
            ui->label->setText(text);

            if(i == 1)
            {
                ui->Button_1->show();
                ui->Title_1->show();
                ui->Title_1->clear();
            }
            else if(i == 2)
            {
                ui->Button_2->show();
                ui->Title_2->show();
                ui->Title_2->clear();
            }
            else if(i == 3)
            {
                ui->Button_3->show();
                ui->Title_3->show();
                ui->Title_3->clear();
            }
            else if(i == 4)
            {
                ui->Button_4->show();
                ui->Title_4->show();
                ui->Title_4->clear();
            }
            else if(i == 5)
            {
                ui->Button_5->show();
                ui->Title_5->show();
                ui->Title_5->clear();
            }


            char filename[20] = {0};
            NCharString* filename_1 = g_GetFileName(num_all[i]);
            for(int j = 0; j < filename_1->m_Length; j ++)
            {
                filename[j] = filename_1->m_String[j];
            }
            ifstream file(filename);
            if(file.is_open())
            {
                //qDebug()<<"open";
            }
            char c[1000] = {0};
            file.getline(c,1000);
            QTextCodec* codec = QTextCodec::codecForName("GBK");
            QString show_string = codec->toUnicode(c);
            delete(filename_1);

            if(i == 1)
            {
                ui->Title_1->append(show_string);
            }
            else if(i == 2)
            {
                ui->Title_2->append(show_string);
            }
            else if(i == 3)
            {
                ui->Title_3->append(show_string);
            }
            else if(i == 4)
            {
                ui->Title_4->append(show_string);
            }
            else if(i == 5)
            {
                ui->Title_5->append(show_string);
            }

        }
        else
        {
            if(i == 1)
            {
                ui->Button_1->hide();
                ui->Title_1->hide();

                char cc[100]="对不起，没有找到对应网页";
                QTextCodec* codec = QTextCodec::codecForName("GBK");
                QString text = codec->toUnicode(cc);
                ui->label->setText(text);
            }
            else if(i == 2)
            {
                ui->Button_2->hide();
                ui->Title_2->hide();
            }
            else if(i == 3)
            {
                ui->Button_3->hide();
                ui->Title_3->hide();
            }
            else if(i == 4)
            {
                ui->Button_4->hide();
                ui->Title_4->hide();
            }
            else if(i == 5)
            {
                ui->Button_5->hide();
                ui->Title_5->hide();
            }
        }
    }

}

void ArticleDisplay::m_ManageButtonClick1()
{
    emit m_OpenNewArticle(m_Recommend[1]);
}
void ArticleDisplay::m_ManageButtonClick2()
{
    emit m_OpenNewArticle(m_Recommend[2]);
}
void ArticleDisplay::m_ManageButtonClick3()
{
    emit m_OpenNewArticle(m_Recommend[3]);
}
void ArticleDisplay::m_ManageButtonClick4()
{
    emit m_OpenNewArticle(m_Recommend[4]);
}
void ArticleDisplay::m_ManageButtonClick5()
{
    emit m_OpenNewArticle(m_Recommend[5]);
}
