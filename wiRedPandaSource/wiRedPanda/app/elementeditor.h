#ifndef ELEMENTEDITOR_H
#define ELEMENTEDITOR_H

#include "graphicelement.h"
#include "scene.h"
#include <QGraphicsScene>
#include <QUndoCommand>
#include <QWidget>

namespace Ui {
  class ElementEditor;
}

class Editor;

class ElementEditor : public QWidget {
  Q_OBJECT

public:
  explicit ElementEditor( QWidget *parent = 0 );
  ~ElementEditor( );

  void setScene( Scene *s );
  void contextMenu( QPoint screenPos, Editor *editor );
  void renameAction();
  void changeTriggerAction();
/*
 *  void renameAction( const QVector< GraphicElement *> &element );
 *  void changeColorAction( const QVector<GraphicElement *> &element );
 */

signals:
  void sendCommand( QUndoCommand *cmd );

private slots:

  void selectionChanged( );

  void on_lineEditElementLabel_editingFinished( );

  void on_comboBoxInputSz_currentIndexChanged( int index );

  void on_doubleSpinBoxFrequency_editingFinished( );

  void on_comboBoxColor_currentIndexChanged( int index );

  void on_lineEditTrigger_textChanged( const QString &arg1 );

  void on_lineEditTrigger_editingFinished( );

  void on_lineEditElementtone_editingFinished();

private:
  void setCurrentElements( const QVector< GraphicElement* > &element );
  void apply( );

  Ui::ElementEditor *ui;
  QVector< GraphicElement* > m_elements;
  Scene *scene;
  bool hasAnyProperty, hasLabel, hasColors,hasTone, hasFrequency;
  bool canChangeInputSize, hasTrigger, hasRotation;
  bool hasSameLabel, hasSameColors, hasSameFrequency,hasSameTone;
  bool hasSameInputSize, hasSameTrigger, canMorph, hasSameType;
  bool hasElements;

  QString _manyLabels;
  QString _manyColors;
  QString _manyTones;
  QString _manyIS;
  QString _manyFreq;
  QString _manyTriggers;


};

#endif /* ELEMENTEDITOR_H */
