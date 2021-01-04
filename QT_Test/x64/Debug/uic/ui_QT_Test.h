/********************************************************************************
** Form generated from reading UI file 'QT_Test.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_TEST_H
#define UI_QT_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT_TestClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *OpenFileButton;
    QPushButton *OpenDocButton;
    QListView *FilelistView;
    QGroupBox *groupBox_2;
    QPushButton *PauseButton;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_3;
    QPushButton *SetBtn;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_speed;
    QPushButton *setVoice;
    QWidget *widgetv;
    QSlider *verticalSlider;
    QWidget *widgetset;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSlider *horizontalSlider_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSlider *horizontalSlider_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSlider *horizontalSlider_5;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QT_TestClass)
    {
        if (QT_TestClass->objectName().isEmpty())
            QT_TestClass->setObjectName(QStringLiteral("QT_TestClass"));
        QT_TestClass->resize(1593, 876);
        QT_TestClass->setAutoFillBackground(false);
        QT_TestClass->setStyleSheet(QLatin1String("#QT_TestClass{\n"
"border-image: url(:/QT_Test/Image/VCG41678168875.jpg);\n"
"\n"
"	\n"
"	\n"
"	background-color: rgb(0, 0, 0);\n"
"	\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
""));
        centralWidget = new QWidget(QT_TestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1150, 0, 381, 771));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 361, 731));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        OpenFileButton = new QPushButton(layoutWidget);
        OpenFileButton->setObjectName(QStringLiteral("OpenFileButton"));
        OpenFileButton->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/QT_Test/Image/white_folder_interface_symbol_of_outline_16px_1245386_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        OpenFileButton->setIcon(icon);
        OpenFileButton->setFlat(true);

        horizontalLayout_5->addWidget(OpenFileButton);

        OpenDocButton = new QPushButton(layoutWidget);
        OpenDocButton->setObjectName(QStringLiteral("OpenDocButton"));
        OpenDocButton->setStyleSheet(QStringLiteral(""));
        OpenDocButton->setIcon(icon);
        OpenDocButton->setFlat(true);

        horizontalLayout_5->addWidget(OpenDocButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        FilelistView = new QListView(layoutWidget);
        FilelistView->setObjectName(QStringLiteral("FilelistView"));
        FilelistView->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(FilelistView);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 700, 1131, 71));
        PauseButton = new QPushButton(groupBox_2);
        PauseButton->setObjectName(QStringLiteral("PauseButton"));
        PauseButton->setGeometry(QRect(0, 20, 41, 34));
        PauseButton->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QT_Test/Image/player_pause_16px_1222644_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PauseButton->setIcon(icon1);
        PauseButton->setFlat(true);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 30, 81, 18));
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 30, 16, 18));
        label_8->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 30, 91, 18));
        label_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        SetBtn = new QPushButton(groupBox_2);
        SetBtn->setObjectName(QStringLiteral("SetBtn"));
        SetBtn->setGeometry(QRect(1030, 20, 41, 34));
        SetBtn->setStyleSheet(QStringLiteral("background-image: url(:/QT_Test/Resources/Lily_Screenshot_1589883684.png);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/QT_Test/Image/settings_16px_1223098_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SetBtn->setIcon(icon2);
        SetBtn->setFlat(true);
        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 0, 1091, 22));
        horizontalSlider->setStyleSheet(QLatin1String("ui.songtime->setStyleSheet(\"  \\\n"
"     QSlider::add-page:Horizontal\\\n"
"     {     \\\n"
"        background-color: rgb(87, 97, 106);\\\n"
"        height:4px;\\\n"
"     }\\\n"
"     QSlider::sub-page:Horizontal \\\n"
"    {\\\n"
"        background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));\\\n"
"        height:4px;\\\n"
"     }\\\n"
"    QSlider::groove:Horizontal \\\n"
"    {\\\n"
"        background:transparent;\\\n"
"        height:6px;\\\n"
"    }\\\n"
"    QSlider::handle:Horizontal \\\n"
"    {\\\n"
"        height: 30px;\\\n"
"        width:8px;\\\n"
"        border-image: url(:/images/ic_music_thumb.png);\\\n"
"        margin: -8 0px; \\\n"
"    }\\\n"
"    \");"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 20, 41, 34));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/QT_Test/Image/player_play_pause_16px_1222646_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1080, 20, 41, 34));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/QT_Test/Image/player-icons_16px_1137009_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 20, 41, 34));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/QT_Test/Image/player-icons_24px_1137006_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon5);
        pushButton_3->setFlat(true);
        pushButton_speed = new QPushButton(groupBox_2);
        pushButton_speed->setObjectName(QStringLiteral("pushButton_speed"));
        pushButton_speed->setGeometry(QRect(910, 20, 51, 34));
        pushButton_speed->setFlat(true);
        setVoice = new QPushButton(groupBox_2);
        setVoice->setObjectName(QStringLiteral("setVoice"));
        setVoice->setGeometry(QRect(980, 20, 31, 34));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/QT_Test/Image/2_media_volume_24px_10385_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        setVoice->setIcon(icon6);
        setVoice->setFlat(true);
        widgetv = new QWidget(centralWidget);
        widgetv->setObjectName(QStringLiteral("widgetv"));
        widgetv->setGeometry(QRect(800, 520, 41, 171));
        widgetv->setStyleSheet(QStringLiteral(""));
        verticalSlider = new QSlider(widgetv);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(10, 0, 22, 160));
        verticalSlider->setValue(50);
        verticalSlider->setOrientation(Qt::Vertical);
        widgetset = new QWidget(centralWidget);
        widgetset->setObjectName(QStringLiteral("widgetset"));
        widgetset->setGeometry(QRect(850, 490, 271, 201));
        widgetset->setStyleSheet(QStringLiteral(""));
        layoutWidget1 = new QWidget(widgetset);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 241, 181));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        horizontalSlider_2 = new QSlider(layoutWidget1);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setStyleSheet(QLatin1String("#QT_Test{\n"
"border-image: url(:/new/prefix1/Image/1.jpg);\n"
"}"));
        horizontalSlider_2->setMinimum(-100);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalSlider_3 = new QSlider(layoutWidget1);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMinimum(-100);
        horizontalSlider_3->setMaximum(100);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        horizontalSlider_4 = new QSlider(layoutWidget1);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setMinimum(-100);
        horizontalSlider_4->setMaximum(100);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        horizontalSlider_5 = new QSlider(layoutWidget1);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setMinimum(-100);
        horizontalSlider_5->setMaximum(100);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_5);


        verticalLayout->addLayout(horizontalLayout_4);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, -20, 1131, 721));
        verticalLayoutWidget = new QWidget(groupBox_3);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 1131, 691));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        QT_TestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QT_TestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1593, 30));
        QT_TestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QT_TestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QT_TestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QT_TestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QT_TestClass->setStatusBar(statusBar);

        retranslateUi(QT_TestClass);
        QObject::connect(verticalSlider, SIGNAL(sliderMoved(int)), QT_TestClass, SLOT(volume_valueChanged(int)));
        QObject::connect(FilelistView, SIGNAL(doubleClicked(QModelIndex)), QT_TestClass, SLOT(SelectFile(QModelIndex)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), QT_TestClass, SLOT(showAll()));

        QMetaObject::connectSlotsByName(QT_TestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QT_TestClass)
    {
        QT_TestClass->setWindowTitle(QApplication::translate("QT_TestClass", "QT_Test", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QT_TestClass", "\346\226\207\344\273\266\345\210\227\350\241\250", Q_NULLPTR));
        OpenFileButton->setText(QString());
        OpenDocButton->setText(QString());
        groupBox_2->setTitle(QString());
        PauseButton->setText(QString());
        label->setText(QApplication::translate("QT_TestClass", "00:00:00", Q_NULLPTR));
        label_8->setText(QApplication::translate("QT_TestClass", "/", Q_NULLPTR));
        label_3->setText(QApplication::translate("QT_TestClass", "00:00:00", Q_NULLPTR));
        SetBtn->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_speed->setText(QApplication::translate("QT_TestClass", "x1", Q_NULLPTR));
        setVoice->setText(QString());
        label_4->setText(QApplication::translate("QT_TestClass", "\344\272\256\345\272\246", Q_NULLPTR));
        label_5->setText(QApplication::translate("QT_TestClass", "\350\211\262\347\233\270", Q_NULLPTR));
        label_6->setText(QApplication::translate("QT_TestClass", "\345\257\271\346\257\224\345\272\246", Q_NULLPTR));
        label_7->setText(QApplication::translate("QT_TestClass", "\351\245\261\345\222\214\345\272\246", Q_NULLPTR));
        groupBox_3->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class QT_TestClass: public Ui_QT_TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_TEST_H
