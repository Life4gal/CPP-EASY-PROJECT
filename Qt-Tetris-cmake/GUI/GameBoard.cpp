#include "GameBoard.h"

using namespace GUI;

GameBoard::GameBoard(QWidget *parent, int _width, int _height)
            : QWidget(parent),
            mainLayout(new QVBoxLayout(this)),      //主布局
            boardLayout(nullptr),               //边界布局，在重设游戏时进行排布
            game(new cGame(_width, _height)),
            width(_width), height(_height),
            score(new QLabel(QString("SCORE: %1").arg(game->getScore()))),  //分数标签
            gameOverWindow(this)
{
    setAttribute(Qt::WA_StyledBackground, true);
    setProperty("class", "GameBoard");

    //窗口大小
    resize(400, 600);
    move(1000, 200);

    setLayout(mainLayout);

    game->registerObserver(this);

    guiBoard.resize(height);
    for(int i = 0; i < height; ++i)
    {
        guiBoard[i].resize(width);
        for(int j = 0; j < width; ++j)
        {
            guiBoard[i][j] = nullptr;
        }
    }

    drawBoard();

    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);

    gameOverWindow.hide();

    timer.setInterval(DELAY);

    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);

    setStyleSheet(".GameBoard { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.getResetButton(), &ResetButton::clicked, this, &GameBoard::resetGame);

    connect(&timer , &QTimer::timeout,[=]()
    {
        game->move(Core::Game::Direction::DOWN);
    });

    timer.start();
}

GameBoard::~GameBoard()
{
    delete game;
}

//观测者收到提醒，判断游戏当前的逻辑是否需要继续
void GameBoard::notify()
{
    if(game->isGameOver())
    {
        timer.stop();
        gameOverWindow.show();
    }

    score->setText(QString("SCORE: %1").arg(game->getScore()));

    drawBoard();
}

void GameBoard::drawBoard()
{
    // 换掉当前的边界布局
    delete boardLayout;
    boardLayout = new QGridLayout();

    Core::Board* b = game->getGameBoard();
    const int w = b->width;
    const int h = b->height;

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            // 重新排布当前的边界布局
            delete guiBoard[i][j];
            guiBoard[i][j] = new LabelTile(b->grid[i][j]);
            boardLayout->addWidget(guiBoard[i][j], i, j);
            guiBoard[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}

void GameBoard::keyPressEvent(QKeyEvent *event)
{
    using Direction = Core::Game::Direction;
    switch(event->key())
    {
        case Qt::Key_Up:
            game->move(Direction::UP);
            return;
        case Qt::Key_Down:
            game->move(Direction::DOWN);
            return;
        case Qt::Key_Left:
            game->move(Direction::LEFT);
            return;
        case Qt::Key_Right:
            game->move(Direction::RIGHT);
            return;
        default:
            return;
    }
    //QWidget::keyPressEvent(event);
}

void GameBoard::resetGame()
{
    game->restart();
    drawBoard();
    score->setText(QString("SCORE: %1").arg(game->getScore()));
    gameOverWindow.hide();
    timer.start();
}
