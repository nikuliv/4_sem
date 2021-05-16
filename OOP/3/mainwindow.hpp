#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGraphicsScene>

#include "facade.hpp"
#include "drawer.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

protected:
  void setup_scene();

  void update_scene();

  void clear_scene();

private slots:
  void on_add_cam_clicked();

  void on_MainWindow_destroyed();

  void on_shift_fig_clicked();

  void on_scale_fig_clicked();

  void on_rotate_fig_clicked();

  void on_import_fig_clicked();

  void on_shift_cam_clicked();

  void on_rotate_cam_clicked();

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;

  std::unique_ptr<facade> _facade;
  std::shared_ptr<base_drawer> drawer;

  void draw();
  void print_message(char str[]);
};
#endif // MAINWINDOW_HPP