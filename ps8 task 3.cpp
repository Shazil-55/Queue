#include <iostream>
#include "Queue.cpp"
using namespace std;

int main()
{
	Queue<int> obj;
	Queue<float> obj_price;
	char ch = 'y';
	char sell_bought;
	int shares;
	float shares_price;
	float profit =0.0 ;
	cout << " enter them in this format ( s/b  'no of shares' 'price of each share'\n";
	cout << " how many times you want to enter? ";
	int num;
	cin >> num;
	for ( int i =0 ; i<num ; i++)
	{
		cin >> sell_bought;
		cin >> shares;
		cin >> shares_price;
		

		if (sell_bought == 'b')
		{
			// agar buy kar raha hai to queue mein push kari jao 
			obj.enQueue(shares);
			obj_price.enQueue(shares_price);
		}
	
		else if (sell_bought == 's')
		{
			
			do
			{
				int get_shares = obj.getElementsAtFront();
				if (shares < get_shares)
				{
					//agar jo sell kar raha hai woh pehle se majood shares se chotay hai to queue mein hum ne update karni hai value is liye change name ka ek function bnaiye 
					int difference = get_shares - shares;
					profit += (shares * shares_price) - (shares * obj_price.getElementsAtFront()); // profit k formulae
					shares = 0; // yeh loop ke liye ke shares to humaray kam thay jo sell kiye un shares se jo paray hovay thay to wo shares 0 ho gaey or loop band ho giya 
					obj.change(difference);
				}
				
				if (shares > get_shares)
				{
					shares = shares - obj.getElementsAtFront();
					// pehli bari function laga kar queue ki value li or dosri bar usko pop kara liya 
					profit += (obj.getElementsAtFront() * shares_price) - ( obj.deQueue() * obj_price.deQueue()); 
				}
				// jab tak shares 0 nhi hotay tab tak loop chalata jaiye ga 
			} while (shares != 0);
		}

	}
		cout << endl << profit;
}