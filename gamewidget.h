#include <QtGui>
#include "ui_gamewidget.h"
#include "blobertscene.h"

// Widget containing scene and game displays.
class GameWidget : public QWidget
{
	Q_OBJECT
public:
	GameWidget(QWidget *parent = 0);

    // Begins the game.
    void beginGame();

private slots:
    // Handles updated number of lives.
    void updateLivesDisplay(int lives);

    // Handles updated score.
    void updateScoreDisplay(int score);

    // Handles updated level.
    void updateLevelDisplay(int level);

    // Handles updated game state.
    void updateStateDisplay(BlobertScene::game_state_t state);

    // Updates all the displays.
    void updateDisplays();

private:
	Ui::GameWidget ui;


};
