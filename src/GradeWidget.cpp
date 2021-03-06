// =====================================================================================
// 
//       Filename:  GradeWidget.cpp
//
//    Description:  面试打分选项卡控件
//
//        Version:  1.0
//        Created:  2013年03月21日 16时07分09秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>
#include <QtSql>

#include "GradeWidget.h"

GradeWidget::GradeWidget()
{
	setupUi(this);

	createAction();

	toolBar = new QToolBar();
	toolBar->setIconSize(QSize(70, 70));
	toolBar->setMovable(false);
	toolBar->addSeparator();
	toolBar->addAction(aPlusAction);
	toolBar->addSeparator();
	toolBar->addAction(aAction);
	toolBar->addSeparator();
	toolBar->addAction(aMinusAction);
	toolBar->addSeparator();
	toolBar->addSeparator();
	toolBar->addAction(bPlusAction);
	toolBar->addSeparator();
	toolBar->addAction(bAction);
	toolBar->addSeparator();
	toolBar->addAction(bMinusAction);
	toolBar->addSeparator();
	toolBar->addSeparator();
	toolBar->addAction(cPlusAction);
	toolBar->addSeparator();
	toolBar->addAction(cAction);
	toolBar->addSeparator();
	toolBar->addAction(cMinusAction);
	toolBar->addSeparator();
	toolBar->addSeparator();
	toolBar->addAction(dAction);
	toolBar->addSeparator();

	toolLayout->addWidget(toolBar);

	QRegExp idRegExp("[0-9]{8}");
	idEdit->setValidator(new QRegExpValidator(idRegExp, this));

	findButton->setEnabled(false);
	connect(idEdit, SIGNAL(textChanged(QString)), this, SLOT(setButtonEnable(QString)));
	connect(findButton, SIGNAL(clicked()), this, SLOT(findUser()));
	connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));
}

GradeWidget::~GradeWidget()
{

}

void GradeWidget::createAction()
{
	aPlusAction = new QAction(tr("A+"), this);
	aPlusAction->setIcon(QIcon(":/res/images/aPlus.png"));
	connect(aPlusAction, SIGNAL(triggered()), this, SLOT(setAPlus()));
	
	aAction = new QAction(tr("A"), this);
	aAction->setIcon(QIcon(":/res/images/a.png"));
	connect(aAction, SIGNAL(triggered()), this, SLOT(setA()));
	
	aMinusAction = new QAction(tr("A-"), this);
	aMinusAction->setIcon(QIcon(":/res/images/aMinus.png"));
	connect(aMinusAction, SIGNAL(triggered()), this, SLOT(setAMinus()));

	bPlusAction = new QAction(tr("B+"), this);
	bPlusAction->setIcon(QIcon(":/res/images/bPlus.png"));
	connect(bPlusAction, SIGNAL(triggered()), this, SLOT(setBPlus()));
	
	bAction = new QAction(tr("B"), this);
	bAction->setIcon(QIcon(":/res/images/b.png"));
	connect(bAction, SIGNAL(triggered()), this, SLOT(setB()));

	bMinusAction = new QAction(tr("B-"), this);
	bMinusAction->setIcon(QIcon(":/res/images/bMines.png"));
	connect(bMinusAction, SIGNAL(triggered()), this, SLOT(setBMinus()));
	
	cPlusAction = new QAction(tr("C+"), this);
	cPlusAction->setIcon(QIcon(":/res/images/cPlus.png"));
	connect(cPlusAction, SIGNAL(triggered()), this, SLOT(setCPlus()));
	
	cAction = new QAction(tr("C"), this);
	cAction->setIcon(QIcon(":/res/images/c.png"));
	connect(cAction, SIGNAL(triggered()), this, SLOT(setC()));
	
	cMinusAction = new QAction(tr("C-"), this);
	cMinusAction->setIcon(QIcon(":/res/images/cMinus.png"));
	connect(cMinusAction, SIGNAL(triggered()), this, SLOT(setCMinus()));
	
	dAction = new QAction(tr("D"), this);
	dAction->setIcon(QIcon(":/res/images/d.png"));
	connect(dAction, SIGNAL(triggered()), this, SLOT(setD()));
}

void GradeWidget::findUser()
{
	// TODO 按照管理员设置填充此处字符串
	QString strSql = QString("select name, sex, class from stu_%1 where id='%2'").arg("2012").arg(idEdit->text());

	QSqlQuery query(strSql);

	if (!query.isActive()) {
		QMessageBox::warning(this, tr("数据库错误"), query.lastError().text());
	}

	if (!query.next()) {
		QMessageBox::warning(this, tr("没有找到相关信息"), tr("数据库无此人记录，请检查您的输入学号。"));	
	} else {
		nameEdit->setText(query.value(0).toString());
		sexEdit->setText(query.value(1).toString());
		classEdit->setText(query.value(2).toString());
	}
}

void GradeWidget::reset()
{
	idEdit->clear();	
	nameEdit->clear();
	sexEdit->clear();
	classEdit->clear();
}

void GradeWidget::setButtonEnable(QString str)
{
	findButton->setEnabled(!(str == ""));
}

void GradeWidget::setAPlus()
{

}

void GradeWidget::setA()
{

}

void GradeWidget::setAMinus()
{

}

void GradeWidget::setBPlus()
{

}

void GradeWidget::setB()
{

}

void GradeWidget::setBMinus()
{

}

void GradeWidget::setCPlus()
{

}

void GradeWidget::setC()
{

}

void GradeWidget::setCMinus()
{

}

void GradeWidget::setD()
{

}
