#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    // Connect signals to display update functions.
    connect(ui.graphicsView->scene(), SIGNAL(levelChanged(int)),
            this, SLOT(updateLevelDisplay(int)));
    connect(ui.graphicsView->scene(), SIGNAL(scoreChanged(int)),
            this, SLOT(updateScoreDisplay(int)));
    connect(ui.graphicsView->scene(), SIGNAL(livesChanged(int)),
            this, SLOT(updateLivesDisplay(int)));
    connect(ui.graphicsView->scene(), SIGNAL(gameStateChanged(BlobertScene::game_state_t)),
            this, SLOT(updateStateDisplay(BlobertScene::game_state_t)));

    // Force update initially.
    updateDisplays();
}

void GameWidget::beginGame()
{
    ui.graphicsView->scene()->beginGame();
}

void GameWidget::updateLivesDisplay(int lives)
{
    ui.livesLabel->setText(QString("Lives: %1").arg(lives));
}

void GameWidget::updateScoreDisplay(int score)
{
    ui.scoreLabel->setText(QString("Score: %1").arg(score));
}

void GameWidget::updateLevelDisplay(int level)
{
    ui.levelLabel->setText(QString("Level: %1").arg(level));
}

void GameWidget::updateStateDisplay(BlobertScene::game_state_t state)
{
    switch (state) {
        case BlobertScene::WAIT_START:
        case BlobertScene::WAIT_CONT:
            ui.statusLabel->setText("Ready");
            break;
        case BlobertScene::RUNNING:
            ui.statusLabel->setText("Game running");
            break;
        case BlobertScene::PAUSED:
            ui.statusLabel->setText("Game paused");
            break;
        case BlobertScene::FINISHED:
            ui.statusLabel->setText("Game finished");
            break;
    }
}

void GameWidget::updateDisplays()
{
    BlobertScene *scene = ui.graphicsView->scene();
    int lives = scene->lives();
    int level = scene->level();
    int score = scene->score();
    BlobertScene::game_state_t state = scene->state();

    updateLivesDisplay(lives);
    updateScoreDisplay(score);
    updateLevelDisplay(level);
    updateStateDisplay(state);
}
