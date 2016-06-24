#include "beep.h"

#include <QDebug>
#include <QGraphicsSceneDragDropEvent>
#include <QMediaPlayer>
#include <QCoreApplication>
//TODO: Beep Icon
Beep::Beep( QGraphicsItem *parent ) : GraphicElement( 1, 1, 0, 0, parent ) {

  setOutputsOnTop( true );
  setRotatable( false );
  setHasTones( true );
  player=new QMediaPlayer;
  setTone("1.0");
  setPixmap( QPixmap( ":/output/beepoff.png" ) );
  updatePorts( );
  setHasLabel( true );
  setPortName( "Beep" );

  inputs( ).at( 0 )->setRequired( false );
  inputs( ).at( 0 )->setDefaultValue( 0 );
}

Beep::~Beep( ) {

}

void Beep::updateLogic( ) {
  if( isValid( ) ) {
    bool value = inputs( ).first( )->value( );
    if( value == 1 ) {
      if(fromplayed){
            player->setPosition(117);
      }
      else
         playBeep();


      if(player->position()>50)
         fromplayed=true;


      setPixmap( QPixmap( ":/output/beepon.png" ) );
    }
    else {
      fromplayed=false;
      setPixmap( QPixmap( ":/output/beepoff.png" ) );
    }
  }
  else {
    fromplayed=false;
    setPixmap( QPixmap( ":/output/beepoff.png" ) );
  }
}

void Beep::playBeep(){
    if(player->state() != QMediaPlayer::PlayingState){
     player->setMedia(QUrl("file:///" + QCoreApplication::applicationDirPath() + "/"+"audio/beep.wav"));
     player->setPlaybackRate(m_tone.toDouble());

     player->play();


    }

}
void Beep::setTone( QString freq ) {
    if(freq.toDouble())
        m_tone = freq;
    else
        m_tone="1.0";


      updateLogic( );
}

QString Beep::getTone( ) {
  return( m_tone );
}


void Beep::save( QDataStream &ds ) {
  GraphicElement::save( ds );
  ds << getTone( );
}

void Beep::load( QDataStream &ds, QMap< quint64, QNEPort* > &portMap, double version ) {
  GraphicElement::load( ds, portMap, version );
  if( version >= 1.1 ) {
    QString clr;
    ds >> clr;
    setTone( clr );
  }
}

QString Beep::genericProperties( ) {
  return( getTone( ) );
}

