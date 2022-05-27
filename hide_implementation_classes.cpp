/* In addtion to hidng the internal methods and variable for you classes, 
 * you should also endeavor to hide any actual classes that are purely implementation detail. 
 * Most programmers are used to hiding methods and variables, although many forget to also consider that not all classes are public. 
 * Indeed some classes are only needed for your implemenatino and should not be revealed as part of the public interface of your API
 * Consider a simple Firework class; 
 * an interface that lets you specify the location fo a fireworsk
 * animation on the screen and lets you controal the color, speed, and number
 * of fire particles
 * Clearly the API will need to keep track of each particle of the firework effect so that 
 * it can update each particle's position per fram.e 
 * This implies that a FireParticle class should be introduced to contain the state for a single fire particle. 
 * However, clients of the API never need to access this class; 
 * It's purely required for the API's implementatino . This class could therefore be mad private, 
 * by nextin it in the Fireworks class with in a private seciton .
 */


#include<iostream>
#include<vector>


class Fireworks
{
    public:
        Fireworks();

        void SetOrigin(double x, double y);
        void SetColor( float r, float g, float b);
        void SetGravity(float g);
        void SetSpeed( float s);
        void SetNumberOfParticles( int num);
        void Start();
        void Stop();
        void NextFrame(float dt);

    private:
        class FireParticle
        {
            public:
                double mX,mY;
                double mVelocityX, mVelocityY;
                double mAcceleartionX, mAccelartionY;
                double mLifeTime;
        };


        double mOriginX, mOriginY;
        float mRed, mGreen, mBlue;
        float mGravity;
        float mSpeed;
        bool mIsActive;
        std::vector<FireParticle*> mParticles;
};

