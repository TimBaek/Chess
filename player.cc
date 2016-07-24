#include "player.h"

Player::Player(): score{0} {}
Player::~Player() {}

void Player::addScore(const double& s) { score = score + s; }

double Player::getScore() { return score; }