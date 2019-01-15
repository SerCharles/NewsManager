/*
 filename: ArticleSelection.h
 function: manage article selection
 version: 2.0
 date:12/17/2018
*/

#ifndef ARTICLESELECTION_H
#define ARTICLESELECTION_H

#include <QMainWindow>

class MainControl;
namespace Ui {
class ArticleSelection;
}

class ArticleSelection : public QMainWindow
{
    Q_OBJECT
friend class MainControl;
public:
    explicit ArticleSelection(QWidget *parent = 0);
    ~ArticleSelection();
    int m_Recommend[6]{0,-1,-1,-1,-1,-1};

private:
    Ui::ArticleSelection *ui;
public slots:
    //used to show recommend article titles
    //variables: the id of the articles
    void m_ManageRecommendDisplay(int num_1, int num_2, int num_3, int num_4, int num_5);

    //used to open a new article
    void m_ManageButtonClick1();
    void m_ManageButtonClick2();
    void m_ManageButtonClick3();
    void m_ManageButtonClick4();
    void m_ManageButtonClick5();
signals:
    void m_OpenNewArticle(int code);
};

#endif // ARTICLESELECTION_H
