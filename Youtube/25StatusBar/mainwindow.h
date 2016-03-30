#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionDo_Sth_triggered();

private:
    Ui::MainWindow *ui;
    QLabel *stateLabel;
    QProgressBar *stateBar;
};

#endif // MAINWINDOW_H
