#ifndef MYBROWSER_H
#define MYBROWSER_H

#include <QApplication>
#include <QScreen>
#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QDir>
#include <QLabel>

class MyBrowser : public QDialog
{
    Q_OBJECT
public:    
    explicit MyBrowser(QWidget *parent = 0);
    ~MyBrowser();

    static QString getPath();

private:
    static QString GlobalString;
    QDir myDir;
    QListWidget *listDir;
    QPushButton *backButton;
    QLabel *MyLabel;
    QPushButton *okButton;

    void loadItem(QString path);

private slots:
    void chooseItem(QListWidgetItem*);
    void upLevel();
    void acceptButton();
};

#endif // MYBROWSER_H
