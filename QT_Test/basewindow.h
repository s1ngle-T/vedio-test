#pragma once

#include <QWidget>
#include "mytitlebar.h"
#include <QtWidgets/QMainWindow>
#include "ui_QT_Test.h"

class BaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    BaseWindow(QWidget* parent = 0);
    ~BaseWindow();

private:
    void initTitleBar();
    void paintEvent(QPaintEvent* event);
    void loadStyleSheet(const QString& sheetName);

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

protected:
    MyTitleBar* m_titleBar;

};