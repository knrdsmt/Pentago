# Pentago Game

This is a console-based implementation of the Pentago game written in C++. The game supports both single-player and two-player modes.

<p align="center">
<img src="https://github.com/knrdsmt/Pentago/blob/main/Pentago.png?raw=true" alt="Pentago" width="45%" height="auto" />
</p>

## Features

- **Two-Player Mode**: Play against a friend.
- **Dynamic Board Rotation**: Rotate board quadrants during gameplay.
- **Win Condition**: The first player to form a row of five of their pieces wins.

## How to Play

1. Run the executable.
2. Follow the prompts to enter the players' names.
3. Choose between single-player or two-player mode.
4. Use the keyboard to select the quadrant and position to place your piece.
5. Optionally, rotate a quadrant after placing your piece.
6. The game ends when one player achieves a winning condition or there's a draw.

## Controls

- Use `q`, `w`, `a`, `s` to select the quadrant.
- Use `1` to `9` to choose the position within the selected quadrant.
- After selecting the position, use `z` to rotate the quadrant clockwise or `x` to rotate counterclockwise.
- Press `p` to pause the game.
- Press `u` to undo the last move.
- Press `o` to load a predefined game board.
- Press `m` to enter the options menu.
- Press `h` for help and game instructions.

## Build Instructions

To build the game, compile the `main.cpp` file using a C++ compiler.

```bash
g++ main.cpp -o pentago
```

## License
This project is licensed under the MIT License - see the LICENSE file for details.

<p>&nbsp;</p>

---
<p>&nbsp;</p>

# Gra Pentago

## Opis

Gra Pentago jest konsolową implementacją popularnej gry planszowej. Została napisana w języku C++ bez użycia zewnętrznych bibliotek. 

<p align="center">
<img src="https://github.com/knrdsmt/Pentago/blob/main/Pentago.png?raw=true" alt="Pentago" width="45%" height="auto" />
</p>

## Zasady Gry

Pentago to gra dla dwóch graczy, którzy wykonują ruchy na wspólnej planszy 6x6. Plansza jest podzielona na cztery 3x3 obszary. Gracze na przemian umieszczają swoje znaki (krzyżyk lub kółko) na planszy, a następnie obracają jedną z czterech części planszy o 90 stopni w prawo lub w lewo. Gracz wygrywa, gdy uda mu się umieścić pięć swoich znaków w pionie, poziomie lub po przekątnej.

## Uruchomienie

Aby uruchomić grę, skompiluj program i uruchom go. Następnie postępuj zgodnie z instrukcjami wyświetlanymi w menu. Możesz wybrać tryb gry - klasyczny Kolko i Krzyżyk lub Pentago.

## Sterowanie

- Podczas wyboru planszy: q, w, a, s - wybór części planszy; 1-9 - wybór konkretnego pola na planszy
- Podczas obrotu planszy: z - obrót zgodnie z ruchem wskazówek zegara; x - obrót przeciwnie do ruchu wskazówek zegara
- Instrukcje pomocnicze: h - pomoc; p - pauza
- Wyjście z opcji: dowolna inna klawisz niż wybór możliwości

## Autorzy

- Ten program został stworzony przez [Twój_Nick](https://github.com/twoj_nick).
- Zaprojektowany na podstawie reguł gry w Pentago.

## Licencja

Ten program jest dostępny na licencji MIT. Szczegółowe informacje znajdują się w pliku [LICENSE](LICENSE).
