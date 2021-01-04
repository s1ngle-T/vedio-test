#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QT_Test.h"

#include <QMediaPlayer>
#include<QWidget>




class QMediaPlayer;  //������Ƶ
class QVideoWidget;   //������Ƶ��
class QStandardItemModel;  //����ģ��
class QMediaPlaylist;
class QT_Test : public QMainWindow
{
	Q_OBJECT

public:
	QT_Test(QWidget *parent = Q_NULLPTR);

private:
	Ui::QT_TestClass ui;


//�Զ��庯��
public:
	QString ChangeTime(qint64 position); //ʱ��ת��
	void QT_Test::QSliderStyle();
//�ۺ���
private slots:
	void OnPausevedio();
	void OpenFileBtn();
	void OpenDocBtn();
	void SelectFile(QModelIndex index);
	void Set();
	void on_pushButton_next_clicked();
	void volume_valueChanged(int value);
	void showAll();
	void Setv();
	bool setModle();
	void keyPressEvent(QKeyEvent* event);

	///////////////////////////////////////////////////////////////////////
	//������
	void positionChange(qint64 position);//�ı䲥��λ��
	void durationChanged(qint64 duration);//��������Χ
	void on_horizontalSlider_sliderMoved(int position);//�����ƶ��Ĳۺ���
	void on_pushButton_speed_clicked();

	///////////////////////////////////////////////////////////////////

	bool eventFilter(QObject* target, QEvent* e);

	void timerEvent(QTimerEvent* ev);
	
public:
	 QMediaPlayer *player;  //������Ƶ
	 QVideoWidget *videoWidget;   //������Ƶ��
	 QStringList strListName;
	 QStringList strListUrl;
	 QStandardItemModel* modle;
	 QMediaPlaylist* playlist;
	// QDialog* Skill01_dlg;
	
	/* QVBoxLayout* layout_video;*/
};


