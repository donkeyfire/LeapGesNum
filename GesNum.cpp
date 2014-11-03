#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Leap.h"

using namespace Leap;
/*class MyListener : public Listener{
public:
	virtual void onConnect(const Controller&);
	// virtual void onFrame(const Controller&);
};

void MyListener::onConnect(const Controller& controller){
	std::cout<<"Connected"<<std::endl;
}*/



//void MyListener::onFrame(const Controller& controller){

	
	
//}

int main(int argc, char** argv){

//	MyListener listener;
	Controller controller;
	//controller.enableGesture(Gesture::TYPE_CIRCLE);
	controller.enableGesture(Gesture::TYPE_SWIPE);
	controller.enableGesture(Gesture::TYPE_SCREEN_TAP);

//	controller.addListener(listener);

	long old_id=0;
	int last=0;
	int start=0;

	int wait=0;
	int down=0;
	int right=0;
	int left=0;
	int rightdown=0;
	int leftdown=0;
	int leftdown2=0; // samll angle leftdown 
	int other;
	float startx=0;
	float starty=0;
	float endx=0;
	float endy=0;

	float startpx=0;
	float startpy=0;
	float endpx=0;
	float endpy=0;

	float leftmost=0;
	float rightmost=0;
	float upmost=0;
	float downmost=0;

	float diff=0;
	float diffx=0;
	float diffy=0;
	int DIFF=0;

	int been=0;

	int firstframe=0;
	float sumx=0;
	float sumy=0;
	int up=0;
	int	swipefirst=0;
	int rightdownchange=0;
	int uprightchange=0;
	int leftrightchange=0;
	int updownchange=0;
	int rightleftchange=0;
	int leftrightchange4=0;
	int rightupchange=0;
	int downrightchange=0;
	int leftupchange=0;
	int vote[10];
	int maxvote;
	int maxvoteindex;
	for (int i=0; i<10 ; i++)
		vote[i]=0;

	GestureList lastgesturelist;

	if(!controller.isConnected())
		{std::cout<<"Plugin in your Leap Motion Controller"<<std::endl;}

	while(!controller.isConnected())
	{

	}

	std::cout<<"Swipe Your Number 0 to 9 SLOWLY and CLEARLY, Tap the screen to exit. "<<std::endl;

    while(1){
    	if (controller.isConnected()){

    	


    const Frame frame=controller.frame();
	GestureList tgesturelist=frame.gestures();


	if (frame.id()==old_id)
	{continue;}

	
		if (!tgesturelist.isEmpty())
		{
			// test for position
			firstframe++;
	
			if (firstframe>=0){
			if (tgesturelist[0].type()==SwipeGesture::TYPE_SWIPE){
		swipefirst=1;
				SwipeGesture tgesture=tgesturelist[0];
			Vector direction=tgesture.direction();
			Vector position=tgesture.position();

				if (direction[1]<-0.85 && direction[0]<0.1 && direction[0]>-0.1)
					down++;
				else if (direction[0]>0.7 && direction[1]<0.3 && direction[1]>-0.3)
					right++;
				else if (direction[0]<-0.7 && direction[1]<0.3 && direction[1]>-0.3)
					left++;
				else if (direction[0]>0.5 && direction[1]<-0.5)
					rightdown++;
				else if (direction[0]<-0.5 && direction[1]<-0.5)
					leftdown++;
				else if (direction[0]<0 && direction[0]>-0.5 && direction[1]<-0.2 && direction[1]>-0.8)
					leftdown2++;
				else if (direction[1]>0)
					up++;
				else 
					other++;
				if (start==0)
				{
		
						startx=direction[0];
			
						starty=direction[1];
						startpx=position[0];
						startpy=position[1];

				leftmost=position[0];
				rightmost=position[0];
				upmost=position[1];
				downmost=position[1];
		
				}
				if (start!=0){
					SwipeGesture lgesture=lastgesturelist[0];
				Vector lastdirection=lgesture.direction();
				

				diffx=pow((lastdirection[0]-direction[0]),2);
				diffy=pow((lastdirection[1]-direction[1]),2);
				diff=diffx+diffy;
				if (diff>1.5)
				{
				
					DIFF++;
				}

				if (lastdirection[0]<-0.5 && direction[0]>0.5)
					leftrightchange++;
				if (lastdirection[0]<0.5 && lastdirection[1]>0.5 && direction[0]>0.5 && direction[1]<0.5)
					uprightchange++;
				if (lastdirection[1]>0.8 && direction[1]<-0.8)
					{updownchange++;
					//std::cout<<"Updown at Frame "<<firstframe<<std::endl;
					}
				if (lastdirection[0]>0.5 && direction[0]<-0.5)
					rightleftchange++;
				if (lastdirection[0]>0.7 && abs(direction[0])<0.5 && abs(lastdirection[1])<0.3 && direction[1]<-0.7 )
					rightdownchange++;
				if (lastdirection[0]<0 && lastdirection[0]>-0.6 && direction[0]>0.7 && lastdirection[1]<-0.5 && abs(direction[1])<0.3)
					leftrightchange4++;
				if (lastdirection[0]>0.7 && direction[0]<0 && direction[1]>0.7)
					rightupchange++;
				if (lastdirection[1]<-0.7 && abs(direction[1])<0.4 && direction[0]>0.7)
					downrightchange++;
				if (lastdirection[0]<-0.7 && direction[1]>0.7)
					leftupchange++;
				}




				if (leftmost>position[0])
					leftmost=position[0];
				if (rightmost<position[0])
				{	//std::cout<<"Rightmost is "<<rightmost<<std::endl;
					rightmost=position[0];}
				if (upmost<position[1])
					upmost=position[1];
				if (downmost>position[1])
					downmost=position[1];


			//	std::cout<<"X position is "<<position[0]<<"Y position is "<<position[1]<<std::endl;
			//	std::cout<<"Rightmost is "<<rightmost<<std::endl;



				//std::cout<<"X direction is "<<direction[0]<<" Y direction is "<<direction[1]<<" Z direction is "<<direction[2]<<" at Frame "<<firstframe<<std::endl;

				endx=direction[0];
				endy=direction[1];
				endpx=position[0];
				endpy=position[1];

				sumx=sumx+direction[0];
				sumy=sumy+direction[1];
	lastgesturelist=tgesturelist;
			
			}
			start=1;
			last=1;
			wait=0;
			//std::cout<<"Count: "<<tgesturelist.count()<<std::endl;
			


			
		
		}	
		

		}
		// Right after the gesture//
		else if(last==1)
		{
			wait++;

			if (wait==50){

					
			SwipeGesture swipe=lastgesturelist[0];
			
		


			if (firstframe>10){
	/*		std::cout<<"DIFF "<<DIFF<<std::endl;
			std::cout<<"down is "<<down<<std::endl;
			std::cout<<"right is "<<right<<std::endl;
			std::cout<<"left is "<<left<<std::endl;
			std::cout<<"rightdown is "<<rightdown<<std::endl;
			std::cout<<"leftdown is "<<leftdown<<std::endl;
			std::cout<<"leftdown2 is "<<leftdown2<<std::endl;
			std::cout<<"other is "<<other<<std::endl;
			std::cout<<"sumX is "<<sumx<<std::endl;
			std::cout<<"sumY is "<<sumy<<std::endl;
			std::cout<<"up is "<<up<<std::endl;


			std::cout<<"uprightchange is "<<uprightchange<<std::endl;


			std::cout<<"leftrightchange is "<<leftrightchange<<std::endl;
			std::cout<<"rightleftchange is "<<rightleftchange<<std::endl;
			std::cout<<"updownchange is "<<updownchange<<std::endl;
				std::cout<<"rightdownchange is "<<rightdownchange<<std::endl;
				std::cout<<"leftright4 is "<<leftrightchange4<<std::endl;
				std::cout<<"rightup is "<<rightupchange<<std::endl;
				std::cout<<"downright is "<<downrightchange<<std::endl;
				std::cout<<"leftup is "<<leftupchange<<std::endl;
			std::cout<<"StartX is "<<startx<<std::endl;
			std::cout<<"StartY is "<<starty<<std::endl;
		std::cout<<"EndX is "<<endx<<std::endl;
			std::cout<<"EndY is "<<endy<<std::endl;

			std::cout<<"Start Position is x= "<<startpx<<" y= "<<startpy<<std::endl;
			std::cout<<"End Position is x= "<<endpx<<" y= "<<endpy<<std::endl;*/
			float distance=pow((pow(startpx-endpx,2)+pow(startpy-endpy,2)),0.5);
			/*std::cout<<"Distance is "<<distance<<std::endl;

			std::cout<<"Leftmost is "<<leftmost<<std::endl;

			std::cout<<"Rightmost is "<<rightmost<<std::endl;

			std::cout<<"Upmost is "<<upmost<<std::endl;
				std::cout<<"Downmost is "<<downmost<<std::endl;


				std::cout<<"Total Frame is "<<firstframe<<std::endl;*/
			/*if (down>10 && up<firstframe && right==0 && left==0 && leftdown==0 && leftdown2==0 
				&& other==0 && sumx<5 && sumy<-15 && uprightchange==0 && leftrightchange==0 && rightleftchange==0 && updownchange<=1
				&& rightdownchange==0 && rightupchange==0 && downrightchange==0 &&  abs(endx)<0.2 && endy<-0.8)
			

			std::cout<<"IS 1 "<<std::endl;

			if ((endx>0.6 || endx<-0.6 ) && abs(endy)<0.4 && leftrightchange>0 && right>0 && left>0 && uprightchange==0)
				std::cout<<"IS 2"<<std::endl;
			if (uprightchange>=1)
				std::cout<<"IS 5"<<std::endl;
			if (leftrightchange4==1)
				std::cout<<"IS 4 "<<std::endl;*/


					if (leftrightchange4>0)
					{
						vote[4]+=60;
						vote[9]+=10;
						vote[5]+=20;
						vote[6]+=10;
						vote[8]+=5;
					}		
					else 
					{
						vote[4]-=60;
						vote[9]-=10;
						vote[5]-=20;
						vote[6]-=10;
					}

					if (uprightchange>0)
					{
						vote[5]+=100;
						vote[8]+=10;
					}		
					else 
					{
						vote[5]-=60;
					}
					if (updownchange>0)
					{
						//vote[1]+=10;
						vote[4]+=30;
						vote[6]+=50;
						//vote[7]+=20;
						vote[9]+=50;
						vote[0]+=20;
						vote[8]+=10;
					}
					else 

					{
					
						vote[4]-=30;
						vote[6]-=30;
						vote[7]-=20;
						vote[9]-=30;
						

					}
					if (rightdownchange>0)
					{
						vote[2]+=20;
						vote[7]+=60;
						vote[8]+=20;
					}
					else
					{
					vote[2]-=20;
						vote[7]-=40;
						vote[8]-=10;
					}
					if (leftrightchange>0)
					{
						vote[2]+=40;
						vote[3]+=40;
						vote[4]+=30;
						vote[8]+=10;
					}
					else
					{
						vote[2]-=40;
						vote[3]-=40;
						vote[4]-=30;
					}
					if (rightleftchange>0)
					{
						vote[2]+=40;
						vote[3]+=40;
						vote[6]+=20;
					}
					else
					{
						vote[2]-=40;
						vote[3]-=40;
						vote[6]-=0;
					}
					if (rightupchange>0)
					{
						vote[4]+=70;
						vote[5]+=30;
					}
					else 
					{
						vote[4]-=70;
						vote[5]-=30;
					}
					if (downrightchange>0)
					{
						vote[4]+=20;
						vote[5]+=50;
						vote[6]+=20;
						vote[8]+=20;
					}
					else 
					{	vote[4]-=20;
						vote[5]-=50;
						vote[6]-=0;
						vote[8]-=5;

					}
					if (endx>0.7)
					{
						vote[2]+=40;
						vote[5]+=40;
					}
					else 
					{
						vote[2]-=40;
						vote[5]-=40;
					}
					if (endx<-0.7)
					{
						vote[3]+=50;
					}
					else 
					{
						vote[3]-=0;
					}
					if (endy<-0.7)
					{
						vote[1]+=30;
						vote[4]+=30;
						vote[7]+=30;
						vote[9]+=30;

					}
					else{
					
						vote[1]-=30;
						vote[4]-=30;
						vote[7]-=30;
						vote[9]-=30;
						
					
					}


					if (distance<100)
					{
						vote[8]+=30;
						vote[0]+=30;
					}
					if (left+right+leftdown+rightdown+other>5)
						{
							vote[1]-=30;
						}
					/*if (DIFF>=3)
					{
						//vote[3]+=30;
						vote[8]+=30;
					}*/
					if (sumx>0)
					{
						vote[9]-=30;
					}
					if (starty>0.8 || starty<-0.8)
					{
						vote[1]+=20;
						vote[5]+=20;
						vote[0]+=20;
						vote[6]+=20;

					}


					if ((endpy-downmost)>30)
					{
						vote[8]+=50;
						vote[0]+=50;
						vote[6]+=30;
						vote[5]+=30;
					}
					else
					{
						vote[8]-=50;
						vote[0]-=50;
						vote[6]-=10;
						vote[5]-=30;
					}
					if (right>5)
					{
						vote[2]+=30;
						vote[5]+=30;
						vote[7]+=20;
					}
					else 
					{
						vote[2]-=30;
						vote[5]-=30;
						vote[7]-=20;
					}


				//	else 


			//	{
						//vote[1]-=20;
					//	vote[5]-=20;
					//	vote[0]-=20;
					//	vote[6]-=20;				}


					maxvote=vote[0];
					maxvoteindex=0;
				//	std::cout<<"SCORE For 0 IS "<<vote[0]<<std::endl;
					for (int i=1;i<10;i++)
					{
						if (maxvote<vote[i])
						{
							maxvote=vote[i];
							maxvoteindex=i;
						}
					//	std::cout<<"SCORE For "<<i<<" IS "<<vote[i]<<std::endl;
					}

					std::cout<<"IS "<<maxvoteindex<<std::endl;

							}

			

			last=0;
			start=0;
			down=0;
			right=0;
			left=0;
			leftdown=0;
			rightdown=0;

			leftdown2=0;
			up=0;
			other=0;

			been=0;

			sumx=0;
			sumy=0;

			DIFF=0;
			swipefirst=0;

			uprightchange=0;
	 leftrightchange=0;
	 updownchange=0;
	 rightleftchange=0;
	 rightdownchange=0;
	 leftrightchange4=0;
	 rightupchange=0;
downrightchange=0;
leftupchange=0;
firstframe=0;
	for (int i=0; i<10 ; i++)
		vote[i]=0;


		}

		}


		old_id=frame.id();
	


	Gesture fgesture=tgesturelist[0];
	if (fgesture.type()==5)
	{
		std::cout<<"tap"<<std::endl;
		break;
	}

    }
	}

	//std::cout <<"Press Enter to quit..."<<std::endl;
	//std::cin.get();

	//controller.removeListener(listener);




	return 0;
}