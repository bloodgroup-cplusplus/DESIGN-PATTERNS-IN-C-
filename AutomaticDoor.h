class AutomaticDoor
{
    public:
        enum class State
        {
            closed =1, 
            opening, 
            open , 
            closing
        };


    private:
        State state;
        // ... more attributes here. ...


    public:
        State getState() const ;
        // .. more member functions here ... 
        
    };




