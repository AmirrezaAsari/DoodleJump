#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <vector>

#include "basics.h"
#include "trampo.h"
#include "platform-generator.h"
#include "bullet.h"
#include "jetpack.h"
#include "shield.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void generate();
    void sethard();
    void timestop();
    void set();

public slots:
    void jump();
    void setPic();
    void Gameover();
    void invincible_end();
    virtual void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);

private slots:
    void on_Pausebt_clicked();
    void on_Resumebt_clicked();
    void on_playButton_clicked();
    void on_menuButton_clicked();
    void on_Normal_clicked();
    void on_Multiplayer_clicked();


    void on_page_4_windowIconTextChanged(const QString &iconText);

private:
    Ui::MainWindow *ui;
    shield *sd;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *player,*pausebg,*line;
    QTimer *timer,*b_timer;
    bullet *b;
    jetpack *jet;
    trampo *trp;
    vector<platform*> plf_ptr;
    vector<monster*> mon_ptr;
    vector<platform2*>plf2_ptr;
    int count=0,t=0,plf2 = 0,score = 0,game_mode;
    unsigned long a = 0;
    double dy,dx=0;
    bool fly_md,invin_md;
    bool jet_est = false,shield_est = false;
};

#endif // MAINWINDOW_H
