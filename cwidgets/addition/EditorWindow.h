//
// Created by Алексей Половин on 08.04.2022.
//

#ifndef BARYBIANSX_EDITORWINDOW_H
#define BARYBIANSX_EDITORWINDOW_H

#include <QFileSystemModel>
#include <QLabel>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QToolBar>
#include <QTreeView>
#include <QVBoxLayout>
#include <QVector>
#include <QWindow>
#include <QLineEdit>
#include "base/basefragment.h"

class EditorWindow : public QMainWindow{
Q_OBJECT
public:
    explicit EditorWindow(QWidget *parent = nullptr);

    QString postTitle;
    QString postText;

private:
    QLineEdit *titleEdit;
    QWidget *centerWidget;
    QToolBar *toolbar{};
    QVBoxLayout *mainLayout;
    QTextEdit *textEdit;

    QString oFileName;

    QToolBar *createToolbar();
    void openFile();

    void readTextFromFile(QString qString);

signals:

    void postWritten();
};


#endif //BARYBIANSX_EDITORWINDOW_H
