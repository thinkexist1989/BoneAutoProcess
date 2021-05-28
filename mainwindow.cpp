#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QFileInfo>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_viewExecBtn_clicked()
{
    execName = QFileDialog::getOpenFileName(
                this,
                tr("Open Cut Plan Program"),
                rootDirName,
                tr("program(*.exe)"));
    if(execName.isEmpty()) {
        QMessageBox::warning(this, "Warning!", "No such program!");
        return;
    }

    ui->ExecEdit->setText(execName);
}

void MainWindow::on_viewPointBtn_clicked()
{
    pointName = QFileDialog::getOpenFileName(
                this,
                tr("Open Bone Con"),
                rootDirName,
                tr("text(*.csv)"));

    ui->point50Data->setText(pointName);
}

void MainWindow::on_openDirButton_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(rootDirName));
}

void MainWindow::on_replaceBtn_clicked()
{
//    rootDirName.replace('/', '\\');
    QString fileName = QString::fromLocal8Bit("/ÇÐ¹ÇÂÖÀª-50¸öµã.csv");
    qDebug() << rootDirName + fileName;

    if(!QFile::remove(rootDirName + fileName)) {
        QMessageBox::warning(this, "Warning", "Remove Failed");
    }

    if(!QFile::copy(pointName, rootDirName+fileName)) {
        QMessageBox::warning(this, "Warning", "Copy Failed");
    }

    QDesktopServices::openUrl(QUrl::fromLocalFile(rootDirName+fileName));
}

void MainWindow::on_openRootDirBtn_clicked()
{
    rootDirName = QFileDialog::getExistingDirectory(
                this,
                tr("Select Root Dir"),
                "C:");

    ui->rootDirEdit->setText(rootDirName);
    execName = rootDirName + "/BoneCuttingPathGeneratorV1.7.exe";
    ui->ExecEdit->setText(execName);
}

void MainWindow::on_openPointButton_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(pointName));
}

void MainWindow::on_viewCorBtn_clicked()
{
    allCorFileName = QFileDialog::getOpenFileName(
                this,
                tr("Select All Coordinate File"),
                rootDirName + "/CorSystem");

    QDesktopServices::openUrl(QUrl::fromLocalFile(allCorFileName));
}

void MainWindow::on_chooseCorBtn_clicked()
{
    QString boneCorFileName = QString::fromLocal8Bit("/CorSystem/ÇÐ¹Ç×ø±êÏµ.txt");
    QString name = rootDirName + boneCorFileName;
    QDesktopServices::openUrl(QUrl::fromLocalFile(name));
}

void MainWindow::on_openkeyPointBtn_clicked()
{
    keyPointFileName = QString::fromLocal8Bit("/CorSystem/keyPointNumber.csv");
    QString name = rootDirName + keyPointFileName;
    QDesktopServices::openUrl(QUrl::fromLocalFile(name));
}

void MainWindow::on_openActorInitBtn_clicked()
{
    actorInitName = QString::fromLocal8Bit("/figurePath/actorInit.txt");
    QString name = rootDirName + actorInitName;
    QDesktopServices::openUrl(QUrl::fromLocalFile(name));
}

void MainWindow::on_openOffsetBtn_clicked()
{
    offsetposeName = QString::fromLocal8Bit("/figurePath/Offsetpose1.txt");
    QString name = rootDirName + offsetposeName;
    QDesktopServices::openUrl(QUrl::fromLocalFile(name));
}

void MainWindow::on_ExecBtn_clicked()
{
    QFileInfo fInfo(execName);

    QStringList list;

//    QProcess::startDetached(execName,list,fInfo.absolutePath());
    QProcess* p = new QProcess;
    connect(p, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, [=](){qDebug() << "Program Finished";});
    p->setProgram(execName);
    p->setWorkingDirectory(fInfo.absolutePath());
//    qDebug() << fInfo.absoluteDir();
    p->start(execName,list);
}
