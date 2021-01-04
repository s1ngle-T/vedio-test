#include "QT_Test.h"
#include "ui_QT_Test.h"
#include <QtWidgets/QWidget>
#include <QMediaPlaylist>
#include<QMediaPlayer>
#include<QVideoWidget>

#include<QStandardItemModel>
#include<QFileDialog>
#include<QFileDialog>
#include<QFileInfo>
#include <QTime>
#include <QKeyEvent>

int page = 0;
static int p = 1;
static int flag = 1;
static int i;
static QModelIndex qindex;
static int Type = 0; //默认顺序
QT_Test::QT_Test(QWidget *parent)
	: QMainWindow(parent)
{
	this->grabKeyboard();
	ui.setupUi(this);
	
	QSliderStyle();
	/*setWindowOpacity(0.8);*/
	ui.FilelistView->setStyleSheet("background-color:transparent");

	///////////////////////////////////////////////////////
	
	
	ui.SetBtn->installEventFilter(this);

	ui.setVoice->installEventFilter(this);
	ui.widgetset->hide();
	ui.widgetv->hide();


////////////////////////////////////////////////////////

	ui.widgetset->setVisible(true);
	ui.widgetset->setWindowFlags(Qt::Dialog | Qt::Tool | Qt::FramelessWindowHint);
	ui.widgetset->setWindowOpacity(0.8);

	ui.widgetv->setVisible(true);
	ui.widgetv->setWindowFlags(Qt::Dialog | Qt::Tool | Qt::FramelessWindowHint);
	ui.widgetv->setWindowOpacity(0.8);
	

	 strListName.clear();
	strListUrl.clear();
	modle = new QStandardItemModel(this);
	ui.FilelistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//对象
	

	player = new QMediaPlayer(this);
	videoWidget = new QVideoWidget(this);
	ui.verticalLayout_3->setMargin(10);

	ui.verticalLayout_3->addWidget(videoWidget);

	player->setVideoOutput(videoWidget);
	
	
	
	//连接
	//亮度
	ui.horizontalSlider_4->setValue(videoWidget->brightness());
	connect(ui.horizontalSlider_4,&QSlider::sliderMoved,videoWidget,&QVideoWidget::setBrightness);
	connect(videoWidget, &QVideoWidget::brightnessChanged, ui.horizontalSlider_4, &QSlider::value);



	//色相
	ui.horizontalSlider_5->setValue(videoWidget->hue());
	connect(ui.horizontalSlider_5, &QSlider::sliderMoved, videoWidget, &QVideoWidget::setHue);
	connect(videoWidget, &QVideoWidget::hueChanged, ui.horizontalSlider_5, &QSlider::value);

	//对比度
	ui.horizontalSlider_3->setValue(videoWidget->contrast());
	connect(ui.horizontalSlider_3, &QSlider::sliderMoved, videoWidget, &QVideoWidget::setContrast);
	connect(videoWidget, &QVideoWidget::contrastChanged, ui.horizontalSlider_3, &QSlider::value);

	//饱和度
	ui.horizontalSlider_2->setValue(videoWidget->saturation());
	connect(ui.horizontalSlider_2, &QSlider::sliderMoved, videoWidget, &QVideoWidget::setSaturation);
	connect(videoWidget, &QVideoWidget::saturationChanged, ui.horizontalSlider_2, &QSlider::value);


	//点击
	connect(ui.PauseButton, SIGNAL(clicked(bool)), this, SLOT(OnPausevedio()));
	connect(ui.OpenFileButton, SIGNAL(clicked(bool)), this, SLOT(OpenFileBtn()));
	connect(ui.OpenDocButton, SIGNAL(clicked(bool)), this, SLOT(OpenDocBtn()));
	connect(ui.FilelistView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SelectFile(const QModelIndex&)));
	connect(ui.SetBtn, SIGNAL(clicked(bool)), this, SLOT(Set()));
	connect(ui.setVoice, SIGNAL(clicked(bool)), this, SLOT(Setv()));
	connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(showAll()));
	connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(setModle()));
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_next_clicked()));
	connect(ui.pushButton_speed, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_speed_clicked()));
	

	////////////////////////////////////////////////
	ui.horizontalSlider->setMaximum(player->duration());
	connect(player, &QMediaPlayer::positionChanged, this, &QT_Test::positionChange);
    connect(player, &QMediaPlayer::durationChanged, this, &QT_Test::durationChanged);
	playlist = new QMediaPlaylist;
	
}



