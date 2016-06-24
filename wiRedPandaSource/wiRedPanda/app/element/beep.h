#ifndef BEEP_H
#define BEEP_H

#include "graphicelement.h"
#include <QMediaPlayer>

class Beep : public GraphicElement {

public:
  explicit Beep( QGraphicsItem *parent = 0 );
  virtual ~Beep( );

  /* GraphicElement interface */
  virtual ElementType elementType( ) {
    return( ElementType::BEEP );
  }
  virtual ElementGroup elementGroup( ) {
    return( ElementGroup::OUTPUT );
  }
  void updateLogic( );
  void setTone( QString getTone );
  void playBeep( );
  QString getTone( );

private:
  QString m_tone;
  QMediaPlayer *player;
  bool fromplayed;
  /* GraphicElement interface */
public:
  void save( QDataStream &ds );
  void load( QDataStream &ds, QMap< quint64, QNEPort* > &portMap, double version );
  QString genericProperties( );
};

#endif /* BEEP_H */
