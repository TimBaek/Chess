#ifndef _PIECE_H
#define _PIECE_H

class Piece {
  shared_ptr<Board> b_obs;
  shared_ptr<TextDisplay> td_obs;
  shared_ptr<GraphicDisplay> gd_obs;
  shared_ptr<Player> player;
  int row;
  int col;
  char letter;


 public:
  Piece(shared_ptr<Board> b, shared_ptr<TextDisplay> td, shared_ptr<GraphicDisplay gd, shared_ptr<Player> p, int c, int r, char l);
  virtual ~Piece();
  void notifyBoard(int dr, int dc);
  void notifyTextDisplay(int dr, int dc);
  void notifyGraphicDisplay(int dr, int dc);
  virtual void move(int row, int col)=0;
  int getRow() const;
  int getCol() const;
  char getLetter() const;


#endif


class King: public Piece {
  bool evermoved = false;
 public:
  
}