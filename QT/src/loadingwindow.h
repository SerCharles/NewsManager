#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H

#include <QMainWindow>

class MainControl;

namespace Ui {
class LoadingWindow;
}

class LoadingWindow : public QMainWindow
{
    friend class MainControl;
    Q_OBJECT

public:
    explicit LoadingWindow(QWidget *parent = 0);
    ~LoadingWindow();

private slots:
    void m_ChangeValue(int value);
private:
    Ui::LoadingWindow *ui;
};

#endif // LOADINGWINDOW_H
