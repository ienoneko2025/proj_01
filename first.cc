#include <qboxlayout.h>
#include <qlabel.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qstyle.h>
#include <qwidget.h>

#include "first.h"

scr_first::scr_first (void)
: QWidget(nullptr)
{
  this->setLayout(this->m_box = new QVBoxLayout());

  this->m_box->addWidget(this->m_btn_bar_holder = new QWidget());
  this->m_btn_bar_holder->setLayout(this->m_btn_bar_layout = new QHBoxLayout());
  this->m_btn_bar_layout->addWidget(this->m_new_btn = new QPushButton("&New"));
  this->m_new_btn->setIcon(this->m_new_btn->style()->standardIcon(QStyle::SP_FileDialogNewFolder));
  this->m_btn_bar_layout->addWidget(this->m_open_btn = new QPushButton("&Open"));
  this->m_open_btn->setIcon(this->m_open_btn->style()->standardIcon(QStyle::SP_DialogOpenButton));

  this->m_box->addWidget(this->m_recent_lbl = new QLabel("Recent"));
  this->m_box->addWidget(this->m_recent_lst = new QListWidget());
}

scr_first::~scr_first (void)
{
  delete this->m_box;

  delete this->m_btn_bar_layout;
  delete this->m_new_btn;
  delete this->m_open_btn;
  delete this->m_btn_bar_holder;

  delete this->m_recent_lbl;
  delete this->m_recent_lst;
}