///////////////////////////////////////////////////////////////////////////////////////////

void QT_Test::OnPausevedio()
{
	if (p == 1)
	{
		player->play();
		ui.PauseButton->setIcon(QIcon(":/QT_Test/Image/player-icons_16px_1137033_easyicon.net.ico"));
		p = 0;
	}

	else
	{
		player->pause();
		ui.PauseButton->setIcon(QIcon(":/QT_Test/Image/player_pause_16px_1222644_easyicon.net.ico"));
		p = 1;
	}

}


void QT_Test::OpenFileBtn()
{
	QString filename = QFileDialog::getOpenFileName(this, "open vedio", QDir::currentPath(), "video file(*.*);;ALL files(*.*)");
	player->setMedia(QUrl::fromLocalFile(filename));
	player->play();
}

void QT_Test::OpenDocBtn()
{

	strListName.clear();
	strListUrl.clear();
	modle->clear();
	player->stop();
	QString dirname = QFileDialog::getExistingDirectory(this, tr("open Directory"), ".");
	QDir dir(dirname);
	dir.setNameFilters(QStringList("*.mp4"));//可以写多个
	strListName=dir.entryList();//获取文件名列表
	QString PathName = dir.absolutePath(); //路径
	int count = strListName.count();
	for (int i = 0; i < count; i++)
	{
		QStandardItem* item = new QStandardItem(strListName.at(i));
		
		
		modle->appendRow(item);
		strListUrl.append(PathName+"/"+ strListName.at(i));
		playlist->addMedia(QUrl::fromLocalFile(PathName + "/" + strListName.at(i)));
	}
	ui.FilelistView->setModel(modle);
	//player->setPlaylist(playlist);
}

