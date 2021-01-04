#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QT_Test.h"

#include <QMediaPlayer>
#include<QWidget>




class QMediaPlayer;  //播放视频
class QVideoWidget;   //播放视频框
class QStandardItemModel;  //复制模型
class QMediaPlaylist;
class QT_Test : public QMainWindow
{
	Q_OBJECT

public:
	QT_Test(QWidget *parent = Q_NULLPTR);

private:
	Ui::QT_TestClass ui;


//自定义函数
public:
	QString ChangeTime(qint64 position); //时间转换
	void QT_Test::QSliderStyle();
//槽函数
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
	//进度条
	void positionChange(qint64 position);//改变播放位置
	void durationChanged(qint64 duration);//进度条范围
	void on_horizontalSlider_sliderMoved(int position);//滑块移动的槽函数
	void on_pushButton_speed_clicked();

	///////////////////////////////////////////////////////////////////

	bool eventFilter(QObject* target, QEvent* e);

	void timerEvent(QTimerEvent* ev);
	
public:
	 QMediaPlayer *player;  //播放视频
	 QVideoWidget *videoWidget;   //播放视频框
	 QStringList strListName;
	 QStringList strListUrl;
	 QStandardItemModel* modle;
	 QMediaPlaylist* playlist;
	// QDialog* Skill01_dlg;
	
	/* QVBoxLayout* layout_video;*/
};


