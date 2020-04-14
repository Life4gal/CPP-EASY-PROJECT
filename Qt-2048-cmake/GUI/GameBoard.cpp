#include "GameBoard.h"

using namespace GUI;

GameBoard::GameBoard(QWidget *parent, int dimension)
            : QWidget(parent),
                mainLayout(new QVBoxLayout()),  //主布局
                boardLayout(nullptr),       //边界布局，在重设游戏时进行排布
                game(new Core::Game(dimension)),    //默认是4阶面板
                score(new QLabel(QString("SCORE: %1").arg(game->getScore())))   //分数标签
{
    setAttribute(Qt::WA_StyledBackground, true);
    setProperty("class", "GameBoard");

    //窗口大小
    resize(650, 450);

    setLayout(mainLayout);

    //游戏管理者将当前面板管理者注册为观测者
    game->registerObserver(this);

    guiBoard.resize(dimension);
    for(int i = 0; i < dimension; ++i)
    {
        guiBoard[i].resize(dimension);
        for(int j = 0; j < dimension; ++j)
        {
            guiBoard[i][j] = nullptr;
        }
    }

    drawBoard();

    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);

    setStyleSheet(".GameBoard { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.getResetButton(), &ResetButton::clicked, this, &GameBoard::resetGame);
}

GameBoard::~GameBoard()
{
    delete game;
}

void GameBoard::keyPressEvent(QKeyEvent *event)
{
    using Direction = Core::Board::Direction;
    switch(event->key())
    {
        case Qt::Key_Up:
            game->move(Direction::UP);
            break;
        case Qt::Key_Down:
            game->move(Direction::DOWN);
            break;
        case Qt::Key_Left:
            game->move(Direction::LEFT);
            break;
        case Qt::Key_Right:
            game->move(Direction::RIGHT);
            break;
        default:
            ;
    }
}

//观测者收到提醒，判断游戏当前的逻辑是否需要继续
void GameBoard::notify()
{
    if(game->isGameOver())
    {
        gameOverWindow.show();
    }

    if(game->isWon())
    {
        score->setText(QString(QString("You hit 2048, congratulations! Keep playing to increase your score.\t\t SCORE: %1").arg(game->getScore())));
    }
    else
    {
        score->setText(QString("SCORE: %1").arg(game->getScore()));
    }

    drawBoard();
}

void GameBoard::drawBoard()
{
    //换掉当前的边界布局
    delete boardLayout;
    boardLayout = new QGridLayout();

    int dimension = game->getGameBoard()->getDimension();
    for(int i = 0; i < dimension; ++i)
    {
        for(int j = 0; j < dimension; ++j)
        {
            //重新排布当前的边界布局
            delete guiBoard[i][j];
            guiBoard[i][j] = new LabelTile(game->getGameBoard()->getTile(i, j));
            boardLayout->addWidget(guiBoard[i][j], i, j);
            guiBoard[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}

void GameBoard::resetGame()
{
    game->restart();
    drawBoard();
    score->setText(QString("SCORE: %1").arg(game->getScore()));
    gameOverWindow.hide();
}