void QT_Test::SelectFile(QModelIndex index)
{
	
	player->setMedia(QUrl::fromLocalFile(strListUrl.at(index.row())));
	i = index.row();

	QModelIndexList modelIndexList = ui.FilelistView->selectionModel()->selectedIndexes();
	player->play();
	ui.PauseButton->setIcon(QIcon(":/QT_Test/Image/player-icons_16px_1137033_easyicon.net.ico"));
	p = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////

//自定义函数
QString QT_Test::ChangeTime(qint64 position)
{
	int min = position / 60;
	int second = position % 60;
	int hour = 0;
	if (min >= 60)
	{
		hour = min / 60;
		min = min % 60;
	}
	QString strhour = (hour > 9) ? QString::number(hour) : tr("0") + QString::number(hour);
	QString strmin = (min > 9) ? QString::number(min) : tr("0") + QString::number(min);
	QString strsec = (second > 9) ? QString::number(second) : tr("0") + QString::number(second);
	return strhour + ":" + strmin + ":" + strsec;
}

void QT_Test::Set()
{
	
	if ((page % 2 == 0))
	{

		QRect screenRect = videoWidget->geometry();	//获得父类窗口得大小
		int	screenx = screenRect.width();	//父窗口得宽
		int screeny = screenRect.height();	//父窗口得高


		ui.widgetset->move(screenx - 150, screeny - 150);
		ui.widgetset->setVisible(true);

		//ui.widgetv->setVisible(true);
		page = 1;
	}
	else
	{
		ui.widgetset->setVisible(false);
		page = 0;
	}

}

void QT_Test::Setv()
{
	if ((page % 2 == 0))
	{

		QRect screenRect = videoWidget->geometry();	//获得父类窗口得大小
		int	screenx = screenRect.width();	//父窗口得宽
		int screeny = screenRect.height();	//父窗口得高
		ui.widgetv->move(screenx + 60, screeny - 70);
		ui.widgetv->setVisible(true);
		page = 1;
	}
	else
	{
		ui.widgetv->setVisible(false);
		page = 0;
	}

}


bool QT_Test::setModle()
{
	if (Type == 1)
	{
		
		ui.pushButton_3->setIcon(QIcon(":/QT_Test/Image/player-icons_24px_1137006_easyicon.net.ico"));
		Type =0;
	
	}

	else
	{
	//循环
		ui.pushButton_3->setIcon(QIcon(":/QT_Test/Image/player-icons_24px_1137017_easyicon.net.ico"));
		Type = 1;
	}

	//////////////////////////////////////////////////////////////////////////////

	





	return Type;
}


void QT_Test::showAll()
{

	if (flag == 0)
	{
		ui.pushButton_2->setIcon(QIcon(":/QT_Test/Image/player-icons_16px_1137009_easyicon.net.ico"));
		videoWidget->setWindowFlags(Qt::Window);
		videoWidget->showFullScreen();
		flag = 1;
	}

	else
	{
		ui.pushButton_2->setIcon(QIcon(":/QT_Test/Image/player-icons_16px_1137008_easyicon.net.ico"));
		flag = 0;
	}


}


void QT_Test::volume_valueChanged(int value)
{
	//音量调节

	player->setVolume(ui.verticalSlider->value());
}


void QT_Test::QSliderStyle()
{
	ui.horizontalSlider->setStyleSheet("  \
     QSlider::add-page:Horizontal\
     {     \
        background-color: rgb(87, 97, 106);\
        height:4px;\
     }\
     QSlider::sub-page:Horizontal \
    {\
        background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));\
        height:4px;\
     }\
    QSlider::groove:Horizontal \
    {\
        background:transparent;\
        height:6px;\
    }\
    QSlider::handle:Horizontal \
    {\
        height: 30px;\
        width:8px;\
        border-image: url(:/images/ic_music_thumb.png);\
        margin: -8 0px; \
    }\
    ");

	/////////////////////////////////////////////////////////////////////////////////////////
	ui.horizontalSlider_2->setStyleSheet("  \
     QSlider::add-page:Horizontal\
     {     \
        background-color: rgb(87, 97, 106);\
        height:4px;\
     }\
     QSlider::sub-page:Horizontal \
    {\
        background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));\
        height:4px;\
     }\
    QSlider::groove:Horizontal \
    {\
        background:transparent;\
        height:6px;\
    }\
    QSlider::handle:Horizontal \
    {\
        height: 30px;\
        width:8px;\
        border-image: url(:/images/ic_music_thumb.png);\
        margin: -8 0px; \
    }\
    ");

////////////////////////////////////////////////////////////////////////////////////////////////////////

	ui.horizontalSlider_3->setStyleSheet("  \
     QSlider::add-page:Horizontal\
     {     \
        background-color: rgb(87, 97, 106);\
        height:4px;\
     }\
     QSlider::sub-page:Horizontal \
    {\
        background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));\
        height:4px;\
     }\
    QSlider::groove:Horizontal \
    {\
        background:transparent;\
        height:6px;\
    }\
    QSlider::handle:Horizontal \
    {\
        height: 30px;\
        width:8px;\
        border-image: url(:/images/ic_music_thumb.png);\
        margin: -8 0px; \
    }\
    ");
/////////////////////////////////////////////////////////////////////////////////
	ui.horizontalSlider_4->setStyleSheet("  \
     QSlider::add-page:Horizontal\
     {     \
        background-color: rgb(87, 97, 106);\
        height:4px;\
     }\
     QSlider::sub-page:Horizontal \
    {\
        background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));\
        height:4px;\
     }\
    QSlider::groove:Horizontal \
    {\
        background:transparent;\
        height:6px;\
    }\
    QSlider::handle:Horizontal \
    {\
        height: 30px;\
        width:8px;\
        border-image: url(:/images/ic_music_thumb.png);\
        margin: -8 0px; \
    }\
    ");
//////////////////////////////////////////////////////////////////////////
	ui.horizontalSlider_5->setStyleSheet("  \
     QSlider::add-page:Horizontal\
     {     \
        background-color: rgb(87, 97, 106);\
        height:4px;\
     }\
     QSlider::sub-page:Horizontal \
    {\
        background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));\
        height:4px;\
     }\
    QSlider::groove:Horizontal \
    {\
        background:transparent;\
        height:6px;\
    }\
    QSlider::handle:Horizontal \
    {\
        height: 30px;\
        width:8px;\
        border-image: url(:/images/ic_music_thumb.png);\
        margin: -8 0px; \
    }\
    ");



	///////////////////////////////////////////////
	ui.verticalSlider->setStyleSheet(
		" \
   QSlider::add-page:vertical     {    \
         background-color: rgb(37, 168, 198);   \
     width:4px;    \
 }     QSlider::sub-page:vertical     {   \
     background-color: rgb(87, 97, 106);  \
      width:4px;     }   \
 QSlider::groove:vertical     {    \
    background:transparent;     \
   width:6px;    }   \
 QSlider::handle:vertical     {       \
  height: 13px;      \
  width:13px;     \
   border-image: url(:/images/ic_volume_thumb.png);  \
       margin: -0 -4px;      }    \
");
}


static int state = 0;
void QT_Test::keyPressEvent(QKeyEvent* event)
{

	QRect rect0 = videoWidget->geometry();//记录widget位置，恢复时使用
	videoWidget->installEventFilter(this);
	//捕捉事件
	if (event->key() == Qt::Key_Escape) {
		videoWidget->setWindowFlags(Qt::SubWindow);
		videoWidget->showNormal();
	}

	if (event->key() == Qt::Key_Space) {
		if (state == 0)
		{
			player->pause();
			state = 1;
			return;
		}
		if (state == 1)
		{
			player->play();
			state = 0;
			return;
		}
	}



}


void QT_Test::on_pushButton_next_clicked()
{
	if (i == (ui.FilelistView->model()->rowCount() - 1))
		i = -1;

	if (ui.FilelistView->model()->rowCount()>0&&i< ui.FilelistView->model()->rowCount())    //播放列表不为空
	{
	
		player->setMedia(QUrl::fromLocalFile(strListUrl.at(i+1)));
		i++;
		/*QModelIndex*/ qindex = modle->index(i, 0);
		ui.FilelistView->setCurrentIndex(qindex);
		/*QModelIndexList modelIndexList = ui.FilelistView->selectionModel()->selectedIndexes();*/
		player->play();
		if (i == (ui.FilelistView->model()->rowCount() - 1))
			i = -1;
	}


}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void QT_Test::positionChange(qint64 position)
{
	ui.horizontalSlider->setValue(position);
	ui.label_3->setText(ChangeTime(player->duration() / 1000));
	ui.label->setText(ChangeTime(position / 1000));

	if ((player->duration() == position ) && (ui.label_3->text() != "00:00:00"))
	{
		i = ui.FilelistView->currentIndex().row();
		if (Type == 0)
		{
			if (i == (ui.FilelistView->model()->rowCount() - 1))
				i = -1;

			if (ui.FilelistView->model()->rowCount() > 0 && i < ui.FilelistView->model()->rowCount())    //播放列表不为空
			{
				//strListUrl.at(i);
				i++;
				player->setMedia(QUrl::fromLocalFile(strListUrl.at(i)));
				
				qindex = modle->index(i, 0);
				ui.FilelistView->setCurrentIndex(qindex);
				QModelIndexList modelIndexList = ui.FilelistView->selectionModel()->selectedIndexes();

			/*	if (i == (ui.FilelistView->model()->rowCount() - 1))
					i = -1;*/
			}

		
		
		}
		player->play();
	}
}


void QT_Test::durationChanged(qint64 duration)
{
	ui.horizontalSlider->setRange(0, duration);//获取进度条范围
}

void QT_Test::on_horizontalSlider_sliderMoved(int position)
{
	player->setPosition(position);
	ui.label_3->setText(ChangeTime(player->duration() / 1000));
	ui.label->setText(ChangeTime(position / 1000));
}


void QT_Test::on_pushButton_speed_clicked()
{
	static int speed = 1;
	switch (speed)
	{
	case 1:
		player->setPlaybackRate(1.25);
		ui.pushButton_speed->setText("X1.25");
		speed++;
		break;

	case 2:
		player->setPlaybackRate(1.5);

		ui.pushButton_speed->setText("X1.5");
		speed++;
		break;

	case 3:
		player->setPlaybackRate(2);
		ui.pushButton_speed->setText("X2");
		speed++;
		break;
	case 4:
		player->setPlaybackRate(0.5);
		ui.pushButton_speed->setText("X0.5");
		speed++;
		break;
	case 5:
		player->setPlaybackRate(1);
		ui.pushButton_speed->setText("X1");
		speed = 1;
		break;

	}



}

/////////////////////////////////////////////////////////////////////
bool QT_Test::eventFilter(QObject* target, QEvent* e)
{
	QPoint coursePoint;
	QPoint BtnPoint;
	coursePoint = QCursor::pos();//获取当前光标的位置
	BtnPoint = coursePoint;
	
	int x = BtnPoint.x();
	int y = BtnPoint.x();
	if (target == ui.SetBtn)
	{
		ui.widgetset->move(geometry().x() + 870, geometry().y() + 530);//坐标
		if (e->type() == QEvent::Enter)
		{
			ui.widgetset->show();
			ui.widgetv->hide();
			this->startTimer(100);

		}
		
	}

	else if (target == ui.setVoice)
	{
		ui.widgetv->move(geometry().x() + 990, geometry().y() + 560);//坐标
		if (e->type() == QEvent::Enter)
		{
			ui.widgetv->show();
			ui.widgetset->hide();
			this->startTimer(100);
		}

	}
	
	return QMainWindow::eventFilter(target, e);

}


void QT_Test::timerEvent(QTimerEvent* ev)
{
	if ((ui.widgetset != nullptr) && (ui.widgetset->isVisible()))
	{

		QPoint oPoint = QCursor::pos();
		QPoint oWidgetPoint = ui.widgetset->mapFromGlobal(oPoint);
		QPoint oSelfPoint = ui.SetBtn->mapFromGlobal(oPoint);
		QRect oWidgetRect = ui.widgetset->rect();
		QRect oSelfRect = ui.SetBtn->rect();
		if ((!oSelfRect.contains(oSelfPoint)) && (!oWidgetRect.contains(oWidgetPoint)))
		{
			ui.widgetset->hide();
			killTimer(ev->timerId());
		}

	}
		else if ((ui.setVoice != nullptr) && (ui.setVoice->isVisible()))
		{

			QPoint oPoint = QCursor::pos();
			QPoint oWidgetPoint = ui.widgetv->mapFromGlobal(oPoint);
			QPoint oSelfPoint = ui.setVoice->mapFromGlobal(oPoint);
			QRect oWidgetRect = ui.widgetv->rect();
			QRect oSelfRect = ui.setVoice->rect();
			if ((!oSelfRect.contains(oSelfPoint)) && (!oWidgetRect.contains(oWidgetPoint)))
			{
				ui.widgetv->hide();
				killTimer(ev->timerId());
			}
		}
	else
	{
		killTimer(ev->timerId());
	}
}





