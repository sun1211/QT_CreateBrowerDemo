#include "mybrowser.h"

QString MyBrowser::GlobalString = "";

MyBrowser::MyBrowser(QWidget *parent): QDialog(parent)
{
    QPalette paletteForLabel;
    paletteForLabel.setColor(QPalette::Background,QColor(30,144,255));
    this->setPalette(paletteForLabel);

    backButton = new QPushButton("<",this);
    okButton = new QPushButton("OK",this);
    MyLabel = new QLabel(this);
    listDir = new QListWidget(this);

    QHBoxLayout *headerLayout = new QHBoxLayout();
    headerLayout->addWidget(backButton);
    headerLayout->addWidget(MyLabel);

    QHBoxLayout *bodyLayout = new QHBoxLayout();
    bodyLayout->addWidget(listDir);

    QHBoxLayout *bottonLayout = new QHBoxLayout();
    bottonLayout->addStretch(1);
    bottonLayout->addWidget(okButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(headerLayout,1);
    mainLayout->addLayout(bodyLayout,8);
    mainLayout->addLayout(bottonLayout,1);


    QScreen *screen = QApplication::screens().at(0);
    int width, height;
    width = screen->size().width();
    height = screen->size().height();
    setFixedSize(screen->size().width(), screen->availableSize().height());

    okButton->setDisabled(true);

    QStringList filters;
    filters << "*.xml";
    myDir.setNameFilters(filters);

    loadItem("/sdcard/");
    connect(listDir, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(chooseItem(QListWidgetItem*)));
    connect(backButton,SIGNAL(clicked()),this,SLOT(upLevel()));
    connect(okButton,SIGNAL(clicked()),this,SLOT(acceptButton()));
}

MyBrowser::~MyBrowser()
{
    delete backButton;
    delete  okButton;
    delete MyLabel;
    delete listDir;
}

QString MyBrowser::getPath()
{
    MyBrowser *tmpBrowser = new MyBrowser();
    tmpBrowser->exec();
    return GlobalString;
}

void MyBrowser::loadItem(QString path)
{
    listDir->clear();
    myDir.cd(path);
    QStringList allFiles = myDir.entryList(QDir::NoDotAndDotDot | QDir::System  | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
    MyLabel->setText(myDir.path());

    for(int i = 0 ; i < allFiles.size(); i++){
        listDir->addItem(allFiles[i]);
        listDir->setStyleSheet("font: 45px");
    }
}

void MyBrowser::chooseItem(QListWidgetItem *item)
{
    if(!(item->text().contains(".xml", Qt::CaseInsensitive))){
        loadItem(myDir.path() +"/"+ item->text());
        okButton->setDisabled(true);
    }else{
        GlobalString = myDir.path() +"/"+ item->text();        
        okButton->setDisabled(false);
    }

}

void MyBrowser::upLevel()
{
    myDir.cdUp();
    loadItem(myDir.path());
}

void MyBrowser::acceptButton()
{
    this->close();
}



