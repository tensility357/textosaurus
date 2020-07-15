// This file is distributed under GNU GPLv3 license. For full license text, see <project-git-repository-root-folder>/LICENSE.md.

#include "common/gui/baselineedit.h"

#include <QKeyEvent>

BaseLineEdit::BaseLineEdit(QWidget* parent) : QLineEdit(parent) {
  setClearButtonEnabled(true);
}

void BaseLineEdit::submit(const QString& text) {
  setText(text);
  emit submitted(text);
}

void BaseLineEdit::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
    emit submitted(text());

    event->accept();
  }
  else {
    QLineEdit::keyPressEvent(event);
  }
}
