#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <string>

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
    void on_FindPushButton_clicked();

    void on_matchCheckBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    std::string find_from_file_;
    std::string find_what_;
    std::string status_;
};

#endif // MAINWINDOW_HH
