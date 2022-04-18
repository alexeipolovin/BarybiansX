#include <QFileDialog>
#include "EditorWindow.h"

EditorWindow::EditorWindow(QWidget *parent) : QMainWindow(parent) {
    toolbar = nullptr;
    this->setStyleSheet("QMainWindow"
                        "{"
                        "background-color:#1e2327;"
                        "}");
    auto sendButton = new QPushButton("Send post");
    centerWidget = new QWidget();
    mainLayout = new QVBoxLayout(this);
    textEdit = new QTextEdit();
    titleEdit = new QLineEdit();
    titleEdit->setPlaceholderText("Title");
    titleEdit->setStyleSheet("QLineEdit "
                             "{"
//                             "border: 1px solid #282830;"
//                             "color: white;"
                             "font-size: 15px;"
                             "height:17px;"
                             "width:400px;"
                             "margin-left:20px;"
                             "margin-right:20px;"
                             "border-radius:10px;"
                             "padding:5px;"
                             "background-color:#1e2327;"
                             "}");

    textEdit->setStyleSheet("QTextEdit "
                            "{"
//                            "border: 1px solid #282830;"
//                            "color: white;"
                            "font-size: 15px;"
                            "height:17px;"
                            "width:400px;"
                            "margin-left:20px;"
                            "margin-right:20px;"
                            "border-radius:10px;"
                            "padding:5px;"
                            "background-color:#1e2327;"
                            "}");
    textEdit->setPlaceholderText("Text");

    addToolBar(createToolbar());
    mainLayout->addWidget(titleEdit);
    mainLayout->addWidget(textEdit);
    sendButton->setStyleSheet("QPushButton{"
                              "background-color: #1e2327;"
                              "border-style: solid;"
                              "border-color: #1e2327;"
                              "font-size:14px;"
                              "border-width: 5px;"
                              "border-radius: 10px;"
                              "}");
    connect(sendButton, &QPushButton::clicked, this, [this]() {
        this->postTitle = this->titleEdit->text();
        qDebug() << "title:" << postTitle;
        this->postText = this->textEdit->toPlainText();
        qDebug() << "text:" << postText;
        emit postWritten();
    });
    mainLayout->addWidget(sendButton);
    centerWidget->setLayout(mainLayout);
    this->setCentralWidget(centerWidget);
}

QToolBar* EditorWindow::createToolbar() {
    this->toolbar = new QToolBar();
    this->toolbar->setMovable(false);

    toolbar->setStyleSheet("QToolBar"
                           "{"
                           "background:white;"
                           "}");
    //Весь блок содержащий в себе QAction, т.е с 38 по 48 строчку отвечает за создние *действия* для тулбара, в качестве аргумента передаётся строка в которой указано имя действие(название которое должно показаться) и указатель на текущи объект(снова this)
    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":drawable/resources/edit-file-64.png"));
    const QIcon imgIcon = QIcon::fromTheme("document-open", QIcon(":drawable/resources/edit-image-64.png"));
    const QIcon boldIcon = QIcon::fromTheme("document-open", QIcon(":drawable/resources/text-edit-64.png"));
//    const QIcon editIcon = QIcon::fromTheme("document-open", QIcon(":drawable/resources/edit-image-64.png"));
    const QIcon curIcon = QIcon::fromTheme("document-open", QIcon(":drawable/resources/line-64.png"));
    const QIcon underlineIcon = QIcon::fromTheme("document-open", QIcon(":drawable/resources/text-64.png"));
    const QIcon normalIcon = QIcon::fromTheme("document-open", QIcon(":drawable/resources/backspace-64.png"));
    const QIcon saveIcon = QIcon::fromTheme("document-open", QIcon(":drawable/resources/check-file-64.png"));
    QAction *quitAction = new QAction(openIcon,"Open File",this);
    QAction *addImage = new QAction(imgIcon, "Add Image", this);
//    QAction *makeHeader = new QAction(headIcon, "Create Header", this);
    QAction *normalizeText = new QAction(normalIcon, "Normalize", this);
//    QAction *liveEditMode = new QAction(editIcon, "Live Edit", this);
    QAction *cursiveText = new QAction(curIcon, "Cursive", this);
    QAction *boldText = new QAction(boldIcon, "Bold", this);
    QAction *makeHR = new QAction(underlineIcon, "HR", this);
//    QAction *increaseFont = new QAction("+", this);
    QAction *saveFile = new QAction(saveIcon,"Save", this);


    connect(quitAction, &QAction::triggered, this, &EditorWindow::openFile);



    toolbar->addAction(quitAction);
    toolbar->addAction(addImage);
//    toolbar->addAction(makeHeader);
    toolbar->addAction(normalizeText);
//    toolbar->addAction(liveEditMode);
    toolbar->addAction(cursiveText);
    toolbar->addAction(boldText);
    toolbar->addAction(makeHR);
//    toolbar->addAction(increaseFont);
    toolbar->addAction(saveFile);

    return this->toolbar;
}


void EditorWindow::openFile() {
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,"", "", "*.txt") ;
    this->oFileName = fileName;
    this->readTextFromFile(fileName);
}

void EditorWindow::readTextFromFile(QString qString) {
    QFile file(qString);

    if(file.open(QFile::ReadOnly)) {
        this->textEdit->setText(file.readAll());
    }
}

