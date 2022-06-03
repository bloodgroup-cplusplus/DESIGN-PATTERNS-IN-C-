/* Motivation 
 * Algorithms can be decomposed into common parts+ specifics
 * Strategy pattern does this through composition 
 *  High-level algorithm uses an interface
 *  Conceret implementations implemnt the interface
 *
 *
 *  Template Method does the same thing through inheritance
 *      Overall algorithm makes use of abstract member
 *      Inheritors override 
 *
 *
 *      Template method allows use to define the 'skeleton' of the algorithm, with concrete
 *      implementations defined in subclass
 *      '
 */


#include "Headers.hpp"
class Game
{
    public:
        Game(int number_of_players) :number_of_players(number_of_players){}
        void run()
        {
            start();
            while(!have_winner())
                take_turn();
            std::cout<<"Player"<<get_winnter() << "wins";
        }

        
    protected:
        virtual void start () =0;
        virtual void have_winner() = 0;
        virtual void take_turn() =0;
        virtual int get_winnter() = 0;
        int number_of_players;
        int current_player{0};

    
};

class Chess :public Game
{
    public:
        Chess() : Game(2) {}

    protected:
        void start() override
        {
            std::cout<<"Starting the game of chess with "<<number_of_players<<"players";
        }
        bool have_winner() override
        {
            return turn ==max_turns;
        }

        void take_turn() override
        {
            std::cout<<"Turn" <<turn << " taken by player"<<current_player<<std::endl;
            ++turn;
            current_player = (current_player+1)%number_of_players;
        }
        int get_winner() override
        {
            return current_player;
        }

    private:
        int turn{0},max_turns{10};
};




int main( int ac, char* av[])
{
    Chess chess;
    chess.run();
    // when we call run we are running skeleton algorithm 
    // details of the function are allowed to be inherited
    // we shall inherit the abstrat class and provide implementations 
    //
    //the template is the function run which has all the functions that has to be inherited 
    //in order to make the program fully functional 
    return 0;
}

