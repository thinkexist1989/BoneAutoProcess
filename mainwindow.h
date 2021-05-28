#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_viewExecBtn_clicked();

    void on_viewPointBtn_clicked();

    void on_openDirButton_clicked();

    void on_openOffsetBtn_clicked();

    void on_replaceBtn_clicked();

    void on_openRootDirBtn_clicked();

    void on_openPointButton_clicked();

    void on_viewCorBtn_clicked();

    void on_chooseCorBtn_clicked();

    void on_openkeyPointBtn_clicked();

    void on_openActorInitBtn_clicked();

    void on_ExecBtn_clicked();

private:
    Ui::MainWindow *ui;

    QString rootDirName; // for_redistribution_files_only文件夹路径
    QString execName; //切骨规划程序名称 BoneCuttingPathGeneratorV1.7.exe

    QString pointName;

    QString actorInitName = "actorInit.txt";
    QString offsetposeName = "Offsetpose1.txt";

    QString allCorFileName;  // 包含全部坐标系文件名称
    QString boneCorFileName; // 切骨坐标系文件名称
    QString keyPointFileName; // keyPointNumber.csv文件位置
};
#endif // MAINWINDOW_H
