/*
 filename: mainwindow.h
 function: the main window of the program
 version: 2.0
 date:12/16/2018
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainControl;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    friend class MainControl;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
