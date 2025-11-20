#ifndef ANIMILK_FIRST_H
#define ANIMILK_FIRST_H

#include <qwidget.h>

class QHBoxLayout;
class QLabel;
class QListWidget;
class QPushButton;
class QVBoxLayout;

class scr_first
: public QWidget
{
  Q_OBJECT

public:
  scr_first (void);
  ~scr_first (void);

private:
  QVBoxLayout *m_box;

  QWidget *m_btn_bar_holder;
  QHBoxLayout *m_btn_bar_layout;
  QPushButton *m_new_btn;
  QPushButton *m_open_btn;

  QLabel *m_recent_lbl;
  QListWidget *m_recent_lst;
};

#endif
